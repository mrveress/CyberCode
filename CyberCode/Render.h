#pragma once
#include "Utils.h"
namespace game {
	namespace renders {
		class Render
		{
		public:
			static int const size_width = 80;
			static int const size_height = 21;
			void clearScreen();
			wchar_t** getScreen();
			wchar_t* getCell(game::Coords* coords);
			void draw();
			Render();
			~Render();
		private:
			wchar_t** screen;
		};
	}
}

