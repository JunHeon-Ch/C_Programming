#include <string.h>
#include <ctype.h>
#include "ListStack.h"

int caculation(char exp[]) {
	Stack stack;
	int i, expLen = strlen(exp);
	char tok, op1, op2;

	StackInit(&stack);

	for (i = 0; i < expLen; i++) {
		tok = exp[i];
		if (isdigit(tok))
			SPush(&stack, tok - '0');
		else {
			op1 = SPop(&stack);
			op2 = SPop(&stack);
			switch (tok) {
			case '+':
				SPush(&stack, op2 + op1);
				break;
			case '-':
				SPush(&stack, op2 - op1);
				break;
			case '*':
				SPush(&stack, op2 * op1);
				break;
			case '/':
				SPush(&stack, op2 / op1);
				break;
			default:
				printf("Error\n");
				break;
			}
		}
	}

	return SPop(&stack);
}