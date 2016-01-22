#pragma once
namespace game {
	namespace controllers {
		class Controller
		{
		private:
			game::actors::User* user;
		public:
			Controller();
			~Controller();
			void setUser(game::actors::User* user);
			void startHandling();
		};
	}
}

