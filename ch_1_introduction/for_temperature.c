#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

int main() {
	for(int fahr = LOWER; fahr <= UPPER; fahr += STEP) {
		printf("%3d %6.1f\n", fahr, (fahr - 32.0) * 5 / 9);
	}
	return 0;
}