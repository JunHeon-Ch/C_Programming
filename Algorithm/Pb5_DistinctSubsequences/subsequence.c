#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define STR_SIZE 10000
#define SUBSTR_SIZE 100

void initTable(int** table, int row, int col);
int countSubsequence(int** table, char* str, char* substr, int row, int col);
void freeTable(int** table, int row);

void main() {
	FILE* fp;
	char str[STR_SIZE];
	char substr[SUBSTR_SIZE];
	int** table;
	int row, col;
	int num;
	int i, j;
	int cnt;

	fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("Error: file not found\n");
	}

	fscanf(fp, "%d", &num);
	for (i = 0; i < num; i++) {
		fscanf(fp, "%s", str);
		fscanf(fp, "%s", substr);

		row = strlen(substr) + 1;
		col = strlen(str) + 1;

		table = (int**)malloc(sizeof(int*) * row);
		for (j = 0; j < row; j++) {
			table[j] = (int*)malloc(sizeof(int) * col);
		}

		initTable(table, row, col);

		cnt = countSubsequence(table, str, substr, row, col);

		printf("\n#%d String -> %s\tSubstring -> %s\n", i + 1, str, substr);
		printf("Number of subsequence -> %d\n", cnt);

		freeTable(table, row);
	}

	fclose(fp);

	Sleep(1000);
}

void initTable(int** table, int row, int col) {
	int i;

	for (i = 0; i < row; i++) {
		table[i][0] = 0;
	}

	for (i = 0; i < col; i++) {
		table[0][i] = 1;
	}
}

int countSubsequence(int** table, char* str, char* substr, int row, int col) {
	int i, j;

	if (row > col) {
		return 0;
	}

	for (i = 1; i < row; i++) {
		for (j = 1; j < col; j++) {
			if (substr[i - 1] == str[j - 1]) {
				table[i][j] = table[i - 1][j - 1] + table[i][j - 1];
			}
			else {
				table[i][j] = table[i][j - 1];
			}
		}
	}

	return table[row - 1][col - 1];
}

void freeTable(int** table, int row) {
	int i;

	for (i = 0; i < row; i++) {
		free(table[i]);
	}
	free(table);
}