#include <stdio.h>

#define TOTNOCHARS 128

int main() {
	int character[TOTNOCHARS];
	int c;
	for (int i = 0; i < TOTNOCHARS; i++)
		character[i] = 0;
	while ((c = getchar()) != EOF)
		++character[c];
	for (int i = 0; i < TOTNOCHARS; i++) {
		putchar(i);
		for (int j = 0; j < character[i]; j++)
			putchar('*');
		putchar('\n');
	}

	return 0;
}