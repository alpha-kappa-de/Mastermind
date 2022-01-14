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
	int v[7];
	int i;
	generate_colorcode(v, 7);
	for (i = 0; i < 7; i++) {
		printf("%c\n", v[i]);
	}
	return 0;

}
