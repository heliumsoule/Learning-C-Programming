#include <stdio.h>

#define IN 	1
#define OUT	0

int main() {
	int c, n_lines, n_words, n_char, state;
	state = OUT;
	n_lines = n_words = n_char = 0;
	while ((c = getchar()) != EOF) {
		++n_char;
		if (c == '\n')
			++n_lines;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++n_words;
		}
	}
	printf("%d %d %d\n", n_char, n_words, n_lines);
	return 0;
}