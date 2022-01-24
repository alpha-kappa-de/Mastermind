#include "mastermind.h"

int main()
{
    /* initialize some values */
    srand(time(NULL));

    read_game_savefile(SAVEFILE_SETTINGS_ONLY);

    /* draw main menu */
    gui_print_mastermind_logo();
    while (TRUE) {
        mainmenu();
    }
    exit(SUCCESS);
}
