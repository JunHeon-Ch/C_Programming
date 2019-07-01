#include <stdio.h>
#include "Heap.h"

void HeapSort(HData[], int, PriorityComp);
int PriComp(HData, HData);

void main() {
	HData arr[5];
	int i;

	for (i = 0; i < 5; i++)
		scanf("%d", &arr[i]);

	HeapSort(arr, 5, PriComp);

	for (i = 0; i < 5; i++)
		printf("%d ", arr[i]);
}

int PriComp(HData d1, HData d2) {
	return d2 - d1;
}

void HeapSort(HData arr[], int arrLen, PriorityComp comp) {
	Heap heap;
	int i;

	HeapInit(&heap, comp);

	for (i = 0; i < arrLen; i++)
		HInsert(&heap, arr[i]);

	for (i = 0; i < arrLen; i++) {
		arr[i] = HDelete(&heap);
	}
}