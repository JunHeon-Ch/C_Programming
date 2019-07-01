#ifndef __PERSON_H__
#define __PERSON_H__

#define STR_LEN 10

typedef struct person {
	int ssn;
	char name[STR_LEN];
	char addr[STR_LEN];
}Person;

int GetSSN(Person*);
void ShowPerInfo(Person*);
Person* MakePersonInfo(int, char*, char*);

#endif
