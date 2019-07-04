#include <stdio.h>
int linear(int*, int);
void main() {
	int num;
	int arr[10];
	int i;

	for (i = 0; i < 10; i++)
		scanf("%d", &arr[i]);

	scanf("%d", &num);

	printf("%d\n", linear(arr, num));
}

int linear(int* arr, int target) {
	int i;

	for (i = 0; i < 10; i++) {
		if (arr[i] == target)
			return 1;
	}
	return 0;
}