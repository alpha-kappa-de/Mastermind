#include "mastermind.h"

int main()
{
    gamelanguage = LANGUAGE_ENGLISH;
    printf("test in english\n");
    printf("full names:\t\t %i, %i, %i, %i, %i, %i, %i, %i\n", lang_color_name_to_number("blue"), lang_color_name_to_number("red"), lang_color_name_to_number("yellow"), lang_color_name_to_number("green"), lang_color_name_to_number("purple"), lang_color_name_to_number("brown"), lang_color_name_to_number("orange"), lang_color_name_to_number("cyan"));
    printf("short names:\t\t %i, %i, %i, %i, %i, %i, %i, %i\n", lang_color_name_to_number("bl"), lang_color_name_to_number("re"), lang_color_name_to_number("ye"), lang_color_name_to_number("gr"), lang_color_name_to_number("pu"), lang_color_name_to_number("br"), lang_color_name_to_number("or"), lang_color_name_to_number("cy"));
    printf("crap:\t\t\t %i, %i, %i, %i, %i, %i, %i, %i", lang_color_name_to_number("blueblue"), lang_color_name_to_number("bleu"), lang_color_name_to_number("blau"), lang_color_name_to_number("1"), lang_color_name_to_number("ve"), lang_color_name_to_number("b"), lang_color_name_to_number("grgr"), lang_color_name_to_number(""));

    gamelanguage = LANGUAGE_FRENCH;
    printf("\n\ntest in french\n");
    printf("full names:\t\t %i, %i, %i, %i, %i, %i, %i, %i\n", lang_color_name_to_number("bleu"), lang_color_name_to_number("rouge"), lang_color_name_to_number("jaune"), lang_color_name_to_number("vert"), lang_color_name_to_number("mauve"), lang_color_name_to_number("brun"), lang_color_name_to_number("orange"), lang_color_name_to_number("cyan"));
    printf("short names:\t\t %i, %i, %i, %i, %i, %i, %i, %i\n", lang_color_name_to_number("bl"), lang_color_name_to_number("ro"), lang_color_name_to_number("ja"), lang_color_name_to_number("ve"), lang_color_name_to_number("ma"), lang_color_name_to_number("br"), lang_color_name_to_number("or"), lang_color_name_to_number("cy"));
    printf("crap:\t\t\t %i, %i, %i, %i, %i, %i, %i, %i", lang_color_name_to_number("blueblue"), lang_color_name_to_number("\n"), lang_color_name_to_number("blau"), lang_color_name_to_number("1"), lang_color_name_to_number("\tve"), lang_color_name_to_number("ve\n"), lang_color_name_to_number("ve\t"), lang_color_name_to_number(""));


    gamelanguage = LANGUAGE_GERMAN;
    printf("\n\ntest in german\n");
    printf("full names:\t\t %i, %i, %i, %i, %i, %i, %i, %i\n", lang_color_name_to_number("blau"), lang_color_name_to_number("rot"), lang_color_name_to_number("gelb"), lang_color_name_to_number("gruen"), lang_color_name_to_number("lila"), lang_color_name_to_number("braun"), lang_color_name_to_number("orange"), lang_color_name_to_number("cyan"));
    printf("short names:\t\t %i, %i, %i, %i, %i, %i, %i, %i\n", lang_color_name_to_number("bl"), lang_color_name_to_number("ro"), lang_color_name_to_number("ge"), lang_color_name_to_number("gr"), lang_color_name_to_number("li"), lang_color_name_to_number("br"), lang_color_name_to_number("or"), lang_color_name_to_number("cy"));
    printf("crap:\t\t\t %i, %i, %i, %i, %i, %i, %i, %i", lang_color_name_to_number("blueblue"), lang_color_name_to_number("bleu"), lang_color_name_to_number("\n"), lang_color_name_to_number("1"), lang_color_name_to_number("ve"), lang_color_name_to_number("b"), lang_color_name_to_number("grgr"), lang_color_name_to_number(""));


    exit(-1);
}