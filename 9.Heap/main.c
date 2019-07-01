#include <stdio.h>
#include "Heap.h"

int DataPriorityComp(HData, HData);

void main() {
	Heap heap;
	HeapInit(&heap, DataPriorityComp);

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c\n", HDelete(&heap));

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c\n", HDelete(&heap));

	while(!HIsEmpty(&heap))
		printf("%c\n", HDelete(&heap));
}

int DataPriorityComp(HData d1, HData d2) {
	return d2 - d1;
}