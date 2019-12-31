#include <stdio.h>
#include <Windows.h>
#include "door.h"

void door_open(Elevator* elevator) {
	elevator->state = OPEN;
//	Sleep(1000);
}

void door_close(Elevator* elevator) {
	elevator->state = CLOSE;
//	Sleep(1000);
}