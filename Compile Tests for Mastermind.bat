@echo off


echo       _________________________________________
echo      /   Compile Tests for Mastermind         /
echo     /                     by alpha-kappa-de  /
echo    /________________________________________/
echo.
echo This program will compile the translation units and your test using gcc und C89 standard. Then it will start the compiled test.
echo Place it into the same path where your c files are located.
echo.

echo What's the name of your test? Example "TEST_mytest" (Without quotationmarks and without the ".c")
echo.
set /p test_file_name=

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
echo Compiling %test_file_name%.c
cmd /c "gcc mastermind.o mastermind_language.o mastermind_gui.o %test_file_name%.c -o %test_file_name%.exe -ansi -pedantic -Wall -Wextra" 



echo ___________________________________________________________________________
echo If you didn't see any warnings or errors then everything worked perfectly. 
echo Else correct your code and try again.
echo.
echo To run your test, press any key.
pause >nul
echo.

cmd /c "%test_file_name%.exe"

echo.
echo.
echo End of test. Press any button to exit
pause >nul
