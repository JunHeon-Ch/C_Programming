#include <stdio.h>
void main() {
	int i, j;
	int line, curline, half = 0;
	int star = 0, space = 0;

	scanf("%d", &line);
	half = line / 2;

	curline = 1;
	if (line % 2 == 0) {
		i = 0;
		while (curline <= line / 2) {
			space = half - (i + 1);
			star = line - (line - (i * 2 + 1));
			while (space > 0) {
				printf(" ");
				space--;
			}
			while (star > 0) {
				printf("*");
				star--;
			}
			printf("\n");
			i++;
			curline++;
		}
		i = 0;
		while (curline <= line) {
			space = half - (half - i);
			star = line - (i * 2 + 1);
			while (space > 0) {
				printf(" ");
				space--;
			}
			while (star > 0) {
				printf("*");
				star--;
			}
			printf("\n");
			i++;
			curline++;
		}
	}
	else {
		i = 0;
		while (curline <= (line / 2 + 1)) {
			space = half - i;
			star = line - (line - (i * 2 + 1));
			while (space > 0) {
				printf(" ");
				space--;
			}
			while (star > 0) {
				printf("*");
				star--;
			}
			printf("\n");
			i++;
			curline++;
		}
		i = 0;
		while (curline <= line) {
			space = half - (half - (i + 1));
			star = line - (i + 1) * 2;
			while (space > 0) {
				printf(" ");
				space--;
			}
			while (star > 0) {
				printf("*");
				star--;
			}
			printf("\n");
			i++;
			curline++;
		}
	}
}