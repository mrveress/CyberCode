#include "stdafx.h"
#include "Game.h"
#include "utils.h"
#include "defines.h"
#include "config.h"

Game::Game()
{
}


Game::~Game()
{
}

void Game::start()
{

	
	int cur_x = 0;
	int cur_y = 0;
	
		clearScreen();
		testStringToScreen(L"This is unicode string and она должна показывать кириллицу", cur_y, cur_x);
		render();
		chcode = _getch();
		if (_CC_DBG_LINE_NMBS) {
			OutputDebugStringW(utils::to_wstring(chcode).c_str());
			OutputDebugStringW(L"\r\n");
		}
	}
}

void Game::render()
{

}
