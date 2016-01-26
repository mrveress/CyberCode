#pragma once
#include "Utils.h"
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
			game::Coords* coords; //Coords

		public:
			void move(short x, short y);
			void move(int DIR);
			game::Coords* getCoords();
			User();
			~User();
		};
	}
}
