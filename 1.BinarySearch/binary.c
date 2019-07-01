void sort(int* arr, int arr_size) {
	int i, j;
	int tmp = 0;

	for (i = 0; i < arr_size - 1; i++) {
		for (j = i + 1; j < arr_size; j++) {
			if (arr[i] > arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int binarySearch(int* arr, int arr_size, int target) {
	int first = 0, last = arr_size - 1, mid = 0;

	while (first <= last) {
		mid = (first + last) / 2;
		if (arr[mid] == target)
			return 1;
		else if (arr[mid] > target)
			first = mid + 1;
		else
			last = mid - 1;
	}
	return 0;
}