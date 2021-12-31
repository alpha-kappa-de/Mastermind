#include "mastermind.h"

int main()
{
    gamelanguage = LANGUAGE_GERMAN;

    colorcode_length = 6;

    player1_colorcode[0] = BLUE;
    player1_colorcode[1] = RED;
    player1_colorcode[2] = GREEN;
    player1_colorcode[3] = PURPLE;
    player1_colorcode[4] = GREEN;
    player1_colorcode[5] = BLUE;

    player2_guess[0] = BLUE;
    player2_guess[1] = PURPLE;
    player2_guess[2] = GREEN;
    player2_guess[3] = BLUE;
    player2_guess[4] = GREEN;
    player2_guess[5] = RED;


    check_colorcode_and_print_correct_pins(player1_colorcode, player2_guess);
    return 0;

}