#include "mastermind.h"

int main()
{
    /* initialize some values */
    starttime = time(NULL);
    gamelanguage = LANGUAGE_ENGLISH;
    colorcode_length = 4;

    /* draw main menu */
    gui_print_mastermind_logo();
    mainmenu();

    exit(SUCCESS);
}
