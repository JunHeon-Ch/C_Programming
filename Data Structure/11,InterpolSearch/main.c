#include <stdio.h>
int ISerach(int[], int, int, int);

void main() {
	int arr[5];
	int target;
	int i;

	for (i = 0; i < 5; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &target);

	printf("%d\n", ISerach(arr, 0, 4, target));
}

int ISearch(int arr[], int left, int right, int target) {
	int tIdx;

	if (arr[left] > target || arr[right] < target)
		return -1;

	tIdx = (double)(target - arr[left]) / (arr[right] - arr[left]) * (right - left) + left;

	if (arr[tIdx] == target)
		return tIdx;
	else if (arr[tIdx] > target)
		ISearch(arr, left, tIdx - 1, target);
	else
		ISearch(arr, tIdx + 1, right, target);
}