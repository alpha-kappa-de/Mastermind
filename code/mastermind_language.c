#include "mastermind_language.h"
#include "mastermind.h"

char *lang_color_name(int color)
{
    if (gamelanguage == LANGUAGE_GERMAN) {
        switch (color) {
        case BLUE:
            return "Blau";
            break;

        case RED:
            return "Rot";
            break;

        case YELLOW:
            return "Gelb";
            break;

        case GREEN:
            return "Gruen";
            break;

        case PURPLE:
            return "Lila";
            break;

        case BROWN:
            return "Braun";
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
    return NULL;
}

char *lang_you_typed()
{
    switch (gamelanguage) {
    case LANGUAGE_ENGLISH:
        return "You typed";
        break;

    case LANGUAGE_FRENCH:
        return "Votre entree";
        break;

    case LANGUAGE_GERMAN:
        return "Deine Eingabe";
        break;

    default:
        break;
    }
    
    return NULL;
}

char *lang_correct_pins()
{
    switch (gamelanguage) {
    case LANGUAGE_ENGLISH:
        return "Correct pins";
        break;

    case LANGUAGE_FRENCH:
        return "Stylos corrects";
        break;

    case LANGUAGE_GERMAN:
        return "Richtige Stifte";
        break;

    default:
        break;
    }
    return NULL;
}

char *lang_correct_colors()
{
    switch (gamelanguage) {
    case LANGUAGE_ENGLISH:
        return "Correct colors";
        break;

    case LANGUAGE_FRENCH:
        return "Couleurs correctes";
        break;

    case LANGUAGE_GERMAN:
        return "Richtige Farbe";
        break;

    default:
        break;
    }
    return NULL;
}

char *lang_type_your_guess()
{
    switch (gamelanguage) {
    case LANGUAGE_ENGLISH:
        return "Guess the colorcode";
        break;

    case LANGUAGE_FRENCH:
        return "Devinez le code couleur";
        break;

    case LANGUAGE_GERMAN:
        return "Errate den Farbcode";
        break;

    default:
        break;
    }
    return NULL;
}