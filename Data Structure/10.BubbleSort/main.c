#include <stdio.h>

void bubblesort(int[], int);

void main() {
	int arr[5];
	int i;

	for (i = 0; i < 5; i++)
		scanf("%d", &arr[i]);

	bubblesort(arr, 5);

	for (i = 0; i < 5; i++)
		printf("%d ", arr[i]);
}

void bubblesort(int arr[], int arrLen) {
	int i, j;
	int tmp = 0;

	for (i = 0; i < arrLen - 1; i++) {
		for (j = 0; j < arrLen - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}