#include <stdio.h>
#include "binary.h"
void main() {
	int arr[5], target;
	int i, result = 0;

	for (i = 0; i < 5; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &target);

	sort(arr, sizeof(arr) / sizeof(int));
	result = binarySearch(arr, sizeof(arr) / sizeof(int), target);

	if (result == 1)
		printf("success");
	else
		printf("fail");
	
}