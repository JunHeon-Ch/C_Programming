#include <stdio.h>
#include "DLinkedList.h"

void main() {
	List list;
	Data rData;

	ListInit(&list);

	while (1) {
		scanf("%d", &rData);
		if (rData < 1)
			break;

		LInsert(&list, rData);
	}

	if (LFirst(&list, &rData) == TRUE) {
		printf("%d ", rData);
		while (LNext(&list, &rData) == TRUE)
			printf("%d ", rData);
		while (LPrevious(&list, &rData) == TRUE)
			printf("%d ", rData);
	}
	printf("\n\n");

	if (LFirst(&list, &rData) == TRUE) {
		if (rData % 2 == 0)
			LRemove(&list);
		while (LNext(&list, &rData) == TRUE) {
			if (rData % 2 == 0)
				LRemove(&list);
		}
	}

	if (LFirst(&list, &rData) == TRUE) {
		printf("%d ", rData);
		while (LNext(&list, &rData) == TRUE)
			printf("%d ", rData);
	}
	printf("\n\n");

	LFree(&list);
}