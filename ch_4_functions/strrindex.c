#include <stdio.h>

int strrindex(char s[], char t[]);

int main() {
	char s[] = "How are you doing today?";
	char t[] = "o";

	printf("Index was %d\n", strrindex(s, t));
	return 1;
}

int strrindex(char s[], char t[]) {
	int i, j, k;

	int best_index = -1;

	for(i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
		if (k > 0 && t[k] == '\0')
			best_index = i;
	}
	return best_index;
}