#include <stdio.h>

#define MAXLINE 1000

int reverse_line(char line[], int lim);

int main() {
	char line[MAXLINE];
	while (reverse_line(line, MAXLINE)) {}

	return 0;
}

int reverse_line(char line[], int lim) {
	int c, i, len;
	for (i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i] = c;
	}
	len = i;
	while (i > 0) 
		putchar(line[--i]);
	if (len > 0) 
		putchar('\n');
	return len;
}