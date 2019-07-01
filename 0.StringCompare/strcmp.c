#include <stdio.h>
#include <string.h>
void stringCmp(char[][15], int);
void output(char[][15], int);
void main() {
	char str[10][15], tmp[15];
	int max = 0, i = 0;

	puts("Á¾·á: Enter\n");
	while (1) {
		gets(tmp);
		if (tmp[0] == '\0') {
			max = i;
			break;
		}
		strcpy(str[i], tmp);
		i++;
	}

	stringCmp(str, max);
	output(str, max);
}

void stringCmp(char str[][15], int max) {
	char tmp[15] = { 0, };
	int i, j;

	for (i = 0; i < max; i++) {
		for (j = i + 1; j < max; j++) {
			if (strcmp(str[i], str[j]) > 0) {
				strcpy(tmp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], tmp);
			}
		}
	}
}

void output(char str[][15], int max) {
	int i;

	for (i = 0; i < max; i++)
		puts(str[i]);
}