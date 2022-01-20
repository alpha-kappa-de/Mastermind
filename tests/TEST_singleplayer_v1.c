#include "mastermind.h"

int main()
{
    gamelanguage = LANGUAGE_ENGLISH;
    pretty_mode = TRUE;
    colorcode_length = 4;

    generate_random_colorcode(player2_colorcode);
    printf("Generated Colorcode was: %s %s %s %s\n", lang_color_name(player2_colorcode[0]), lang_color_name(player2_colorcode[1]), lang_color_name(player2_colorcode[2]), lang_color_name(player2_colorcode[3]));

    while (1) {
        while (player_colorcode_input(player_guess) != SUCCESS) {
            lang_print_colorcode_wrong_format_message();
        }

        if (check_colorcode_and_print_correct_pins(player2_colorcode, player_guess) == colorcode_length) {
            printf("\nGewonnen!\n");
            break;
        }
    }

    exit(SUCCESS);
}
