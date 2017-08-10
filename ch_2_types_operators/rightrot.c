#include <stdio.h>
#include <math.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned getbits(unsigned x, int p, int n);
unsigned invert(unsigned x, int p, int n);
unsigned rot_right(unsigned x, int n);

int main() {
	unsigned int x = 617;
	printf("%d\n", rot_right(x, 2));
	return 0;
}

unsigned getbits(unsigned int x, int p, int n) {
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
	unsigned end = getbits(x, p - n, p - n + 1);
	unsigned start = x >> (p + 1);
	return ((start << n) | getbits(y, n - 1, n)) << (p - n + 1) | end;
}

unsigned invert(unsigned x, int p, int n) {
	unsigned updated_bits = ~getbits(x, p, n);
	return setbits(x, p, n, updated_bits);
}

unsigned rot_right(unsigned x, int n) {
	int length = (int)ceil(log2(x)) - 1;
	while (n-- > 0) {
		unsigned digit = x & 1;
		x = setbits(x >> 1, length, 1, digit);
	}
	return x;
}