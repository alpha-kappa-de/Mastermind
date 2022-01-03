#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int number_of_guesses = 4;



int main() {
	char color_input1[7], color_input2[7], color_input3[7], color_input4[7];
	int i;
	char color_input = color_input1;

	int *color_guess_int = malloc((number_of_guesses + 1) * sizeof(int));

	scanf("%s,%s,%s,%s\n",color_input1,color_input2,color_input3,color_input4);

	for(i = 0; i < number_of_guesses; i++){

		switch (i){
			case 0:
				color_input = color_input1;
				break;
			case 1:
				color_input = color_input2;
				break;
			case 2:
				color_input = color_input3;
				break;
			case 3:
				color_input = color_input4;
				break;
			}

		switch (gamelanguage){
			case LANGUAGE_GERMAN:
				if (strcmp(color_input,"blau") == 0){
					*(color_guess_int + i) = BLUE;
					break;
				}
				if (strcmp(color_input,"rot") == 0){
					*(color_guess_int + i) = RED;
					break;
				}
				if (strcmp(color_input,"gelb") == 0){
					*(color_guess_int + i) = YELLOW;
					break;
				}
				if (strcmp(color_input,"gruen") == 0){
					*(color_guess_int + i) = GREEN;
					break;
				}
				if (strcmp(color_input,"lila") == 0){
					*(color_guess_int + i) = PURPLE;
					break;
				}
				if (strcmp(color_input,"braun") == 0){
					*(color_guess_int + i) = BROWN;
					break;
				}else {
					printf("typo");
				}
			case LANGUAGE_ENGLISH:
				if (strcmp(color_input,"blue") == 0){
					*(color_guess_int + i) = BLUE;
					break;
				}
				if (strcmp(color_input,"red") == 0){
					*(color_guess_int + i) = RED;
					break;
				}
				if (strcmp(color_input,"yellow") == 0){
					*(color_guess_int + i) = YELLOW;
					break;
				}
				if (strcmp(color_input,"green") == 0){
					*(color_guess_int + i) = GREEN;
					break;
				}
				if (strcmp(color_input,"purple") == 0){
					*(color_guess_int + i) = PURPLE;
					break;
				}
				if (strcmp(color_input,"brown") == 0){
					*(color_guess_int + i) = BROWN;
					break;
				}else {
					printf("typo");
				}
			case LANGUAGE_FRENCH:
				if (strcmp(color_input,"bleu") == 0){
					*(color_guess_int + i) = BLUE;
					break;
				}
				if (strcmp(color_input,"rouge") == 0){
					*(color_guess_int + i) = RED;
					break;
				}
				if (strcmp(color_input,"jaune") == 0){
					*(color_guess_int + i) = YELLOW;
					break;
				}
				if (strcmp(color_input,"vert") == 0){
					*(color_guess_int + i) = GREEN;
					break;
				}
				if (strcmp(color_input,"mauve") == 0){
					*(color_guess_int + i) = PURPLE;
					break;
				}
				if (strcmp(color_input,"brun") == 0){
					*(color_guess_int + i) = BROWN;
					break;
				}else {
					printf("typo");
				}
			}

		}
	return 0;
}
