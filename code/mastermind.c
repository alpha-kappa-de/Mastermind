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
