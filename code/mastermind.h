#ifndef MASTERMIND_H_INCLUDED
#define MASTERMIND_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mastermind_language.h"

#define INVALID_LANGUAGE_ERROR() {printf("Invalid language set. Please restart the game."); exit(LANGUAGE_ERROR);}

#define LANG_PRINT_RANDOM_COLOR() (printf("%s", lang_color_name(generate_random_color())))

#define LANGUAGE_ERROR -1

#define AMOUNT_OF_COLORS 6
#define BLUE 0
#define RED 1
#define YELLOW 2
#define GREEN 3
#define PURPLE 4
#define BROWN 5

int player1_colorcode[AMOUNT_OF_COLORS];
int player2_colorcode[AMOUNT_OF_COLORS];
int player_guess[AMOUNT_OF_COLORS];

int colorcode_length;

int check_colorcode_and_print_correct_pins(int *colorcode, int *guess);
int generate_random_color();

#endif
