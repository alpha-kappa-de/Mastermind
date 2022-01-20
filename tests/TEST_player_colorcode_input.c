#include "mastermind.h"

int main()
{
    int i;
    gamelanguage = LANGUAGE_ENGLISH;
    pretty_mode = TRUE;

    printf("First test with colorcode_length 4\n");
    colorcode_length = 4;
    while (player_colorcode_input(player1_colorcode) != SUCCESS) {
        lang_print_colorcode_wrong_format_message();
    }
    printf("\nExited whileloop, printing results:\n");
    for (i = 0; i < colorcode_length; i++) {
        printf("%s ", lang_color_name(player1_colorcode[i]));
    }

    printf("Second test with colorcode_length 6\n");
    colorcode_length = 6;
    while (player_colorcode_input(player1_colorcode) != SUCCESS) {
        lang_print_colorcode_wrong_format_message();
    }
    printf("\nExited whileloop, printing results:\n");
    for (i = 0; i < colorcode_length; i++) {
        printf("%s ", lang_color_name(player1_colorcode[i]));
    }

    printf("Third and last test with colorcode_length 8\n");
    colorcode_length = 8;
    while (player_colorcode_input(player1_colorcode) != SUCCESS) {
        lang_print_colorcode_wrong_format_message();
    }
    printf("\nExited whileloop, printing results:\n");
    for (i = 0; i < colorcode_length; i++) {
        printf("%s ", lang_color_name(player1_colorcode[i]));
    }
    
    exit(SUCCESS);
}
