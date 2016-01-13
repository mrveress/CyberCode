#include "stdafx.h"
#include "Game.h"


int main()
{
	Game *game = new Game();
	while (1) {
		std::cout << _getch();
	}
    return 0;
}

