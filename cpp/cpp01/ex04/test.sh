#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

pass=0
fail=0

check_contains() {
	local desc="$1"
	local output="$2"
	local expected="$3"
	if echo "$output" | grep -qF "$expected"; then
		echo -e "${GREEN}OK${NC}   - $desc"
		pass=$((pass+1))
	else
		echo -e "${RED}FAIL${NC} - $desc"
		echo "     esperaba (contener): $expected"
		echo "     obtuve: $output"
		fail=$((fail+1))
	fi
}

check_file_equals() {
	local desc="$1"
	local file="$2"
	local expected="$3"
	if [ -f "$file" ] && diff -q <(printf "%s" "$expected") "$file" > /dev/null 2>&1; then
		echo -e "${GREEN}OK${NC}   - $desc"
		pass=$((pass+1))
	else
		echo -e "${RED}FAIL${NC} - $desc"
		echo "     archivo: $file"
		[ -f "$file" ] && echo "     contenido: $(cat "$file")" || echo "     (el archivo no existe)"
		fail=$((fail+1))
	fi
}

echo "=== Recompilando ==="
make re > /dev/null 2>&1

echo ""
echo "=== Test 1: reemplazo normal (varias ocurrencias) ==="
./replace test1.txt hello bonjour
check_file_equals "test1 reemplazado correctamente" "test1.txt.replace" \
"bonjour world, bonjour there, bonjour!
no match here
bonjouro edge case
"

echo ""
echo "=== Test 2: ocurrencias consecutivas ==="
./replace test2.txt aaa X
check_file_equals "test2 reemplazado correctamente" "test2.txt.replace" \
"X bbb X ccc X
"

echo ""
echo "=== Test 3: sin coincidencias ==="
./replace test3.txt xyz abc
check_file_equals "test3 queda igual (sin match)" "test3.txt.replace" \
"sin coincidencias en este archivo
otra linea normal
"

echo ""
echo "=== Test 4: coincidencia al final sin salto de línea ==="
./replace test4.txt hello HI
check_file_equals "test4 reemplazado en el borde" "test4.txt.replace" \
"texto que termina justoHI
"

echo ""
echo "=== Test 5: archivo vacío ==="
./replace test5_vacio.txt a b
check_file_equals "test5 sigue vacío" "test5_vacio.txt.replace" ""

echo ""
echo "=== Test 6: s1 vacío -> debe dar error, no colgarse ==="
output=$(timeout 2 ./replace test1.txt "" x 2>&1)
if [ $? -eq 124 ]; then
	echo -e "${RED}FAIL${NC} - se quedó colgado (bucle infinito) con s1 vacío"
	fail=$((fail+1))
else
	check_contains "s1 vacío da error controlado" "$output" "Error"
fi

echo ""
echo "=== Test 7: archivo inexistente ==="
output=$(./replace noexiste.txt a b 2>&1)
check_contains "archivo inexistente da error" "$output" "Impossible"

echo ""
echo "=== Test 8: argumentos incorrectos ==="
output=$(./replace test1.txt hello 2>&1)
check_contains "argumentos incorrectos muestra uso" "$output" "argument"

echo ""
echo "=== Limpieza ==="
rm -f *.replace
make fclean > /dev/null 2>&1

echo ""
echo "======================================"
echo -e "Resultado: ${GREEN}$pass OK${NC} / ${RED}$fail FAIL${NC}"
echo "======================================"