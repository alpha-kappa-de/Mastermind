#ifndef MASTERMIND_LANGUAGE_H_INCLUDED
#define MASTERMIND_LANGUAGE_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "mastermind.h"
#include "mastermind_gui.h"

#define AMOUNT_OF_LANGUAGES 3
#define LANGUAGE_GERMAN 0
#define LANGUAGE_ENGLISH 1
#define LANGUAGE_FRENCH 2


int gamelanguage;

char *lang_color_name(int color);
void lang_print_you_typed(int *typed_code);
char *lang_correct_pins();
char *lang_correct_colors();
char *lang_type_colorcode();
void lang_print_colorcode_wrong_format_message();
char *lang_menu_options(int menu_option);
char *lang_wrong_format();
char *lang_please_input_menu_option();
char *lang_goodbye();
char *lang_language_name(int language);
char *lang_language_changed_to();
void lang_print_how_to_play();
int lang_color_name_to_number(char *color_string);
char *lang_change_guimode_message();
char *lang_compatible_mode_whitespaced();
char *lang_pretty_mode_whitespaced();
char *lang_compatible_mode();
char *lang_pretty_mode();
char *lang_always_safe_to_choose_comp_mode();
char *lang_current_setting();
char *lang_correctly_guessed_code();
void lang_print_please_input_name();
char *lang_singleplayer_multiplayer(int amount_of_players);
char *lang_player();
char *lang_game_over();
char *lang_right_colorcode_was();
char *lang_what_a_pity();
char *lang_its_your_try_nr();
char *lang_its_your_last_try();

#endif
