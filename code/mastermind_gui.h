#ifndef MASTERMIND_GUI_H_INCLUDED
#define MASTERMIND_GUI_H_INCLUDED

#include <string.h>
#include "mastermind.h"
#include "mastermind_language.h"

#define COLORMODE_BLUE "\033[38;5;4m"
#define COLORMODE_RED "\033[38;5;1m"
#define COLORMODE_YELLOW "\033[38;5;226m"
#define COLORMODE_GREEN "\033[38;5;10m"
#define COLORMODE_PURPLE "\033[38;5;5m"
#define COLORMODE_BROWN "\033[38;5;94m"
#define COLORMODE_ORANGE "\033[38;5;166m"
#define COLORMODE_CYAN "\033[38;5;14m"
#define COLORMODE_RESET "\033[0m"

#define MENU_OPTION_PLAY 1
#define MENU_OPTION_HOWTOPLAY 2
#define MENU_OPTION_STATS 3
#define MENU_OPTION_SETTINGS 4
#define MENU_OPTION_EXIT 5
#define MENU_OPTION_LANGUAGE 6
#define MENU_OPTION_GUIMODE 7
#define MENU_OPTION_BACK 8


void gui_print_mastermind_logo();
void gui_print_options_menu();
void gui_print_settings_menu();
void gui_print_gamemode_menu();
void gui_print_single_or_multiplayer_menu();
void gui_print_language_menu();
void gui_print_GUI_mode_menu();
char *gui_write_in_random_color();

#endif
