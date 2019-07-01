#include <stdio.h>
#include <string.h>
void countAlpha(char*, int*);
void output(int*);
void main() {
	char str[100];
	char* pstr = NULL;
	int strCnt[26] = { 0, };
	gets(str);
	pstr = strlwr(str);
	countAlpha(pstr, strCnt);
	output(strCnt);
}

void countAlpha(char* str, int* strCnt) {
	int i = 0;

	while (str[i] != NULL) {
		if (str[i] >= 'a' && str[i] <= 'z')
			strCnt[str[i] - 97]++;
		i++;
	}
}

void output(int* cnt) {
	int i;

	for (i = 0; i < 26; i++) {
		if (cnt[i] == 0)
			continue;
		printf("%c: %d°³\n", 'a' + i, cnt[i]);
	}
}