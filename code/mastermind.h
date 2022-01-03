#ifndef MASTERMIND_H_INCLUDED
#define MASTERMIND_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mastermind_language.h"
#include "mastermind_gui.h"

#define INVALID_LANGUAGE_ERROR() {printf("Invalid language set. Please restart the game."); exit(LANGUAGE_ERROR);}
#define EXIT_PROGRAM_SUCCESSFUL() {printf("Game is exiting now."); exit(SUCCESS);}
#define INVALID_MENU_INPUT_ERROR() (lang_print_invalid_menu_input_message())

#define LANG_PRINT_RANDOM_COLOR() (printf("%s", lang_color_name(generate_random_color())))

#define SUCCESS 0
#define LANGUAGE_ERROR -1
#define BUFFER_ERROR -2
#define INVALID_MENU_INPUT -3

#define MAX_COLORCODE_LENGTH 8
#define AMOUNT_OF_COLORS 6
#define BLUE 0
#define RED 1
#define YELLOW 2
#define GREEN 3
#define PURPLE 4
#define BROWN 5

#define MENU_OPTION_PLAY 1
#define MENU_OPTION_HOWTOPLAY 2
#define MENU_OPTION_LANGUAGE 3
#define MENU_OPTION_STATS 4
#define MENU_OPTION_EXIT 5

int player1_colorcode[MAX_COLORCODE_LENGTH];
int player2_colorcode[MAX_COLORCODE_LENGTH];
int player_guess[MAX_COLORCODE_LENGTH];

int colorcode_length;

int check_colorcode_and_print_correct_pins(int *colorcode, int *guess);
int generate_random_color();

#endif
