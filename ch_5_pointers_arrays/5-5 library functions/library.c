#include <stdio.h>

void strncpy_pointer(char *s, char *t, int n);
void strncat_pointer(char *s, char *t, int n);
int strcmp_pointer(char *s, char *t);

int main() {
	char s[50] = "obsession";
	char *t = " is a prereq :)";
	char *u = "being obsessed is a prereq";
	int n = 12;
	int o = 30;

	char *a = "This is Jing";
	char *b = "This is Alisa";

	strncat_pointer(s, t, n);
	printf("strncat created %s\n", s);
	
	strncpy_pointer(s, u, o);
	printf("\nstrncpy created %s\n", s);

	printf("\n%s\ncompared with\n%s\n%d\n", 
			a, 
			b, 
			strcmp_pointer(a, b));

	return 1;
}

void strncat_pointer(char *s, char *t, int n) {
	while (*s)
		s++;
	while (n-- && *t)
		*s++ = *t++;
}

void strncpy_pointer(char *s, char *t, int n) {
	while (n-- && *t)
		*s++ = *t++;
}

int strcmp_pointer(char *s, char *t) {
	for (; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}



