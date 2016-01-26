#include "stdafx.h"
#include "utils.h"
#include "defines.h"
#include "config.h"
#include "User.h"
#include "Render.h"
#include "Controller.h"
#include "Game.h"

Game::Game()
{
}


Game::~Game()
{
}

void Game::start()
{
	game::renders::Render* rndr = new game::renders::Render();
	rndr->clearScreen();
	game::actors::User* user = new game::actors::User();
	game::controllers::Controller* con = new game::controllers::Controller();
	con->setUser(user);
	con->setRender(rndr);
	con->startHandling();
}
