#include "mastermind.h"


int number_of_guesses = 4;


int main(){
	int i,c;
	static int b = 0;
	int *color_guess = malloc((number_of_guesses + 1) * sizeof(int));
	for (i = 0 ; i < number_of_guesses; i++){
		*(color_guess + i) = getchar();
		switch(*(color_guess+i)){
			case 48 : *(color_guess+i) = BLUE; break;
			case 49 : *(color_guess+i) = RED; break;
			case 50 : *(color_guess+i) = YELLOW; break;
			case 51 : *(color_guess+i) = GREEN; break;
			case 52 : *(color_guess+i) = PURPLE; break;
			case 53 : *(color_guess+i) = BROWN; break;
			default : printf("Please enter your choice of colors correctly, for example : 2431"); return 0;
		}
	}
	while ((c = getchar ()) != '\n' && c != EOF ){
		if (b == 0){
			printf("Your input was to long, please enter %i numbers",number_of_guesses);
			++b;
		}
	}
	if (b == 1){
		return 0;
	}
	for (i = 0 ; i < number_of_guesses; i++){
	printf("|%i",*(color_guess+i));
	if ((i + 1) == number_of_guesses){
		printf("|");
	}
	}
	free(color_guess);
	return 0;
}
