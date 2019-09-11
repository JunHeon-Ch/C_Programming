#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_SIZE 60

void flip(int* stack, int n);
void printOutput(char* input, int* stack, int* fPos, int length, int fIdx);
void init(int* stack, int* fPos);
void main() {
	FILE* fp;

	char tmp[MAX_SIZE];
	char input[MAX_SIZE];
	char* buff;
	int stack[MAX_SIZE];
	int fPos[MAX_SIZE];
	int i, j, cnt, maxIdx, fIdx;

	fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("Error: file can't read\n");
	}

	while (fgets(tmp, MAX_SIZE, fp) != NULL) {
		i = 0;
		strcpy(input, tmp);
		buff = strtok(tmp, " ");
		while (buff != NULL) {
			stack[i++] = atoi(buff);
			buff = strtok(NULL, " ");
		}
	}
	
	fclose(fp);

	// Positioning pancake: After finding maximum value, locating correct position.
	cnt = 0; fIdx = 0;
	while (cnt < i) {
		maxIdx = 0;
		// Find maximum value.
		for (j = 1; j < i - cnt; j++) {
			if (stack[j] >= stack[maxIdx]) {
				maxIdx = j;
			}
		}

		// case 1: Maximum value locates last position.
		if (maxIdx == i - cnt - 1) {
			cnt++;
		}
		// case 2: Maximum value locates first position.
		else if (maxIdx == 0) {
			flip(stack, j - 1);
			fPos[fIdx++] = i - (j - 1);
			cnt++;
		}
		// case 3: Maximum value locates between last and first position.
		else {
			flip(stack, maxIdx);
			fPos[fIdx++] = i - maxIdx;
		}
	}
	fPos[fIdx] = 0;

	printOutput(input, stack, fPos, i, fIdx);
}

// Initialization
void init(int* stack, int* fPos) {
	int i;

	for (i = 0; i < MAX_SIZE; i++) {
		stack[i] = fPos[i] = 0;
	}
}

// Flip function
void flip(int* stack, int n) {
	int i;
	int tmp;

	i = 0;
	while (i < n) {
		tmp = stack[i];
		stack[i] = stack[n];
		stack[n] = tmp;
		i++; n--;
	}
}

// Print output
void printOutput(char* input, int* stack, int* fPos, int length, int fIdx) {
	int i;

	i = 0;
	while (input[i] != NULL) {
		printf("%c", input[i++]);
	}

	printf("( ");
	for (i = 0; i < length; i++) {
		printf("%d ", stack[i]);
	}
	printf(")\n");

	for (i = 0; i <= fIdx; i++) {
		printf("%d ", fPos[i]);
	}

	Sleep(1000);
}