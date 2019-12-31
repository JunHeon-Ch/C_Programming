#ifndef __PROCESS_BOARDING_H__
#define __PROCESS_BOARDONG_H__

#include <WinSock2.h>
#include "elevator.h"
#include "floor.h"

/*
엘리베이터 승,하차 알고리즘
- 엘리베이터 용량 초과시 안태움
*/
void getInElevator(Elevator* elevators, Floor* floors, SOCKET socket); // 엘리베이터 승차
void getOutElevator(Elevator* elevators, Floor* floors, SOCKET socket); // 엘리베이터 하차
int checkState(Elevator* elevators, Floor* floors); // 전체 층과 엘리베이터의 상황을 고려해서 상태 체크
#endif // !__BOARDING_H__
