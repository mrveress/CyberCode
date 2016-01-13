#pragma once

#include "stdafx.h"

class Utils
{
public:

	Utils()
	{
	}

	~Utils()
	{
	}

	static void SetWindowSize(int width, int height) {
		_COORD coord;
		coord.X = width;
		coord.Y = height;

		_SMALL_RECT Rect;
		Rect.Top = 0;
		Rect.Left = 0;
		Rect.Bottom = height - 1;
		Rect.Right = width - 1;

		HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleScreenBufferSize(Handle, coord);
		SetConsoleWindowInfo(Handle, TRUE, &Rect);
	}
};

