#include <stdio.h>
int binary(int*, int, int, int);
void main() {
	int arr[5];
	int i;
	int target = 0;
	int first = 0, mid = 0, last = 4;

	for (i = 0; i < 5; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &target);

	printf("%d", binary(arr, target, first, last));
}

int binary(int* arr, int target, int first, int last) {
	if (first > last)
		return -1;
	if (arr[(first + last) / 2] == target)
		return (first + last) / 2;
	else if (arr[(first + last) / 2] > target)
		binary(arr, target, first, (first + last) / 2 - 1);
	else
		binary(arr, target, (first + last) / 2 + 1, last);
}