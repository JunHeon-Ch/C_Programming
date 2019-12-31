#ifndef __PROCESS_SEEK_H__
#define __PROCESS_SEEK_H__

#include "elevator.h"
#include "passenger.h"

/* 
ž���� ��ġ ���� ���� ����ؼ� ���� �� ���������� ã�� (Jarvis)
�ð� üũ
*/

float up_computingAngle(Point p1, Point p2); // �ö� �� ����
float down_computingAngle(Point p1, Point p2); // ������ �� ����

void seek(Elevator* elevators, Passenger* psgr); 
int seek_elevator(Point psgr_p, Point* ele_p, int up_down); // ���� ���� ���������� ã��

#endif