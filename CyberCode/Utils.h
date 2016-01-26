#pragma once
namespace game{
	class Utils
	{
	public:
		Utils(){}
		~Utils(){}
		static void SetWindowSize(int width, int height) {
			/* _COORD coord;
			coord.X = width;
			coord.Y = height;

			_SMALL_RECT Rect;
			Rect.Top = 0;
			Rect.Left = 0;
			Rect.Bottom = height - 1;
			Rect.Right = width -1;

			HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleScreenBufferSize(Handle, coord);
			SetConsoleWindowInfo(Handle, TRUE, &Rect); */

			const char *tmplcommand = "mode con: cols=%d lines=%d";
			char *command = new char[(sizeof(tmplcommand) / sizeof(char)) + 32];
			sprintf(command, tmplcommand, width + 1, height + 1);
			system(command);
			delete[] command;
		}
		template < typename T > std::wstring to_wstring(const T& n){
			std::wstringstream stm;
			stm << n;
			return stm.str();
		}

	};

	class Coords
	{
	public:
		Coords(int x, int y){
			this->x = x;
			this->y = y;
		}
		~Coords();
		int x, y;
	};
}

