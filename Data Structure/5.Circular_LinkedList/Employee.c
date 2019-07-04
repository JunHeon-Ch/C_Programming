#include <stdio.h>
#include <string.h>
#include "Employee.h"

Employee* SetInfor(char* name, int idNum) {
	Employee* emp = (Employee*)malloc(sizeof(Employee));
	strcpy(emp->name, name);
	emp->num = idNum;
	return emp;
}

void ShowInfor(Employee* emp) {
	printf("name: %s\nid_num:%d\n", emp->name, emp->num);
}