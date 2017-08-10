#include <stdio.h>
#include <time.h>
#include <math.h>

int n_one_bits(unsigned n);
int n_one_bits_slow(unsigned n);

int main() {

	clock_t start, end;
	double cpu_time_used;
	int n = (int)pow(2, 62) - 241;

	start = clock();
	n_one_bits(n);
	end = clock();
	printf("Best is %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
	
	start = clock();
	n_one_bits_slow(n);
	end = clock();
	printf("Reg is %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
	return 0;
}

int n_one_bits(unsigned n) {
	int b;
	for (b = 0; n != 0; n &= n - 1) {
		b++;
	}
	return b;
}

int n_one_bits_slow(unsigned n) {
	int b;
	for (b = 0; n != 0; n >>= 1) {
		if (n & 01) 
			b++;
	}
	return b;
}