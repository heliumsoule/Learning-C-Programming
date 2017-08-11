#include <stdio.h>
#include <stdlib.h>

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
		return stack[--sp];
	else {
		printf("empty stack\n");
		return 0;
	}
}

int main(int argc, char *argv[]) {
	int c;
	char *element;
	double op2;

	argv++;

	while (argc-- > 1) {
		element = argv[0];
		switch (c = *argv[0]) {
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				push(pop() / op2);
				break;
			default:
				push(atof(element));
				break;
		}
		argv++;
	}
	printf("The calculated value was %.8g\n", pop());
}

