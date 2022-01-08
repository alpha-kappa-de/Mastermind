#include "mastermind.h"
#include "mastermind_language.h"
#include "mastermind_gui.h"


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
    printf(" /%s/     /%s/     /%s/     /%s/     /%s/  \n", lang_menu_options(MENU_OPTION_PLAY), lang_menu_options(MENU_OPTION_HOWTOPLAY), lang_menu_options(MENU_OPTION_STATS), lang_menu_options(MENU_OPTION_SETTINGS), lang_menu_options(MENU_OPTION_EXIT));
    printf("/________________/     /________________/     /________________/     /________________/     /________________/    \n");
    printf("%s\n", lang_please_input_menu_option());
}

void gui_print_settings_menu()
{
    printf("   _________________      _________________      _________________ \n");
    printf("  /      (1)       /     /      (2)       /     /      (3)       / \n");
    printf(" /%s/     /%s/     /%s/  \n", lang_menu_options(MENU_OPTION_LANGUAGE), lang_menu_options(MENU_OPTION_GUIMODE), lang_menu_options(MENU_OPTION_EXIT));
    printf("/________________/     /________________/     /________________/    \n");
    printf("%s\n", lang_please_input_menu_option());
}

void gui_print_language_menu()
{
    int i;
    /* 1. Row: Head */
    for (i = 0; i < AMOUNT_OF_LANGUAGES; i++) {
        printf("   _________________");
        
        if (i != (AMOUNT_OF_LANGUAGES - 1)) {
            printf("   ");
        } else printf("\n");
    }

    /* 2. Row: Number */
    for (i = 0; i < AMOUNT_OF_LANGUAGES; i++) {
        printf("  /      (%i)       /", i + 1);
        
        if (i != (AMOUNT_OF_LANGUAGES - 1)) {
            printf("   ");
        } else printf("\n");
    }
    
    /* 3. Row: Language name */
    for (i = 0; i < AMOUNT_OF_LANGUAGES; i++) {
        printf(" /%s/", lang_language_name(i));
        
        if (i != (AMOUNT_OF_LANGUAGES - 1)) {
            printf("    ");
        } else printf("\n");
    }

    /* 4. Row: Bottom */
    for (i = 0; i < AMOUNT_OF_LANGUAGES; i++) {
        printf("/________________/");
        
        if (i != (AMOUNT_OF_LANGUAGES - 1)) {
            printf("     ");
        } else printf("\n");
    }

    printf("%s\n", lang_please_input_menu_option());
}

void gui_print_GUI_mode_menu()
{
    int current_pretty_mode_setting = pretty_mode;
    pretty_mode = FALSE;
    printf("%s", lang_change_guimode_message());
    printf("               (1)              |               (2)              \n");
    printf("%s|%s\n________________________________|________________________________\n", lang_compatible_mode_whitespaced(), lang_pretty_mode_whitespaced());
    printf("                                |                                \n");
    printf("%s\t\t\t\t|%s%s%s\n", lang_color_name(BLUE), COLORMODE_BLUE, lang_color_name(BLUE), COLORMODE_RESET);
    printf("%s\t\t\t\t|%s%s%s\n", lang_color_name(RED), COLORMODE_RED, lang_color_name(RED), COLORMODE_RESET);
    printf("%s\t\t\t\t|%s%s%s\n", lang_color_name(YELLOW), COLORMODE_YELLOW, lang_color_name(YELLOW), COLORMODE_RESET);
    printf("%s\t\t\t\t|%s%s%s\n", lang_color_name(GREEN), COLORMODE_GREEN, lang_color_name(GREEN), COLORMODE_RESET);
    printf("%s\t\t\t\t|%s%s%s\n", lang_color_name(PURPLE), COLORMODE_PURPLE, lang_color_name(PURPLE), COLORMODE_RESET);
    printf("%s\t\t\t\t|%s%s%s\n", lang_color_name(ORANGE), COLORMODE_ORANGE, lang_color_name(ORANGE), COLORMODE_RESET);
    printf("%s\t\t\t\t|%s%s%s\n", lang_color_name(CYAN), COLORMODE_CYAN, lang_color_name(CYAN), COLORMODE_RESET);
    printf("________________________________|________________________________\n");
    
    if (current_pretty_mode_setting != pretty_mode) {
        pretty_mode = current_pretty_mode_setting;
    } 

    printf("%s: ", lang_current_setting());
    if (pretty_mode == FALSE) {
        printf("%s\n", lang_compatible_mode());
    } else if (pretty_mode == TRUE) {
        printf("%s\n", lang_pretty_mode());
    } else INVALID_PRETTYMODE_ERROR();
    
    
    printf("%s\n", lang_always_safe_to_choose_comp_mode());
    printf("%s\n", lang_please_input_menu_option());
}
