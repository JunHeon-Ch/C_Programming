#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define MAXWEIGHT 100

void floyd(int** a, int** d, int n);
int locateCenter(int** d, int* hV, int vn, int cn);

void main() {
	FILE* fp;
	
	int hnum, vnum;
	char hVertex[200];
	int sVtx, dVtx, weight;
	int* hV;
	int** adj, **d;
	int i, j;
	int num;

	fp = fopen("input.txt", "r");
	if (fp == NULL)
		printf("Error: file is not founded\n");
	
	fscanf(fp, "%d %d", &hnum, &vnum);
	fgetc(fp);
	fgets(hVertex, 200, fp);
	hV = (int*)malloc(sizeof(int) * hnum);
	i = j = 0;
	while (hVertex[i] != NULL) {
		num = hVertex[i] - 48;
		if (num >= 0 && num <= 9) {
			hV[j++] = num;
		}
		i++;
	}
	
	adj = (int**)malloc(sizeof(int*) * (vnum + 1));
	d = (int**)malloc(sizeof(int*) * (vnum + 1));
	for (i = 0; i <= vnum; i++) {
		adj[i] = (int*)malloc(sizeof(int) * (vnum + 1));
		d[i] = (int*)malloc(sizeof(int) * (vnum + 1));
	}

	for (i = 1; i <= vnum; i++)
		for (j = 1; j <= vnum; j++) {
			if (i == j) {
				adj[i][j] = 0;
				continue;
			}
			adj[i][j] = MAXWEIGHT;
		}

	while (fscanf(fp, "%d %d %d", &sVtx, &dVtx, &weight) > 0) {
		adj[sVtx][dVtx] = weight;
		adj[dVtx][sVtx] = weight;
	}
	
	floyd(adj, d, vnum);
	
	printf("Location of Health Center: %d\n", locateCenter(d, hV, vnum, hnum));

	for (i = 0; i <= vnum; i++) {
		free(adj[i]);
		free(d[i]);
	}
	free(adj);
	free(d);
	free(hV);

	fclose(fp);
	Sleep(1000);
}

void floyd(int** a, int** d, int n) {
	int i, j, k;

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			d[i][j] = a[i][j];

	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
}

int locateCenter(int** d, int* hV, int vn, int cn) {
	int* locate = (int*)malloc(sizeof(int)*(vn + 1));
	int i, j;
	int min, max, maxi;

	for (i = 1; i <= vn; i++) {
		min = d[i][hV[0]];
		for (j = 1; j < cn; j++) {
			if (min > d[i][hV[j]])
				min = d[i][hV[j]];
		}
		locate[i] = min;
	}

	max = locate[1];
	maxi = 1;
	for (i = 2; i <= vn; i++) {
		if (max < locate[i]) {
			max = locate[i];
			maxi = i;
		}
	}

	free(locate);

	return maxi;
}