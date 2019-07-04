#include <stdio.h>
#include "사칙연산.h"
void main() {
	double n1, n2, result = 0;
	char c;

	scanf("%lf %c %lf", &n1, &c, &n2);

	switch (c) {
	case '+':
		result = sum(n1, n2);
		printf("%lf %c %lf = %lf\n", n1, c, n2, result);
		break;
	case '-':
		result = supplication(n1, n2);
		printf("%lf %c %lf = %lf\n", n1, c, n2, result);
		break;
	case '*':
		result = multiplication(n1, n2);
		printf("%lf %c %lf = %lf\n", n1, c, n2, result);
		break;
	case '/':
		if (n2 != 0) {
			result = division(n1, n2);
			printf("%lf %c %lf = %lf\n", n1, c, n2, result);
		}
		else
			printf("error\n");
		break;
	default:
		printf("메롱\n");
		break;
	}
}