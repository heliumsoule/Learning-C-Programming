#include <stdio.h>

int strend(char *s, char *t);

int main() {
	char *s = "change can happen";
	char *t = "happen";
	int end = strend(s, t);
	printf("%s\nended in\n%s\n%d\n", s, t, end);
	return 0;
}

int strend(char *s, char *t) {
	char *t_start = t;
	while (*s)
		s++;
	while (*t)
		t++;
	while ((t != t_start) && (*--s == *--t));
	return t_start == t ? 1 : 0;
}
