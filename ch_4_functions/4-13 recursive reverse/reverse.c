#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void reverse_helper(char s[], int index);

int main() {

	char s[] = "Hello";
	printf("The original string %s\n", s);
	reverse(s);
	printf("The reversed string %s\n", s);

	return 0;
}

void reverse(char s[]) {
	reverse_helper(s, 0);
}

void reverse_helper(char s[], int index) {
	int length = strlen(s) - 1;
	int midpoint = length / 2;
	if (index < midpoint) {
		char temp = s[index];
		s[index] = s[length - index];
		s[length - index] = temp;

		reverse_helper(s, ++index);
	}  

}