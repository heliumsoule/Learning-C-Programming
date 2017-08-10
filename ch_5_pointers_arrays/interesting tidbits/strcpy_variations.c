#include <stdio.h>

void strcpy_first(char *s, char *t);
void strcpy_pointer(char *s, char *t);

int main() {
	char s[50] = "I am irresponsible";
	char t[] = "I will be more responsible";
	strcpy_pointer(s, t);
	printf("%s\n", s);
	return 0;
}

void strcpy_first(char *s, char *t) {
	int i;
	i = 0;
	while ((s[i] = t[i]) != '\0')
		i++;
}

// void strcpy_pointer(char *s, char *t) {
// 	while ((*s = *t) != '\0') {
// 		s++;
// 		t++;
// 	}
// }

// void strcpy_pointer(char *s, char *t) {
// 	while ((*s++ = *t++) != '\0')
// }

void strcpy_pointer(char *s, char *t) {
	while ((*s++ = *t++));
}