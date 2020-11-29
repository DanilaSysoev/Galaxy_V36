#ifndef GAME_H
#define GAME_H
#include <vector>

namespace galaxy_v36
{
	namespace game
	{
		class DrawManager;
		class Drawable;
		class CommandProcessor;
		class UpdateManager;
		class Updatable;

		using Drawables = std::vector<Drawable*>;
		using Updatables = std::vector<Updatable*>;

		class Game
		{
		public:
			Game();

			void run();
			void initialize( DrawManager* drawManager
				           , CommandProcessor* commandProcesor
				           , UpdateManager* updateManager);

			virtual ~Game();


		protected:
			virtual void prepareGame()     = 0;
			virtual void finishGame()      = 0;
			virtual bool isGameEnd() const = 0;

			virtual Drawables& getDravables() = 0;
			virtual Updatables& getUpdatables() = 0;

		private:
			DrawManager* drawManager;
			CommandProcessor* commandProcesor;
			UpdateManager* updateManager;

			void drawAll();
			void updateAll();
		};
	}
}
#endif  // !GAME_H
