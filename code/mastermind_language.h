#ifndef MASTERMIND_LANGUAGE_H_INCLUDED
#define MASTERMIND_LANGUAGE_H_INCLUDED

#include <stdio.h>
#include <string.h>

#define LANGUAGE_GERMAN 0
#define LANGUAGE_ENGLISH 1
#define LANGUAGE_FRENCH 2

int gamelanguage;

char *lang_color_name(int color);
char *lang_you_typed();
char *lang_correct_pins();
char *lang_correct_colors();
char *lang_type_your_guess();

#endif