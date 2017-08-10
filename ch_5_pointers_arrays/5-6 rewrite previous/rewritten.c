#include <stdio.h>

void reverse(char *s);

int main() {
	char s[] = "change is possible";
	printf("%s\n", s);
	reverse(s);
	printf("%s\n", s);

	return 0;
}

void reverse(char *s) {
	char c;
	char *p = s;
	while (*p)
		p++;
	p--;
	while (s <= p) {
		c = *s;
		*s++ = *p;
		*p-- = c;
	}
}

