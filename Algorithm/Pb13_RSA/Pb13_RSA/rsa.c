#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>

int repeated_Squaring(int a, int b, int n);

void main() {
	FILE* fp;
	int e, n, c;
	int p, q, t, d, m;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL)
		printf("Error: file is not founded\n");

	fscanf(fp, "%d %d %d", &n, &e, &c);

	p = 2;
	while (1) {
		if (n % p == 0) {
			q = n / p;
			break;
		}
		p++;
	}

	t = (p - 1) * (q - 1);

	
	i = 0;
	while (1) {
		if ((t * i + 1) % e == 0) {
			break;
		}
		i++;
	}

	d = (t * i + 1) / e;

	m = repeated_Squaring(c, d, n);

	printf("(e, n) => (%d, %d)\nC = %d\n", e, n, c);
	printf("Original Message: %d\n", m);

	Sleep(1000);
}

int repeated_Squaring(int a, int b, int n) {
	int c = 0, d = 1;
	int bit[100];
	int i, k = 0;
	int tmp = b;

	while (tmp > 0) {
		bit[k] = tmp % 2;
		tmp = tmp / 2;
		k++;
	}

	for (i = k - 1; i >= 0; i--) {
		c = 2 * c;
		d = (d*d) % n;
		if (bit[i] == 1) {
			c++;
			d = (d*a) % n;
		}
	}

	return d;
}