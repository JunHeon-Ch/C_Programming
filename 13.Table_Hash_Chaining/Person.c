#include <stdio.h>
#include <string.h>
#include "Person.h"

int GetSSN(Person* p) {
	return p->ssn;
}

void ShowPerInfo(Person* p) {
	printf("SSN: %d\n", p->ssn);
	printf("NAME: %s\n", p->name);
	printf("ADDR: %s\n", p->addr);
}

Person* MakePersonInfo(int ssn, char* name, char* addr) {
	Person* p = (Person*)malloc(sizeof(Person));
	p->ssn = ssn;
	strcpy(p->name, name);
	strcpy(p->addr, addr);

	return p;
}