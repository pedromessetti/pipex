#!/bin/bash

# ANSI color escape sequences
RED='\033[1;31m'
GREEN='\033[1;32m'
WHITE='\033[1;37m'
BLUE='\033[1;34m'
CYAN='\033[1;36m'
UNDERLINE='\033[4m'
RESET='\033[0m'

infile="Makefile"

# Function to compare output and display result
compare_output() {
    if diff -q out_pipex out_bash > /dev/null 2>&1; then
        echo -ne "${GREEN}[OK] ${RESET}"
    else
        echo -ne "${RED}[KO] ${RESET}"
    fi
}

new_line() {
    echo ""
}

echo -e "\\n ${CYAN}${UNDERLINE}PIPEX TESTER${RESET}\\n"

echo -e "${BOLD} Mandatory ${RESET}"

# Test 01
echo -ne "${WHITE}01:${RESET}"
# Execute the program
./pipex $infile "cat" "wc" out_pipex
< $infile cat | wc > out_bash
# Compare the output with the expected result
compare_output

# Test 01
echo -ne "${WHITE}01:${RESET}"
# Execute the program
./pipex $infile "cat" "cat" out_pipex
< $infile cat | cat > out_bash
# Compare the output with the expected result
compare_output

# Test 02
echo -ne "${WHITE}02:${RESET}"
# Execute the program
./pipex $infile "/bin/cat" "/bin/wc" out_pipex
< $infile /bin/cat | /bin/wc > out_bash
# Compare the output with the expected result
compare_output

# Test 02
echo -ne "${WHITE}02:${RESET}"
# Execute the program
./pipex $infile "/bin/cat" "/bin/cat" out_pipex
< $infile /bin/cat | /bin/cat > out_bash
# Compare the output with the expected result
compare_output

# Test 03
echo -ne "${WHITE}03:${RESET}"
# Execute the program
./pipex $infile "ls -l" "grep Makefile" out_pipex
< $infile ls -l | grep Makefile > out_bash
compare_output

# Test 04
echo -ne "${WHITE}04:${RESET}"
# Execute the program
./pipex $infile "cat" "hostname" out_pipex
< $infile cat | hostname > out_bash
compare_output

# Test 05
echo -ne "${WHITE}05:${RESET}"
# Execute the program
./pipex $infile "cat" "wc -l -c -w" out_pipex
< $infile cat | wc -l -c -w > out_bash
compare_output

echo -e "\\n\\n${BOLD} Error handling ${RESET}"

# Test 06
echo -ne "${WHITE}06:${RESET}"
# Execute the program
new_line
./pipex $infile "" "" out_pipex
< $infile "" | "" > out_bash
compare_output

# Test 07
echo -ne "${WHITE}07:${RESET}"
# Execute the program
new_line
./pipex $infile "" "cat" out_pipex
< $infile "" | cat > out_bash
compare_output

# Test 08
echo -ne "${WHITE}08:${RESET}"
# Execute the program
new_line
./pipex $infile "cat" "" out_pipex
< $infile cat |  > out_bash
compare_output

# Test 09
echo -ne "${WHITE}09:${RESET}"
# Execute the program
new_line
./pipex $infile "abc" "abc" out_pipex
< $infile abc | abc > out_bash
compare_output

# Test 10
echo -ne "${WHITE}10:${RESET}"
# Execute the program
new_line
./pipex $infile "abc" "" out_pipex
< $infile abc | "" > out_bash
compare_output

# Test 11
echo -ne "${WHITE}11:${RESET}"
# Execute the program
new_line
./pipex $infile "" "abc" out_pipex
< $infile "" | abc > out_bash
compare_output

# Test 12
echo -ne "${WHITE}12:${RESET}"
# Execute the program
new_line
./pipex $infile "abc" "cat" out_pipex
< $infile abc | cat > out_bash
compare_output

# Test 13
echo -ne "${WHITE}13:${RESET}"
# Execute the program
new_line
./pipex $infile "cat" "abc" out_pipex
< $infile cat | abc > out_bash
compare_output

# Test 14
echo -ne "${WHITE}14:${RESET}"
# Execute the program
new_line
./pipex $infile "abc" "ls" out_pipex
< $infile abc | ls > out_bash
compare_output

# Test 15
echo -ne "${WHITE}15:${RESET}"
# Execute the program
new_line
./pipex $infile "wc -x" "ls -." out_pipex
< $infile wc -x | ls -. > out_bash
compare_output

# Test 16
echo -ne "${WHITE}16:${RESET}"
# Execute the program
new_line
./pipex $infile "0" "0" out_pipex
< $infile 0 | 0 -. > out_bash
compare_output

# Test 17
echo -ne "${WHITE}17:${RESET}"
# Execute the program
new_line
./pipex $infile "wc -x" "" out_pipex
< $infile wc -x | "" > out_bash
compare_output

# Test 18
echo -ne "${WHITE}18:${RESET}"
# Execute the program
new_line
./pipex $infile "" "ls -." out_pipex
< $infile "" | ls -. > out_bash
compare_output

# Test 19
echo -ne "${WHITE}19:${RESET}"
# Execute the program
new_line
./pipex $infile "wc 0" "ls 0" out_pipex
< $infile wc 0 | ls 0 > out_bash
compare_output

# Test 20
echo -ne "${WHITE}20:${RESET}"
# Execute the program
new_line
./pipex $infile "/bin/xxx" "/bin/xxx" out_pipex
< $infile /bin/xxx | /bin/xxx > out_bash
# Compare the output with the expected result
compare_output

# Test 21
echo -ne "${WHITE}21:${RESET}"
# Execute the program
new_line
./pipex $infile "/bin/190i90qs01w9jç" "/bin/190i90qs01w9jç" out_pipex
< $infile /bin/190i90qs01w9jç | /bin/190i90qs01w9jç > out_bash
# Compare the output with the expected result
compare_output

echo -e "\\n\\n${BOLD} Multiple pipes ${RESET}"

# Test 06
echo -ne "${WHITE}06:${RESET}"
# Execute the program
./pipex $infile "cat -e" "grep $" "head -2" out_pipex
< $infile cat -e | grep $ | head -2 > out_bash
compare_output

new_line

# Remove the output files
rm -f out_pipex out_bash