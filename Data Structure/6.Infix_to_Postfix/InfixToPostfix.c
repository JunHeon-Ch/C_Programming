#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListStack.h"

int GetOpPrec(char op) {
	switch (op) {
	case '*':case'/':
		return 3;
	case '+':case'-':
		return 2;
	case '(':
		return 1;
	}
	return -1;
}

int WhoPrecOp(char op1, char op2) {
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

void convToRPNExp(char exp[]) {
	int i, index = 0, expLen = strlen(exp);
	char* convExp = (char*)malloc(sizeof(char) * (expLen + 1));
	char popOp;
	Stack stack;

	memset(convExp, 0, sizeof(char) * (expLen + 1));
	StackInit(&stack);

	for (i = 0; i < expLen; i++) {
		if (isdigit(exp[i]))
			convExp[index++] = exp[i];
		else {
			switch (exp[i]) {
			case '(':
				SPush(&stack, exp[i]);
				break;
			case ')':
				while (1) {
					popOp = SPop(&stack);
					if (popOp == '(')
						break;
					convExp[index++] = popOp;
				}
				break;
			case '+': case'-':
			case '*': case'/':
				while (SEmpty(&stack) != TRUE && WhoPrecOp(SPeek(&stack), exp[i]) >= 0)
					convExp[index++] = SPop(&stack);

				SPush(&stack, exp[i]);
				break;
			default:
				printf("Error\n");
				break;
			}
		}
	}
	while (SEmpty(&stack) != TRUE)
		convExp[index++] = SPop(&stack);

	strcpy(exp, convExp);
	free(convExp);
}