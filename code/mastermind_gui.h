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

#define DELETE_LAST_LINES_GAMELOGO 22
#define DELETE_LAST_LINES_MENUOPTION 8
#define DELETE_LAST_LINES_GUI_MENU 23
#define DELETE_LAST_LINES_ONE_LINE 1
#define DELETE_LAST_LINES_HOW_TO_PLAY 20
#define DELETE_LAST_LINES_STATS -1
#define DELETE_LAST_LINES_GAME 100



void gui_print_mastermind_logo();
void gui_print_options_menu();
void gui_print_settings_menu();
void gui_print_gamemode_menu();
void gui_print_single_or_multiplayer_menu();
void gui_print_back_only();
void gui_print_language_menu();
void gui_print_GUI_mode_menu();
char *gui_write_in_random_color();
void gui_print_stats();
void gui_print_stat_lines_right_justified(int value);
void gui_print_stat_line_winrate_right_justified();
void delete_last_lines_and_go_there(int amount_of_lines);
void wait(int seconds);

#endif
