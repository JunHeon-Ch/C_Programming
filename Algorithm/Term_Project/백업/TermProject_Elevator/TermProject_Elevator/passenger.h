#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#define WEIGHT_MAX 50

#include "point.h"

/*
- 랜덤하게 승객 생성 / 무게, 시작 도착층 랜덤
- 타는 층보다 전에 있는 엘베 오기까지 기다렸다가 탐
*/

typedef struct passenger {
	int weight;
	int startF, endF; // 출발 층, 도착 층
	int direction; // 올라가면 1, 내려가면 0
	Point p; // 승객 위치 좌표
}Passenger;

Passenger* makePassenger();

#endif