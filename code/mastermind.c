#include "mastermind.h"
#include "mastermind_language.h"
#include "mastermind_gui.h"

int check_colorcode_and_print_correct_pins(int *colorcode, int *guess)
{
    int i;
    int j;
    int counter_correct_pins;
    int counter_correct_color;

    char *colorcode_pin_array;
    char *start_of_colorcode_pin_array;
    char *guess_pin_array;
    char *start_of_guess_pin_array;

    /* initialize counters and allocate space for pin assignment */
    counter_correct_pins = 0;
    counter_correct_color = 0;

    colorcode_pin_array = calloc(colorcode_length, sizeof(char));
    if (colorcode_pin_array == NULL) {
        SPACE_ALLOCATION_ERROR();
    }
    guess_pin_array = calloc(colorcode_length, sizeof(char));
    if (guess_pin_array == NULL) {
        free(colorcode_pin_array);
        SPACE_ALLOCATION_ERROR();
    }

    start_of_colorcode_pin_array = colorcode_pin_array;
    start_of_guess_pin_array = guess_pin_array;

    /* get amount of correct pins */
    for (i = 0; i < colorcode_length; i++, colorcode_pin_array++, guess_pin_array++) {
        if (colorcode[i] == guess[i]) {
            *colorcode_pin_array = 'B';
            *guess_pin_array = 'B';
            counter_correct_pins++;
        }
    }

    /* if all colors are correct, doesn't need to check rest */
    if (counter_correct_pins == colorcode_length) {
        free(start_of_colorcode_pin_array);
        free(start_of_guess_pin_array);
        return counter_correct_pins;
    }


    /* get amount of correct colors */
    colorcode_pin_array = start_of_colorcode_pin_array;
    guess_pin_array = start_of_guess_pin_array;
    for (i = 0; i < colorcode_length; i++) {
        if (*(guess_pin_array + i) != 'B') {
            for (j = 0; j < colorcode_length; j++) {
                if (colorcode[i] == guess[j] && *(guess_pin_array + j) != 'B' && *(guess_pin_array + j) != 'W') {
                    *(colorcode_pin_array + i) = 'W';
                    *(guess_pin_array + j) = 'W';
                    counter_correct_color++;
                }
            }
        }
    }

    /* print amount of correct pins and correct colors */
    printf("\t\t%s: %i\t%s: %i\n", lang_correct_pins(), counter_correct_pins, lang_correct_colors(), counter_correct_color);

    /* free up space and return amount of correct pins */
    free(start_of_colorcode_pin_array);
    free(start_of_guess_pin_array);
    return counter_correct_pins;
}

int generate_random_color()
{
    if (is_super_mastermind == TRUE) {
        return ((rand() + rand()) % (AMOUNT_OF_COLORS_IN_SUPER_MASTERMIND));
    } else return ((rand() + rand()) % (AMOUNT_OF_COLORS_IN_MASTERMIND));
}

int flush_buff()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF ) {}
    return c != EOF ;
}

int player_input_menu(int amount_of_menu_options)
{
    int input, status, c;

    c = '\0';
    status = scanf("%i", &input);

    if (status == EOF)
        return BUFFER_ERROR;
    if (status == 0 || input <= 0 || input > amount_of_menu_options || (c = getchar()) != '\n') {
        if (c == EOF || !flush_buff()) {
            return BUFFER_ERROR;
        }
        return INVALID_MENU_INPUT;
    }
    return input;
}

void mainmenu()
{
    int i;
    gui_print_options_menu();
    i = player_input_menu(5);

    while (i == INVALID_MENU_INPUT || i == BUFFER_ERROR) {
        delete_last_lines_and_go_there(DELETE_LAST_LINES_ONE_LINE);
        printf("%s %s: ", lang_wrong_format(), lang_please_input_menu_option());
        i = player_input_menu(5);
    }

    switch (i)
    {
        case 1:
            delete_last_lines_and_go_there(DELETE_LAST_LINES_MENUOPTION);
            start_game();
            break;
        case 2:
            delete_last_lines_and_go_there(DELETE_LAST_LINES_MENUOPTION);
            how_to_play_menu();
            break;
        case 3:
            delete_last_lines_and_go_there(DELETE_LAST_LINES_MENUOPTION);
            statistics_menu();
            break;
        case 4:
            delete_last_lines_and_go_there(DELETE_LAST_LINES_MENUOPTION);
            settings_menu();
            break;
        case 5:
            EXIT_PROGRAM_SUCCESSFUL();
        default:
            break;
        }
}

void how_to_play_menu()
{
    int i;
    gui_print_back_only();
    lang_print_how_to_play();

    printf("%s: ", lang_please_type_one_to_go_back());
    i = player_input_menu(1);
    while (i == INVALID_MENU_INPUT || i == BUFFER_ERROR) {
        delete_last_lines_and_go_there(DELETE_LAST_LINES_ONE_LINE);
        printf("%s %s: ", lang_wrong_format(), lang_please_type_one_to_go_back());
        i = player_input_menu(1);
    }
    delete_last_lines_and_go_there(DELETE_LAST_LINES_HOW_TO_PLAY);
}

void statistics_menu()
{
    int i;
    gui_print_back_only();
    gui_print_stats();

    printf("%s: ", lang_please_type_one_to_go_back());
    i = player_input_menu(1);
    while (i == INVALID_MENU_INPUT || i == BUFFER_ERROR) {
        delete_last_lines_and_go_there(DELETE_LAST_LINES_ONE_LINE);
        printf("%s %s: ", lang_wrong_format(), lang_please_type_one_to_go_back());
        i = player_input_menu(1);
    }
    delete_last_lines_and_go_there(DELETE_LAST_LINES_STATS);
}

void settings_menu()
{
    int i;
    gui_print_settings_menu();
    i = player_input_menu(3);

    while (i == INVALID_MENU_INPUT || i == BUFFER_ERROR) {
        delete_last_lines_and_go_there(DELETE_LAST_LINES_ONE_LINE);
        printf("%s %s: ", lang_wrong_format(), lang_please_input_menu_option());
        i = player_input_menu(3);
    }

    switch (i)
    {
        case 1:
            delete_last_lines_and_go_there(DELETE_LAST_LINES_MENUOPTION);
            language_menu();
            break;
        case 2:
            delete_last_lines_and_go_there(DELETE_LAST_LINES_MENUOPTION);
            change_gui_mode();
            break;
        case 3:
            break;
        default:
            INVALID_MENUOPTION_ERROR();
        }
    delete_last_lines_and_go_there(DELETE_LAST_LINES_MENUOPTION);
}

void language_menu()
{
    int i;
    gui_print_language_menu();
    i = player_input_menu(AMOUNT_OF_LANGUAGES);

    while (i == INVALID_MENU_INPUT || i == BUFFER_ERROR) {
        delete_last_lines_and_go_there(DELETE_LAST_LINES_ONE_LINE);
        printf("%s %s: ", lang_wrong_format(), lang_please_input_menu_option());
        i = player_input_menu(AMOUNT_OF_LANGUAGES);
    }

    switch (i - 1) {
        case LANGUAGE_GERMAN:
            gamelanguage = LANGUAGE_GERMAN;
            break;
        case LANGUAGE_ENGLISH:
            gamelanguage = LANGUAGE_ENGLISH;
            break;
        case LANGUAGE_FRENCH:
            gamelanguage = LANGUAGE_FRENCH;
            break;
        default:
            INVALID_LANGUAGE_ERROR();
            break;
    }
    save_game_savefile(SAVEFILE_SETTINGS_ONLY);
    delete_last_lines_and_go_there(DELETE_LAST_LINES_MENUOPTION);
}

void change_gui_mode()
{
    int i;
    gui_print_GUI_mode_menu();
    i = player_input_menu(2);

    while (i == INVALID_MENU_INPUT || i == BUFFER_ERROR) {
        delete_last_lines_and_go_there(DELETE_LAST_LINES_ONE_LINE);
        printf("%s %s: ", lang_wrong_format(), lang_please_input_menu_option());
        i = player_input_menu(2);
    }

    if (i == 1) {
        pretty_mode = FALSE;
    } else if (i == 2) {
        if (pretty_mode == FALSE) {
            pretty_mode = TRUE;
            save_game_savefile(SAVEFILE_SETTINGS_ONLY);
            PLEASE_RESTART_THE_GAME_TO_APPLY_CHANGES();
        } else {
            pretty_mode = TRUE;
            save_game_savefile(SAVEFILE_SETTINGS_ONLY);
        }
    }
    delete_last_lines_and_go_there(DELETE_LAST_LINES_GUI_MENU);
}

int player_colorcode_input(int *codearray)
{
	int i, status, colorcode[SUPER_MASTERMIND_COLORCODE_LENGTH];
    char c, input[MAX_COLOR_INPUT_LENGTH], *currently_checked_color;
    const char delim[2] = " ";

    printf("%s", lang_type_colorcode());

    /* read player input and turn every letter into a lowercase letter. finalize string with \0 */
    status = scanf("%c", &c);
    if (status == EOF) {
        return BUFFER_ERROR;
    }else if (c == '\n') {
        return NOT_A_COLOR;
    }
    for (i = 0; i < MAX_COLOR_INPUT_LENGTH && c != '\n'; i++) {
        input[i] = tolower(c);
        if (i == (MAX_COLOR_INPUT_LENGTH - 1) && (c = getchar()) != '\n' ) {
            if (c == EOF || flush_buff()) {
                return BUFFER_ERROR;
            }
        }
        c = getchar();
    }
    input[i] = '\0';

    /* check first color and turn into the number, the color corresponds to */
    currently_checked_color = strtok(input, delim);
    if (lang_color_name_to_number(currently_checked_color) == NOT_A_COLOR) {
        return INVALID_COLORCODE_INPUT;
    }
    colorcode[0] = lang_color_name_to_number(currently_checked_color);


    /* check the other colors and turn into the number, the colors correspond to */
    for (i = 1; i < colorcode_length; i++) {
        currently_checked_color = strtok(NULL, delim);
        if (currently_checked_color == NULL || lang_color_name_to_number(currently_checked_color) == NOT_A_COLOR) {
            return INVALID_COLORCODE_INPUT;
        }
        colorcode[i] = lang_color_name_to_number(currently_checked_color);
    }

    /* check, if player did input more colors than needed */
    currently_checked_color = strtok(NULL, delim);
        if (currently_checked_color != NULL) {
            return INVALID_COLORCODE_INPUT;
        }

    /* passing the generated colorcode into the array, given to this function  */
    for (i = 0; i < colorcode_length; i++) {
        codearray[i] = colorcode[i];
    }

	return SUCCESS;
}

void generate_random_colorcode(int *colorcode)
{

    int i;
	for (i = 0; i < colorcode_length; i++) {
		colorcode[i] = generate_random_color();
	}
}

int get_player_name(char *player_x_name)
{
    int i, status;
	char c, player_name[MAX_NAME_LENGTH];

    /* read player input and check, if it's valid. finalize string with \0 */
    status = scanf("%c", &c);
    if (status == EOF) {
        return BUFFER_ERROR;
    } else if (c == '\n') {
        return NAME_ERROR;
    }
    for (i = 0; i < MAX_NAME_LENGTH && c != '\n'; i++) {
        player_name[i] = c;
        if (i == (MAX_NAME_LENGTH - 1) && (c = getchar()) != '\n' ) {
            if (c == EOF || flush_buff()) {
                return BUFFER_ERROR;
            }
        }
        c = getchar();
    }
    if (i == MAX_NAME_LENGTH) {
        player_name[i - 1] = '\0';
    } else player_name[i] = '\0';

    /* paste player input to the passed player_x_name */
    for (i = 0; player_name[i] != '\0'; i++) {
        player_x_name[i] = player_name[i];
    }
    player_name[i] = '\0';

	return SUCCESS;
}

void ask_player_for_name(int player_number)
{
    if (player_number != 1 && player_number != 2) {
        INVALID_PLAYER_NUMBER_ERROR();
    }
    
    printf("%s %i ", lang_player(), player_number);
    lang_print_please_input_name();
    if (player_number == 1) {
        while (get_player_name(player1_name) != SUCCESS) {
            delete_last_lines_and_go_there(DELETE_LAST_LINES_ONE_LINE);
            printf("%s %i ", lang_player(), player_number);
            lang_print_please_input_name();
        }
    } else if (player_number == 2) {
        while (get_player_name(player2_name) != SUCCESS) {
            delete_last_lines_and_go_there(DELETE_LAST_LINES_ONE_LINE);
            printf("%s %i ", lang_player(), player_number);
            lang_print_please_input_name();
        }
    }

    get_savefile_line_of_player(player_number);
    delete_last_lines_and_go_there(DELETE_LAST_LINES_ONE_LINE);
}

void ask_player_for_colorcode(int player_number)
{
    if (player_number != 1 && player_number != 2) {
        INVALID_PLAYER_NUMBER_ERROR();
    }
    
    if (player_number == 1) {
        printf("%s. ", player1_name);
        while (player_colorcode_input(player1_colorcode) != SUCCESS) {
            delete_last_lines_and_go_there(DELETE_LAST_LINES_ONE_LINE);
            lang_print_colorcode_wrong_format_message();
        }
    } else if (player_number == 2) {
        printf("%s. ", player2_name);
        while (player_colorcode_input(player2_colorcode) != SUCCESS) {
            delete_last_lines_and_go_there(DELETE_LAST_LINES_ONE_LINE);
            lang_print_colorcode_wrong_format_message();
        }
    }
    delete_last_lines_and_go_there(DELETE_LAST_LINES_ONE_LINE);
}

void player_turn(int player_number)
{
    int i;
    if (player_number != 1 && player_number != 2) {
        INVALID_PLAYER_NUMBER_ERROR();
    }

    if (player_number == 1) {
        if (player1_game_over == FALSE) {
        /* let player guess */
        if (player1_attempts == (MAX_ATTEMPTS_TO_GUESS_CODE - 1)) {
            if (pretty_mode == TRUE) {
                printf("%s%s, %s. %s", COLORMODE_RED, lang_its_your_last_try(), player1_name, COLORMODE_RESET);
            } else printf("%s, %s. ", lang_its_your_last_try(), player1_name);
        } else printf("%s%i, %s. ", lang_its_your_try_nr(), (player1_attempts + 1) , player1_name);

        while (player_colorcode_input(player_guess) != SUCCESS) {
            delete_last_lines_and_go_there(DELETE_LAST_LINES_ONE_LINE);
            lang_print_colorcode_wrong_format_message();
        }
        delete_last_lines_and_go_there(DELETE_LAST_LINES_ONE_LINE);
        lang_print_name_you_typed_guess(player_number);
        /* if guessed right */
        if (check_colorcode_and_print_correct_pins(player2_colorcode, player_guess) == colorcode_length) {
            player1_attempts++;

            if (pretty_mode == TRUE) {
                printf("\n");
                gui_print_string_colorful(player1_name);
                printf(", ");
                gui_print_string_colorful(lang_correctly_guessed_code());
                printf("%i\n", player1_attempts);
            } else {
                printf("\n%s, %s %i\n", player1_name, lang_correctly_guessed_code(), player1_attempts);
            }

            player1_game_over = TRUE;
            player1_won = TRUE;
            save_game_savefile(player_number);
        /* if guessed wrong, increment attempts and check if max. attempts are reached */
        } else {
            player1_attempts++;
            if (player1_attempts == MAX_ATTEMPTS_TO_GUESS_CODE) {
                if (pretty_mode == TRUE) {
                        printf("%s%s %s... %s\n%s:%s ", COLORMODE_RED, lang_what_a_pity(), player1_name, lang_game_over(), lang_right_colorcode_was(), COLORMODE_RESET);
                    } else {
                        printf("%s %s... %s\n%s: ", lang_what_a_pity(), player1_name, lang_game_over(), lang_right_colorcode_was());
                    }
                
                for (i = 0; i < colorcode_length; i++) {
                    printf("%s ", lang_color_name(player2_colorcode[i]));
                }
                printf("\n");
                
                player1_game_over = TRUE;
                player1_won = FALSE;
                save_game_savefile(player_number);
            }
        }
    }
    } else if (player_number == 2) {
        if (player2_game_over == FALSE) {
            /* let player guess */
            if (player2_attempts == (MAX_ATTEMPTS_TO_GUESS_CODE - 1)) {
                if (pretty_mode == TRUE) {
                    printf("%s%s, %s. %s", COLORMODE_RED, lang_its_your_last_try(), player2_name, COLORMODE_RESET);
                } else printf("%s, %s. ", lang_its_your_last_try(), player2_name);
            } else printf("%s%i, %s. ", lang_its_your_try_nr(), (player2_attempts + 1) , player2_name);

            while (player_colorcode_input(player_guess) != SUCCESS) {
                delete_last_lines_and_go_there(DELETE_LAST_LINES_ONE_LINE);
                lang_print_colorcode_wrong_format_message();
            }
            delete_last_lines_and_go_there(DELETE_LAST_LINES_ONE_LINE);
            lang_print_name_you_typed_guess(player_number);
            /* if guessed right */
            if (check_colorcode_and_print_correct_pins(player1_colorcode, player_guess) == colorcode_length) {
                player2_attempts++;

                if (pretty_mode == TRUE) {
                    printf("\n");
                    gui_print_string_colorful(player2_name);
                    printf(", ");
                    gui_print_string_colorful(lang_correctly_guessed_code());
                    printf("%i\n", player2_attempts);
                } else {
                    printf("\n%s, %s %i\n", player2_name, lang_correctly_guessed_code(), player2_attempts);
            }

                player2_game_over = TRUE;
                player2_won = TRUE;
                save_game_savefile(player_number);
            /* if guessed wrong, increment attempts and check, if max. attempts are reached */
            } else {
                player2_attempts++;
                if (player2_attempts == MAX_ATTEMPTS_TO_GUESS_CODE) {
                    if (pretty_mode == TRUE) {
                        printf("%s%s %s... %s\n%s:%s ", COLORMODE_RED, lang_what_a_pity(), player2_name, lang_game_over(), lang_right_colorcode_was(), COLORMODE_RESET);
                    } else {
                        printf("%s %s... %s\n%s: ", lang_what_a_pity(), player2_name, lang_game_over(), lang_right_colorcode_was());
                    }
            
                    for (i = 0; i < colorcode_length; i++) {
                        printf("%s ", lang_color_name(player1_colorcode[i]));
                    }
                    printf("\n");

                    player2_game_over = TRUE;
                    player2_won = FALSE;
                    save_game_savefile(player_number);
                }
            }
        }
    }
}

void start_game()
{
    int i;

    /* gamemode selection */
    gui_print_gamemode_menu();
    i = player_input_menu(3);

    while (i == INVALID_MENU_INPUT || i == BUFFER_ERROR) {
        delete_last_lines_and_go_there(DELETE_LAST_LINES_ONE_LINE);
        printf("%s %s: ", lang_wrong_format(), lang_please_input_menu_option());
        i = player_input_menu(3);
    }

    if (i == 1) {
        is_super_mastermind = FALSE;
        colorcode_length = MASTERMIND_COLORCODE_LENGTH;
    } else if (i == 2) {
        is_super_mastermind = TRUE;
        colorcode_length = SUPER_MASTERMIND_COLORCODE_LENGTH;
    } else {
        /* deletes last lines and returns, so it can go back to main menu */
        delete_last_lines_and_go_there(DELETE_LAST_LINES_MENUOPTION);
        return;
    }

    delete_last_lines_and_go_there(DELETE_LAST_LINES_MENUOPTION);

    /* single or multiplayer selection */
    gui_print_single_or_multiplayer_menu();
    i = player_input_menu(3);

    while (i == INVALID_MENU_INPUT || i == BUFFER_ERROR) {
        delete_last_lines_and_go_there(DELETE_LAST_LINES_ONE_LINE);
        printf("%s %s: ", lang_wrong_format(), lang_please_input_menu_option());
        i = player_input_menu(3);
    }

    if (i == 1) {
        is_singleplayer = TRUE;
    } else if (i == 2) {
        is_singleplayer = FALSE;
    } else {
        /* deletes last lines and returns, so it can go back to main menu */
	    delete_last_lines_and_go_there(DELETE_LAST_LINES_MENUOPTION);
        return;
    }

    delete_last_lines_and_go_there(DELETE_LAST_LINES_MENUOPTION);

    /* initialize players values */
    player1_attempts = 0;
    player2_attempts = 0;
    player1_game_over = FALSE;
    player2_game_over = FALSE;
    savefile_line_of_player_1 = PLAYER_NOT_IN_SAVEFILE;
    savefile_line_of_player_2 = PLAYER_NOT_IN_SAVEFILE;

    /* let player1 input his name */
    ask_player_for_name(1);

    /* If Multiplayer ask for name of player2 and ask for both players colorcodes */
    if (is_singleplayer == FALSE) {
        ask_player_for_name(2);
        ask_player_for_colorcode(1);
        ask_player_for_colorcode(2);
    } else /* if singleplayer, don't ask for player2 name and generate random colorcode */ {
        generate_random_colorcode(player2_colorcode);
        player2_game_over = TRUE;
    }

    /* actual start of the game. lets player guess the colorcode and breaks if colorcode is guessed or took to many attempts */
    game_starttime = time(NULL);

    while (TRUE) {
        /* if player1_game_over is FALSE, let player1 do his turn */
        player_turn(1);
        /* if player2_game_over is FALSE, let player2 do his turn */
        player_turn(2);
        /* when both players are done */
        if (player1_game_over == TRUE && player2_game_over == TRUE) {
            for (i = 0; i < MAX_NAME_LENGTH; i++) {
                *(player1_name + i) = '\0';
                *(player2_name + i) = '\0';
            }
            player1_attempts = 0;
            player2_attempts = 0;
            wait_seconds(3);
            break;
        }
    }
    delete_last_lines_and_go_there(DELETE_LAST_LINES_GAME);
}

int calc_seconds_played()
{
        return (int)(time(NULL) - game_starttime);
}

void read_game_savefile(int line_to_scan)
{
    FILE *savefile;
    int i, j;
    char pretty_mode_save[3], gamelanguage_save[3], savefile_score_line[SAVEFILE_SCORE_LINE_LENGTH], *token;
    const char delim[2] = ";";

    savefile = fopen("savegame.mstrmnd_sav", "r");

    /* if there is no savefile, it generates a new savefile with the standard gamesettings */
    if (savefile == NULL) {
        save_game_savefile(GENERATE_NEW_SAVEFILE);
        fclose(savefile);
        return;
    }

    clear_savefile_variables();

    /* get gamesettings from savefile */
    if (fgets(pretty_mode_save, 3, (FILE*)savefile) == NULL) {
        fclose(savefile);
        CORRUPT_SAVE_FILE_ERROR();
    }
    if (fgets(gamelanguage_save, 3, (FILE*)savefile) == NULL) {
        fclose(savefile);
        CORRUPT_SAVE_FILE_ERROR();
    }

    /* check pretty_mode setting from savefile and apply if it's ok */
    if (atoi(pretty_mode_save) != TRUE && atoi(pretty_mode_save) != FALSE) {
        fclose(savefile);
        CORRUPT_SAVE_FILE_ERROR();
    } else pretty_mode = atoi(pretty_mode_save);

    /* check gamelanguage setting from savefile and apply if it's ok */
    if (atoi(gamelanguage_save) < 0 || atoi(gamelanguage_save) >= AMOUNT_OF_LANGUAGES) {
        fclose(savefile);
        CORRUPT_SAVE_FILE_ERROR();
    } else gamelanguage = atoi(gamelanguage_save);

    /* if function was called with SAVEFILE_SETTINGS_ONLY it quits now */
    if (line_to_scan == SAVEFILE_SETTINGS_ONLY) {
        fclose(savefile);
        return;
    }

    /* get line_to_scan from savefile (in the savefile, line 0 begins where the first score is saved (line 3 in file)) */
    for (i = 0; i < (line_to_scan + 1); i++) {
        for (j = 0; j < SAVEFILE_SCORE_LINE_LENGTH; j++) {
            savefile_score_line[j] = '\0';
        }
        if (fgets(savefile_score_line, SAVEFILE_SCORE_LINE_LENGTH, (FILE*)savefile) == NULL) {
            fclose(savefile);
            return;
        }
    }

    /* close savefile again */
    fclose(savefile);

    /* save scanned name to savefile_score_line_name */
    token = strtok(savefile_score_line, delim);
    if (token == NULL) {
        CORRUPT_SAVE_FILE_ERROR();
    }
    for (i = 0; token[i] != '\0'; i++) {
        savefile_score_line_name[i] = token[i];
    }
    savefile_score_line_name[i] = '\0';

    /* save total time played to savefile_score_line_total_time_played */
    token = strtok(NULL, delim);
    if (token == NULL) {
        CORRUPT_SAVE_FILE_ERROR();
    }
    savefile_score_line_total_time_played = atoi(token);

    /* save total played games to savefile_score_line_total_played_games */
    token = strtok(NULL, delim);
    if (token == NULL) {
        CORRUPT_SAVE_FILE_ERROR();
    }
    savefile_score_line_total_played_games = atoi(token);

    /* save lost games to savefile_score_line_lost_games */
    token = strtok(NULL, delim);
    if (token == NULL) {
        CORRUPT_SAVE_FILE_ERROR();
    }
    savefile_score_line_lost_games = atoi(token);

    /* save won games to savefile_score_line_won_games */
    token = strtok(NULL, delim);
    if (token == NULL) {
        CORRUPT_SAVE_FILE_ERROR();
    }
    savefile_score_line_won_games = atoi(token);

    /* save total attempts to savefile_score_line_total_attempts */
    token = strtok(NULL, delim);
    if (token == NULL) {
        CORRUPT_SAVE_FILE_ERROR();
    }
    savefile_score_line_total_attempts = atoi(token);
}

void save_game_savefile(int player_number)
{
    FILE *savefile, *savefile_temp;
    char savefile_score_line[SAVEFILE_SCORE_LINE_LENGTH], buf[3];
    int i, j;

    /* if player_number is GENERATE_NEW_SAVEFILE then it generates a new savefile and quits */
    if (player_number == GENERATE_NEW_SAVEFILE) {
        savefile = fopen("savegame.mstrmnd_sav", "w");
        gamelanguage = LANGUAGE_ENGLISH;
        pretty_mode = FALSE;
        fprintf(savefile, "%i\n%i\n", pretty_mode, gamelanguage);
        fclose(savefile);
        return;
    }

    /* if player_number is SAVEFILE_SETTINGS_ONLY then it only saves gamesettings */
    if (player_number == SAVEFILE_SETTINGS_ONLY) {
        savefile = fopen("savegame.mstrmnd_sav", "r");
        savefile_temp = fopen(".savegame.mstrmnd_sav.temp", "w");

        /* ignore old gamesettings, stored in savefile */
        fgets(buf, 3, (FILE*)savefile);
        fgets(buf, 3, (FILE*)savefile);

        /* write the new settings into the temp file */
        fprintf(savefile_temp, "%i\n%i\n", pretty_mode, gamelanguage);

        /* copy all lines from the savefile to the temp file. then copy everything back from the temp file to the original and delete the temp file */
        while (TRUE) {
            for (i = 0; i < SAVEFILE_SCORE_LINE_LENGTH; i++) {
                savefile_score_line[i] = '\0';
            }
            if (fgets(savefile_score_line, SAVEFILE_SCORE_LINE_LENGTH, (FILE*)savefile) == NULL) {
                fclose(savefile);
                fclose(savefile_temp);
                copy_temp_savefile_to_original_and_delete_temp();
                return;
            }
            fprintf(savefile_temp, "%s", savefile_score_line);
        }
    }

    /* if players are not in savefile, it just appends their score to the savefile. If they are, it replaces their lines with the new data */
    if (player_number == 1 && savefile_line_of_player_1 == PLAYER_NOT_IN_SAVEFILE) {
        savefile = fopen("savegame.mstrmnd_sav", "a");
            if (player1_won == TRUE ) {
                fprintf(savefile, "%s;%i;%i;%i;%i;%i\n", player1_name, calc_seconds_played(), 1, 0, 1,  player1_attempts);
            } else {
                fprintf(savefile, "%s;%i;%i;%i;%i;%i\n", player1_name, calc_seconds_played(), 1, 1, 0,  player1_attempts);
            }
            fclose(savefile);
            return;
    } else if (player_number == 2 && savefile_line_of_player_2 == PLAYER_NOT_IN_SAVEFILE) {
        savefile = fopen("savegame.mstrmnd_sav", "a");
            if (player2_won == TRUE ) {
                fprintf(savefile, "%s;%i;%i;%i;%i;%i\n", player2_name, calc_seconds_played(), 1, 0, 1,  player2_attempts);
            } else {
                fprintf(savefile, "%s;%i;%i;%i;%i;%i\n", player2_name, calc_seconds_played(), 1, 1, 0,  player2_attempts);
            }
            fclose(savefile);
            return;
    } else if (player_number == 1 && savefile_line_of_player_1 != PLAYER_NOT_IN_SAVEFILE) {
        savefile = fopen("savegame.mstrmnd_sav", "r");
        savefile_temp = fopen(".savegame.mstrmnd_sav.temp", "w");

        /* ignore old gamesettings, stored in savefile */
        fgets(buf, 3, (FILE*)savefile);
        fgets(buf, 3, (FILE*)savefile);

        /* write the new settings into the temp file */
        fprintf(savefile_temp, "%i\n%i\n", pretty_mode, gamelanguage);

        /* write all lines, which do not contain data of the current player, to the temp file */
        for (i = 0; i < savefile_line_of_player_1; i++) {
            for (j = 0; j < SAVEFILE_SCORE_LINE_LENGTH; j++) {
                savefile_score_line[j] = '\0';
            }
            fgets(savefile_score_line, SAVEFILE_SCORE_LINE_LENGTH, (FILE*)savefile);
            fprintf(savefile_temp, "%s", savefile_score_line);
        }

        /* get the line of the player in the savefile  */
        for (j = 0; j < SAVEFILE_SCORE_LINE_LENGTH; j++) {
                savefile_score_line[j] = '\0';
            }
        fgets(savefile_score_line, SAVEFILE_SCORE_LINE_LENGTH, (FILE*)savefile);

        /* now the new data for this player is written to the savefile temp */
        if (player1_won == TRUE) {
            fprintf(savefile_temp, "%s;%i;%i;%i;%i;%i\n", player1_name, (savefile_score_line_total_time_played + calc_seconds_played()), (savefile_score_line_total_played_games + 1), savefile_score_line_lost_games, (savefile_score_line_won_games + 1), (savefile_score_line_total_attempts + player1_attempts));
        } else {
            fprintf(savefile_temp, "%s;%i;%i;%i;%i;%i\n", player1_name, (savefile_score_line_total_time_played + calc_seconds_played()), (savefile_score_line_total_played_games + 1), (savefile_score_line_lost_games + 1), savefile_score_line_won_games, (savefile_score_line_total_attempts + player1_attempts));
        }

        /* write rest to the temp file, then write the hole temp file to the original file and delete the temp file */
        while (TRUE) {
            for (i = 0; i < SAVEFILE_SCORE_LINE_LENGTH; i++) {
                savefile_score_line[i] = '\0';
            }
            if (fgets(savefile_score_line, SAVEFILE_SCORE_LINE_LENGTH, (FILE*)savefile) == NULL) {
                fclose(savefile);
                fclose(savefile_temp);
                copy_temp_savefile_to_original_and_delete_temp();
                return;
            }
            fprintf(savefile_temp, "%s", savefile_score_line);
        }
    } else if (player_number == 2 && savefile_line_of_player_2 != PLAYER_NOT_IN_SAVEFILE) {
        savefile = fopen("savegame.mstrmnd_sav", "r");
        savefile_temp = fopen(".savegame.mstrmnd_sav.temp", "w");

        /* ignore old gamesettings, stored in savefile */
        fgets(buf, 3, (FILE*)savefile);
        fgets(buf, 3, (FILE*)savefile);

        /* write the new settings into the temp file */
        fprintf(savefile_temp, "%i\n%i\n", pretty_mode, gamelanguage);

        /* write all lines, which do not contain data of the current player, to the temp file */
        for (i = 0; i < savefile_line_of_player_2; i++) {
            for (j = 0; j < SAVEFILE_SCORE_LINE_LENGTH; j++) {
                savefile_score_line[j] = '\0';
            }
            fgets(savefile_score_line, SAVEFILE_SCORE_LINE_LENGTH, (FILE*)savefile);
            fprintf(savefile_temp, "%s", savefile_score_line);
        }

        /* get the line of the player in the savefile  */
        for (j = 0; j < SAVEFILE_SCORE_LINE_LENGTH; j++) {
                savefile_score_line[j] = '\0';
            }
        fgets(savefile_score_line, SAVEFILE_SCORE_LINE_LENGTH, (FILE*)savefile);

        /* now the new data for this player is written to the savefile temp */
        if (player2_won == TRUE) {
            fprintf(savefile_temp, "%s;%i;%i;%i;%i;%i\n", player2_name, (savefile_score_line_total_time_played + calc_seconds_played()), (savefile_score_line_total_played_games + 1), savefile_score_line_lost_games, (savefile_score_line_won_games + 1), (savefile_score_line_total_attempts + player2_attempts));
        } else {
            fprintf(savefile_temp, "%s;%i;%i;%i;%i;%i\n", player2_name, (savefile_score_line_total_time_played + calc_seconds_played()), (savefile_score_line_total_played_games + 1), (savefile_score_line_lost_games + 1), savefile_score_line_won_games, (savefile_score_line_total_attempts + player2_attempts));
        }

        /* write rest to the temp file, then write the hole temp file to the original file and delete the temp file */
        while (TRUE) {
            for (i = 0; i < SAVEFILE_SCORE_LINE_LENGTH; i++) {
                savefile_score_line[i] = '\0';
            }
            if (fgets(savefile_score_line, SAVEFILE_SCORE_LINE_LENGTH, (FILE*)savefile) == NULL) {
                fclose(savefile);
                fclose(savefile_temp);
                copy_temp_savefile_to_original_and_delete_temp();
                return;
            }
            fprintf(savefile_temp, "%s", savefile_score_line);
        }
    } else {
        WRONG_PLAYER_TO_SAVE_ERROR();
    }
}

void copy_temp_savefile_to_original_and_delete_temp()
{
    FILE *savefile, *savefile_temp;
    char savefile_score_line[SAVEFILE_SCORE_LINE_LENGTH];
    int i;

    savefile = fopen("savegame.mstrmnd_sav", "w");
    savefile_temp = fopen(".savegame.mstrmnd_sav.temp", "r");

    while (TRUE) {
        for (i = 0; i < SAVEFILE_SCORE_LINE_LENGTH; i++) {
            savefile_score_line[i] = '\0';
        }
        if (fgets(savefile_score_line, SAVEFILE_SCORE_LINE_LENGTH, (FILE*)savefile_temp) == NULL) {
            fclose(savefile);
            fclose(savefile_temp);
            if (remove(".savegame.mstrmnd_sav.temp") != 0) {
                DELETE_TEMP_SAVE_FILE_ERROR()
            }
            return;
        }
        fprintf(savefile, "%s", savefile_score_line);
    }
}

int name_length(char *name)
{
    int i;
    for (i = 0; name[i] != '\0'; i++) {}
    return i;
}

void clear_savefile_variables()
{
    int i;
    for (i = 0; i < MAX_NAME_LENGTH; i++) {
        savefile_score_line_name[i] = '\0';
    }
    savefile_score_line_total_time_played = 0;
    savefile_score_line_total_played_games = 0;
    savefile_score_line_lost_games = 0;
    savefile_score_line_won_games = 0;
    savefile_score_line_total_attempts = 0;
}

void get_savefile_line_of_player(int player_number)
{
    int i;

    read_game_savefile(0);
    for (i = 0; savefile_score_line_name[0] != '\0'; i++ ) {
        read_game_savefile(i);
        if (player_number != 1 && player_number != 2) {
            clear_savefile_variables();
            WRONG_PLAYER_TO_SAVE_ERROR();
        } else if (player_number == 1 && compare_player_names(player1_name, savefile_score_line_name)) {
            savefile_line_of_player_1 = i;
            return;
        } else if (player_number == 2 && compare_player_names(player2_name, savefile_score_line_name)) {
            savefile_line_of_player_2 = i;
            return;
        }
    }

    clear_savefile_variables();
    if (player_number == 1) {
        savefile_line_of_player_1 = PLAYER_NOT_IN_SAVEFILE;
    } else if (player_number == 2) {
        savefile_line_of_player_2 = PLAYER_NOT_IN_SAVEFILE;
    } else {
        WRONG_PLAYER_TO_SAVE_ERROR();
    }
}

int compare_player_names(char *name1, char *name2)
{
    int i;
    for (i = 0; i < MAX_NAME_LENGTH; i++) {
        if (name1[i] != name2[i]) {
            return FALSE;
        }
    }
    return TRUE;
}
