@echo off


echo       _________________________________________
echo      /       Compile Mastermind               /
echo     /                     by alpha-kappa-de  /
echo    /________________________________________/
echo.
echo This program will build the game Mastermind.
echo RUN THIS SCRIPT ONLY IN THE ROOT FOLDER "/Mastermind"!
echo.
echo Press any key to continue. Else just close this window.
pause >nul

mkdir .temp
mkdir MASTERMIND_EXECUTABLE

echo ___________________________________________________________________________
echo Copying needed files
>NUL copy "code\mastermind.c" ".temp\mastermind.c"
>NUL copy "code\mastermind.h" ".temp\mastermind.h"
>NUL copy "code\mastermind_language.c" ".temp\mastermind_language.c"
>NUL copy "code\mastermind_language.h" ".temp\mastermind_language.h"
>NUL copy "code\mastermind_gui.c" ".temp\mastermind_gui.c"
>NUL copy "code\mastermind_gui.h" ".temp\mastermind_gui.h"
>NUL copy "code\program.c" ".temp\program.c"
>NUL copy "code\mastermind_info.rc" ".temp\mastermind_info.rc"
>NUL copy "mastermind_icon.ico" ".temp\mastermind_icon.ico"
cd .temp

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
echo Compiling mastermind_info.rc
cmd /c "windres mastermind_info.rc mastermind_info.o" 

echo ___________________________________________________________________________
echo Compiling program.c
cmd /c "gcc mastermind.o mastermind_language.o mastermind_gui.o mastermind_info.o program.c -o Mastermind.exe -ansi -pedantic -Wall -Wextra" 

echo ___________________________________________________________________________
echo Cleaning up
cd ..\
>NUL copy ".temp\Mastermind.exe" "MASTERMIND_EXECUTABLE\Mastermind.exe"
rmdir ".temp" /S /Q
echo ___________________________________________________________________________
echo.
echo.
echo If you didn't see any warnings or errors then everything worked perfectly. 
echo.
echo Note: 	Before playing the game on Windows, make sure to run "activate_ansi_escape_codes_in_windows.reg", 
echo 	so you can use the pretty mode GUI.
echo.
echo Press any key to exit.
pause >nul
