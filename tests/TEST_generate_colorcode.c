#include "mastermind.h"


void generate_colorcode(int *colorcode, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		colorcode[i] = generate_random_color();
	}
}

int main()
{
	int v[COLORS];
	int i;
	generate_colorcode(v);
	for (i = 0; i < COLORS; i++) {
		printf("%c\n", v[i]);
	}
	return 0;

}
