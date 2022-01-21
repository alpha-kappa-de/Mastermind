#include "mastermind.h"

int main()
{
    gamelanguage = LANGUAGE_ENGLISH;
    pretty_mode = TRUE;
    colorcode_length = 4;
    player1_attempts = 0;

    printf("Player1 name is %s, Player2 name is %s\n", player1_name, player2_name);
    
    generate_random_colorcode(player2_colorcode);    
    printf("Generated Colorcode was: %s %s %s %s\n\n", lang_color_name(player2_colorcode[0]), lang_color_name(player2_colorcode[1]), lang_color_name(player2_colorcode[2]), lang_color_name(player2_colorcode[3]));
    start_game();
    printf("\nPlayer1 name was %s, Player2 name was %s\n", player1_name, player2_name);

    return SUCCESS;
}
