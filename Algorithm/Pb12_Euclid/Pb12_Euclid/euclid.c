#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <Windows.h>

int euclid(int a, int b, int* x, int* y);

void main() {
	FILE* fp;
	char str[100];
	int a, b;
	int x = 0, y = 0, tmp;
	int gcd;
	
	fp = fopen("input.txt", "r");
	if (fp == NULL)
		printf("Error: file is not founded\n");

	while (fgets(str, 100, fp) != 0) {
		a = atoi(strtok(str, " "));
		b = atoi(strtok(NULL, " "));

		gcd = euclid(a, b, &x, &y);
		
		if (x > y)
			printf("(%d, %d) => %d %d %d\n", b, a, y, x, gcd);
		else
			printf("(%d, %d) => %d %d %d\n", a, b, x, y, gcd);
	}

	Sleep(1000);
}

int euclid(int a, int b, int* x, int* y) {
	int x1, y1;
	int gcd;

	if (b == 0) {
		*x = 1;
		*y = 0;
		return a;
	}

	gcd = euclid(b, a % b, &x1, &y1);

	*x = y1;
	*y = x1 - (a / b) * y1;

	return gcd;
}