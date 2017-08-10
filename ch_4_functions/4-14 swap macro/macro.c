#include <stdio.h>

#define IPRINT(expr) printf(#expr " = %d\n", expr)
#define SWAP(t, x, y) t temp = x; x = y; y = temp;

int main() {

	int x = 4;
	int y = 6;

	IPRINT(x);
	IPRINT(y);
	SWAP(int, x, y);
	IPRINT(x);
	IPRINT(y);

	return 0;
}