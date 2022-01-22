#include "mastermind.h"

int main(void)
{

	player1_starttime = time(NULL);
	getchar();
	printf("Du spielst schon %i sekunden!\n", ((int)time(NULL) - player1_starttime));
	return 0;
}
