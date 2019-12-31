#ifndef __DOOR_H__
#define __DOOR_H__

#include "elevator.h"

#define OPEN_TIME 100 // ¿­¸®´Â ½Ã°£
#define CLOSE_TIME 100 // ´ÝÈ÷´Â ½Ã°£

void door_open(Elevator* elevator); // ¿­¸²
void door_close(Elevator* elevator); // ´ÝÈû

#endif
