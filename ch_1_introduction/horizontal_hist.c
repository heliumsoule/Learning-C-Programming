#include <stdio.h>

int main() {
	int c;
	while ((c = getchar()) != EOF) {
		if (c == '\n' || c == ' ' || c == '\n') {
			putchar('\n');
		} else {
			putchar('*');
		}
	}
	return 0;
}