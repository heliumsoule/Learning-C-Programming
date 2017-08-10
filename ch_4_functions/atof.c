#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]);

int main() {

	printf("Testing Double %f\n", atof("127.23"));
	printf("Testing Positive Scientific Double %f\n", atof("127.23e4"));
	printf("Testing Negative Scientific Double %f\n", atof("127.23e-2"));
	return 0;
}

double atof(char s[]) {
	double val, power, scientific;
	int i, sign, scientific_sign;

	for (i = 0; isspace(s[i]); i++);
	sign = (s[i]) == '-' ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	if (s[i] == '\0')
		return sign * val / power;
	else {
		scientific_sign = (s[++i]) == '-' ? -1 : 1;
		if (scientific_sign == -1) 
			i++;
		for (scientific = 0; isdigit(s[i]); i++)
			scientific = scientific * 10 + (s[i] - '0');
		return sign * val / power * pow(10, scientific_sign * scientific);
	}
}