#ifndef GAME_H
#define GAME_H

#include <vector>
#include <set>
#include "Drawable.h"
#include "Updatable.h"

namespace galaxy_v36
{
	namespace entities
	{
		class Galaxy;
	}

	namespace game
	{
		class DrawManager;
		class CommandProcessor;
		class UpdateManager;
		class Drawable;
		class Updatable;


		class DrawableComparator
		{
			bool operator()(const Drawable*& left, const Drawable*& right);
		};
		class UpdatableComparator
		{
			bool operator()(const Updatable*& left, const Updatable*& right);
		};

		using Drawables = std::multiset<Drawable*, DrawableComparator>;
		using Updatables = std::multiset<Updatable*, UpdatableComparator>;

		class Game
		{
		public:
			Game();

			void run();
			void initialize( DrawManager* drawManager
				           , CommandProcessor* commandProcesor
				           , UpdateManager* updateManager);

			virtual galaxy_v36::entities::Galaxy* getGalaxy() = 0;

			DrawManager*      getDrawManager();
			CommandProcessor* getCommandProcessor();
			UpdateManager*    getUpdateManager();

			virtual ~Game();


		protected:
			virtual void prepareGame()     = 0;
			virtual void finishGame()      = 0;
			virtual bool isGameEnd() const = 0;

			virtual Drawables& getDravables() = 0;
			virtual Updatables& getUpdatables() = 0;

		private:
			DrawManager* drawManager;
			CommandProcessor* commandProcessor;
			UpdateManager* updateManager;

			void drawAll();
			void updateAll();
		};
	}
}
#endif  // !GAME_H
