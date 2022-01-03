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
    /* Please mind that every string has to be exactly 17 chars long (including \0) */
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

char *lang_language_name(int language)
{
    /* Please mind that every string has to be exactly 17 chars long (including \0) */
    switch (language) {
    case LANGUAGE_ENGLISH:
        return "     ENGLISH    ";
        break;

    case LANGUAGE_FRENCH:
        return "    FRANCAIS    ";
        break;

    case LANGUAGE_GERMAN:
        return "     DEUTSCH    ";
        break;

    default:
        INVALID_LANGUAGE_ERROR();
    }
}

char *lang_language_changed_to()
{
    switch (gamelanguage) {
    case LANGUAGE_ENGLISH:
        return "Language changed to English.";
        break;

    case LANGUAGE_FRENCH:
        return "Langue changee en francais.";
        break;

    case LANGUAGE_GERMAN:
        return "Sprache wurde auf Deutsch eingestellt.";
        break;

    default:
        INVALID_LANGUAGE_ERROR();
    }
}

void lang_print_how_to_play()
{
    switch (gamelanguage) {
    case LANGUAGE_ENGLISH:
        printf("_____________________________________________\nHow to play:\n_____________________________________________\n");
        printf("At the beginning, both players secretly determine a four-digit ordered color code, which is selected from six colors.\n");
        printf("Each color can also be used several times. The aim of the game is to find out the other player's\n");
        printf("color code with as few moves as possible, but after a maximum of twelve attempts.\n");
        printf("With every move you get the information how many pins (in the color code) have been correctly set\n");
        printf("in color and position and how many pins are in the correct color but are in the wrong position.\n\nSuper mastermind:\n");
        printf("If the Super Mastermind option is selected, the color code consists of five pins.\n");
        printf("Instead of six colors, you can now choose from eight colors.\n");
        printf("Here, too, you have a maximum of twelve attempts to guess the code.\n_____________________________________________\n");
        break;

    case LANGUAGE_FRENCH:
        printf("_____________________________________________\nComment jouer:\n_____________________________________________\n");
        printf("Au debut, les deux joueurs determinent secretement un code couleur ordonne a quatre chiffres,\n");
        printf("qui est selectionne parmi six couleurs. Chaque couleur peut egalement etre utilisee plusieurs fois.\n");
        printf("Le but du jeu est de decouvrir le code couleur de l'autre joueur avec le moins de coups possible,\n");
        printf("mais apres un maximum de douze tentatives. A chaque mouvement, vous obtenez des informations sur le\n");
        printf("nombre de broches (dans le code de couleur) qui ont ete correctement definies dans la couleur et la position\n");
        printf("et sur le nombre de broches de la bonne couleur mais dans la mauvaise position.\n\nSuper Mastermind:\n");
        printf("Si l'option Super Mastermind est selectionnee, le code couleur se compose de cinq broches. Au lieu de six couleurs,\n");
        printf("vous pouvez desormais choisir parmi huit couleurs.\n");
        printf("Ici aussi, vous disposez d'un maximum de douze tentatives pour deviner le code.\n_____________________________________________\n");
        break;

    case LANGUAGE_GERMAN:
        printf("_____________________________________________\nWie man spielt:\n_____________________________________________\n");
        printf("Beide Spieler legen zu Beginn verdeckt einen vierstelligen geordneten Farbcode fest, der aus sechs Farben\n");
        printf("ausgewaehlt wird. Jede Farbe kann auch mehrmals verwendet werden. Ziel des Spieles ist es, den Farbcode des\n"); 
        printf("anderen mit so wenig Zuegen wie moeglich, jedoch nach maximal zwoelf Versuchen, herauszufinden.\n");
        printf("Auf jeden Zug hin bekommt man die Information, wie viele Pins (im Farbcode)\n");
        printf("in Farbe und Position richtig gesetzt wurden und wie viele Pins zwar die richtige Farbe haben, aber an einer\n");
        printf("falschen Position stehen.\n\nSuper Mastermind:\nWird die Option Super Mastermind ausgewaehlt besteht der Farbcode aus fuenf Pins.\n");
        printf("Statt aus sechs Farben kann nun aus acht Farben ausgewaehlt werden.\n");
        printf("Auch hier hat man maximal zwoelf Versuche, um den Code zu erraten.\n_____________________________________________\n");
        break;

    default:
        INVALID_LANGUAGE_ERROR();
    }
}