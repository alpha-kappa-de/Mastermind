#include "mastermind.h"
#include "mastermind_language.h"
#include "mastermind_gui.h"

void gui_print_mastermind_logo()
{
    printf("\n\n\n\n\n");
    printf("                    __          __         _                                       _           \n");
    printf("                    \\ \\        / /        | |                                     | |          \n");
    printf("                     \\ \\  /\\  / /    ___  | |   ___    ___    _ __ ___     ___    | |_    ___  \n");
    printf("                      \\ \\/  \\/ /    / _ \\ | |  / __|  / _ \\  | '_ ` _ \\   / _ \\   | __|  / _ \\ \n");
    printf("                       \\  /\\  /    |  __/ | | | (__  | (_) | | | | | | | |  __/   | |_  | (_) |\n");
    printf("                        \\/  \\/      \\___| |_|  \\___|  \\___/  |_| |_| |_|  \\___|    \\__|  \\___/ \n");
    printf("\n\n");
    printf("                          __  __                 _                               _               _  \n");
    printf("                         |  \\/  |               | |                             (_)             | | \n");
    printf("                         | \\  / |   __ _   ___  | |_    ___   _ __   _ __ ___    _   _ __     __| | \n");
    printf("                         | |\\/| |  / _` | / __| | __|  / _ \\ | '__| | '_ ` _ \\  | | | '_ \\   / _` | \n");
    printf("                         | |  | | | (_| | \\__ \\ | |_  |  __/ | |    | | | | | | | | | | | | | (_| | \n");
    printf("                         |_|  |_|  \\__,_| |___/  \\__|  \\___| |_|    |_| |_| |_| |_| |_| |_|  \\__,_| \n");
    printf("                                                         by alpha-kappa-de, Jooosy and JanisNoah \n\n");

    if (pretty_mode == TRUE) {
        wait_seconds(WAIT_3_SECONDS);
        delete_last_lines_and_go_there(DELETE_LAST_LINES_GAMELOGO);
    }
}

void gui_print_options_menu()
{
    printf("   _________________      _________________      _________________      _________________      _________________ \n");
    printf("  /      (1)       /     /      (2)       /     /      (3)       /     /      (4)       /     /      (5)       / \n");
    if (pretty_mode == TRUE) {
        printf(" /%s%s%s/     /%s%s%s/     /%s%s%s/     /%s%s%s/     /%s%s%s/  \n", gui_write_in_random_color(), lang_menu_options(MENU_OPTION_PLAY), COLORMODE_RESET, gui_write_in_random_color(), lang_menu_options(MENU_OPTION_HOWTOPLAY), COLORMODE_RESET, gui_write_in_random_color(), lang_menu_options(MENU_OPTION_STATS), COLORMODE_RESET, gui_write_in_random_color(), lang_menu_options(MENU_OPTION_SETTINGS), COLORMODE_RESET, gui_write_in_random_color(), lang_menu_options(MENU_OPTION_EXIT), COLORMODE_RESET);
    } else printf(" /%s/     /%s/     /%s/     /%s/     /%s/  \n", lang_menu_options(MENU_OPTION_PLAY), lang_menu_options(MENU_OPTION_HOWTOPLAY), lang_menu_options(MENU_OPTION_STATS), lang_menu_options(MENU_OPTION_SETTINGS), lang_menu_options(MENU_OPTION_EXIT));
    printf("/________________/     /________________/     /________________/     /________________/     /________________/    \n");
    printf("%s: ", lang_please_input_menu_option());
}

void gui_print_settings_menu()
{
    printf("   _________________      _________________      _________________ \n");
    printf("  /      (1)       /     /      (2)       /     /      (3)       / \n");

    if (pretty_mode == TRUE) {
        printf(" /%s%s%s/     /%s%s%s/     /%s%s%s/  \n", gui_write_in_random_color(), lang_menu_options(MENU_OPTION_LANGUAGE), COLORMODE_RESET, gui_write_in_random_color(), lang_menu_options(MENU_OPTION_GUIMODE), COLORMODE_RESET, gui_write_in_random_color(), lang_menu_options(MENU_OPTION_BACK), COLORMODE_RESET);
    } else printf(" /%s/     /%s/     /%s/  \n", lang_menu_options(MENU_OPTION_LANGUAGE), lang_menu_options(MENU_OPTION_GUIMODE), lang_menu_options(MENU_OPTION_BACK));

    printf("/________________/     /________________/     /________________/    \n");
    printf("%s: ", lang_please_input_menu_option());
}

void gui_print_gamemode_menu()
{
    printf("   _________________      _________________      _________________ \n");
    printf("  /      (1)       /     /      (2)       /     /      (3)       / \n");

    if (pretty_mode == TRUE) {
        printf(" /%s   Mastermind   %s/     /%sSuper Mastermind%s/     /%s%s%s/  \n", gui_write_in_random_color(), COLORMODE_RESET, gui_write_in_random_color(), COLORMODE_RESET, gui_write_in_random_color(), lang_menu_options(MENU_OPTION_BACK), COLORMODE_RESET);
    } else printf(" /   Mastermind   /     /Super Mastermind/     /%s/  \n", lang_menu_options(MENU_OPTION_BACK));

    printf("/________________/     /________________/     /________________/    \n");
    printf("%s: ", lang_please_input_menu_option());
}

void gui_print_single_or_multiplayer_menu()
{
    printf("   _________________      _________________      _________________ \n");
    printf("  /      (1)       /     /      (2)       /     /      (3)       / \n");

    if (pretty_mode == TRUE) {
        printf(" /%s%s%s/     /%s%s%s/     /%s%s%s/  \n", gui_write_in_random_color(), lang_singleplayer_multiplayer(1), COLORMODE_RESET, gui_write_in_random_color(), lang_singleplayer_multiplayer(2), COLORMODE_RESET, gui_write_in_random_color(), lang_menu_options(MENU_OPTION_BACK), COLORMODE_RESET);
    } else printf(" /%s/     /%s/     /%s/  \n", lang_singleplayer_multiplayer(1), lang_singleplayer_multiplayer(2), lang_menu_options(MENU_OPTION_BACK));

    printf("/________________/     /________________/     /________________/    \n");
    printf("%s: ", lang_please_input_menu_option());
}

void gui_print_back_only()
{
    printf("   _________________\n");
    printf("  /      (1)       /\n");

    if (pretty_mode == TRUE) {
        printf(" /%s%s%s/\n", gui_write_in_random_color(), lang_menu_options(MENU_OPTION_BACK), COLORMODE_RESET);
    } else printf(" /%s/\n", lang_menu_options(MENU_OPTION_BACK));

    printf("/________________/\n");
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

        if (pretty_mode == TRUE) {
            printf(" /%s%s%s/", gui_write_in_random_color(), lang_language_name(i), COLORMODE_RESET);
        } else printf(" /%s/", lang_language_name(i));

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

    printf("%s: ", lang_please_input_menu_option());
}

void gui_print_GUI_mode_menu()
{
    int current_pretty_mode_setting = pretty_mode;
    is_super_mastermind = TRUE;
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
    printf("%s\t\t\t\t|%s%s%s\n", lang_color_name(BROWN), COLORMODE_BROWN, lang_color_name(BROWN), COLORMODE_RESET);
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
    printf("%s: ", lang_please_input_menu_option());
}

char *gui_write_in_random_color()
{
    switch ((rand() + rand()) % AMOUNT_OF_COLORS) {
        case BLUE:
            return COLORMODE_BLUE;
        case RED:
            return COLORMODE_RED;
        case YELLOW:
            return COLORMODE_YELLOW;
        case GREEN:
            return COLORMODE_GREEN;
        case PURPLE:
            return COLORMODE_PURPLE;
        case BROWN:
            return COLORMODE_BROWN;
        case ORANGE:
            return COLORMODE_ORANGE;
        case CYAN:
            return COLORMODE_CYAN;
        default:
            return COLORMODE_RESET;
    }
    return COLORMODE_RESET;
}

void gui_print_stats()
{
    int i,j;

    /* print header */
    printf("__________________________________________________________________________________________________________________\n");
    printf("|                      |              |              |              |              |              |              |\n");
    printf("|%s|%s|%s|%s|%s|%s|%s|\n", lang_stat_player_name(1), lang_stat_game_time(1), lang_stat_total_games_played(1), lang_stat_lost_games(1), lang_stat_won_games(1), lang_stat_win_rate(1), lang_stat_average_tries(1));
    printf("|%s|%s|%s|%s|%s|%s|%s|\n", lang_stat_player_name(2), lang_stat_game_time(2), lang_stat_total_games_played(2), lang_stat_lost_games(2), lang_stat_won_games(2), lang_stat_win_rate(2), lang_stat_average_tries(2));
    printf("|______________________|______________|______________|______________|______________|______________|______________|\n");
    printf("|                      |              |              |              |              |              |              |\n");

    /* print stat lines */
    i = 0;
    while (TRUE) {
        read_game_savefile(i);
        if (savefile_score_line_name[0] == '\0') {
            break;
        } else {
            printf("| %s", savefile_score_line_name);
            for (j = 0; j < (MAX_NAME_LENGTH - name_length(savefile_score_line_name)); j++) {
                printf(" ");
            }
            gui_print_stat_lines_right_justified(savefile_score_line_total_time_played / ONE_HOUR_IN_SECONDS);
            gui_print_stat_lines_right_justified(savefile_score_line_total_played_games);
            gui_print_stat_lines_right_justified(savefile_score_line_lost_games);
            gui_print_stat_lines_right_justified(savefile_score_line_won_games);
            gui_print_stat_line_winrate_right_justified();
            gui_print_stat_lines_right_justified((savefile_score_line_total_attempts / savefile_score_line_total_played_games));

            printf("|\n");
            i++;
        }
    }

    /* print footer */
    printf("|______________________|______________|______________|______________|______________|______________|______________|\n");

    clear_savefile_variables();
}

void gui_print_stat_lines_right_justified(int value)
{
    if (value >= 0 && value <= 9) {
        printf("|            %i ", value);
    } else if (value >= 10 && value <= 99) {
        printf("|           %i ", value);
    } else if (value >= 100 && value <= 999) {
        printf("|          %i ", value);
    } else if (value >= 1000 && value <= 9999) {
        printf("|         %i ", value);
    } else if (value >= 10000 && value <= 99999) {
        printf("|        %i ", value);
    } else if (value >= 100000 && value <= 999999) {
        printf("|       %i ", value);
    } else if (value < 0 || value > 999999) {
        printf("|      >999999 ");
    } else {
        printf("|              ");
    }
}

void gui_print_stat_line_winrate_right_justified()
{
    double percentage;
    percentage = ((double)savefile_score_line_won_games / (double)savefile_score_line_total_played_games);
    if (percentage >= 0.000 && percentage <= 0.099) {
        printf("|         %.1f%% ", (percentage * 100));
    } else if (percentage >= 0.100 && percentage <= 0.999) {
        printf("|        %.1f%% ", (percentage * 100));
    } else if (percentage == 1.000) {
        printf("|       %.1f%% ", (percentage * 100));
    } else {
        printf("|              ");
    }
}

void delete_last_lines_and_go_there(int amount_of_lines)
{
    int i;

    if (amount_of_lines == DELETE_LAST_LINES_STATS) {
        for (i = 0; TRUE; i++) {
            clear_savefile_variables();
            read_game_savefile(i);
            if (savefile_score_line_name[0] == '\0') {
                amount_of_lines = i + 12;
                clear_savefile_variables();
                break;
            }
        }
    }

    if (pretty_mode == TRUE) {
        printf("\033[200D");
        for (i = 0; i < amount_of_lines; i++) {
            printf("\033[1A");
            printf("\033[2K");
        }
    }
}

void move_cursor(char up_or_down, int amount_of_lines)
{
    if (amount_of_lines < 1 || (up_or_down != UP && up_or_down != DOWN)) {
        MOVE_CURSOR_ERROR()
    }
    if (up_or_down == DOWN) {
        amount_of_lines -= 1;
    } else if (up_or_down == UP) {
        amount_of_lines += 1;
    }
    
    if (pretty_mode == TRUE) {
        printf("\n");
        printf("\033[%i%c", amount_of_lines, up_or_down);
    }
}

void wait_seconds(int seconds)
{
    time_t starttime;

    starttime = time(NULL);
    while ((starttime + seconds) > time(NULL)) {}
}
