#include <stdio.h>
#include <stdlib.h>

void MergeSort(int[], int, int);
void MergeTwoArea(int[], int, int, int);

void main() {
	int arr[5];
	int i;

	for (i = 0; i < 5; i++)
		scanf("%d", &arr[i]);

	MergeSort(arr, 0, 4);

	for (i = 0; i < 5; i++)
		printf("%d ", arr[i]);
}

void MergeSort(int arr[], int left, int right) {
	int mid = 0;

	if (left < right) {
		mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeTwoArea(arr, left, mid, right);
	}
}

void MergeTwoArea(int arr[], int left, int mid, int right) {
	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));
	int sIdx = left;
	int fIdx = left;
	int rIdx = mid + 1;
	int i;

	while (fIdx <= mid && rIdx <= right) {
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx++] = arr[fIdx++];
		else
			sortArr[sIdx++] = arr[rIdx++];
	}

	if (fIdx > mid) {
		while (rIdx <= right)
			sortArr[sIdx++] = arr[rIdx++];
	}
	else if (rIdx > right) {
		while (fIdx <= mid)
			sortArr[sIdx++] = arr[fIdx++];
	}

	for (i = left; i <= right; i++)
		arr[i] = sortArr[i];

	free(sortArr);
}