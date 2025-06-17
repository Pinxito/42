#!/bin/bash

# ========= CONFIG =========
PIPEX=./pipex
OUTFILE=out_pipex.txt
TMP_OUT=out_shell.txt
LOG=valgrind.log

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # Reset color

# ========= UTILS =========
function print_title() {
	echo -e "\n\033[1;34m== $1 ==\033[0m"
}

function compare_output() {
	diff "$1" "$2" > /dev/null
	if [ $? -eq 0 ]; then
		echo -e "${GREEN}[✓] Output matches${NC}"
	else
		echo -e "${RED}[✗] Output differs${NC}"
	fi
}

function compare_exit_code() {
	if [ $1 -eq $2 ]; then
		echo -e "${GREEN}[✓] Exit code matches ($1)${NC}"
	else
		echo -e "${RED}[✗] Exit code differs (pipex: $1, shell: $2)${NC}"
	fi
}

function check_valgrind() {
	valgrind --leak-check=full --error-exitcode=42 $@ 2> $LOG > /dev/null
	if [ $? -eq 42 ]; then
		echo -e "${RED}[✗] Memory leaks detected (Valgrind)${NC}"
		grep "definitely lost" $LOG
	else
		echo -e "${GREEN}[✓] No memory leaks (Valgrind)${NC}"
	fi
	rm -f $LOG
}

function check_valgrind_fds() {
	valgrind --track-fds=yes --error-exitcode=43 $@ 2> $LOG > /dev/null
	if [ $? -eq 43 ]; then
		echo -e "${RED}[✗] File descriptors no cerrados correctamente (Valgrind FDs)${NC}"
		grep "Open file descriptor" $LOG
	else
		echo -e "${GREEN}[✓] Todos los file descriptors cerrados (Valgrind FDs)${NC}"
	fi
	rm -f $LOG
}

# ========= TESTS =========

# Test 1: Valid command: tr | rev
print_title "Test 1: tr | rev"
echo "hello" > in.txt
echo "hello" | tr a-z A-Z | rev > $TMP_OUT
$PIPEX in.txt "tr a-z A-Z" "rev" $OUTFILE
compare_output $TMP_OUT $OUTFILE
compare_exit_code $? $?
check_valgrind $PIPEX in.txt "tr a-z A-Z" "rev" $OUTFILE
rm -f in.txt $OUTFILE $TMP_OUT

# Test 2: Comando inexistente
print_title "Test 2: Comando inexistente"
echo "test" > in.txt
$PIPEX in.txt "no_such_cmd" "cat" $OUTFILE 2> /dev/null
if [ $? -ne 0 ]; then
	echo -e "${GREEN}[✓] Error code on invalid command${NC}"
else
	echo -e "${RED}[✗] No error on invalid command${NC}"
fi
check_valgrind $PIPEX in.txt "no_such_cmd" "cat" $OUTFILE
rm -f in.txt $OUTFILE

# Test 3: Archivo de entrada inexistente
print_title "Test 3: Archivo de entrada inexistente"
$PIPEX nofile.txt "cat" "wc -l" $OUTFILE 2> /dev/null
if [ $? -ne 0 ]; then
	echo -e "${GREEN}[✓] Error code on missing file${NC}"
else
	echo -e "${RED}[✗] No error on missing file${NC}"
fi
check_valgrind $PIPEX nofile.txt "cat" "wc -l" $OUTFILE
rm -f $OUTFILE

# Test 4: Muy pocos argumentos
print_title "Test 4: Muy pocos argumentos"
$PIPEX only_one_arg 2> err.txt
if grep -q "Usage" err.txt; then
	echo -e "${GREEN}[✓] Usage message shown${NC}"
else
	echo -e "${RED}[✗] No usage message${NC}"
fi
rm -f err.txt

# Test 5: Archivo vacío
print_title "Test 5: Archivo vacío"
touch empty.txt
< empty.txt cat | wc -l > $TMP_OUT
$PIPEX empty.txt "cat" "wc -l" $OUTFILE
compare_output $TMP_OUT $OUTFILE
compare_exit_code $? $?
check_valgrind $PIPEX empty.txt "cat" "wc -l" $OUTFILE
rm -f empty.txt $OUTFILE $TMP_OUT

# Test 6: awk | wc -l
print_title "Test 6: awk | wc -l"
echo -e "uno dos\ntres\ncuatro cinco" > in.txt
< in.txt awk '{print $1}' | wc -l > $TMP_OUT
$PIPEX in.txt "awk '{print \$1}'" "wc -l" $OUTFILE
compare_output $TMP_OUT $OUTFILE
compare_exit_code $? $?
check_valgrind $PIPEX in.txt "awk '{print \$1}'" "wc -l" $OUTFILE
rm -f in.txt $OUTFILE $TMP_OUT

# Test 7: outfile sin permisos
print_title "Test 7: outfile sin permisos"
echo "test input" > in.txt
touch outfile_no_perm
chmod 000 outfile_no_perm
$PIPEX in.txt "cat" "cat" outfile_no_perm 2> /dev/null
if [ $? -ne 0 ]; then
	echo -e "${GREEN}[✓] Error al abrir outfile sin permisos${NC}"
else
	echo -e "${RED}[✗] No hay error con outfile sin permisos${NC}"
fi
check_valgrind $PIPEX in.txt "cat" "cat" outfile_no_perm
check_valgrind_fds $PIPEX in.txt "cat" "cat" outfile_no_perm
chmod 644 outfile_no_perm
rm -f in.txt outfile_no_perm

# Test 8: infile sin permisos
print_title "Test 8: infile sin permisos"
touch infile_no_perm
chmod 000 infile_no_perm
$PIPEX infile_no_perm "cat" "cat" $OUTFILE 2> /dev/null
if [ $? -ne 0 ]; then
	echo -e "${GREEN}[✓] Error al abrir infile sin permisos${NC}"
else
	echo -e "${RED}[✗] No hay error con infile sin permisos${NC}"
fi
check_valgrind $PIPEX infile_no_perm "cat" "cat" $OUTFILE
check_valgrind_fds $PIPEX infile_no_perm "cat" "cat" $OUTFILE
chmod 644 infile_no_perm
rm -f infile_no_perm $OUTFILE

# Test 9: infile inexistente
print_title "Test 9: infile inexistente"
rm -f nonexistent.txt
$PIPEX nonexistent.txt "cat" "cat" $OUTFILE 2> /dev/null
if [ $? -ne 0 ]; then
	echo -e "${GREEN}[✓] Error con infile inexistente${NC}"
else
	echo -e "${RED}[✗] No hay error con infile inexistente${NC}"
fi
check_valgrind $PIPEX nonexistent.txt "cat" "cat" $OUTFILE
check_valgrind_fds $PIPEX nonexistent.txt "cat" "cat" $OUTFILE
rm -f $OUTFILE

# Test 10: comando vacío con espacio
print_title "Test 10: Comando vacío (espacio)"
echo "data" > in.txt
$PIPEX in.txt "cat" " " $OUTFILE 2> /dev/null
if [ $? -ne 0 ]; then
	echo -e "${GREEN}[✓] Error con comando vacío (espacio)${NC}"
else
	echo -e "${RED}[✗] No hay error con comando vacío (espacio)${NC}"
fi
check_valgrind $PIPEX in.txt "cat" " " $OUTFILE
check_valgrind_fds $PIPEX in.txt "cat" " " $OUTFILE
rm -f in.txt $OUTFILE

# Test 11: comando completamente vacío
print_title "Test 11: Comando vacío (string vacío)"
echo "data" > in.txt
$PIPEX in.txt "cat" "" $OUTFILE 2> /dev/null
if [ $? -ne 0 ]; then
	echo -e "${GREEN}[✓] Error con comando vacío (string vacío)${NC}"
else
	echo -e "${RED}[✗] No hay error con comando vacío (string vacío)${NC}"
fi
check_valgrind $PIPEX in.txt "cat" "" $OUTFILE
check_valgrind_fds $PIPEX in.txt "cat" "" $OUTFILE
rm -f in.txt $OUTFILE

# Test 12: Valgrind FDs - ejecución sin errores
print_title "Test 12: Verificación de file descriptors cerrados correctamente"
echo "data" > in.txt
$PIPEX in.txt "cat" "cat" $OUTFILE > /dev/null
check_valgrind $PIPEX in.txt "cat" "cat" $OUTFILE
check_valgrind_fds $PIPEX in.txt "cat" "cat" $OUTFILE
rm -f in.txt $OUTFILE

# ========= DONE =========
echo -e "\n\033[1;32mTodos los tests finalizados.\033[0m"
