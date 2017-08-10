#include <stdio.h>

int strlen_pointer(char *s);
int strlen_two_pointers(char *s);

int main() {
	char *s = "I'm different now";
	printf("The length is %d\n", strlen_pointer(s));
	printf("The length is %d\n", strlen_two_pointers(s));
	return 0;
}

int strlen_pointer(char *s) {
	int n;
	for (n = 0; *s != '\0'; s++)
		n++;
	return n;
}

int strlen_two_pointers(char *s) {
	char *p = s;
	while (*p != '\0')
		p++;
	return p - s;
}