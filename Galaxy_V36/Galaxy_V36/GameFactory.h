#ifndef GAME_FACTORY_H
#define GAME_FACTORY_H

#include "GameType.h"

namespace galaxy_v36
{
	namespace game
	{
		class Game;
		class UpdateManager;
		class DrawManager;
		class CommandProcessor;
	}

	class GameFactory
	{
	public:
		game::Game* createGame();

		virtual ~GameFactory();


	protected:
		virtual game::Game* buildGame() = 0;
		virtual game::UpdateManager* buildUpdateManager() = 0;
		virtual game::DrawManager* buildDrawManager() = 0;
		virtual game::CommandProcessor* buildCommandProcessor() = 0;
	};
}

#endif // !GAME_FACTORY_H

