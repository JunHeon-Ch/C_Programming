#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <Windows.h>

#define MAX_SIZE 1000

typedef struct dressmaker {
	int day;
	int fine;
	int seq;
	float rate;
}Dressmaker;

void initJobs(Dressmaker* jobs);
void scheduleJobs(Dressmaker* jobs, int n);
void printSchedule(Dressmaker* jobs, int n);

void main() {
	FILE* fp;
	int n, jobN, i;
	Dressmaker jobs[MAX_SIZE];

	fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("Error: file not founded\n");
		return;
	}

	fscanf(fp, "%d", &n);
	while (n > 0) {
		initJobs(jobs);

		fscanf(fp, "%d", &jobN);
		for (i = 0; i < jobN; i++) {
			fscanf(fp, "%d %d", &jobs[i].day, &jobs[i].fine);
			jobs[i].rate = (float)jobs[i].fine / jobs[i].day;
			jobs[i].seq = i + 1;
		}

		scheduleJobs(jobs, jobN);
		printSchedule(jobs, jobN);

		n--;
	}

	Sleep(1000);
}

void initJobs(Dressmaker* jobs) {
	int i;

	for (i = 0; i < MAX_SIZE; i++) {
		jobs[i].day = jobs[i].fine = jobs[i].seq = jobs[i].rate = 0;
	}
}

void scheduleJobs(Dressmaker* jobs, int n) {
	int i, j;
	float maxRate;
	int maxi;
	Dressmaker tmp;

	for (i = 0; i < n; i++) {
		maxRate = jobs[i].rate;
		maxi = i;
		for (j = i + 1; j < n; j++) {
			if (maxRate < jobs[j].rate) {
				maxRate = jobs[j].rate;
				maxi = j;
			}
			else if (maxRate == jobs[j].rate && jobs[maxi].day > jobs[j].day) {
				maxRate = jobs[j].rate;
				maxi = j;
			}
		}

		if (i != j) {
			tmp = jobs[i];
			jobs[i] = jobs[maxi];
			jobs[maxi] = tmp;
		}
	}
}

void printSchedule(Dressmaker* jobs, int n) {
	int i;

	printf("Job Schedule: ");
	for (i = 0; i < n; i++) {
		printf("%d ", jobs[i].seq);
	}
	printf("\n\n");
}