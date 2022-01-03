#include "mastermind_language.h"
#include "mastermind.h"
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
    guess_pin_array = calloc(colorcode_length, sizeof(char));
    start_of_colorcode_pin_array = colorcode_pin_array;
    start_of_guess_pin_array = guess_pin_array;


    /* get amount of correct pins */
    for (i = 0; i < colorcode_length; i++) {
        if (colorcode[i] == guess[i]) {
            ++counter_correct_pins;
            *colorcode_pin_array = 'B';
            *guess_pin_array = 'B';
        }
        colorcode_pin_array++;
        guess_pin_array++;
    }
    colorcode_pin_array = start_of_colorcode_pin_array;
    guess_pin_array = start_of_guess_pin_array;

    /* get amount of correct colors */
    for (i = 0; i < colorcode_length; i++, guess_pin_array++) {
        for (j = 0; j < colorcode_length; j++, colorcode_pin_array++) {
            if (*colorcode_pin_array != 'B' && *guess_pin_array != 'W' && *colorcode_pin_array != 'W' && colorcode[j] == guess[i]) {
            ++counter_correct_color;
            *guess_pin_array = 'W';
            *colorcode_pin_array = 'W';
            }
        }
        colorcode_pin_array = start_of_colorcode_pin_array;
    }
    
    /* print message: input of player, amount of correct pins and correct colors */
    printf("\t\t");
    lang_print_correct_pins();
    printf(": %i\t", counter_correct_pins);
    lang_print_correct_colors();
    printf(": %i\n", counter_correct_color);

    /* free up space and return amount of correct pins */
    free(colorcode_pin_array);
    free(guess_pin_array);
    return counter_correct_pins;
}

int generate_random_color()
{
    static int random_number = 0;

    if (random_number == 0) {
        srand(time(NULL));
    }

    random_number = rand();
    return (random_number % (AMOUNT_OF_COLORS));
}

int flush_buff (void) 
{
    int c;
    while ((c = getchar ()) != '\n' && c != EOF ) {}
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
        printf("%s %s\n", lang_wrong_format(), lang_please_input_menu_option());
        i = player_input_menu(5);
    }
    
    switch (i)
    {
        /* Play */
        case 1:
            lang_print_you_typed_menu_option(i);
            /* goto menu 1 */
            break;
        
        /* How to play */
        case 2:
            lang_print_you_typed_menu_option(i);
            /* goto menu 2 */
            break;
        
        /* Language */
        case 3:
            lang_print_you_typed_menu_option(i);
            language_menu();
            break;

        /* Statistics */
        case 4:
            lang_print_you_typed_menu_option(i);
            /* goto menu 4 */
            break;

        /* Exit */
        case 5:
            lang_print_you_typed_menu_option(i);
            EXIT_PROGRAM_SUCCESSFUL();
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
        printf("%s %s\n", lang_wrong_format(), lang_please_input_menu_option());
        i = player_input_menu(AMOUNT_OF_LANGUAGES);
    }
    
    switch (i - 1) {
    
        case LANGUAGE_GERMAN:
            gamelanguage = LANGUAGE_GERMAN;
            printf("%s\n", lang_language_changed_to());
            mainmenu();
            break;
        
        case LANGUAGE_ENGLISH:
            gamelanguage = LANGUAGE_ENGLISH;
            printf("%s\n", lang_language_changed_to());
            mainmenu();
            break;
        
        case LANGUAGE_FRENCH:
            gamelanguage = LANGUAGE_FRENCH;
            printf("%s\n", lang_language_changed_to());
            mainmenu();
            break;

        default:
            INVALID_LANGUAGE_ERROR();
            break;
        }
}