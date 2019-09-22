#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define MAX_SIZE 100

typedef struct elephant {
	int weight;
	int iq;
	int index;
}Elephant;

void sortByWeight(Elephant* elephants, int cnt);
void swap(Elephant* elephants, int i, int mini);
void disprove(Elephant* elephants, int size);
void printSequence(int* prev, int i);

void main() {
	FILE* fp;

	Elephant elephants[MAX_SIZE];
	int i, cnt;
	
	fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("Error: file not found\n");
	}

	i = 0;
	while (fscanf(fp, "%d %d", &(elephants[i].weight), &(elephants[i].iq)) > 0) {
		elephants[i].index = i;
		i++;
	}
	fclose(fp);

	disprove(elephants, i);
	
	Sleep(1000);
}

void swap(Elephant* elephants, int i, int mini) {
	Elephant tmp;

	tmp = elephants[i];
	elephants[i] = elephants[mini];
	elephants[mini] = tmp;
}

// Sort
void sortByWeight(Elephant* elephants, int cnt) {
	int i, j, mini;

	for (i = 0; i < cnt; i++) {
		mini = i;
		for (j = i + 1; j < cnt; j++) {
			if (elephants[mini].weight > elephants[j].weight) {
				mini = j;
			}
		}
		if (mini != i) {
			swap(elephants, i, mini);
		}
	}
}

// Recursively print sequence
void printSequence(int* prev, int i) {
	if (prev[i] == -1) {
		printf("%d\n", i + 1);
	}
	else {
		printSequence(prev, prev[i]);
		printf("%d\n", i + 1);
	}
}

void disprove(Elephant* elephants, int size) {
	int* prev;
	int* length;
	int i, j;
	int max = -1, lastIdx = -1;

	prev = (int*)malloc(sizeof(int) * size);
	length = (int*)malloc(sizeof(int) * size);

	for (i = 0; i < size; i++) {
		prev[i] = -1;
		length[i] = 1;
	}

	sortByWeight(elephants, size);

	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			if (elephants[i].weight < elephants[j].weight && elephants[i].iq > elephants[j].iq) {
				if (length[elephants[i].index] + 1 > length[elephants[j].index]) { // Finding subsequence, Storing previous sequence
					prev[elephants[j].index] = elephants[i].index;
					length[elephants[j].index] = length[elephants[i].index] + 1;

					if (max < length[elephants[j].index]) { // Maximum length
						max = length[elephants[j].index];
						lastIdx = elephants[j].index;
					}
				}
			}
		}
	}

	printf("Max length: %d\n\n", max);
	printf("Sequence\n");
	printSequence(prev, lastIdx);

	free(prev);
	free(length);
}
