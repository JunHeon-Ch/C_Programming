#include <stdio.h>
#include "Caculation.h"
#include "InfixToPostfix.h"

void main() {
	char exp[] = "((1-2)+3)*(5-2)";

	convToRPNExp(exp);
	puts(exp);

	printf("%d\n", caculation(exp));
}