#include "mastermind_gui.h"
#include "mastermind.h"
#include "mastermind_language.h"


void gui_print_mastermind_logo()
{
    printf(" __          __         _                                       _           \n");
    printf(" \\ \\        / /        | |                                     | |          \n");
    printf("  \\ \\  /\\  / /    ___  | |   ___    ___    _ __ ___     ___    | |_    ___  \n");
    printf("   \\ \\/  \\/ /    / _ \\ | |  / __|  / _ \\  | '_ ` _ \\   / _ \\   | __|  / _ \\ \n");
    printf("    \\  /\\  /    |  __/ | | | (__  | (_) | | | | | | | |  __/   | |_  | (_) |\n");
    printf("     \\/  \\/      \\___| |_|  \\___|  \\___/  |_| |_| |_|  \\___|    \\__|  \\___/ \n");
    printf("\n\n");
    printf("  __  __                 _                               _               _  \n");
    printf(" |  \\/  |               | |                             (_)             | | \n");
    printf(" | \\  / |   __ _   ___  | |_    ___   _ __   _ __ ___    _   _ __     __| | \n");
    printf(" | |\\/| |  / _` | / __| | __|  / _ \\ | '__| | '_ ` _ \\  | | | '_ \\   / _` | \n");
    printf(" | |  | | | (_| | \\__ \\ | |_  |  __/ | |    | | | | | | | | | | | | | (_| | \n");
    printf(" |_|  |_|  \\__,_| |___/  \\__|  \\___| |_|    |_| |_| |_| |_| |_| |_|  \\__,_| \n");
    printf("                                 by alpha-kappa-de, Jooosy and JanisNoah \n\n");
}

void gui_print_options_menu()
{
    printf("   _________________      _________________      _________________      _________________      _________________ \n");
    printf("  /      (1)       /     /      (2)       /     /      (3)       /     /      (4)       /     /      (5)       / \n");
    printf(" /%s/     /%s/     /%s/     /%s/     /%s/  \n", lang_menu_options(MENU_OPTION_PLAY), lang_menu_options(MENU_OPTION_HOWTOPLAY), lang_menu_options(MENU_OPTION_LANGUAGE), lang_menu_options(MENU_OPTION_STATS), lang_menu_options(MENU_OPTION_EXIT));
    printf("/________________/     /________________/     /________________/     /________________/     /________________/    \n");
    printf("%s\n", lang_please_input_menu_option());
}