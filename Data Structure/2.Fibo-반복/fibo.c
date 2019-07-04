#include <stdio.h>
int fibo(int);
void output(int);
void main() {
	int num;

	scanf_s("%d", &num);

	fibo(num);
}

int fibo(int f) {
	int f1 = 0, f2 = 1, f3 = 0;
	int i;

	for (i = 0; i < f; i++) {
		output(f1);
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
}

void output(int f) {
	printf("%d ", f);
}