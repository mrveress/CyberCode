#include "stdafx.h"
#include "config.h"
#include "Utils.h"
#include "Render.h"


game::renders::Render::Render()
{
	game::utils::SetWindowSize(size_width, size_height);
	system("cls");
	setlocale(LC_ALL, "Russian");
	clearScreen();
}


game::renders::Render::~Render()
{
}

void game::renders::Render::draw()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD nulCoord;
	nulCoord.X = 0;
	nulCoord.Y = 0;
	COORD rbCoord;
	rbCoord.X = size_width - 1;
	rbCoord.Y = size_height - 1;

	SetConsoleTextAttribute(hOut, 31);
	SetConsoleCursorPosition(hOut, nulCoord);

	for (int i = 0; i < size_height; i++) {
		for (int j = 0; j < size_width; j++) {
			if (j == 0 && _CC_DBG_LINE_NMBS) {
				std::wcout << i;
				if (i < 10) {
					std::wcout << L" ";
				}
				j++;
			}
			else {
				std::wcout << screen[i][j];
			}
			if (j == (size_width - 1)) {
				std::wcout << std::endl;
			}
		}
	}
	SetConsoleCursorPosition(hOut, rbCoord);
	SetConsoleTextAttribute(hOut, 15);
}

void game::renders::Render::clearScreen()
{
	for (int i = 0; i < size_height; i++) {
		for (int j = 0; j < size_width; j++) {
			screen[i][j] = L' ';
		}
	}
}