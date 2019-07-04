#include <stdio.h>
int add(int, int);
int subtract(int, int);
int multiplication(int, int);
int division(int, int);
void output(int);
void main() {
	int n1, n2;
	char c;
	int(*func)(int, int) = NULL;

	scanf("%d %c %d", &n1, &c, &n2);

	switch (c) {
	case '+':
		func = add;
		break;
	case '-':
		func = subtract;
		break;
	case '*':
		func = multiplication;
		break;
	case '/':
		func = division;
		break;
	default:
		break;
	}

	output(func(n1, n2));
}

int add(int n1, int n2) {
	return n1 + n2;
}

int subtract(int n1, int n2) {
	return n1 - n2;
}

int multiplication(int n1, int n2) {
	return n1 * n2;
}

int division(int n1, int n2) {
	return n1 / n2;
}

void output(int result) {
	printf("%d\n", result);
}