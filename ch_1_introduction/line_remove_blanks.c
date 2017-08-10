#include <stdio.h>

// Doesn't work for the trailing blank or space next to the final character.

int remove_blanks();

int main() {
	while(remove_blanks()) {}
	return 0;
}

int remove_blanks() {
	int previous_c, c;
	previous_c = '_';
	while ((c = getchar()) != EOF && c != '\n') {
		if (!(c == '\t' && previous_c == '\t') && 
			!(c == ' ' && previous_c == ' ')) {
			putchar(c);
		}
		previous_c = c;
	}
	if (c == EOF) {
		return 0;
	} else {
		putchar('\n');
		return 1;
	}
}