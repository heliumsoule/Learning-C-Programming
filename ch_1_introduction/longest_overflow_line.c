#include <stdio.h>

#define MAXLINE 1000

int min(int a, int b);
int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0) {
		printf("\n\n\n%s%d", longest, max);
	}

	return 0;
}

int get_line(char s[], int lim) {
	int c, i;
	for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < lim - 1)
			s[i] = c;
	}
	if ((c == '\n') && i < lim - 1) {
		s[i] = c;
		++i;
	}
	s[min(i, lim - 1)] = '\0';
	return i;
}

void copy(char to[], char from[]) {
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0') 
		++i;
}

int min(int a, int b) {
	if (a <= b) {
		return a;
	} else {
		return b;
	}
}