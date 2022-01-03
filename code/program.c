#include "mastermind.h"
#include "mastermind_language.h"

int main()
{
    /* initialize some values */
    gamelanguage = LANGUAGE_ENGLISH;
    colorcode_length = 4;

    /* draw main menu */
    gui_print_mastermind_logo();
    gui_print_options_menu();
}
