#!/bin/bash

# Color variables
RED='\033[1;31m'
GREEN='\033[1;32m'
WHITE='\033[1;37m'
BLUE='\033[1;34m'
CYAN='\033[1;36m'
UNDERLINE='\033[4m'
RESET='\033[0m'

input_file="Makefile"

compare_output() {
    if diff -q out_pipex out_bash > /dev/null 2>&1; then
        echo -ne "${GREEN}[OK] ${RESET}"
    else
        echo -ne "${RED}[KO] ${RESET}"
    fi
}

echo -e "\\n ${CYAN}${UNDERLINE}PIPEX TESTER${RESET}\\n"

echo -e "${BOLD} MANDATORY PART ${RESET}"

# Test 01
echo -ne "${WHITE}01:${RESET}"
# Execute the program
./pipex $input_file cat wc out_pipex
< $input_file cat | wc > out_bash
# Compare the output with the expected result
compare_output

# Test 02
echo -ne "${WHITE}02:${RESET}"
# Execute the program
./pipex $input_file "/bin/cat" "/bin/wc" out_pipex
< $input_file /bin/cat | /bin/wc > out_bash
# Compare the output with the expected result
compare_output

# Test 03
echo -ne "${WHITE}03:${RESET}"
# Execute the program
./pipex $input_file "ls -l" "grep Makefile" out_pipex
< $input_file ls -l | grep Makefile > out_bash
compare_output

# Test 04
echo -ne "${WHITE}04:${RESET}"
# Execute the program
./pipex $input_file "ls -l" "grep Makefile" out_pipex
< $input_file ls -l | grep Makefile > out_bash
compare_output

echo ""

# Remove the output files
rm -f out_pipex out_bash