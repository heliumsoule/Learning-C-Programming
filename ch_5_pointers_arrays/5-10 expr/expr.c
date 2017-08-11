#include <stdio.h>

#define ELEMENTS 500

static int sp = 0;
static double stack[ELEMENTS];

void push(double);
double pop(void);

void push(double f) {
	if (sp < ELEMENTS)
		stack[sp++] = f;
	else 
		printf("no space on stack\n");
}

double pop(void) {
	if (sp > 0)
		return stack[sp--];
	else {
		printf("empty stack\n");
		return 0;
	}
}

int main(int argc, char *argv[]) {

	while (--argc > 0) {

	}
}

