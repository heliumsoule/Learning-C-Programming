#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int max);
void escape(char s[], char t[]);

int main() {
	char s[MAXLINE], t[MAXLINE];
	get_line(t, MAXLINE);

	escape(s, t);
	printf("%s\n", s);

	return 0;
}

void escape(char s[], char t[]) {
	int i, j;

	i = j = 0;

	while(t[i] != '\0') {
		switch(t[i]) {
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			default:
				s[j++] = t[i];
				break;
		}
		++i;
	}
}

int get_line(char s[], int max) {
	int i, c;
	for (i = 0; i < max - 1 && (c = getchar()) != EOF; i++)
		s[i] = c;
	s[i] = '\0';
	return i;
}