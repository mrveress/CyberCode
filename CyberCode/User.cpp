#include "stdafx.h"
#include "defines.h"
#include "Utils.h"
#include "User.h"

game::actors::User::User()
{
	coords = new game::Coords(0,0);
	speed = 1;
}

void game::actors::User::move(short x, short y)
{
	coords->x += x * speed;
	coords->y += y * speed;
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

game::Coords* game::actors::User::getCoords() {
	return this->coords;
}

game::actors::User::~User()
{
}
