#include <stdio.h>
#include "ArrayList.h"
void main() {
	int i;
	LData data = 0, sum = 0;
	List list;
	ListInit(&list);

	for (i = 1; i < 10; i++)
		LInsert(&list, i);

	if (LFirst(&list, &data)) {
		sum += data;
		while (LNext(&list, &data))
			sum += data;
		printf("sum = %d\n", sum);
	}

	if (LFirst(&list, &data)) {
		if (data % 2 == 0 || data % 3 == 0)
			printf("REMOVE: %d\n", LRemove(&list));
		while (LNext(&list, &data)) {
			if (data % 2 == 0 || data % 3 == 0)
				printf("REMOVE: %d\n", LRemove(&list));
		}
	}

	if (LFirst(&list, &data)) {
		printf("LIst -> %d ", data);
		while (LNext(&list, &data))
			printf("%d ", data);
		printf("\n");
	}
}