#ifndef MASTERMIND_H_INCLUDED
#define MASTERMIND_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mastermind_language.h"
#include "mastermind_gui.h"

#define EXIT_PROGRAM_SUCCESSFUL() {printf("\n%s", lang_goodbye()); exit(SUCCESS);}
#define INVALID_LANGUAGE_ERROR() {printf("Errorcode: %i\nInvalid language set. Please contact the devs.", LANGUAGE_ERROR); exit(LANGUAGE_ERROR);}
#define INVALID_MENUOPTION_ERROR() {printf("Errorcode: %i\nTried to print a non existant menu option. Please contact the devs.", INVALID_MENU_OPTION); exit(INVALID_MENU_OPTION);}

#define LANG_PRINT_RANDOM_COLOR() (printf("%s", lang_color_name(generate_random_color())))

#define SUCCESS 0
#define LANGUAGE_ERROR -1
#define BUFFER_ERROR -2
#define INVALID_MENU_OPTION -3
#define INVALID_MENU_INPUT -4
#define NOT_A_COLOR -5

#define MAX_COLORCODE_LENGTH 8
#define AMOUNT_OF_COLORS 6
#define BLUE 0
#define RED 1
#define YELLOW 2
#define GREEN 3
#define PURPLE 4
#define BROWN 5
#define ORANGE 6
#define CYAN 7

#define MAX_NAME_LENGTH 13

#define MENU_OPTION_PLAY 1
#define MENU_OPTION_HOWTOPLAY 2
#define MENU_OPTION_LANGUAGE 3
#define MENU_OPTION_STATS 4
#define MENU_OPTION_EXIT 5

int player1_colorcode[MAX_COLORCODE_LENGTH];
int player2_colorcode[MAX_COLORCODE_LENGTH];
int player_guess[MAX_COLORCODE_LENGTH];
char *player1_name[MAX_NAME_LENGTH];
char *player2_name[MAX_NAME_LENGTH];
int player1_attempts;
int player2_attempts;


int colorcode_length;

int check_colorcode_and_print_correct_pins(int *colorcode, int *guess);
int generate_random_color();
int flush_buff (void);
int player_input_menu(int amount_of_menu_options);
void mainmenu();
void language_menu();

#endif
