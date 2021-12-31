#ifndef MASTERMIND_H_INCLUDED
#define MASTERMIND_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "mastermind_language.h"

#define BLUE 0
#define RED 1
#define YELLOW 2
#define GREEN 3
#define PURPLE 4
#define BROWN 5

int player1_colorcode[6];
int player2_colorcode[6];
int player_guess[6];

int colorcode_length;

int check_colorcode_and_print_correct_pins(int *colorcode, int *guess);

#endif