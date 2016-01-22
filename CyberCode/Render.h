#pragma once
namespace game {
	namespace renders {
		class Render
		{
		public:
			static int const size_width = 80;
			static int const size_height = 21;
			void clearScreen();
			wchar_t* getScreen();
			void draw();
			Render();
			~Render();
		private:
			wchar_t screen[size_height][size_width];
		};
	}
}

