#include "mastermind.h"

int main()
{
    srand(time(NULL));
    read_game_savefile(SAVEFILE_SETTINGS_ONLY);
    gui_print_mastermind_logo();
    while (TRUE) {
        mainmenu();
    }
    exit(SUCCESS);
}
