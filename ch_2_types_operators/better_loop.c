#include <stdio.h>

#define MAXLINE 1000
 
int main() {
	int c;
	int lim = MAXLINE;
	for (int i = 0; i < lim - 1; i++) {
		c = getchar();
		if (c == '\n')
			break;
		if (c == EOF)
			break;
	}
	return 0;
}