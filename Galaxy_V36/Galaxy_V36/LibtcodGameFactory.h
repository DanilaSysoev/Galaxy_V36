#ifndef LIBTCOD_GAME_FACTORY_H
#define LIBTCOD_GAME_FACTORY_H

#include "GameFactory.h"

namespace galaxy_v36
{
	class LibtcodGameFactory : public GameFactory
	{
	protected:
		virtual game::Game*             buildGame();
		virtual game::UpdateManager*    buildUpdateManager();
		virtual game::DrawManager*      buildDrawManager();
		virtual game::CommandProcessor* buildCommandProcessor();
	};
}

#endif  // !LIBTCOD_GAME_FACTORY_H
