#include <stdio.h>

void Swap(int[], int, int);
int Partition(int[], int, int);
void QuickSort(int[], int, int);
int MedianOfThree(int[], int, int);

void main() {
	int arr[5];
	int i;

	for (i = 0; i < 5; i++)
		scanf("%d", &arr[i]);

	QuickSort(arr, 0, 4);

	for (i = 0; i < 5; i++)
		printf("%d ", arr[i]);
}

void QuickSort(int arr[], int left, int right) {
	int pivot = 0;

	if (left < right) {
		pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

int Partition(int arr[], int left, int right) {
	int pIdx = MedianOfThree(arr, left, right);
	int pivot = arr[pIdx];
	int low = left + 1;
	int high = right;

	Swap(arr, pIdx, left);

	printf("%d ", pivot);
	printf("\n\n");

	while (low <= high) {
		while (pivot >= arr[low] && low <= right)
			low++;
		while (pivot <= arr[high] && high >= left + 1)
			high--;
		if (low < high)
			Swap(arr, low, high);
	}
	Swap(arr, left, high);

	return high;
}

void Swap(int arr[], int idx1, int idx2) {
	int tmp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = tmp;
}

int MedianOfThree(int arr[], int left, int right) {
	int idx[3] = { left, (left + right) / 2, right };

	if (arr[idx[0]] > arr[idx[1]])
		Swap(idx, 0, 1);
	if (arr[idx[1]] > arr[idx[2]])
		Swap(idx, 1, 2);
	if (arr[idx[0]] > arr[idx[2]])
		Swap(idx, 0, 2);
}