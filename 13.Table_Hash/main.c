#include <stdio.h>
#include <string.h>
#include "Table.h"

int MyHashFunc(int);

void main() {
	Table mytbl;
	Person* p;
	int ssn;
	char name[STR_LEN], addr[STR_LEN];

	TBLInit(&mytbl, MyHashFunc);

	printf("INSERT\n");
	while (1) {
		scanf("%d", &ssn);
		if (ssn < 1)
			break;
		getchar();
		gets(name);
		gets(addr);

		p = MakePersonInfo(ssn, name, addr);
		TBLInsert(&mytbl, GetSSN(p), p);
		printf("Insert Success\n");
	}

	printf("\nSEARCH\n");
	while (1) {
		scanf("%d", &ssn);
		if (ssn < 1)
			break;

		p = TBLSearch(&mytbl, ssn);
		if (p != NULL)
			ShowPerInfo(p);
	}

	printf("\nDELETE\n");
	while (1) {
		scanf("%d", &ssn);
		if (ssn < 1)
			break;

		p = TBLDelete(&mytbl, ssn);
		if (p != NULL) {
			ShowPerInfo(p);
			free(p);
		}
	}
}	

int MyHashFunc(int k) {
	return k % 100;
}
