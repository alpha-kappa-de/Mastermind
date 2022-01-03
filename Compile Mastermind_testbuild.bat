@echo off


echo       _________________________________________
echo      /     Compile Mastermind (for testing)   /
echo     /                     by alpha-kappa-de  /
echo    /________________________________________/
echo.
echo This program will build the game Mastermind and then delete it again. It is for testing purposes only.
echo Place it into the the root directory. (the directory with \code and \tests)
echo.

mkdir temp
>NUL copy "code\mastermind.c" "temp\mastermind.c"
>NUL copy "code\mastermind.h" "temp\mastermind.h"
>NUL copy "code\mastermind_language.c" "temp\mastermind_language.c"
>NUL copy "code\mastermind_language.h" "temp\mastermind_language.h"
>NUL copy "code\mastermind_gui.c" "temp\mastermind_gui.c"
>NUL copy "code\mastermind_gui.h" "temp\mastermind_gui.h"
>NUL copy "code\program.c" "temp\program.c"

cd temp

echo ___________________________________________________________________________
echo Compiling mastermind.c
cmd /c "gcc -c mastermind.c mastermind.h -ansi -pedantic -Wall -Wextra" 

echo ___________________________________________________________________________
echo Compiling mastermind_language.c
cmd /c "gcc -c mastermind_language.c mastermind_language.h -ansi -pedantic -Wall -Wextra" 

echo ___________________________________________________________________________
echo Compiling mastermind_gui.c
cmd /c "gcc -c mastermind_gui.c mastermind_gui.h -ansi -pedantic -Wall -Wextra" 

echo ___________________________________________________________________________
echo Compiling program.c
cmd /c "gcc mastermind.o mastermind_language.o mastermind_gui.o program.c -o Mastermind.exe -ansi -pedantic -Wall -Wextra" 

echo ___________________________________________________________________________
echo If you didn't see any warnings or errors then everything worked perfectly. 
echo You can start the Game by typing Mastermind.exe into the command line.
echo.

cd ..\
>NUL copy "temp\Mastermind.exe" "Mastermind_testbuild.exe"

echo Cleaning up temporary files...
rmdir "temp" /S /Q

echo To run your test, press any key.
pause >nul
echo.

cmd /c "Mastermind_testbuild.exe"

echo.
echo.
echo End of test. Press any button to clean up and exit.
pause >nul

del "Mastermind_testbuild.exe"

