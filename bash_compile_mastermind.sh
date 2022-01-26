#!/usr/bin/env bash

REQUIRED_CODE_FILES=$'\nmastermind.c \nmastermind.h \nmastermind_language.c \nmastermind_language.h \nmastermind_gui.c \nmastermind_gui.h \nprogram.c'

GREEN="\033[1;32m"
RED="\033[1;31m"
BLUE="\033[1;34m"
RESET_TEXT_FORMATTING="\033[0m"


echo -e "${BLUE}       ___________________________________________________________ "
echo "      /                   Compile Mastermind                     / "
echo "     /                                                          / "
echo "    /                                by alpha-kappa-de         / "
echo -e "   /__________________________________________________________/"
echo ""
echo "This program will build the game Mastermind using gcc."
echo "If gcc is not installed on your PC, please install it and try again."
echo -e "RUN THIS SCRIPT ONLY IN THE \"Mastermind\" DIRECTORY! USING AT OWN RISK!${RESET_TEXT_FORMATTING}"
echo ""

echo -n "Proceed? [Y|N]: "
while true; do
    read -p "" yn
    case $yn in
        [Yy]* ) break;;
        [Nn]* ) echo "OK. Goodbye"; exit 1;;
        * ) tput bel; echo -n "Proceed? [Y|N]: ";;
    esac
done

cd $PWD
cd ..


if [ ! -d "Mastermind" ]; then
    tput bel
    echo -e "${RED}Directory \"Mastermind\" doesn't exist.${RESET_TEXT_FORMATTING}"
    echo -e "${RED}You may be missing some files or start the script in the wrong directory${RESET_TEXT_FORMATTING}"
    echo -e "${RED}Please make sure you're running this script in the root directory called \"Mastermind\".${RESET_TEXT_FORMATTING}"
    exit 2
else cd Mastermind
fi

if [ ! -d "code" ]; then
    tput bel
    echo -e "${RED}Directory \"code\" doesn't exist.${RESET_TEXT_FORMATTING}"
    echo -e "${RED}You may be missing some files or start the script in the wrong directory${RESET_TEXT_FORMATTING}"
    echo -e "${RED}Please make sure you're running this script in the root directory called \"Mastermind\".${RESET_TEXT_FORMATTING}"
    echo -e "${RED}Please make also sure that the \"code\" directory is inside${RESET_TEXT_FORMATTING}"
    exit 3
fi

echo "___________________________________________________________________________"
echo "Copying codefiles"
mkdir -p .temp
if cp code/mastermind.c code/mastermind.h code/mastermind_language.c code/mastermind_language.h code/mastermind_gui.c code/mastermind_gui.h code/program.c .temp/; then 
    cd .temp
    echo -e "${GREEN}SUCCESS!${RESET_TEXT_FORMATTING}"
else 
    tput bel
    echo "Files are missing. Make sure these files are in the \"code\" directory:${REQUIRED_CODE_FILES}"
    rm -r .temp
    exit 5
fi

echo "___________________________________________________________________________"
echo "Compiling mastermind.c"
if gcc -c mastermind.c mastermind.h -ansi -pedantic -Wall -Wextra; then 
    echo -e "${GREEN}SUCCESS!${RESET_TEXT_FORMATTING}"
else 
    tput bel
    echo -e "${RED}FAILURE!${RESET_TEXT_FORMATTING}"
    rm -r .temp
    exit 6
fi

echo "___________________________________________________________________________"
echo "Compiling mastermind_language.c"
if gcc -c mastermind_language.c mastermind_language.h -ansi -pedantic -Wall -Wextra; then 
    echo -e "${GREEN}SUCCESS!${RESET_TEXT_FORMATTING}"
else 
    tput bel
    echo -e "${RED}FAILURE!${RESET_TEXT_FORMATTING}"
    rm -r .temp
    exit 7
fi

echo "___________________________________________________________________________"
echo "Compiling mastermind_gui.c"
if gcc -c mastermind_gui.c mastermind_gui.h -ansi -pedantic -Wall -Wextra; then 
    echo -e "${GREEN}SUCCESS!${RESET_TEXT_FORMATTING}"
else 
    tput bel
    echo -e "${RED}FAILURE!${RESET_TEXT_FORMATTING}"
    rm -r .temp
    exit 8
fi

echo "___________________________________________________________________________"
echo "Compiling program.c"
if gcc mastermind.o mastermind_language.o mastermind_gui.o program.c -o Mastermind.out -ansi -pedantic -Wall -Wextra; then 
    echo -e "${GREEN}SUCCESS!${RESET_TEXT_FORMATTING}"
else 
    tput bel
    echo -e "${RED}FAILURE!${RESET_TEXT_FORMATTING}"
    rm -r .temp
    exit 9
fi

echo "___________________________________________________________________________"
echo "Copying Mastermind.out to the root folder"
cd ..
if cp .temp/Mastermind.out Mastermind.out; then 
    echo -e "${GREEN}SUCCESS!${RESET_TEXT_FORMATTING}"
else 
    tput bel
    echo -e "${RED}FAILURE!${RESET_TEXT_FORMATTING}"
    rm -r .temp
    exit 10
fi

echo "___________________________________________________________________________"
echo "Removing temporary files"
if rm -r .temp; then 
    echo -e "${GREEN}SUCCESS!${RESET_TEXT_FORMATTING}"
else 
    tput bel
    echo "${RED}FAILURE!${RESET_TEXT_FORMATTING}" 
    echo "You may try to delete the temporary folder \".temp\" by yourself"
    exit 11
fi

echo "___________________________________________________________________________"
echo ""
echo ""
echo "Everything worked perfectly."
echo "Mastermind.out is in the root directory now. Have fun playing the game."
echo "To start the game, open a terminal in the Mastermind folder (or just use"
echo "this one) and type ./Mastermind.out"
exit 0
