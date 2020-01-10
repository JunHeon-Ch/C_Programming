#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define TRUE 1
#define FALSE 0
#define NUM_COLOR 2

int** adj;
int* vcolor;
int vn, count = 0, flag = FALSE;

void coloring(int i);
int promising(int i);

void main() {
	FILE* fp;

	int en, sv, ev;
	int i, j;

	fp = fopen("input.txt", "r");

	if (fp == NULL)
		printf("Error: file isn't founded\n");

	fscanf(fp, "%d", &vn);
	vcolor = (int*)malloc(sizeof(int) * (vn + 1));
	adj = (int**)malloc(sizeof(int*) * (vn + 1));
	for (i = 0; i <= vn; i++) {
		adj[i] = (int*)malloc(sizeof(int) * (vn + 1));
	}
	
	for (i = 0; i <= vn; i++) {
		vcolor[i] = 0;
	}
	for (i = 0; i <= vn; i++) {
		for (j = 0; j <= vn; j++) {
			adj[i][j] = 0;
		}
	}

	fscanf(fp, "%d", &en);
	for (i = 0; i < en; i++) {
		fscanf(fp, "%d %d", &sv, &ev);
		adj[sv + 1][ev + 1] = adj[ev + 1][sv + 1] = 1;
	}

	coloring(0);

	if (flag == TRUE)
		printf("tow color\n");
	else
		printf("not tow color\n");

	Sleep(2000);
}

void coloring(int i) {
	int color;

	if (promising(i)) {
		if (i == vn) {
			flag = TRUE;
		}
		else {
			for (color = 1; color <= NUM_COLOR; color++) {
				vcolor[i + 1] = color;
				coloring(i + 1);
			}
		}
	}
}

int promising(int i) {
	int j = 1, flag = TRUE;

	while (j < i && flag) {
		if (adj[i][j] && vcolor[i] == vcolor[j]) {
			flag = FALSE;
		}
		j++;
	}

	return flag;
}