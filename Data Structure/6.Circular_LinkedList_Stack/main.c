#include <stdio.h>
#include "CListStack.h"

void main() {
	Stack stack;
	Data rData;

	StackInit(&stack);

	while (1) {
		scanf("%d", &rData);
		if (rData < 1) {
			break;
		}

		SPush(&stack, rData);
	}

	while (SEmpty(&stack) != TRUE)
		printf("%d ", SPop(&stack));

	SFree(&stack);
}