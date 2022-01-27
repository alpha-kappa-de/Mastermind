@echo off


echo       _________________________________________
echo      /   Compile Tests for Mastermind         /
echo     /                     by alpha-kappa-de  /
echo    /________________________________________/
echo.
echo This program will compile the translation units and your test using gcc und C89 standard. Then it will start the compiled test.
echo RUN THIS SCRIPT ONLY IN THE "/scripts" FOLDER!
echo.

echo What's the name of your test? Press TAB to scroll trough the folder or type in the name. 
echo Example "TEST_mytest.c" (Without quotationmarks)
echo.

cd ..\
mkdir .temp
>NUL copy "code\mastermind.c" ".temp\mastermind.c"
>NUL copy "code\mastermind.h" ".temp\mastermind.h"
>NUL copy "code\mastermind_language.c" ".temp\mastermind_language.c"
>NUL copy "code\mastermind_language.h" ".temp\mastermind_language.h"
>NUL copy "code\mastermind_gui.c" ".temp\mastermind_gui.c"
>NUL copy "code\mastermind_gui.h" ".temp\mastermind_gui.h"

cd tests
set /p test_file_name=

cd ..\
>NUL copy "tests\%test_file_name%" ".temp\%test_file_name%"

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
echo Compiling %test_file_name%
cmd /c "gcc mastermind.o mastermind_language.o mastermind_gui.o %test_file_name% -o %test_file_name%.exe -ansi -pedantic -Wall -Wextra" 

echo ___________________________________________________________________________
echo If you didn't see any warnings or errors then everything worked perfectly. Else correct your code and try again.
echo.

echo To run your test, press any key.
pause >nul
echo.

cmd /c "%test_file_name%.exe"

echo.
echo.
echo End of test. Press any key to clean up and exit.
pause >nul
echo Cleaning up temporary files...
cd ..\
rmdir ".temp" /S /Q
