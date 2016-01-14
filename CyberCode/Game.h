#pragma once

class Game
{
private:
	static int const size_width = 80;
	static int const size_height = 21;
	wchar_t screen[size_height][size_width];
public:
	Game();
	~Game();
	void start();
	void render();
	void clearScreen();
	void testStringToScreen(std::wstring str, int start_row, int start_col);
};

