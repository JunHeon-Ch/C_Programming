#ifndef __PROCESS_SEEK_H__
#define __PROCESS_SEEK_H__

#define PER_TIME 5

#include "elevator.h"
#include "passenger.h"

/* 
ž���� ��ġ ���� ���� ����ؼ� ���� �� ���������� ã�� (Jarvis)
���� ���� �ð� üũ
*/

float up_computingAngle(Point p1, Point p2); // �ö� �� ����
float down_computingAngle(Point p1, Point p2); // ������ �� ����

int seek(Elevator* elevators, Passenger* psgr); 
int seek_elevator(Elevator* elevators, Point psgr_p, Point* ele_p, int up_down); // ���� ���� ���������� ã��
int extimateTime(Elevator elevator, Passenger* psgr); // ���� ���� �ð� ���
#endif