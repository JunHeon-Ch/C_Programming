#include <stdio.h>
#include "Deque.h"

void main() {
	Deque deque;
	Data rData;
	int add, rem;

	DequeInit(&deque);

	while (1) {
		scanf("%d", &add);
		if (add == 0) {
			break;
		}
		scanf("%d", &rData);
		if (add == 1)
			DQAddFirst(&deque, rData);
		else if (add == 2)
			DQAddLast(&deque, rData);
	}

	while (DQIsEmpty(&deque) != TRUE) {
		scanf("%d", &rem);
		if (rem == 1)
			printf("%d\n", DQRemoveFirst(&deque));
		else if (rem == 2)
			printf("%d\n", DQRemoveLast(&deque));
	}
}