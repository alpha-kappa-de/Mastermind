#include "mastermind.h"


void generate_colorcode(int *colorcode, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		colorcode[i] = random_num(COLORS);
	}
}

int main()
{
	int v[COLORS];
	int i;
	generate_colorcode(v, COLORS);
	for (i = 0; i < COLORS; i++) {
		printf("%c\n", v[i]);
	}
	return 0;

}
