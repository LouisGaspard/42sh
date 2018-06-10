#!/bin/bash

###################
## MADE BY 42SCH ##
###################

read -p "PATH REPOSITORY ?  " REPO;

echo -e "COMPILATION ...\n"
make re -C $REPO > /dev/null
cp $REPO/42sh . > /dev/null 2>&1

RED='\e[0;31m'
GREEN='\e[0;32m'
NC='\e[0m'

SH=tcsh
SHB=./42sh
OUT=tcsh_out
OUTB=42sh_out
DIFF=diff.txt
i=1

COMMAND=""

echo -e "~~~~~ RETURN VALUE ~~~~~\n"

check_return_value() {
    echo "~~~~~~~ TEST $i: ~~~~~~~"
    echo -n ${TEST_NAME}
    echo ${COMMAND} | ${SH} > /dev/null 2>&1; echo $? > ${OUT}
    echo ${COMMAND} | ${SHB} > /dev/null 2>&1; echo $? > ${OUTB}
    diff ${OUT} ${OUTB} > ${DIFF}
    if [ $? -eq 1 ]
    then
	echo -ne "\t${RED}KO${NC}"
	echo -e "\tTest -> '$>" ${COMMAND} "'\n"
	cat ${DIFF}
	echo ""
    else
	echo -e "\t${GREEN}OK${NC}"
    fi
    ((i++))
}

TEST_NAME="Wrong path cd"
COMMAND="cd toto"
check_return_value

TEST_NAME="Wrong setenv"
COMMAND="setenv 42"
check_return_value

TEST_NAME="Wrong exit"
COMMAND="exit toto"
check_return_value

TEST_NAME="Wrong where"
COMMAND="where"
check_return_value

TEST_NAME="Only a pipe"
COMMAND="|"
check_return_value

TEST_NAME="Simple ls"
COMMAND="ls"
check_return_value

TEST_NAME="Wrong simple command"
COMMAND="ls"
check_return_value

echo -e "\n\n~~~~ ERROR MESSAGES ~~~~\n"

check_return_value() {
    echo "~~~~~~~ TEST $i: ~~~~~~~"
    echo -n ${TEST_NAME}
    echo ${COMMAND} | ${SH} > ${OUT} > /dev/null 2>&1
    echo ${COMMAND} | ${SHB} > ${OUTB} > /dev/null 2>&1
    diff ${OUT} ${OUTB} > ${DIFF}
    if [ $? -eq 1 ]
    then
	echo -ne "\t${RED}KO${NC}"
	echo -e "\tTest -> '$>" ${COMMAND} "'\n"
	cat ${DIFF}
	echo ""
    else
	echo -e "\t${GREEN}OK${NC}"
    fi
    ((i++))
}

touch tmp

TEST_NAME="CD: No such file or directory"
COMMAND="cd toto"
check_return_value

TEST_NAME="CD: Not a directory"
COMMAND="cd tmp"
check_return_value

TEST_NAME="Command not found"
COMMAND="toto"
check_return_value

TEST_NAME="Permission denied"
COMMAND="./tmp"
check_return_value

TEST_NAME="EXIT: Expression Syntax"
COMMAND="exit toto"
check_return_value

TEST_NAME="SETENV: Variable name must contain alphanumeric characters"
COMMAND="setenv to@to toto"
check_return_value

TEST_NAME="SETENV: Too many arguments"
COMMAND="setenv toto tata titi"
check_return_value

TEST_NAME="SETENV: Variable name must begin with a letter"
COMMAND="setenv 23toto titi"
check_return_value

rm -f ${OUT} ${OUTB} ${DIFF} ${SHB} tmp
make fclean -C ../../../PSU_42sh_2017 > /dev/null
