#include <stdio.h>
#include <math.h>
#include <string.h>

#define LENGTH 120
char s[LENGTH];

void itoa(int n);
void itoa_helper(long n, int index);
void reverse(char s[], int start);

int main() {

	int n_positive = -1724;
	// int n_negative = -pow(2, 31);

	itoa(n_positive);
	// printf("The string is %s\n", s);
	// itoa(n_negative);
	printf("The string is %s\n", s);

	return 0;
}

void itoa(int n) {
	itoa_helper((long)n, 0);
	int start = n >= 0 ? 0 : 1;
	reverse(s, start);
}

void itoa_helper(long n, int index) {
	if (n < 0) {
		s[index++] = '-';
		n = -n;
	}
	if (n) {
		s[index++] = (int)n % 10 + '0';
		itoa_helper(n / 10, index);
	}
	else {
		s[index] = '\0';
		return;
	}
}

void reverse(char s[], int start)
{
    int length = strlen(s);
    int c, i, j;

    for (i = start, j = length - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}







