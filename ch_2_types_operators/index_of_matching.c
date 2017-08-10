#include <stdio.h>

int index_matching(char s[], char search[]);

int main() {
	char s[] = "Today I am learning C";
	char search[] = "T";
	int position = index_matching(s, search);
	printf("%d\n", position);
}

int index_matching(char s[], char search[]) {
	int i, index;
	index = -1;

	for (i = 0; s[i] != '\0'; i++) {
		for (int k = 0; search[k] != '\0'; k++) {
			if (s[i] == search[k]) {
				index = i;
				goto end;
			}
		}
	}
	end:
	return index;
}