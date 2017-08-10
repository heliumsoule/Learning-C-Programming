#include <stdio.h>
#include <math.h>
#include <assert.h>

#define NELEMENTS(x) (sizeof(x) / sizeof(x[0]))
#define HEX_PREFIX(x) (x[0] == '0' && (x[1] == 'x' || x[1] == 'X'))
#define HEX 16
#define DEC 10

int htoi(char s[], int length, int prefix);

int main() {
	char simple[] = "0xF";
	char simple_wout_prefix[] = "0xF";
	char difficult[] = "0xF42";
	assert(htoi(simple, (int)NELEMENTS(simple) - 1, HEX_PREFIX(simple)) == 15);
	assert(htoi(simple_wout_prefix, (int)NELEMENTS(simple_wout_prefix) - 1, HEX_PREFIX(simple_wout_prefix)) == 15);
	assert(htoi(difficult, (int)NELEMENTS(difficult) - 1, HEX_PREFIX(difficult)) == 3906);
	return 0;
}

int htoi(char hex_digits[], int length, int prefix) {
	int output, c, power, lower_bound;
	output = 0;
	lower_bound = prefix ? 1 : -1;

	for (int i = length - 1; i > lower_bound; i--) {
		c = hex_digits[i];
		power = length - i - 1;
		if (c >= '0' && c <= '9')
			output += (c - '0') * (int)pow(HEX, power);
		if (c >= 'a' && c <= 'z')
			output += ((c - 'a') + DEC) * (int)pow(HEX, power);
		if (c >= 'A' && c <= 'Z') {
			output += ((c - 'A') + DEC) * (int)pow(HEX, power);
		}
	}
	return output;
}