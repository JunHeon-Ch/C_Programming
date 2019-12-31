#ifndef __FLOOR_H__
#define __FLOOR_H__

#include "circular_queue.h"

typedef struct floor {
	Queue upQ;
	Queue downQ;
}Floor;

void floorInit(Floor* floors); // �ʱ�ȭ
int isFloorEmpty(Queue* queue); // ���� ž���ڰ� �ִ��� Ȯ��

void waitingElevator(Queue* queue, Data psgr); // ���� ž���� �߰�
Data boardingElevator(Queue* queue); // ���������� ž���ϸ� ������ ž���� ����
Data peekData(Queue* queue); // ùž���� ���� Ȯ��

void printFloor(Floor* floors);


#endif
