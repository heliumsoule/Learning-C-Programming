#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main() {
	unsigned int x = 1234;
	printf("%d\n", getbits(67, 3, 4));
	return 0;
}

unsigned getbits(unsigned int x, int p, int n) {
	return (x >> (p + 1 - n)) & ~(~0 << n);
}
