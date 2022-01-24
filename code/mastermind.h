#ifndef MASTERMIND_H_INCLUDED
#define MASTERMIND_H_INCLUDED

/* included libraries */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "mastermind_language.h"
#include "mastermind_gui.h"

/* Macros */
#define EXIT_PROGRAM_SUCCESSFUL() {printf("\n%s", lang_goodbye()); exit(SUCCESS);}
#define INVALID_LANGUAGE_ERROR() {printf("Errorcode: %i\nInvalid language set. Please contact the devs.", LANGUAGE_ERROR); exit(LANGUAGE_ERROR);}
#define INVALID_MENUOPTION_ERROR() {printf("Errorcode: %i\nTried to print a non existant menu option. Please contact the devs.", INVALID_MENU_OPTION); exit(INVALID_MENU_OPTION);}
#define INVALID_PRETTYMODE_ERROR() {printf("Errorcode: %i\nSomething is wrong with the pretty mode settings. Please contact the devs.", PRETTYMODE_ERROR_CODE); exit(PRETTYMODE_ERROR_CODE);}
#define SPACE_ALLOCATION_ERROR() {printf("Errorcode: %i\nSpace allocation didn't work. Please check your computer or if this doesn't happen for the first time, contact the devs.", SPACE_ALLOCATION_ERROR_CODE); exit(SPACE_ALLOCATION_ERROR_CODE);}
#define INVALID_PLAYER_AMOUNT_ERROR() {printf("Errorcode: %i\nTried to print a non existant menu option. Please contact the devs.", INVALID_PLAYER_AMOUNT); exit(INVALID_PLAYER_AMOUNT);}
#define CORRUPT_SAVE_FILE_ERROR() {printf("Errorcode: %i\nSomething is wrong with the savefile. Delete the savefile and try again or if this doesn't happen for the first time, contact the devs.", CORRUPT_SAVE_FILE_ERROR_CODE); exit(CORRUPT_SAVE_FILE_ERROR_CODE);}
#define WRONG_PLAYER_TO_SAVE_ERROR() {printf("Errorcode: %i\nInternal error in code. Please contact the devs.", WRONG_PLAYER_TO_SAVE_ERROR_CODE); exit(WRONG_PLAYER_TO_SAVE_ERROR_CODE);}
#define DELETE_TEMP_SAVE_FILE_ERROR() {printf("Errorcode: %i\nDeleting temp savefile didn't work. Please contact the devs.", DELETE_TEMP_SAVE_FILE_ERROR_CODE); exit(DELETE_TEMP_SAVE_FILE_ERROR_CODE);}

/* Boolean constants */
#define TRUE 1
#define FALSE 0

/* Errorcode constants */
#define SUCCESS 0
#define LANGUAGE_ERROR -1
#define BUFFER_ERROR -2
#define INVALID_MENU_OPTION -3
#define INVALID_MENU_INPUT -4
#define NOT_A_COLOR -5
#define PRETTYMODE_ERROR_CODE -6
#define INVALID_COLORCODE_INPUT -7
#define SPACE_ALLOCATION_ERROR_CODE -8
#define NAME_ERROR -9
#define INVALID_PLAYER_AMOUNT -10
#define CORRUPT_SAVE_FILE_ERROR_CODE -11
#define WRONG_PLAYER_TO_SAVE_ERROR_CODE -12
#define DELETE_TEMP_SAVE_FILE_ERROR_CODE -13

/* Mastermind constants */
#define MASTERMIND_COLORCODE_LENGTH 4
#define AMOUNT_OF_COLORS_IN_MASTERMIND 6

/* Super Mastermind constants */
#define SUPER_MASTERMIND_COLORCODE_LENGTH 5
#define AMOUNT_OF_COLORS_IN_SUPER_MASTERMIND 8

/* Colors constants */
#define AMOUNT_OF_COLORS 8
#define BLUE 0
#define RED 1
#define YELLOW 2
#define GREEN 3
#define PURPLE 4
#define ORANGE 5
#define BROWN 6
#define CYAN 7

/* Misc. constants */
#define MAX_COLOR_INPUT_LENGTH 100
#define MAX_NAME_LENGTH 21
#define MAX_ATTEMPTS_TO_GUESS_CODE 12
#define SAVEFILE_SCORE_LINE_LENGTH 50
#define SAVEFILE_SETTINGS_ONLY -1
#define GENERATE_NEW_SAVEFILE -2
#define ONE_HOUR_IN_SECONDS 3600
#define PLAYER_NOT_IN_SAVEFILE -1

/* variables for gamedata */
int player1_colorcode[SUPER_MASTERMIND_COLORCODE_LENGTH];
int player2_colorcode[SUPER_MASTERMIND_COLORCODE_LENGTH];
int player_guess[SUPER_MASTERMIND_COLORCODE_LENGTH];
char player1_name[MAX_NAME_LENGTH];
char player2_name[MAX_NAME_LENGTH];
int player1_attempts;
int player2_attempts;
int player1_won;
int player2_won;
int player1_game_over;
int player2_game_over;
int colorcode_length;
int pretty_mode;
int is_singleplayer;
int is_super_mastermind;
time_t game_starttime;

/* variables for savefile */
char savefile_score_line_name[MAX_NAME_LENGTH];
int savefile_score_line_total_time_played;
int savefile_score_line_total_played_games;
int savefile_score_line_lost_games;
int savefile_score_line_won_games;
int savefile_score_line_total_attempts;
int savefile_line_of_player_1;
int savefile_line_of_player_2;

/* function prototypes */
int check_colorcode_and_print_correct_pins(int *colorcode, int *guess);
int generate_random_color();
int flush_buff();
int player_input_menu(int amount_of_menu_options);
void mainmenu();
void statistics_menu();
void settings_menu();
void language_menu();
void change_gui_mode();
int player_colorcode_input(int *codearray);
void generate_random_colorcode(int *colorcode);
int get_player_name(char *player_x_name);
void start_game();
int calc_seconds_played();
void read_game_savefile(int line_to_scan);
void save_game_savefile();
void copy_temp_savefile_to_original_and_delete_temp();
int name_length();
void clear_savefile_variables();
void get_savefile_line_of_player(int player_number);
int compare_player_names(char *name1, char *name2);

#endif
