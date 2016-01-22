#pragma once

class Game
{
private:
public:
	Game();
	~Game();
	void start();
	void render();
	void clearScreen();
	void testStringToScreen(std::wstring str, int start_row, int start_col);
};

