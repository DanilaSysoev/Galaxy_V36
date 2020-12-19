#ifndef GAME_H
#define GAME_H

#include <set>
#include <string>
#include <vector>
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

		class DrawableComparator
		{
		public:
			bool operator()(Drawable* left, Drawable* right) const;
		};
		class UpdatableComparator
		{
		public:
			bool operator()(Updatable* left, Updatable* right) const;
		};


		using Drawables = std::multiset<Drawable*, DrawableComparator>;		
		using Updatables = std::multiset<Updatable*, UpdatableComparator>;


		class Game
		{
		public:
			Game();

			void run();
			void initialize(
				DrawManager* drawManager, 
				CommandProcessor* commandProcesor,
				UpdateManager* updateManager
			);

			virtual galaxy_v36::entities::Galaxy* getGalaxy() = 0;

			DrawManager*      getDrawManager();
			CommandProcessor* getCommandProcessor();
			UpdateManager*    getUpdateManager();

			virtual ~Game();

			static Game* getGame();


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

			static Game* game;

			void drawAll();
			void updateAll();
		};
	}
}
#endif  // !GAME_H
