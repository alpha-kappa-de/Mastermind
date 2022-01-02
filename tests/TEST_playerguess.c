#include "mastermind.h"

int flush_buff(void);

int main(int argc, char const *argv[])
{
	return 0;
}


int let_player_guess()
{
	int i;
	int guess[4];
		
	for (i = 0 ; i < 4; i++) {
		guess[i] = getchar();
		
		switch(guess[i]) {
			case 48 : 
				guess[i] = BLUE; 
				break;
			case 49 : 
				guess[i] = RED; 
				break;
			case 50 : 
				guess[i] = YELLOW; 
				break;
			case 51 : 
				guess[i] = GREEN; 
				break;
			case 52 : 
				guess[i] = PURPLE; 
				break;
			case 53 : 
				guess[i] = BROWN; 
				break;
			default : 
				printf("please enter a valid Number");
				return 0;
		}
	}

	printf("%i,%i,%i,%i", guess[0], guess[1], guess[2], guess[3]);
	return 0;
}
