#include "mastermind_language.h"
#include "mastermind.h"

char *lang_color_name(int color)
{
    if (gamelanguage == LANGUAGE_GERMAN) {
        switch (color) {
        case BLUE:
            return "blau";
            break;

        case RED:
            return "rot";
            break;

        case YELLOW:
            return "gelb";
            break;

        case GREEN:
            return "gruen";
            break;

        case PURPLE:
            return "lila";
            break;

        case BROWN:
            return "braun";
            break;

        default:
            break;
        }
    }else if (gamelanguage == LANGUAGE_ENGLISH) {
        switch (color) {
        case BLUE:
            return "blue";
            break;

        case RED:
            return "red";
            break;

        case YELLOW:
            return "yellow";
            break;

        case GREEN:
            return "green";
            break;

        case PURPLE:
            return "purple";
            break;

        case BROWN:
            return "brown";
            break;

        default:
            break;
        }
    }else if (gamelanguage == LANGUAGE_FRENCH) {
        switch (color) {
        case BLUE:
            return "bleu";
            break;

        case RED:
            return "rouge";
            break;

        case YELLOW:
            return "jaune";
            break;

        case GREEN:
            return "vert";
            break;

        case PURPLE:
            return "mauve";
            break;

        case BROWN:
            return "brun";
            break;

        default:
            break;
        }
    }
    INVALID_LANGUAGE_ERROR();
}

void lang_print_you_typed(int *typed_code)
{
    int i;

    switch (gamelanguage) {
    case LANGUAGE_ENGLISH:
        printf("You typed");
        break;

    case LANGUAGE_FRENCH:
        printf("Votre entree");
        break;

    case LANGUAGE_GERMAN:
        printf("Deine Eingabe");
        break;

    default:
        INVALID_LANGUAGE_ERROR();
    }

    for (i = 0; i < colorcode_length; i++) {
        printf("%s", lang_color_name(typed_code[i]));
        if (i != (colorcode_length - 1)) {
            printf(", ");
        }
    }
}

void lang_print_correct_pins()
{
    switch (gamelanguage) {
    case LANGUAGE_ENGLISH:
        printf("Correct pins");
        break;

    case LANGUAGE_FRENCH:
        printf("Stylos corrects");
        break;

    case LANGUAGE_GERMAN:
        printf("Richtige Stifte");
        break;

    default:
        INVALID_LANGUAGE_ERROR();
    }
}

void lang_print_correct_colors()
{
    switch (gamelanguage) {
    case LANGUAGE_ENGLISH:
        printf("Correct colors");
        break;

    case LANGUAGE_FRENCH:
        printf("Couleurs correctes");
        break;

    case LANGUAGE_GERMAN:
        printf("Richtige Farbe");
        break;

    default:
        INVALID_LANGUAGE_ERROR();
    }
}

void lang_print_type_your_guess()
{
    switch (gamelanguage) {
    case LANGUAGE_ENGLISH:
        printf("Guess the colorcode");
        break;

    case LANGUAGE_FRENCH:
        printf("Devinez le code couleur");
        break;

    case LANGUAGE_GERMAN:
        printf("Errate den Farbcode");
        break;

    default:
        INVALID_LANGUAGE_ERROR();
    }
}

void lang_print_colorcode_wrong_format_message()
{
    int i;

    switch (gamelanguage) {
    case LANGUAGE_ENGLISH:
        printf("%s Enter a colorcode consisting of %i colors. Seperate the colors with a \",\". Example:\n", lang_wrong_format(), colorcode_length);
        break;

    case LANGUAGE_FRENCH:
        printf("%s Entrez un code couleur compose de %i couleurs. Separez les couleurs avec un \",\". Exemple:\n", lang_wrong_format(), colorcode_length);
        break;

    case LANGUAGE_GERMAN:
        printf("%s Gebe einen Farbcode, bestehend aus %i Farben, ein. Trenne die Farben durch ein \",\". Beispiel:\n", lang_wrong_format(), colorcode_length);
        break;

    default:
        INVALID_LANGUAGE_ERROR();
    }
    
    for (i = 0; i < colorcode_length; i++) {
        LANG_PRINT_RANDOM_COLOR();
        if (i != colorcode_length - 1) {
            printf(", ");
        }
    }
}

char *lang_menu_options(int menu_option)
{
    if (menu_option == MENU_OPTION_PLAY) {
        switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "      Play      ";
            break;

        case LANGUAGE_FRENCH:
            return "     Jouer      ";
            break;

        case LANGUAGE_GERMAN:
            return "    Spielen     ";
            break;

        default:
            INVALID_LANGUAGE_ERROR();
        }
    }else if (menu_option == MENU_OPTION_HOWTOPLAY) {
        switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "   How to play  ";
            break;

        case LANGUAGE_FRENCH:
            return " Comment jouer  ";
            break;

        case LANGUAGE_GERMAN:
            return " Wie man spielt ";
            break;

        default:
            INVALID_LANGUAGE_ERROR();
        }
    }else if (menu_option == MENU_OPTION_LANGUAGE) {
        switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "    Language    ";
            break;

        case LANGUAGE_FRENCH:
            return "     Langue     ";
            break;

        case LANGUAGE_GERMAN:
            return "    Sprache     ";
            break;

        default:
            INVALID_LANGUAGE_ERROR();
        }
    }else if (menu_option == MENU_OPTION_STATS) {
        switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "   Statistics   ";
            break;

        case LANGUAGE_FRENCH:
            return "  Statistiques  ";
            break;

        case LANGUAGE_GERMAN:
            return "   Statistiken  ";
            break;

        default:
            INVALID_LANGUAGE_ERROR();
        }
    }else if (menu_option == MENU_OPTION_EXIT) {
        switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "      Exit      ";
            break;

        case LANGUAGE_FRENCH:
            return "      Finir     ";
            break;

        case LANGUAGE_GERMAN:
            return "    Beenden     ";
            break;

        default:
            INVALID_LANGUAGE_ERROR();
        }
    }
    INVALID_MENUOPTION_ERROR();
}

void lang_print_you_typed_menu_option(int menu_option)
{
    switch (gamelanguage) {
    case LANGUAGE_ENGLISH:
        printf("You typed menu option %i", menu_option);
        break;

    case LANGUAGE_FRENCH:
        printf("Vous avez tape l'option de menu %i", menu_option);
        break;

    case LANGUAGE_GERMAN:
        printf("Du waehltest Menueoption %i", menu_option);
        break;

    default:
        INVALID_LANGUAGE_ERROR();
    }
}

char *lang_wrong_format()
{
    switch (gamelanguage) {
    case LANGUAGE_ENGLISH:
        return "Wrong format!";
        break;

    case LANGUAGE_FRENCH:
        return "Mauvais format!";
        break;

    case LANGUAGE_GERMAN:
        return "Falsches Format!";
        break;

    default:
        INVALID_LANGUAGE_ERROR();
    }
}

char *lang_please_input_menu_option()
{
    switch (gamelanguage) {
    case LANGUAGE_ENGLISH:
        return "Please enter a number according to the menu option.";
        break;

    case LANGUAGE_FRENCH:
        return "Veuillez entrer un nombre en fonction de l'option de menu.";
        break;

    case LANGUAGE_GERMAN:
        return "Bitte gebe eine Zahl entsprechend der Menueoption ein.";
        break;

    default:
        INVALID_LANGUAGE_ERROR();
    }
}

char *lang_goodbye()
{
    switch (gamelanguage) {
    case LANGUAGE_ENGLISH:
        return "Thanks for playing. Goodbye!";
        break;

    case LANGUAGE_FRENCH:
        return "Merci d'avoir joue. Au revoir!";
        break;

    case LANGUAGE_GERMAN:
        return "Danke fuers Spielen. Auf Wiedersehen!";
        break;

    default:
        INVALID_LANGUAGE_ERROR();
    }
}