#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#define WEIGHT_MAX 100

#include "point.h"

/*
- �����ϰ� �°� ���� / ����, ���� ������ ����
- Ÿ�� ������ ���� �ִ� ���� ������� ��ٷȴٰ� Ž
*/

typedef struct passenger {
	int weight;
	int startF, endF; // ��� ��, ���� ��
	int direction; // �ö󰡸� 1, �������� 0
	Point p; // �°� ��ġ ��ǥ
}Passenger;

Passenger* makePassenger();

#endif