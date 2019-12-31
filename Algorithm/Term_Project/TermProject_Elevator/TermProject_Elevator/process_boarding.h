#ifndef __PROCESS_BOARDING_H__
#define __PROCESS_BOARDONG_H__

#include "elevator.h"
#include "floor.h"

/*
엘리베이터 승,하차 알고리즘
- 엘리베이터 용량 초과시 안태움
*/
void getInElevator(Elevator* elevators, Floor* floors); // 엘리베이터 승차
void getOutElevator(Elevator* elevators); // 엘리베이터 하차

#endif // !__BOARDING_H__
