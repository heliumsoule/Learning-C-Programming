#include <stdio.h>

#define DASH '-'
#define MAXLINE 1000
#define NELEMENTS(x) (sizeof(x) / sizeof(x[0]))

void expand(char start[], int len, char end[]);
void expand_char(char s[], int index, char first, char second);

int main() {
	char start[MAXLINE] = "a-z0-9";
	char end[MAXLINE];

	expand(start, (int)NELEMENTS(start) - 1, end);
	printf("%s\n", end);
}

void expand(char start[], int len, char end[]) {
	int i, j;
	int c;

	for (i = 0, j = 0; i < len; i++) {
		c = start[i];
		if (c == DASH) {
			if (i == 0 || i == len - 1)
				end[j++] = c;
			else {
				expand_char(end, j, start[i - 1], start[i + 1]);
				j += start[i + 1] - start[i - 1] + 1;
			}
		}
	}
}

void expand_char(char s[], int index, char first, char second) {
	int i;
	for (i = 0; i < second - first + 1; i++) {
		s[index++] = first + i;
	}
}


