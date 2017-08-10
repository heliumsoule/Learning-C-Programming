#include <stdio.h>

int main() {
	int c, previous_c;
	previous_c = '-';

	while((c = getchar()) != EOF) {
		if ((c == ' ' && previous_c != ' ') || c != ' ') {
			putchar(c);
		}
		previous_c = c;
	}
	return 0;
}