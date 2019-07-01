#include <stdio.h>
#include <string.h>
#include "CLinkedList.h"

char* NightDuty(List, char*, int);

void main() {
	List list;
	Employee* emp;
	char name[10];
	int num;
	int i;
	
	ListInit(&list);

	while (1) {
		scanf("%d", &num);
		getchar();
		if (num == 0)
			break;
		gets(name);

		emp = SetInfor(name, num);
		LInsertTail(&list, emp);
	}

	if (LFirst(&list, &emp) == TRUE) {
		ShowInfor(emp);
		
		for (i = 0; i < LCount(&list) - 1; i++) {
			if (LNext(&list, &emp) == TRUE)
				ShowInfor(emp);
		}
	}
	printf("\n\n");

	gets(name);
	scanf("%d", &num);
	puts(NightDuty(list, name, num));
}

char* NightDuty(List list, char* name, int num) {
	int i;
	Employee* ND;

	if (LFirst(&list, &ND) == TRUE) {
		if (strcmp(ND->name, name) == 0) {
			for (i = 0; i < num; i++)
				LNext(&list, &ND);
			return ND->name;
		}
		for (i = 0; i < LCount(&list) - 1; i++) {
			LNext(&list, &ND);
			if (strcmp(ND->name, name) == 0) {
				for (i = 0; i < num; i++)
					LNext(&list, &ND);
				return ND->name;
			}
		}
	}
}
