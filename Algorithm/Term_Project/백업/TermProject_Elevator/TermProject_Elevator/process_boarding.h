#ifndef __PROCESS_BOARDING_H__
#define __PROCESS_BOARDONG_H__

#include <WinSock2.h>
#include "elevator.h"
#include "floor.h"

/*
���������� ��,���� �˰���
- ���������� �뷮 �ʰ��� ���¿�
*/
void getInElevator(Elevator* elevators, Floor* floors, SOCKET socket); // ���������� ����
void getOutElevator(Elevator* elevators, Floor* floors, SOCKET socket); // ���������� ����
int checkState(Elevator* elevators, Floor* floors); // ��ü ���� ������������ ��Ȳ�� ����ؼ� ���� üũ
#endif // !__BOARDING_H__
