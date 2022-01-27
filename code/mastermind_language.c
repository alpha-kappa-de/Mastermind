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
    4       ->  Decimal of colorcode, here 4 stands for blue (other colors: red=1, yellow=226, green=10, purple=57, brown=94, orange=166, cyan=14)
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
                    return "\033[38;5;57mlila\033[0m";
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
                    return "\033[38;5;57mpurple\033[0m";
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
                    return "\033[38;5;57mmauve\033[0m";
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

void lang_print_name_your_guess_was(int player_number)
{
    int i;
    if (player_number != 1 && player_number != 2) {
        INVALID_PLAYER_NUMBER_ERROR();
    }

    if (pretty_mode == TRUE) {
        switch (gamelanguage) {
            case LANGUAGE_ENGLISH:
                if (player_number == 1) {
                    if ((player1_attempts + 1) < 10) {
                        printf("%s. Guess #%i: \t", player1_name, (player1_attempts + 1));
                    } else {
                        printf("%s. Guess #%i:\t", player1_name, (player1_attempts + 1));
                    }
                } else if (player_number == 2) {
                    if ((player2_attempts + 1) < 10) {
                        printf("%s. Guess #%i :\t", player2_name, (player2_attempts + 1));
                    } else {
                        printf("%s. Guess #%i:\t", player2_name, (player2_attempts + 1));
                    }
                }
                break;
            case LANGUAGE_FRENCH:
                if (player_number == 1) {
                    if ((player1_attempts + 1) < 10) {
                        printf("%s. Entree #%i :\t", player1_name, (player1_attempts + 1));
                    } else {
                        printf("%s. Entree #%i:\t", player1_name, (player1_attempts + 1));
                    }
                } else if (player_number == 2) {
                    if ((player2_attempts + 1) < 10) {
                        printf("%s. Entree #%i :\t", player2_name, (player2_attempts + 1));
                    } else {
                        printf("%s. Entree #%i:\t", player2_name, (player2_attempts + 1));
                    }
                }
                break;
            case LANGUAGE_GERMAN:
            if (player_number == 1) {
                    if ((player1_attempts + 1) < 10) {
                        printf("%s. Eingabe #%i :\t", player1_name, (player1_attempts + 1));
                    } else {
                        printf("%s. Eingabe #%i:\t", player1_name, (player1_attempts + 1));
                    }
                } else if (player_number == 2) {
                    if ((player2_attempts + 1) < 10) {
                        printf("%s. Eingabe #%i :\t", player2_name, (player2_attempts + 1));
                    } else {
                        printf("%s. Eingabe #%i:\t", player2_name, (player2_attempts + 1));
                    }
                }
                break;
            default:
                INVALID_LANGUAGE_ERROR();
        }

        for (i = 0; i < colorcode_length; i++) {
            printf("\t%s", lang_color_name(player_guess[i]));
        }
    }
}

char *lang_correct_pins()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "Pins";
        case LANGUAGE_FRENCH:
            return "Stylos";
        case LANGUAGE_GERMAN:
            return "Stifte";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

char *lang_correct_colors()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "Colors";
        case LANGUAGE_FRENCH:
            return "Couleurs";
        case LANGUAGE_GERMAN:
            return "Farben";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

char *lang_type_colorcode()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "Type in a colorcode: ";
        case LANGUAGE_FRENCH:
            return "Tapez un code couleur:";
        case LANGUAGE_GERMAN:
            return "Gebe einen Farbcode ein: ";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

void lang_print_colorcode_wrong_format_message()
{
    int i;

    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            printf("%s Seperate the %i colors with a space. Example: ", lang_wrong_format(), colorcode_length);
            break;
        case LANGUAGE_FRENCH:
            printf("%s Separez les %i couleurs avec un espace. Exemple: ", lang_wrong_format(), colorcode_length);
            break;
        case LANGUAGE_GERMAN:
            printf("%s Trenne die %i Farben durch ein Leerzeichen. Beispiel: ", lang_wrong_format(), colorcode_length);
            break;
        default:
            INVALID_LANGUAGE_ERROR();
    }
    
    for (i = 0; i < colorcode_length; i++) {
        printf("%s", lang_color_name(generate_random_color()));
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
                return "    Mode GUI    ";
            case LANGUAGE_GERMAN:
                return "    GUI Modus   ";
            default:
                INVALID_LANGUAGE_ERROR();
        }
    }else if (menu_option == MENU_OPTION_BACK) {
        switch (gamelanguage) {
            case LANGUAGE_ENGLISH:
                return "      Back      ";
            case LANGUAGE_FRENCH:
                return "     Retour     ";
            case LANGUAGE_GERMAN:
                return "     Zurueck    ";
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
            if (pretty_mode == TRUE) {
                return "\033[38;5;1mWrong format!\033[0m";
            }
            return "Wrong format!";
        case LANGUAGE_FRENCH:
            if (pretty_mode == TRUE) {
                return "\033[38;5;1mMauvais format!\033[0m";
            }
            return "Mauvais format!";
        case LANGUAGE_GERMAN:
            if (pretty_mode == TRUE) {
                return "\033[38;5;1mFalsches Format!\033[0m";
            }
            return "Falsches Format!";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

char *lang_please_input_menu_option()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "Please enter a number according to the menu option";
        case LANGUAGE_FRENCH:
            return "Veuillez entrer un nombre en fonction de l'option de menu";
        case LANGUAGE_GERMAN:
            return "Bitte gebe eine Zahl entsprechend der Menueoption ein";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

char *lang_goodbye()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "Thanks for playing. Goodbye! ";
        case LANGUAGE_FRENCH:
            return "Merci d'avoir joue. Au revoir! ";
        case LANGUAGE_GERMAN:
            return "Danke fuers Spielen. Auf Wiedersehen! ";
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

void lang_print_how_to_play()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            printf("    _____________________________________________\n    How to play:\n    _____________________________________________\n");
            if (pretty_mode == TRUE) {
                printf("    %sMastermind:%s\n", gui_write_in_random_color(), COLORMODE_RESET);
            } else {
                printf("    Mastermind:\n");
            }
            printf("    At the beginning, both players secretly determine a 4-digit ordered color code, which is selected from 6 colors.\n");
            printf("    The possible colors in this mode are: %s, %s, %s, %s, %s and %s.\n", lang_color_name(BLUE), lang_color_name(RED), lang_color_name(YELLOW), lang_color_name(GREEN), lang_color_name(PURPLE), lang_color_name(ORANGE));
            printf("    Each color can also be used several times. The aim of the game is to find out the other player's\n");
            printf("    color code with as few moves as possible, but after a maximum of 12 attempts.\n");
            printf("    With every move you get the information how many pins (in the color code) have been correctly set\n");
            printf("    in color and position and how many pins are in the correct color but are in the wrong position.\n");
            if (pretty_mode == TRUE) {
                printf("%s\n    Super Mastermind:%s\n", gui_write_in_random_color(), COLORMODE_RESET);
            } else {
                printf("\n    Super Mastermind:\n");
            }
            printf("    If the Super Mastermind option is selected, the color code consists of 5 pins.\n");
            printf("    Instead of 6 colors, you can now choose from 8 colors.\n");
            printf("    In addition to the colors from Mastermind there are: %s and %s.\n", lang_color_name(BROWN), lang_color_name(CYAN));
            printf("    Here, too, you have a maximum of 12 attempts to guess the code.\n    _____________________________________________\n");
            break;
        case LANGUAGE_FRENCH:
            printf("    _____________________________________________\n    Comment jouer:\n    _____________________________________________\n");
            if (pretty_mode == TRUE) {
                printf("    %sMastermind:%s\n", gui_write_in_random_color(), COLORMODE_RESET);
            } else {
                printf("    Mastermind:\n");
            }
            printf("    Au debut, les deux joueurs determinent secretement un code couleur ordonne a 4 chiffres, qui est\n");
            printf("    selectionne parmi 6 couleurs. Les couleurs possibles dans ce mode sont: %s, %s, %s, %s, %s et %s.\n", lang_color_name(BLUE), lang_color_name(RED), lang_color_name(YELLOW), lang_color_name(GREEN), lang_color_name(PURPLE), lang_color_name(ORANGE));
            printf("    Chaque couleur peut egalement etre utilisee plusieurs fois.\n");
            printf("    Le but du jeu est de decouvrir le code couleur de l'autre joueur avec le moins de coups possible,\n");
            printf("    mais apres un maximum de 12 tentatives. A chaque mouvement, vous obtenez des informations sur le\n");
            printf("    nombre de broches (dans le code de couleur) qui ont ete correctement definies dans la couleur et la position\n");
            printf("    et sur le nombre de broches de la bonne couleur mais dans la mauvaise position.\n");
            if (pretty_mode == TRUE) {
                printf("%s\n    Super Mastermind:%s\n", gui_write_in_random_color(), COLORMODE_RESET);
            } else {
                printf("\n    Super Mastermind:\n");
            }
            printf("    Si l'option Super Mastermind est selectionnee, le code couleur se compose de 5 broches. Au lieu de 6 couleurs,\n");
            printf("    vous pouvez desormais choisir parmi 8 couleurs.\n");
            printf("    En plus des couleurs de Mastermind, il y a: %s et %s.\n", lang_color_name(BROWN), lang_color_name(CYAN));
            printf("    Ici aussi, vous disposez d'un maximum de 12 tentatives pour deviner le code.\n    _____________________________________________\n");
            break;
        case LANGUAGE_GERMAN:
            printf("    _____________________________________________\n    Wie man spielt:\n    _____________________________________________\n");
            if (pretty_mode == TRUE) {
                printf("    %sMastermind:%s\n", gui_write_in_random_color(), COLORMODE_RESET);
            } else {
                printf("    Mastermind:\n");
            }
            printf("    Beide Spieler legen zu Beginn verdeckt einen vierstelligen geordneten Farbcode fest, der aus 6 Farben\n");
            printf("    ausgewaehlt wird. Moegliche Farben in diesem Modus sind: %s, %s, %s, %s, %s und %s.\n", lang_color_name(BLUE), lang_color_name(RED), lang_color_name(YELLOW), lang_color_name(GREEN), lang_color_name(PURPLE), lang_color_name(ORANGE));
            printf("    Jede Farbe kann auch mehrmals verwendet werden. Ziel des Spieles ist es, den Farbcode des\n"); 
            printf("    anderen mit so wenig Zuegen wie moeglich, jedoch nach maximal 12 Versuchen, herauszufinden.\n");
            printf("    Auf jeden Zug hin bekommt man die Information, wie viele Pins (im Farbcode)\n");
            printf("    in Farbe und Position richtig gesetzt wurden und wie viele Pins zwar die richtige Farbe haben, aber an einer\n");
            printf("    falschen Position stehen.\n");
            if (pretty_mode == TRUE) {
                printf("%s\n    Super Mastermind:%s\n", gui_write_in_random_color(), COLORMODE_RESET);
            } else {
                printf("\n    Super Mastermind:\n");
            }
            printf("    Wird die Option Super Mastermind ausgewaehlt besteht der Farbcode aus 5 Pins.\n");
            printf("    Statt aus 6 Farben kann nun aus 8 Farben ausgewaehlt werden.\n");
            printf("    Zusaetzlich zu den Farben aus Mastermind gibt es noch: %s und %s.\n", lang_color_name(BROWN), lang_color_name(CYAN));
            printf("    Auch hier hat man maximal 12 Versuche, um den Code zu erraten.\n    _____________________________________________\n");
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
            if (is_super_mastermind == TRUE) {
                return BROWN;
            } else return NOT_A_COLOR;
        } else if (strcmp(color_string, "orange") == 0 || strcmp(color_string, "or") == 0) {
            return ORANGE;
        } else if (strcmp(color_string, "cyan") == 0 || strcmp(color_string, "cy") == 0) {
            if (is_super_mastermind == TRUE) {
                return CYAN;
            } else return NOT_A_COLOR;
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
            if (is_super_mastermind == TRUE) {
                return BROWN;
            } else return NOT_A_COLOR;
        } else if (strcmp(color_string, "orange") == 0 || strcmp(color_string, "or") == 0) {
            return ORANGE;
        } else if (strcmp(color_string, "cyan") == 0 || strcmp(color_string, "cy") == 0) {
            if (is_super_mastermind == TRUE) {
                return CYAN;
            } else return NOT_A_COLOR;
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
            if (is_super_mastermind == TRUE) {
                return BROWN;
            } else return NOT_A_COLOR;
        } else if (strcmp(color_string, "orange") == 0 || strcmp(color_string, "or") == 0) {
            return ORANGE;
        } else if (strcmp(color_string, "cyan") == 0 || strcmp(color_string, "cy") == 0) {
            if (is_super_mastermind == TRUE) {
                return CYAN;
            } else return NOT_A_COLOR;
        } else return NOT_A_COLOR; 
    } else INVALID_LANGUAGE_ERROR();
}

char *lang_change_guimode_message()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "    _____________________________________________\n    GUI mode:\n    _____________________________________________\n    Do you really want to change the GUI mode?\n    Changing this option may make the game unplayable, if your OS doesn't accept it.\n    If the pretty mode looks weird, don't choose it!\n\n";
        case LANGUAGE_FRENCH:
            return "    _____________________________________________\n    Mode GUI:\n    _____________________________________________\n    Voulez-vous vraiment changer le mode GUI?\n    Changer cette option peut rendre le jeu injouable, si votre systeme operateur ne l'accepte pas.\n    Si le mode jolie a l'air bizarre, ne le choisissez pas!\n\n";
        case LANGUAGE_GERMAN:
            return "    _____________________________________________\n    GUI Modus:\n    _____________________________________________\n    Moechten Sie den GUI Modus wirklich aendern?\n    Das Aendern dieser Option kann das Spiel unspielbar machen, wenn Ihr Betriebssystem dies nicht akzeptiert.\n    Wenn der schoene Modus komisch aussieht, waehle ihn nicht aus!\n\n";
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

char *lang_correctly_guessed_code()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "you guessed the colorcode!";
        case LANGUAGE_FRENCH:
            return "t'avez devine le code couleur!";
        case LANGUAGE_GERMAN:
            return "du hast den Farbcode erraten!";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

char *lang_trials_needed()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "Trials needed:";
        case LANGUAGE_FRENCH:
            return "Essais necessaires:";
        case LANGUAGE_GERMAN:
            return "Benoetigte Versuche:";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

void lang_print_please_input_name()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            printf("please type in your name (max. %i characters): ", (MAX_NAME_LENGTH - 1));
            break;
        case LANGUAGE_FRENCH:
            printf("s'il vous plait entre ton nom (max. %i caracteres): ", (MAX_NAME_LENGTH - 1));
            break;
        case LANGUAGE_GERMAN:
            printf("bitte gebe deinen Namen ein (max. %i Zeichen): ", (MAX_NAME_LENGTH - 1));
            break;
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

char *lang_you_cant_have_the_same_name()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "You can't have both the same name!";
        case LANGUAGE_FRENCH:
            return "Vous ne pouvez pas avoir les deux le meme nom!";
        case LANGUAGE_GERMAN:
            return "Ihr koennt nicht beide den gleichen Namen haben!";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

char *lang_singleplayer_multiplayer(int amount_of_players)
{
    /* Please mind that every string has to be exactly 17 chars long (including \0) */
    switch (amount_of_players) {
        case 1:
            switch (gamelanguage) {
                case LANGUAGE_ENGLISH:
                    return "  Singleplayer  ";
                case LANGUAGE_FRENCH:
                    return "      Solo      ";
                case LANGUAGE_GERMAN:
                    return "  Einzelspieler ";
                default:
                    INVALID_LANGUAGE_ERROR();
        }
        case 2:
            switch (gamelanguage) {
                case LANGUAGE_ENGLISH:
                    return "   Multiplayer  ";
                case LANGUAGE_FRENCH:
                    return "   Multijoueur  ";
                case LANGUAGE_GERMAN:
                    return "   Mehrspieler  ";
                default:
                    INVALID_LANGUAGE_ERROR();
        }
        default:
            INVALID_MENUOPTION_ERROR();
    }
}

char *lang_player()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "Player";
        case LANGUAGE_FRENCH:
            return "Joueur";
        case LANGUAGE_GERMAN:
            return "Spieler";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

char *lang_game_over()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "Game over! You couldn't guess the colorcode.";
        case LANGUAGE_FRENCH:
            return "Jeu termine! Vous ne pouviez pas deviner le code couleur.";
        case LANGUAGE_GERMAN:
            return "Verloren! Du konntest den Farbcode nicht erraten.";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

char *lang_right_colorcode_was()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "The right colorcode was";
        case LANGUAGE_FRENCH:
            return "Le code couleur correct etait";
        case LANGUAGE_GERMAN:
            return "Der richtige Farbcode war";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

char *lang_what_a_pity()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "What a pity";
        case LANGUAGE_FRENCH:
            return "Quel dommage";
        case LANGUAGE_GERMAN:
            return "Wie Schade";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

char *lang_its_your_try_nr()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "It's your try #";
        case LANGUAGE_FRENCH:
            return "C'est ta tentative #";
        case LANGUAGE_GERMAN:
            return "Es ist dein Versuch #";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

char *lang_its_your_last_try()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "It's your last try";
        case LANGUAGE_FRENCH:
            return "C'est ta derniere tentative";
        case LANGUAGE_GERMAN:
            return "Es ist dein letzter Versuch";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

char *lang_please_type_one_to_go_back()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "Please type \"1\" to go back";
        case LANGUAGE_FRENCH:
            return "Veuillez saisir \"1\" pour revenir en arriere";
        case LANGUAGE_GERMAN:
            return "Bitte gib \"1\" ein, um zurueck zu gehen";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

void lang_print_please_press_enter_to_go_back()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            printf("Please press enter to go back. ");
            flush_buff();
            break;
        case LANGUAGE_FRENCH:
            printf("Veuillez appuyer sur Entree pour revenir en arriere. ");
            flush_buff();
            break;
        case LANGUAGE_GERMAN:
            printf("Bitte dreucke Enter um zurueck zu gehen. ");
            flush_buff();
            break;
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

void lang_print_please_press_enter_to_exit()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            printf("    Please press enter to exit. ");
            flush_buff();
            break;
        case LANGUAGE_FRENCH:
            printf("    Veuillez appuyer sur Entree pour quitter. ");
            flush_buff();
            break;
        case LANGUAGE_GERMAN:
            printf("    Bitte dreucke Enter zum Beenden. ");
            flush_buff();
            break;
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

char *lang_stat_player_name(int line)
{
    /* Please mind that every string has to be exactly 23 chars long (including \0) */
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            if (line == 1) {
                return "        PLAYER        ";
            } else if (line == 2) {
                return "         NAME         ";
            } else return "";
        case LANGUAGE_FRENCH:
            if (line == 1) {
                return "        NOM DE        ";
            } else if (line == 2) {
                return "        JOUEUR        ";
            } else return "";
        case LANGUAGE_GERMAN:
            if (line == 1) {
                return "        SPIELER       ";
            } else if (line == 2) {
                return "         NAME         ";
            } else return "";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

char *lang_stat_game_time(int line)
{
    /* Please mind that every string has to be exactly 15 chars long (including \0) */
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            if (line == 1) {
                return "   GAME TIME  ";
            } else if (line == 2) {
                return "  (IN HOURS)  ";
            } else return "";
        case LANGUAGE_FRENCH:
            if (line == 1) {
                return " TEMPS DE JEU ";
            } else if (line == 2) {
                return "  (EN HEURES) ";
            } else return "";
        case LANGUAGE_GERMAN:
            if (line == 1) {
                return "   SPIELZEIT  ";
            } else if (line == 2) {
                return " (IN STUNDEN) ";
            } else return "";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

char *lang_stat_total_games_played(int line)
{
    /* Please mind that every string has to be exactly 15 chars long (including \0) */
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            if (line == 1) {
                return " TOTAL GAMES  ";
            } else if (line == 2) {
                return "    PLAYED    ";
            } else return "";
        case LANGUAGE_FRENCH:
            if (line == 1) {
                return "  TOTAL DES   ";
            } else if (line == 2) {
                return "  JEUX JOUES  ";
            } else return "";
        case LANGUAGE_GERMAN:
            if (line == 1) {
                return "INSGESAMT GE- ";
            } else if (line == 2) {
                return "SPIELTE SPIELE";
            } else return "";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

char *lang_stat_lost_games(int line)
{
    /* Please mind that every string has to be exactly 15 chars long (including \0) */
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            if (line == 1) {
                return "     LOST     ";
            } else if (line == 2) {
                return "    GAMES     ";
            } else return "";
        case LANGUAGE_FRENCH:
            if (line == 1) {
                return "     JEUX     ";
            } else if (line == 2) {
                return "    PERDUS    ";
            } else return "";
        case LANGUAGE_GERMAN:
            if (line == 1) {
                return "  VERLORENE   ";
            } else if (line == 2) {
                return "    SPIELE    ";
            } else return "";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

char *lang_stat_won_games(int line)
{
    /* Please mind that every string has to be exactly 15 chars long (including \0) */
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            if (line == 1) {
                return "     WON      ";
            } else if (line == 2) {
                return "    GAMES     ";
            } else return "";
        case LANGUAGE_FRENCH:
            if (line == 1) {
                return "     JEUX     ";
            } else if (line == 2) {
                return "    GAGNES    ";
            } else return "";
        case LANGUAGE_GERMAN:
            if (line == 1) {
                return "  GEWONNENE   ";
            } else if (line == 2) {
                return "    SPIELE    ";
            } else return "";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

char *lang_stat_win_rate(int line)
{
    /* Please mind that every string has to be exactly 15 chars long (including \0) */
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            if (line == 1) {
                return "     WIN-     ";
            } else if (line == 2) {
                return "     RATE     ";
            } else return "";
        case LANGUAGE_FRENCH:
            if (line == 1) {
                return "   TAUX DE    ";
            } else if (line == 2) {
                return "   REUSSITE   ";
            } else return "";
        case LANGUAGE_GERMAN:
            if (line == 1) {
                return "   GEWINN-    ";
            } else if (line == 2) {
                return "     RATE     ";
            } else return "";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

char *lang_stat_average_tries(int line)
{
    /* Please mind that every string has to be exactly 15 chars long (including \0) */
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            if (line == 1) {
                return "   AVERAGE    ";
            } else if (line == 2) {
                return "    TRIES     ";
            } else return "";
        case LANGUAGE_FRENCH:
            if (line == 1) {
                return "    ESSAIS    ";
            } else if (line == 2) {
                return "    MOYENS    ";
            } else return "";
        case LANGUAGE_GERMAN:
            if (line == 1) {
                return "DURCHSCHNITT- ";
            } else if (line == 2) {
                return "LICHE VERSUCHE";
            } else return "";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}

char *lang_please_restart_to_apply_changes()
{
    switch (gamelanguage) {
        case LANGUAGE_ENGLISH:
            return "    Please restart the game to apply changes.";
        case LANGUAGE_FRENCH:
            return "    Veuillez redemarrer le jeu pour appliquer les modifications.";
        case LANGUAGE_GERMAN:
            return "    Bitte starte das Spiel erneut, um die Aenderungen zu uebernehmen.";
        default:
            INVALID_LANGUAGE_ERROR();
    }
}
