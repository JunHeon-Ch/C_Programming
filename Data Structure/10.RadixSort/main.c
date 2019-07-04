#include <stdio.h>
#include "ListQueue.h"

#define BUCK_NUM 10

void RadixSort(int[], int, int);

void main() {
	int arr[5];
	int i;

	for (i = 0; i < 5; i++)
		scanf("%d", &arr[i]);

	RadixSort(arr, 5, 3);

	for (i = 0; i < 5; i++)
		printf("%d ", arr[i]);
}

void RadixSort(int arr[], int num, int maxLen) {
	Queue bucket[BUCK_NUM];
	int bi, di, pos;
	int rdx;
	int divfac = 1;

	for (bi = 0; bi < BUCK_NUM; bi++)
		QueueInit(&bucket[bi]);

	for (pos = 0; pos < maxLen; pos++) {
		for (di = 0; di < num; di++) {
			rdx = arr[di] / divfac % 10;
			Enqueue(&bucket[rdx], arr[di]);
		}

		for (bi = 0, di = 0; bi < BUCK_NUM; bi++) {
			while (QIsEmpty(&bucket[bi]) != TRUE)
				arr[di++] = Dequeue(&bucket[bi]);
		}
		divfac *= 10;
	}
}