#include "stdafx.h"
#include "defines.h"
#include "User.h"
#include "Render.h"
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

void game::controllers::Controller::setRender(game::renders::Render* rndr)
{
	this->render = rndr;
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
				user->move(DIR_TOP);
				break;
			case ARROW_DOWN:
				user->move(DIR_BOTTOM);
				break;
			case ARROW_LEFT:
				user->move(DIR_LEFT);
				break;
			case ARROW_RIGHT:
				user->move(DIR_RIGHT);
				break;
			}
		}
		render->clearScreen();
		if (
			user->getCoords()->x >= 0 && user->getCoords()->x < game::renders::Render::size_width &&
			user->getCoords()->y >= 0 && user->getCoords()->y < game::renders::Render::size_height
			) {
			*(render->getCell(user->getCoords())) = L'@';
		}
		render->draw();
		chcode = _getch();
	}
}