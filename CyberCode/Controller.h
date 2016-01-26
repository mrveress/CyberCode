#pragma once
namespace game {
	namespace controllers {
		class Controller
		{
		private:
			game::actors::User* user;
			game::renders::Render* render;
		public:
			Controller();
			~Controller();
			void setUser(game::actors::User* user);
			void setRender(game::renders::Render* render);
			void startHandling();
		};
	}
}

