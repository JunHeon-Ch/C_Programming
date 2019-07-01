#include <stdio.h>
int fibo(int);
void output(int);
void main() {
	int num;
	int i;

	scanf_s("%d", &num);

	for (i = 0; i < num; i++) {
		output(fibo(i));
	}
}

int fibo(int num) {
	if (num == 0)
		return 0;
	else if (num == 1)
		return 1;
	else
		return fibo(num - 1) + fibo(num - 2);
}

void output(int num) {
	printf("%d ", num);
}