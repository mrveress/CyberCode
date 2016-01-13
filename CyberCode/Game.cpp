#include "stdafx.h"
#include "Game.h"
#include "Utils.h"


Game::Game()
{
	Utils::SetWindowSize(size_width + 1, size_height + 1);
	Utils::SetWindowSize(size_width + 1, size_height + 1);
	system("cls");
	setlocale(LC_ALL, "Russian");
	clearScreen();
	testStringToScreen(L"Htllo ��� my dear friend", 2, 2);
	render();
}


Game::~Game()
{
}

void Game::render()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD nulCoord;
	nulCoord.X = 0;
	nulCoord.Y = 0;

	SetConsoleTextAttribute(hOut, 31);
	SetConsoleCursorPosition(hOut, nulCoord);

	for (int i = 0; i < size_height; i++) {
		for (int j = 0; j < size_width; j++) {
			if (j == 0) {
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

	SetConsoleTextAttribute(hOut, 15);
}

void Game::clearScreen()
{
	for (int i = 0; i < size_height; i++) {
		for (int j = 0; j < size_width; j++) {
			screen[i][j] = L' ';
		}
	}
}

void Game::testStringToScreen(std::wstring str, int start_row, int start_col)
{
	int str_len = str.size();
	int cur_row = start_row;
	int cur_col = start_col;
	for (int i = 0; i < str_len; i++) {
		if (cur_col >= size_width) {
			cur_col = 0;
			cur_row++;
		}
		if (cur_row >= size_height) {
			cur_row = 0;
		}
		screen[cur_row][cur_col] = str.at(i);
		cur_col++;
	}
}