#include <stdio.h>
#include <Windows.h>
#include "door.h"

void door_open(Elevator* elevator) {
	elevator->state = OPEN;
}

void door_close(Elevator* elevator) {
	elevator->state = CLOSE;
}