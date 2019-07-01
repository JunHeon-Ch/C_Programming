#include <stdio.h>
#include "ArrayStack.h"

void StackInit(Stack* pStack) {
	pStack->topIndex = -1;
}

int SEmpty(Stack* pStack) {
	if (pStack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pStack, Data data) {
	pStack->stack[++(pStack->topIndex)] = data;
}

Data SPop(Stack* pStack) {
	if (SEmpty(pStack) == TRUE)
		exit(-1);
	return pStack->stack[(pStack->topIndex)--];
}

Data SPeek(Stack* pStack) {
	if (SEmpty(pStack) == TRUE)
		exit(-1);
	return pStack->stack[pStack->topIndex];
}
