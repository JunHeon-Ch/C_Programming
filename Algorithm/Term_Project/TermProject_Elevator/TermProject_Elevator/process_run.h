#ifndef __PROCESS_RUN_H__
#define __PROCESS_RUN_H__

#include "elevator.h"

/*
���������� ���� �����ϸ鼭 �ð�ݴ�������� ���ư�
*/

void upward(Elevator* elevator); // �ö�
void downward(Elevator* elevator); // ������
void rightward(Elevator* elevator); // ����
void leftward(Elevator* elevator); // ��

void stop(Elevator* elevators); // ����
int checkStop(Elevator* elevators); // �����ִ��� Ȯ��
int checkRun(Elevator* elevators); // ������ ���ư����ϴ���

void runElevator(Elevator* elevators); // ���� ����
void printElevator(Elevator* elevators);

#endif
