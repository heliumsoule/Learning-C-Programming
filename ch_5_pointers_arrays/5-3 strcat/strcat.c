#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strcat_pointer(char *s, char *t);

int main() {
	char s[50] = "change ";
	char *t = "can happen";
	strcat_pointer(s, t);
	printf("%s\n", s);
	return 1;
}

void strcat_pointer(char *s, char *t) {
	char *start = s;
	while (*s)
		s++;
	while ((*s++ = *t++));
	s = start;
}