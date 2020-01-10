#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <Windows.h>

#define MAX_SIZE 30

typedef struct dot {
	float x, y;
	int check;
}Dot;

float MinimumInk(Dot* dots, int num);
float calDistance(Dot d1, Dot d2);

void main() {
	FILE* fp;
	int num;
	int i;
	Dot dots[MAX_SIZE];
	
	fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("Error: file is not founded\n");
	}

	fscanf(fp, "%d", &num);
	for (i = 0; i < num; i++) {
		fscanf(fp, "%f %f", &dots[i].x, &dots[i].y);
		dots[i].check = 0;
	}

	fclose(fp);

	printf("Minimum Ink: %.2f\n", MinimumInk(dots, num));

	Sleep(1000);
}

float MinimumInk(Dot* dots, int num) {
	float minCost = 0;
	float min, dist;
	int start, mini = 0;
	int i;
	int cnt = 0;

	while (cnt != num) {
		start = mini;
		dots[start].check = 1;
		min = INT_MAX;
		
		for (i = 0; i < num; i++) {
			if (dots[i].check == 0) {
				dist = calDistance(dots[start], dots[i]);
				if (dist < min) {
					min = dist;
					mini = i;
				}
			}
		}	
		if (min != INT_MAX) {
			minCost += min;
		}

		cnt++;
	}
	
	return minCost;
}

float calDistance(Dot d1, Dot d2) {
	return sqrt((d1.x - d2.x) * (d1.x - d2.x) + (d1.y - d2.y) * (d1.y - d2.y));
}