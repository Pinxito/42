#!/bin/bash

# Colores
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

PIPEX=./pipex
OK="${GREEN}[OK]${NC}"
KO="${RED}[KO]${NC}"

# Comparador de archivos
check_diff() {
	diff "$1" "$2" > /dev/null
	if [ $? -eq 0 ]; then
		echo -e "$3 $OK"
	else
		echo -e "$3 $KO"
		diff "$1" "$2"
	fi
}

echo "🔧 Compilando..."
make re > /dev/null || { echo -e "${RED}Fallo al compilar${NC}"; exit 1; }

# 1. Test básico
echo -e "hola\nmundo" > infile.txt
$PIPEX infile.txt "tr a-z A-Z" "rev" outfile_pipex.txt
< infile.txt tr a-z A-Z | rev > outfile_shell.txt
check_diff outfile_pipex.txt outfile_shell.txt "Test 1: tr | rev"

# 2. Comando inexistente
echo -e "\nTest 2: Comando inexistente"
$PIPEX infile.txt "noexistecomando" "rev" error.txt 2> stderr.txt
grep -qi "command not found" stderr.txt && echo -e "  Error detectado $OK" || echo -e "  Error no detectado $KO"

# 3. Archivo de entrada inexistente
echo -e "\nTest 3: Archivo de entrada inexistente"
$PIPEX nofile.txt "cat" "wc -l" error2.txt 2> stderr2.txt
grep -qi "No such file" stderr2.txt && echo -e "  Error detectado $OK" || echo -e "  Error no detectado $KO"

# 4. Muy pocos argumentos
echo -e "\nTest 4: Muy pocos argumentos"
$PIPEX infile.txt "cat" error.txt 2> stderr3.txt
grep -qi "usage" stderr3.txt && echo -e "  Mensaje de uso mostrado $OK" || echo -e "  Mensaje de uso no mostrado $KO"

# 5. Archivo vacío
touch empty.txt
$PIPEX empty.txt "cat" "wc -l" out_empty.txt
< empty.txt cat | wc -l > out_shell_empty.txt
check_diff out_empty.txt out_shell_empty.txt "Test 5: Archivo vacío"

# 6. awk | wc -l usando archivo de script para evitar comillas rotas
echo -e "uno dos\ntres cuatro" > infile2.txt

# Creamos un script awk en archivo temporal
echo '{ print $2 }' > awk_script.awk

# Ejecutamos usando -f para cargar el script
$PIPEX infile2.txt "awk -f awk_script.awk" "wc -l" out_flag_pipex.txt
< infile2.txt awk -f awk_script.awk | wc -l > out_flag_shell.txt

check_diff out_flag_pipex.txt out_flag_shell.txt "Test 6: awk | wc -l"

# Limpieza del script awk
rm -f awk_script.awk


# Limpieza
rm -f infile.txt infile2.txt empty.txt error*.txt stderr*.txt out_*.txt outfile_*.txt
