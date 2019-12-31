#ifndef __FLOOR_H__
#define __FLOOR_H__

#include "circular_queue.h"

typedef struct floor {
	Queue upQ;
	Queue downQ;
}Floor;

void floorInit(Floor* floors); // 초기화
int isFloorEmpty(Queue* queue); // 층에 탑승자가 있는지 확인

void waitingElevator(Queue* queue, Data psgr); // 층에 탑승자 추가
Data boardingElevator(Queue* queue); // 엘리베이터 탑승하면 층에서 탑승자 삭제
Data peekData(Queue* queue); // 첫탑승자 정보 확인

void printFloor(Floor* floors);


#endif
