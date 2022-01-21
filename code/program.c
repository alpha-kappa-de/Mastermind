#include "mastermind.h"

int main()
{
    /* initialize some values */
    srand(time(NULL));
    gamelanguage = LANGUAGE_ENGLISH;

    /* TODO: read savefile if exists */

    /* draw main menu */
    gui_print_mastermind_logo();
    while (TRUE) {
        mainmenu();
    }
    exit(SUCCESS);
}
