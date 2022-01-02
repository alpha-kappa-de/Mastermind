#include "mastermind.h"

int main()
{
    gamelanguage = LANGUAGE_ENGLISH;

    gui_print_mastermind_logo();

    printf("Menu in English:\n");
    gui_print_options_menu();

    gamelanguage = LANGUAGE_FRENCH;
    printf("\nMenu in French:\n");
    gui_print_options_menu();

    gamelanguage = LANGUAGE_FRENCH;
    printf("\nMenu in French:\n");
    gui_print_options_menu();

    EXIT_PROGRAM_SUCCESSFUL();
}