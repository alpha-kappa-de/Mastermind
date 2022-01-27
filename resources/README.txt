________________________________________________________________________________________________________________________________________________

MASTERMIND - Game project for university
by α-kappa, Jooosy and JanisNoah.
________________________________________________________________________________________________________________________________________________

This is a little project we were writing for university. It's the game Mastermind also known as SuperHirn, Super Code, Variablo and LogikTrainer.
The code is completely written in C according to the C89 standard and it's only using the C89 standard library.

It was tested only on Windows 10 [21H1]. To start the game, you can simply doubleclick the Mastermind.exe, no need to open a console window.

For the best experience, it's recommended to use a console window size of 120 chars x 30 chars (This should be the default size). If you're not sure,
just maximize the window. It's also recommended to activate the pretty mode. You will have to run activate_ansi_escape_codes_in_windows.reg
in order to activate it (After playing, you can always run deactivate_ansi_escape_codes_in_windows.reg, this will undo the changes in the registry).

In the main menu, you can start a game, get information about how to play the game, show the statistics, change the gamesettings and end the game.
In the settings, you can change the language (English, German and French) and change the GUI mode (compatible mode or pretty mode).
The statistics will read your savegame (if you don't have a savegame it's automatically generated in the directory, where the Mastermind.exe is in) 
and show data about the players. Every time you end a game, your data is saved to the savegame. If it's your first game, you get a new entry in
the stats. Everytime you type in a name, which is already in the savefile, the data in it will be merged.


________________________________________________________________________________________________________________________________________________

How to play:
________________________________________________________________________________________________________________________________________________
Mastermind:
At the beginning, both players secretly determine a 4-digit ordered color code, which is selected from 6 colors. The possible colors in this mode are: 
blue, red, yellow, green, purple and orange. Each color can also be used several times. The aim of the game is to find out the other player's
color code with as few moves as possible, but after a maximum of 12 attempts. With every move you get the information how many pins (in the color code) 
have been correctly set in color and position and how many pins are in the correct color but are in the wrong position.

Super Mastermind:
If the Super Mastermind option is selected, the color code consists of 5 pins. Instead of 6 colors, you can now choose from 8 colors. In addition to 
the colors from Mastermind there are: brown and cyan. Here, too, you have a maximum of 12 attempts to guess the code.
