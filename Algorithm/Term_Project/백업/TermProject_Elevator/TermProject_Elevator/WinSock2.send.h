#pragma once

#include "command.h"

typedef unsigned char byte;

void command(SOCKET socket, Command cmd, byte* args, int argLength)
{
	byte* bytes = (byte*)malloc(sizeof(byte) * (argLength + 2));
	bytes[0] = cmd;
	memcpy(bytes + 1, args, argLength);
	bytes[argLength + 1] = EOF;

	send(socket, (const char*)bytes, argLength + 2, 0);

	free(bytes);
}

void command_elevator(SOCKET socket, Elevator elevator)
{
	byte args[] = { elevator.elevator_id, elevator.icon_id, elevator.now_f, elevator.p.x, elevator.state };
	command(socket, CMD_ELEVATOR, args, sizeof(args));
}

void update_icon(SOCKET socket, Elevator elevator, IconId icon)
{
	elevator.icon_id = icon;
	command_elevator(socket, elevator);
}

void command_getin(SOCKET socket, int startF, int endF)
{
	byte args[] = { (byte)startF, (byte)endF };
	command(socket, CMD_GETIN, args, sizeof(args));
}

void command_getout(SOCKET socket, int floor)
{
	byte args[] = { (byte)floor };
	command(socket, CMD_GETOUT, args, sizeof(args));
}

void command_time(SOCKET socket, int min, int sec)
{
	byte args[] = { (byte)min, (byte)sec };
	command(socket, CMD_RAMAINING_TIME, args, sizeof(args));
}