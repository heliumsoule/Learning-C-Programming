#include <stdio.h>

#define MINLENGTH 10

int get_line(char s[], int min);

int main() {
	char line[MINLENGTH];
	while (get_line(line, MINLENGTH) > 0) {}
	return 0;
}

int get_line(char s[], int min) {
	int c, i, j;
	for (i = 0; ((c = getchar()) != EOF && c != '\n'); ++i) {
		if (i < min)
			s[i] = c; 
		if (i == min - 1) {
			for (j = 0; j < min - 1; ++j)
				putchar(s[j]);
		} 
		if (i >= min - 1)
			putchar(c);
	}
	if (i >= min)
		putchar('\n');
	return i;
}