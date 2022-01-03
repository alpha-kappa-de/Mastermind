#ifndef MASTERMIND_LANGUAGE_H_INCLUDED
#define MASTERMIND_LANGUAGE_H_INCLUDED

#include <stdio.h>
#include <string.h>

#define LANGUAGE_GERMAN 0
#define LANGUAGE_ENGLISH 1
#define LANGUAGE_FRENCH 2

int gamelanguage;

char *lang_color_name(int color);
void lang_print_you_typed(int *typed_code);
void lang_print_correct_pins();
void lang_print_correct_colors();
void lang_print_type_your_guess();
void lang_print_colorcode_wrong_format_message();
char *lang_menu_options(int menu_option);
void lang_print_you_typed_menu_option(int menu_option);
char *lang_wrong_format();
char *lang_please_input_menu_option();
char *lang_goodbye();

#endif