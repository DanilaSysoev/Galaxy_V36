#ifndef UPDATE_MANAGER_H
#define UPDATE_MANAGER_H

namespace galaxy_v36
{
	namespace game
	{
		class Updatable;
		class Game;

		class UpdateManager
		{
		public:
			UpdateManager();

			virtual void prepareUpdate() = 0;			
			virtual void endUpdate() = 0;

			void update(Updatable* updatable);
			Game* getGame();
			void setGame(Game* game);

			virtual ~UpdateManager();


		private:
			Game* game;
		};
	}
}
#endif // !UPDATE_MANAGER_H

