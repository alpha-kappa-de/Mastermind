#include "mastermind.h"
#include "mastermind_language.h"
#include "mastermind_gui.h"

char *lang_color_name(int color)
{
    /*
    Colored text can be used by using ansi escape codes. When translating these, make sure you don't break the codes! 

    For example "\033[38;5;4m"
    \033[   ->  ANSI ESC sequence starts
    38      ->  Foreground color
    5       ->  Lets choose 8 bit color
    4       ->  Decimal of colorcode, here 4 stands for blue (other colors: red=1, yellow=226, green=10, purple=5, brown=94, orange=166, cyan=14)
    m       ->  End of sequence

    To reset colors to normal you use "\033[0m". 0 removes all effects
    */

    if (gamelanguage == LANGUAGE_GERMAN) {
        switch (color) {
            case BLUE:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;4mblau\033[0m";
                }
                return "blau";
            case RED:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;1mrot\033[0m";
                }
                return "rot";
            case YELLOW:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;226mgelb\033[0m";
                }
                return "gelb";
            case GREEN:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;10mgruen\033[0m";
                }
                return "gruen";
            case PURPLE:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;5mlila\033[0m";
                }
                return "lila";
            case BROWN:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;94mbraun\033[0m";
                }
                return "braun";
            case ORANGE:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;166morange\033[0m";
                }
                return "orange";
            case CYAN:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;14mcyan\033[0m";
                }
                return "cyan";
            default:
                break;
        }
    } else if (gamelanguage == LANGUAGE_ENGLISH) {
        switch (color) {
            case BLUE:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;4mblue\033[0m";
                }
                return "blue";
            case RED:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;1mred\033[0m";
                }
                return "red";
            case YELLOW:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;226myellow\033[0m";
                }
                return "yellow";
            case GREEN:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;10mgreen\033[0m";
                }
                return "green";
            case PURPLE:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;5mpurple\033[0m";
                }
                return "purple";
            case BROWN:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;94mbrown\033[0m";
                }
                return "brown";
            case ORANGE:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;166morange\033[0m";
                }
                return "orange";
            case CYAN:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;14mcyan\033[0m";
                }
                return "cyan";
            default:
                break;
        }
    } else if (gamelanguage == LANGUAGE_FRENCH) {
        switch (color) {
            case BLUE:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;4mbleu\033[0m";
                }
                return "bleu";
            case RED:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;1mrouge\033[0m";
                }
                return "rouge";
            case YELLOW:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;226mjaune\033[0m";
                }
                return "jaune";
            case GREEN:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;10mvert\033[0m";
                }
                return "vert";
            case PURPLE:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;5mmauve\033[0m";
                }
                return "mauve";
            case BROWN:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;94mbrun\033[0m";
                }
                return "brun";
            case ORANGE:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;166morange\033[0m";
                }
                return "orange";
            case CYAN:
                if (pretty_mode == TRUE) {
                    return "\033[38;5;14mcyan\033[0m";
                }
                return "cyan";
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

char *lang_type_colorcode()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "Type in a colorcode: ";
            break;
        case LANGUAGE_FRENCH:
            return "Tapez un code couleur:";
            break;
        case LANGUAGE_GERMAN:
            return "Gebe einen Farbcode ein: ";
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
            printf("%s Enter a colorcode consisting of %i colors. Seperate the colors with a space.\nExample: ", lang_wrong_format(), colorcode_length);
            break;
        case LANGUAGE_FRENCH:
            printf("%s Entrez un code couleur compose de %i couleurs. Separez les couleurs avec un espace \" \".\nExemple: ", lang_wrong_format(), colorcode_length);
            break;
        case LANGUAGE_GERMAN:
            printf("%s Gebe einen Farbcode, bestehend aus %i Farben, ein. Trenne die Farben durch ein Leerzeichen.\nBeispiel: ", lang_wrong_format(), colorcode_length);
            break;
        default:
            INVALID_LANGUAGE_ERROR();
        }
    
    for (i = 0; i < colorcode_length; i++) {
        LANG_PRINT_RANDOM_COLOR();
        if (i != colorcode_length - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

char *lang_menu_options(int menu_option)
{
    /* Please mind that every string has to be exactly 17 chars long (including \0) */
    if (menu_option == MENU_OPTION_PLAY) {
        switch (gamelanguage) {
            case LANGUAGE_ENGLISH:
                return "      Play      ";
            case LANGUAGE_FRENCH:
                return "     Jouer      ";
            case LANGUAGE_GERMAN:
                return "    Spielen     ";
            default:
                INVALID_LANGUAGE_ERROR();
            }
    }else if (menu_option == MENU_OPTION_HOWTOPLAY) {
        switch (gamelanguage) {
            case LANGUAGE_ENGLISH:
                return "   How to play  ";
            case LANGUAGE_FRENCH:
                return " Comment jouer  ";
            case LANGUAGE_GERMAN:
                return " Wie man spielt ";
            default:
                INVALID_LANGUAGE_ERROR();
            }
    }else if (menu_option == MENU_OPTION_STATS) {
        switch (gamelanguage) {
            case LANGUAGE_ENGLISH:
                return "   Statistics   ";
            case LANGUAGE_FRENCH:
                return "  Statistiques  ";
            case LANGUAGE_GERMAN:
                return "   Statistiken  ";
            default:
                INVALID_LANGUAGE_ERROR();
            }
    }else if (menu_option == MENU_OPTION_EXIT) {
        switch (gamelanguage) {
            case LANGUAGE_ENGLISH:
                return "      Exit      ";
            case LANGUAGE_FRENCH:
                return "      Finir     ";
            case LANGUAGE_GERMAN:
                return "    Beenden     ";
            default:
                INVALID_LANGUAGE_ERROR();
            }
    }else if (menu_option == MENU_OPTION_SETTINGS) {
        switch (gamelanguage) {
            case LANGUAGE_ENGLISH:
                return "    Settings    ";
            case LANGUAGE_FRENCH:
                return "      Idees     ";
            case LANGUAGE_GERMAN:
                return "  Einstellungen ";
            default:
                INVALID_LANGUAGE_ERROR();
        }
    }else if (menu_option == MENU_OPTION_LANGUAGE) {
        switch (gamelanguage) {
            case LANGUAGE_ENGLISH:
                return "    Language    ";
            case LANGUAGE_FRENCH:
                return "     Langue     ";
            case LANGUAGE_GERMAN:
                return "    Sprache     ";
            default:
                INVALID_LANGUAGE_ERROR();
            }
    }else if (menu_option == MENU_OPTION_GUIMODE) {
        switch (gamelanguage) {
            case LANGUAGE_ENGLISH:
                return "     GUI mode   ";
            case LANGUAGE_FRENCH:
                return "    mode GUI    ";
            case LANGUAGE_GERMAN:
                return "    GUI Modus   ";
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
        case LANGUAGE_FRENCH:
            return "Mauvais format!";
        case LANGUAGE_GERMAN:
            return "Falsches Format!";
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
        default:
            INVALID_LANGUAGE_ERROR();
        }
}

char *lang_goodbye()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "Thanks for playing. Goodbye!";
        case LANGUAGE_FRENCH:
            return "Merci d'avoir joue. Au revoir!";
        case LANGUAGE_GERMAN:
            return "Danke fuers Spielen. Auf Wiedersehen!";
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
        case LANGUAGE_FRENCH:
            return "    FRANCAIS    ";
        case LANGUAGE_GERMAN:
            return "     DEUTSCH    ";
        default:
            INVALID_LANGUAGE_ERROR();
        }
}

char *lang_language_changed_to()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "Language changed to English.";
        case LANGUAGE_FRENCH:
            return "Langue changee en francais.";
        case LANGUAGE_GERMAN:
            return "Sprache wurde auf Deutsch eingestellt.";
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

int lang_color_name_to_number(char *color_string)
{
    if (gamelanguage == LANGUAGE_GERMAN) {
        if (strcmp(color_string, "blau") == 0 || strcmp(color_string, "bl") == 0) {
            return BLUE;
        } else if (strcmp(color_string, "rot") == 0 || strcmp(color_string, "ro") == 0) {
            return RED;
        } else if (strcmp(color_string, "gelb") == 0 || strcmp(color_string, "ge") == 0) {
            return YELLOW;
        } else if (strcmp(color_string, "gruen") == 0 || strcmp(color_string, "gr") == 0) {
            return GREEN;
        } else if (strcmp(color_string, "lila") == 0 || strcmp(color_string, "li") == 0) {
            return PURPLE;
        } else if (strcmp(color_string, "braun") == 0 || strcmp(color_string, "br") == 0) {
            return BROWN;
        } else if (strcmp(color_string, "orange") == 0 || strcmp(color_string, "or") == 0) {
            return ORANGE;
        } else if (strcmp(color_string, "cyan") == 0 || strcmp(color_string, "cy") == 0) {
            return CYAN;
        } else return NOT_A_COLOR; 
    } else if (gamelanguage == LANGUAGE_ENGLISH) {
        if (strcmp(color_string, "blue") == 0 || strcmp(color_string, "bl") == 0) {
            return BLUE;
        } else if (strcmp(color_string, "red") == 0 || strcmp(color_string, "re") == 0) {
            return RED;
        } else if (strcmp(color_string, "yellow") == 0 || strcmp(color_string, "ye") == 0) {
            return YELLOW;
        } else if (strcmp(color_string, "green") == 0 || strcmp(color_string, "gr") == 0) {
            return GREEN;
        } else if (strcmp(color_string, "purple") == 0 || strcmp(color_string, "pu") == 0) {
            return PURPLE;
        } else if (strcmp(color_string, "brown") == 0 || strcmp(color_string, "br") == 0) {
            return BROWN;
        } else if (strcmp(color_string, "orange") == 0 || strcmp(color_string, "or") == 0) {
            return ORANGE;
        } else if (strcmp(color_string, "cyan") == 0 || strcmp(color_string, "cy") == 0) {
            return CYAN;
        } else return NOT_A_COLOR; 
    } else if (gamelanguage == LANGUAGE_FRENCH) {
        if (strcmp(color_string, "bleu") == 0 || strcmp(color_string, "bl") == 0) {
            return BLUE;
        } else if (strcmp(color_string, "rouge") == 0 || strcmp(color_string, "ro") == 0) {
            return RED;
        } else if (strcmp(color_string, "jaune") == 0 || strcmp(color_string, "ja") == 0) {
            return YELLOW;
        } else if (strcmp(color_string, "vert") == 0 || strcmp(color_string, "ve") == 0) {
            return GREEN;
        } else if (strcmp(color_string, "mauve") == 0 || strcmp(color_string, "ma") == 0) {
            return PURPLE;
        } else if (strcmp(color_string, "brun") == 0 || strcmp(color_string, "br") == 0) {
            return BROWN;
        } else if (strcmp(color_string, "orange") == 0 || strcmp(color_string, "or") == 0) {
            return ORANGE;
        } else if (strcmp(color_string, "cyan") == 0 || strcmp(color_string, "cy") == 0) {
            return CYAN;
        } else return NOT_A_COLOR; 
    } else INVALID_LANGUAGE_ERROR();
}

char *lang_change_guimode_message()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "Do you really want to change the GUI mode?\nChanging this option may make the game unplayable, if your OS doesn't accept it.\nIf the pretty mode looks weird, don't choose it!\n\n";
        case LANGUAGE_FRENCH:
            return "Voulez-vous vraiment changer le mode GUI?\nChanger cette option peut rendre le jeu injouable, si votre systeme operateur ne l'accepte pas.\nSi le mode jolie a l'air bizarre, ne le choisissez pas!\n\n";
        case LANGUAGE_GERMAN:
            return "Moechten Sie den GUI-Modus wirklich aendern?\nDas Aendern dieser Option kann das Spiel unspielbar machen, wenn Ihr Betriebssystem dies nicht akzeptiert.\nWenn der schoene Modus komisch aussieht, waehle ihn nicht aus!\n\n";
        default:
            INVALID_LANGUAGE_ERROR();
        }
}

char *lang_compatible_mode_whitespaced()
{
    /* Please mind that every string has to be exactly 33 chars long (including \0) */
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "       Compatible mode          ";
        case LANGUAGE_FRENCH:
            return "        Mode compatible         ";
        case LANGUAGE_GERMAN:
            return "       Kompatibler Modus        ";
        default:
            INVALID_LANGUAGE_ERROR();
        }
}

char *lang_pretty_mode_whitespaced()
{
    /* Please mind that every string has to be exactly 33 chars long (including \0) */
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "          Pretty mode           ";
        case LANGUAGE_FRENCH:
            return "           Mode jolie           ";
        case LANGUAGE_GERMAN:
            return "        Schoener Modus          ";
        default:
            INVALID_LANGUAGE_ERROR();
        }
}

char *lang_compatible_mode()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "Compatible mode";
        case LANGUAGE_FRENCH:
            return "Mode compatible";
        case LANGUAGE_GERMAN:
            return "Kompatibler Modus";
        default:
            INVALID_LANGUAGE_ERROR();
        }
}

char *lang_pretty_mode()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "Pretty mode";
        case LANGUAGE_FRENCH:
            return "Mode jolie";
        case LANGUAGE_GERMAN:
            return "Schoener Modus";
        default:
            INVALID_LANGUAGE_ERROR();
        }
}

char *lang_always_safe_to_choose_comp_mode()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "It's always safe to choose the compatible mode (1).";
        case LANGUAGE_FRENCH:
            return "Il est toujours sur de choisir le mode compatible (1).";
        case LANGUAGE_GERMAN:
            return "Es ist immer sicher den kompatiblen Modus (1) zu waehlen.";
        default:
            INVALID_LANGUAGE_ERROR();
        }
}

char *lang_current_setting()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "Current Setting";
        case LANGUAGE_FRENCH:
            return "Parametre actuel";
        case LANGUAGE_GERMAN:
            return "Aktuelle Einstellung";
        default:
            INVALID_LANGUAGE_ERROR();
        }
}
