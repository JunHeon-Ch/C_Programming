#include <stdio.h>

void InsertionSort(int[], int);

void main() {
	int arr[5];
	int i;

	for (i = 0; i < 5; i++)
		scanf("%d", &arr[i]);

	InsertionSort(arr, 5);
	
	for (i = 0; i < 5; i++)
		printf("%d ", arr[i]);
}

void InsertionSort(int arr[], int arrLen) {
	int i, j;
	int tmp;

	for (i = 1; i < arrLen; i++) {
		tmp = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > tmp)
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = tmp;
	}
}