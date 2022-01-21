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

    /* print message: input of player, amount of correct pins and correct colors */
    printf("%s: %i\t%s: %i\n", lang_correct_pins(), counter_correct_pins, lang_correct_colors(), counter_correct_color);

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
        printf("%s %s: ", lang_wrong_format(), lang_please_input_menu_option());
        i = player_input_menu(5);
    }

    switch (i)
    {
        /* Play */
        case 1:
            start_game();
            break;

        /* How to play */
        case 2:
            lang_print_how_to_play();
            break;

        /* Statistics */
        case 3:
            /* goto menu 3 */
            break;

        /* Settings */
        case 4:
            settings_menu();
            break;

        /* Exit */
        case 5:
            EXIT_PROGRAM_SUCCESSFUL();

        default:
            break;
        }
}

void settings_menu()
{
    int i;
    gui_print_settings_menu();
    i = player_input_menu(3);

    while (i == INVALID_MENU_INPUT || i == BUFFER_ERROR) {
        printf("%s %s: ", lang_wrong_format(), lang_please_input_menu_option());
        i = player_input_menu(3);
    }

    switch (i)
    {
        /* Language */
        case 1:
            language_menu();
            break;
        /* Nice GUI mode */
        case 2:
            change_gui_mode();
            break;
        /* exit */
        case 3:
            break;
        default:
            break;
        }
}

void language_menu()
{
    int i;
    gui_print_language_menu();
    i = player_input_menu(AMOUNT_OF_LANGUAGES);

    while (i == INVALID_MENU_INPUT || i == BUFFER_ERROR) {
        printf("%s %s: ", lang_wrong_format(), lang_please_input_menu_option());
        i = player_input_menu(AMOUNT_OF_LANGUAGES);
    }

    switch (i - 1) {
        case LANGUAGE_GERMAN:
            gamelanguage = LANGUAGE_GERMAN;
            save_gamesettings();
            break;

        case LANGUAGE_ENGLISH:
            gamelanguage = LANGUAGE_ENGLISH;
            save_gamesettings();
            break;

        case LANGUAGE_FRENCH:
            gamelanguage = LANGUAGE_FRENCH;
            save_gamesettings();
            break;

        default:
            INVALID_LANGUAGE_ERROR();
            break;
        }
}

void change_gui_mode()
{
    int i;
    gui_print_GUI_mode_menu();
    i = player_input_menu(2);

    while (i == INVALID_MENU_INPUT || i == BUFFER_ERROR) {
        printf("%s %s: ", lang_wrong_format(), lang_please_input_menu_option());
        i = player_input_menu(2);
    }

    if (i == 1) {
        pretty_mode = FALSE;
        save_gamesettings();
    } else if (i == 2) {
        pretty_mode = TRUE;
        save_gamesettings();
    }
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

void start_game()
{
    int i;

    /* gamemode selection */
    gui_print_gamemode_menu();
    i = player_input_menu(3);

    while (i == INVALID_MENU_INPUT || i == BUFFER_ERROR) {
        printf("%s %s: ", lang_wrong_format(), lang_please_input_menu_option());
        i = player_input_menu(3);
    }

    if (i == 1) {
        is_super_mastermind = FALSE;
        colorcode_length = MASTERMIND_COLORCODE_LENGTH;
    } else if (i == 2) {
        is_super_mastermind = TRUE;
        colorcode_length = SUPER_MASTERMIND_COLORCODE_LENGTH;
    } else return;

    /* single or multiplayer selection */
    gui_print_single_or_multiplayer_menu();
    i = player_input_menu(3);

    while (i == INVALID_MENU_INPUT || i == BUFFER_ERROR) {
        printf("%s %s: ", lang_wrong_format(), lang_please_input_menu_option());
        i = player_input_menu(3);
    }

    if (i == 1) {
        is_singleplayer = TRUE;
    } else if (i == 2) {
        is_singleplayer = FALSE;
    } else return;

    /* initialize players values */
    player1_attempts = 0;
    player2_attempts = 0;
    player1_guessed_or_lost = FALSE;
    player2_guessed_or_lost = FALSE;

    /* let player1 input his name */
    printf("%s %i ", lang_player(), 1);
    lang_print_please_input_name();
    while (get_player_name(player1_name) != SUCCESS) {
            printf("%s %i ", lang_player(), 1);
            lang_print_please_input_name();
    }

    /* If Multiplayer... */
    if (is_singleplayer == FALSE) {
        /* ... let player2 input his name */
        printf("%s %i ", lang_player(), 2);
        lang_print_please_input_name();
        
        while (get_player_name(player2_name) != SUCCESS) {
            printf("%s %i ", lang_player(), 2);
            lang_print_please_input_name();
        }

        /* ... let player1 input his colorcode */
        printf("%s: ", player1_name);
        while (player_colorcode_input(player1_colorcode) != SUCCESS) {
            lang_print_colorcode_wrong_format_message();
        }
        /* ... let player2 input his colorcode */
        printf("%s: ", player2_name);
        while (player_colorcode_input(player2_colorcode) != SUCCESS) {
            lang_print_colorcode_wrong_format_message();
        }
    } else /* if singleplayer, don't ask for player2 name and generate random colorcode */ {
        generate_random_colorcode(player2_colorcode);
        player2_guessed_or_lost = TRUE;

        /* TODO: delete this block, it's for debugging only *//*  */ /*  */ /*  */
        /*  */printf("FOR DEBUGGING ONLY. COMPUTERS COLORCODE IS: ");       /*  */
        /*  */    for (i = 0; i < colorcode_length; i++) {                  /*  */
        /*  */        printf("%s ", lang_color_name(player2_colorcode[i])); /*  */
        /*  */    }                                                         /*  */
        /*  */printf("\n");                                                 /*  */
        /* TODO: delete this block, it's for debugging only *//*  */ /*  */ /*  */
    }
    

    /* actual start of the game. lets player guess the colorcode and breaks if colorcode is guessed or took to many attempts */
    player1_starttime = time(NULL);
    player2_starttime = time(NULL);

    while (TRUE) {
        /* player 1 turn */
        if (player1_guessed_or_lost == FALSE) {
            /* let player 1 guess */
            if (player1_attempts == (MAX_ATTEMPTS_TO_GUESS_CODE - 1)) {
                if (pretty_mode == TRUE) {
                    printf("%s%s, %s. %s", COLORMODE_RED, lang_its_your_last_try(), player1_name, COLORMODE_RESET);
                } else printf("%s, %s. ", lang_its_your_last_try(), player1_name); 
            } else printf("%s%i, %s. ", lang_its_your_try_nr(), (player1_attempts + 1) , player1_name); 

            while (player_colorcode_input(player_guess) != SUCCESS) {
                lang_print_colorcode_wrong_format_message();
            }
            /* if guessed right */
            if (check_colorcode_and_print_correct_pins(player2_colorcode, player_guess) == colorcode_length) {
                player1_attempts++;
                printf("%s, %s %i\n", player1_name, lang_correctly_guessed_code(), player1_attempts);
                player1_guessed_or_lost = TRUE;
            /* if guessed wrong, increment attempts and check, if max. attempts are reached */
            } else {
                player1_attempts++;
                if (player1_attempts == MAX_ATTEMPTS_TO_GUESS_CODE) {
                    printf("%s %s... %s\n%s: ", lang_what_a_pity(), player1_name, lang_game_over(), lang_right_colorcode_was());
                    for (i = 0; i < colorcode_length; i++) {
                        printf("%s ", lang_color_name(player2_colorcode[i]));
                    }
                    printf("\n");
                    player1_guessed_or_lost = TRUE;
                }
            }
        }
        
        /* player 2 turn */
        if (player2_guessed_or_lost == FALSE) {
            /* let player 2 guess */
            if (player2_attempts == (MAX_ATTEMPTS_TO_GUESS_CODE - 1)) {
                if (pretty_mode == TRUE) {
                    printf("%s%s, %s. %s", COLORMODE_RED, lang_its_your_last_try(), player2_name, COLORMODE_RESET);
                } else printf("%s, %s. ", lang_its_your_last_try(), player2_name); 
            } else printf("%s%i, %s. ", lang_its_your_try_nr(), (player2_attempts + 1) , player2_name);           
            
            while (player_colorcode_input(player_guess) != SUCCESS) {
                lang_print_colorcode_wrong_format_message();
            }
            /* if guessed right */
            if (check_colorcode_and_print_correct_pins(player1_colorcode, player_guess) == colorcode_length) {
                player1_attempts++;
                printf("%s, %s %i\n", player2_name, lang_correctly_guessed_code(), player2_attempts);
                player2_guessed_or_lost = TRUE;
            /* if guessed wrong, increment attempts and check, if max. attempts are reached */
            } else {
                player2_attempts++;
                if (player2_attempts == MAX_ATTEMPTS_TO_GUESS_CODE) {
                    printf("%s %s... %s\n%s: ", lang_what_a_pity(), player2_name, lang_game_over(), lang_right_colorcode_was());
                    for (i = 0; i < colorcode_length; i++) {
                        printf("%s ", lang_color_name(player1_colorcode[i]));
                    }
                    printf("\n");
                    player2_guessed_or_lost = TRUE;
                }
            }
        }

        /* when both players are done */
        if (player1_guessed_or_lost == TRUE && player2_guessed_or_lost == TRUE) {
            
            
            /* TODO: write savegame */

            for (i = 0; i < MAX_NAME_LENGTH; i++) {
                *(player1_name + i) = '\0';
                *(player2_name + i) = '\0';
            }
            player1_attempts = 0;
            player2_attempts = 0;
            
            break;
        }
    }   
}

void read_gamesettings()
{
    FILE *savefile;
    char pretty_mode_save[3], gamelanguage_save[3];

    savefile = fopen("savegame.mstrmnd_sav", "r");

    if (savefile == NULL) {
        gamelanguage = LANGUAGE_ENGLISH;
        pretty_mode = FALSE;
        save_gamesettings();
        fclose(savefile);
        return;
    }
    

    fgets(pretty_mode_save, 3, (FILE*)savefile);
    fgets(gamelanguage_save, 3, (FILE*)savefile);
    fclose(savefile);
    
    if (atoi(pretty_mode_save) != TRUE && atoi(pretty_mode_save) != FALSE) {
        CORRUPT_SAVE_FILE_ERROR()
    } else pretty_mode = atoi(pretty_mode_save);
    
    if (atoi(gamelanguage_save) < 0 || atoi(gamelanguage_save) >= AMOUNT_OF_LANGUAGES) {
        CORRUPT_SAVE_FILE_ERROR()
    } else gamelanguage = atoi(gamelanguage_save);
}

void save_gamesettings()
{
    FILE *savefile;
    savefile = fopen("savegame.mstrmnd_sav", "w");
    fprintf(savefile, "%i\n%i\n", pretty_mode, gamelanguage);
    fclose(savefile);
}
