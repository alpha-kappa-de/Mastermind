#!/usr/bin/env bash

REQUIRED_CODE_FILES=$'\nmastermind.c \nmastermind.h \nmastermind_language.c \nmastermind_language.h \nmastermind_gui.c \nmastermind_gui.h \nprogram.c'

GREEN="\033[1;32m"
RED="\033[1;31m"
BLUE="\033[1;34m"
RESET_TEXT_FORMATTING="\033[0m"


echo -e "${BLUE}       ___________________________________________________________ "
echo "      /        Compile Mastermind (FOR DEBUGGING ONLY)           / "
echo "     /                                                          / "
echo "    /                                by alpha-kappa-de         / "
echo -e "   /__________________________________________________________/"
echo ""
echo "This program builds the game Mastermind for debugging using gcc."
echo "If gcc is not installed on your PC, please install it and try again."
echo -e "RUN THIS SCRIPT ONLY IN THE \"debugscripts\" DIRECTORY! USING AT OWN RISK!${RESET_TEXT_FORMATTING}"
echo ""

cd $PWD
cd ..

if [ -d "Mastermind" ]; then
    tput bel
    echo -e "${RED}WRONG DIRECTORY. DON'T USE THIS SCRIPT IN THE \"Mastermind\" ROOT DIRECTORY!${RESET_TEXT_FORMATTING}"
    exit 2
elif [ ! -d "code" ]; then
    tput bel
    echo -e "${RED}DIRECTORY \"code\" DOESN'T EXIST!${RESET_TEXT_FORMATTING}"
    echo -e "${RED}YOU MAY BE IN THE WRONG DIRECTORY.${RESET_TEXT_FORMATTING}"
    exit 2
elif [ ! -d "debugscripts" ]; then
    tput bel
    echo -e "${RED}DIRECTORY \"debugscripts\" DOESN'T EXIST!${RESET_TEXT_FORMATTING}"
    echo -e "${RED}YOU MAY BE IN THE WRONG DIRECTORY.${RESET_TEXT_FORMATTING}"
    exit 2
fi

echo -n "Do you want to debug a test (1) test a gamebuild (2) or exit (3)?: "
while true; do
    read -p "" mode
    case $mode in
        [1]* ) mode="1"; break;;
        [2]* ) mode="2"; break;;
        [3]* ) exit 1;;
        * ) tput bel; echo -n "Do you want to debug a test (1) test a gamebuild (2) or exit (3)?: ";;
    esac
done

if [ $mode == "1" ]; then
    if [ ! -d "tests" ]; then
        tput bel
        echo -e "${RED}DIRECTORY \"tests\" DOESN'T EXIST. IF YOU WANT TO DEBUG THE MAINGAME, USE OPTION 2!${RESET_TEXT_FORMATTING}"
        exit 2
    else 
        cd tests
        echo "___________________________________________________________________________"
        ls
        echo "___________________________________________________________________________"
        echo "Choose a test from one of the files below."
        read -p "Please enter only the filename without suffix: " test_file_name
        while true; do
            if [ ! -f ${test_file_name}.c ]; then
                echo "${test_file_name}.c doesn't exist!"
                read -p "Please enter only the filename without suffix: " test_file_name
            else
                break
            fi
        done
        filename="tests/$test_file_name.c"
        cd ..
    fi
elif [ $mode == "2" ]; then
    filename="code/program.c"
fi


echo "___________________________________________________________________________"
echo "Copying codefiles"
mkdir -p .temp
if cp code/mastermind.c code/mastermind.h code/mastermind_language.c code/mastermind_language.h code/mastermind_gui.c code/mastermind_gui.h "$filename" .temp/; then 
    cd .temp
    echo -e "${GREEN}SUCCESS!${RESET_TEXT_FORMATTING}"
else 
    tput bel
    echo "Files are missing. Make sure these files are in the \"code\" directory:${REQUIRED_CODE_FILES}"
    rm -r .temp
    exit 3
fi

echo "___________________________________________________________________________"
echo "Compiling mastermind.c"
if gcc -c mastermind.c mastermind.h -ansi -pedantic -Wall -Wextra; then 
    echo -e "${GREEN}SUCCESS!${RESET_TEXT_FORMATTING}"
else 
    tput bel
    echo -e "${RED}FAILURE!${RESET_TEXT_FORMATTING}"
    rm -r .temp
    exit 4
fi

echo "___________________________________________________________________________"
echo "Compiling mastermind_language.c"
if gcc -c mastermind_language.c mastermind_language.h -ansi -pedantic -Wall -Wextra; then 
    echo -e "${GREEN}SUCCESS!${RESET_TEXT_FORMATTING}"
else 
    tput bel
    echo -e "${RED}FAILURE!${RESET_TEXT_FORMATTING}"
    rm -r .temp
    exit 5
fi

echo "___________________________________________________________________________"
echo "Compiling mastermind_gui.c"
if gcc -c mastermind_gui.c mastermind_gui.h -ansi -pedantic -Wall -Wextra; then 
    echo -e "${GREEN}SUCCESS!${RESET_TEXT_FORMATTING}"
else 
    tput bel
    echo -e "${RED}FAILURE!${RESET_TEXT_FORMATTING}"
    rm -r .temp
    exit 6
fi

echo "___________________________________________________________________________"
if [ $mode == "2" ]; then
    echo "Compiling program.c"
else
    echo "Compiling $test_file_name.c"
fi

if [ $mode == "2" ]; then
    if gcc mastermind.o mastermind_language.o mastermind_gui.o program.c -o testbuild.out -ansi -pedantic -Wall -Wextra; then 
        echo -e "${GREEN}SUCCESS!${RESET_TEXT_FORMATTING}"
    else 
        tput bel
        echo -e "${RED}FAILURE!${RESET_TEXT_FORMATTING}"
        rm -r .temp
        exit 7
    fi
else
    if gcc mastermind.o mastermind_language.o mastermind_gui.o "$test_file_name.c" -o testbuild.out -ansi -pedantic -Wall -Wextra; then 
        echo -e "${GREEN}SUCCESS!${RESET_TEXT_FORMATTING}"
    else 
        tput bel
        echo -e "${RED}FAILURE!${RESET_TEXT_FORMATTING}"
        rm -r .temp
        exit 7
    fi
fi
echo "___________________________________________________________________________"
echo "Copying testbuild.out to the root folder"
cd ..
if cp .temp/testbuild.out testbuild.out; then 
    echo -e "${GREEN}SUCCESS!${RESET_TEXT_FORMATTING}"
else 
    tput bel
    echo -e "${RED}FAILURE!${RESET_TEXT_FORMATTING}"
    rm -r .temp
    exit 8
fi

echo "___________________________________________________________________________"
echo "Removing temporary files"
if rm -r .temp; then 
    echo -e "${GREEN}SUCCESS!${RESET_TEXT_FORMATTING}"
else 
    tput bel
    echo "${RED}FAILURE!${RESET_TEXT_FORMATTING}" 
    echo "You may try to delete the temporary folder \".temp\" by yourself"
    exit 9
fi

echo "___________________________________________________________________________"
echo "If you didn't see any warnings or errors then everything worked perfectly."
echo ""

read -n 1 -s -r -p "To run your test, press any key. "

./testbuild.out

echo ""
echo ""

if rm testbuild.out; then 
    read -n 1 -s -r -p "End of test. Press any key to exit. "
    exit 0
else 
    tput bel
    echo "${RED}testbuild.out COULDN'T BE DELETED OR DOESN'T EVEN EXIST. PLEASE TRY YOURSELF!${RESET_TEXT_FORMATTING}" 
    exit 10
fi
