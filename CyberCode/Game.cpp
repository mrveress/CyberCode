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
	Utils::SetWindowSize(size_width, size_height);
	system("cls");
	setlocale(LC_ALL, "Russian");
	int chcode = -1;
	int cur_x = 0;
	int cur_y = 0;
	while (chcode != CTRL_C) {
		if (chcode == ARROW_HEAD_AP || chcode == ARROW_HEAD_NP)
		{
			switch (_getch())
			{
			case ARROW_UP:
				cur_y--;
				if (cur_y < 0) {
					cur_y = size_height - 1;
				}
				break;
			case ARROW_DOWN:
				cur_y++;
				if (cur_y >= size_height) {
					cur_y = 0;
				}
				break;
			case ARROW_LEFT:
				cur_x--;
				if (cur_x < 0) {
					cur_x = size_width - 1;
				}
				break;
			case ARROW_RIGHT:
				cur_x++;
				if (cur_x >= size_width) {
					cur_x = 0;
				}
				break;
			}
		}
		clearScreen();
		testStringToScreen(L"This is unicode string and она должна показывать кириллицу", cur_y, cur_x);
		render();
		chcode = _getch();
		if (_CC_DBG_LINE_NMBS) {
			OutputDebugStringW(std::to_wstring(chcode).c_str());
			OutputDebugStringW(L"\r\n");
		}
	}
}

void Game::render()
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
		}
		if (cur_row >= size_height) {
			cur_row = 0;
		}
		screen[cur_row][cur_col] = str.at(i);
		cur_col++;
	}
}
