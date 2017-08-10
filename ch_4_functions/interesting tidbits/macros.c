#include <stdio.h>

#define iprint(expr) printf(#expr " = %d\n", expr)
#define dprint(expr) printf(#expr " = %g\n", expr)
#define paste(front, back) front ## back

int main() {

	dprint(124.0 / 7);
	int paste(name, 1) = 4;
	iprint(name1);

	return 0;
}