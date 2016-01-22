#pragma once
namespace game {
	namespace actors {
		class User
		{
		private:
			double h; //Health
			double m; //Mana
			double lh; //Limit health
			double lm; //Limit mana
			double rh; //Regen health
			double rm; //Regen mana
			short speed;
			int coords[2]; //Coords
		public:
			void move(short x, short y);
			void move(int DIR);
			int* getCoords();
			User();
			~User();
		};
	}
}
