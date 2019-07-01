#include <stdio.h>
#include "ArrayStack.h"

void main() {
	Stack stack;
	Data data;
	StackInit(&stack);

	while (1) {
		scanf("%d", &data);
		if (data < 1)
			break;

		SPush(&stack, data);
	}

	while (SEmpty(&stack) != TRUE)
		printf("%d ", SPop(&stack));
}