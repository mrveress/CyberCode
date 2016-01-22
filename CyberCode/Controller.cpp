#include "stdafx.h"
#include "defines.h"
#include "User.h"
#include "Controller.h"


game::controllers::Controller::Controller()
{
}


game::controllers::Controller::~Controller()
{
}

void game::controllers::Controller::setUser(game::actors::User* user) 
{
	this->user = user;
}

void game::controllers::Controller::startHandling() 
{
	int chcode = -1;
	while (chcode != CTRL_C) {
		if (chcode == ARROW_HEAD_AP || chcode == ARROW_HEAD_NP)
		{
			switch (_getch())
			{
			case ARROW_UP:
				this->user->move(DIR_TOP);
				break;
			case ARROW_DOWN:
				this->user->move(DIR_BOTTOM);
				break;
			case ARROW_LEFT:
				this->user->move(DIR_LEFT);
				break;
			case ARROW_RIGHT:
				this->user->move(DIR_RIGHT);
				break;
			}
		}
		this->render->draw();
	}
}