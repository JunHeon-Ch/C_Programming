#include <stdio.h>

void SelectionSort(int[], int);

void main() {
	int i;
	int arr[5];

	for (i = 0; i < 5; i++)
		scanf("%d", &arr[i]);

	SelectionSort(arr, 5);

	for (i = 0; i < 5; i++)
		printf("%d ", arr[i]);
}

void SelectionSort(int arr[], int arrLen) {
	int i, j;
	int tmp, idx;


	for (i = 0; i < arrLen - 1; i++) {
		idx = i;
		for (j = i + 1; j < arrLen; j++) {
			if (arr[idx] > arr[j])
				idx = j;
		}
		tmp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = tmp;
	}
}