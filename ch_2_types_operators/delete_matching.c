#include <stdio.h>

void squeeze(char s[], char remove[]);

int main() {
	char s[] = "Today I am learning C";
	char remove[] = "an";
	squeeze(s, remove);
	printf("%s\n", s);
}

void squeeze(char s[], char remove[]) {
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++) {
		int any_match = 0;
		for (int k = 0; remove[k] != '\0'; k++) {
			if (s[i] == remove[k])
				any_match = 1;
		}
		if (!any_match)
			s[j++] = s[i];
	}
	s[j] = '\0';
}