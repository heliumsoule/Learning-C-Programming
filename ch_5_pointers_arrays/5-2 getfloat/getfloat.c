#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define BUFSIZE 100
#define SIZE 100

int getch(void);
void ungetch(int c);
double getfloat(double *pn);

char buf[BUFSIZE];
int bufp = 0;

int main() {
	int n; 
	double array[SIZE];

	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++) {
		printf("The stored element %.2f\n", array[n]);
	}
	return 0;
}

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many characters\n");
	} else {
		buf[bufp++] = c;
	}
}

double getfloat(double *pn) {
	int index, c, sign;

	while (isspace(c = getch()));
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	if (c == '.')
		c = getch();
	for (index = -1; isdigit(c); c = getch(), index--)
		*pn += (double)(c - '0') * pow(10, index);
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}