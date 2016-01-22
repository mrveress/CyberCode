#include "stdafx.h"
#include "User.h"
#include "defines.h"

game::actors::User::User()
{
	coords[0] = 0;
	coords[1] = 0;
	speed = 1;
}

void game::actors::User::move(short x, short y)
{
	coords[0] += x * speed;
	coords[1] += y * speed;
}

void game::actors::User::move(int DIR)
{
	switch (DIR)
	{
	case DIR_STAY:
		this->move(0, 0);
		break;
	case DIR_LEFT:
		this->move(-1, 0);
		break;
	case DIR_RIGHT:
		this->move(1, 0);
		break;
	case DIR_TOP:
		this->move(0, -1);
		break;
	case DIR_BOTTOM:
		this->move(0, 1);
		break;
	};
}

int* game::actors::User::getCoords() {
	return this->coords;
}

game::actors::User::~User()
{
}
