#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

typedef struct employee {
	int num;
	char name[10];
}Employee;

Employee* SetInfor(char* name, int idNum);
void ShowInfor(Employee*);
#endif
