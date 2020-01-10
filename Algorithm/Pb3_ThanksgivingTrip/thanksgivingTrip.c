#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define MAX_NUM 100

void initArr(int* expense);
int shareExpense(int* expense, int avg, int num);

void main() {
	FILE* fp;
	int num, i;
	int expense[MAX_NUM];
	int avg;
	int shExp;

	fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("Error: file not founded\n");
	}

	do {
		fscanf(fp, "%d", &num);
		
		if (num == 0) {
			break;
		}

		initArr(expense);
		avg = 0;

		for (i = 0; i < num; i++) {
			fscanf(fp, "%d", &expense[i]);
			avg += expense[i];
		}
		avg = avg / num;
		avg = avg / 10 * 10;

		shExp = shareExpense(expense, avg, num);

		printf("\\%d\n", shExp);
	} while (num != 0);

	Sleep(1000);
}

void initArr(int* expense) {
	int i;

	for (i = 0; i < MAX_NUM; i++) {
		expense[i] = 0;
	}
}

int shareExpense(int* expense, int avg, int num) {
	int i;
	int change = 0;

	for (i = 0; i < num; i++) {
		if (expense[i] < avg) {
			change += avg - expense[i];
		}
	}

	return change;
}