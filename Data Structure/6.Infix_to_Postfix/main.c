#include <stdio.h>
#include "InfixToPostfix.h"

void main() {
	char exp[] = "((1-2)+3)*(5-2)";

	convToRPNExp(exp);

	puts(exp);
}