#ifndef __ELEVATOR_H__
#define __ELEVATOR_H__

#define TRUE 1
#define FALSE 0

#define FLOOR_NUM 6 // ����
#define CAPACITY_MAX 100 // ���������� �뷮
#define ELEVATOR_NUM 3 // ���������� ��

/*direction*/
#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

/*state*/
#define RUN 1
#define STOP 2
#define OPEN 3
#define CLOSE 4

#include "iconid.h"
#include "linkedList.h"
#include "point.h"

typedef struct elevator {
	int elevator_id; // ���������� ������ȣ

	IconId icon_id; // GUI�� ��� �̹���

	int now_f; // ���� ��
	int now_w; // ���� ����
	Point p; // ��ǥ
	int interval; // �� ���������Ϳ� ����
	int state; // ���� 1 ���� 2 ����3 ���� 4
	int direction; // �ö� 1 ������ 2 ���� 3 ��4
	int pasCnt; // ž�� �°� ��
	List pasList; // ���� ���� ���� sorting �Ǿ� ����
} Elevator;

int up_WhoIsPrecede(LData d1, LData d2); // �ö� �� sorting ���
int down_WhoIsPrecede(LData d1, LData d2); // ������ �� sorting ���

void initInterval(Elevator* elevators); // ���������Ͱ� ���� �ʱ�ȭ
void initElevator(Elevator* elevators); // ���������� ���� �ʱ�ȭ

#endif // !__ELEVATOR_H__