#ifndef __PROCESS_SEEK_H__
#define __PROCESS_SEEK_H__

#define PER_TIME 5

#include "elevator.h"
#include "passenger.h"

/* 
탑승자 위치 기준 각도 사용해서 먼저 올 엘리베이터 찾음 (Jarvis)
도착 예정 시간 체크
*/

float up_computingAngle(Point p1, Point p2); // 올라갈 때 각도
float down_computingAngle(Point p1, Point p2); // 내려갈 때 각도

int seek(Elevator* elevators, Passenger* psgr); 
int seek_elevator(Elevator* elevators, Point psgr_p, Point* ele_p, int up_down); // 먼저 오는 엘리베이터 찾기
int extimateTime(Elevator elevator, Passenger* psgr); // 도착 예정 시간 계산
#endif