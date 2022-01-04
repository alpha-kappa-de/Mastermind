#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "mastermind.h"


int main(){
	int i;
	char *player_guess_char = malloc((colorcode_length) * 8 * sizeof(char));
	tolower(scanf("%s",player_guess_char));
	player_guess[0] = lang_color_name_to_number(strtok(player_guess_char,","));
	for( i = 1 ; i < colorcode_length; ++i){
		printf("%i",player_guess[i]);
		player_guess[i] = lang_color_name_to_number(strtok(NULL,","));
	}
	free(player_guess_char);
	return 0;
}
