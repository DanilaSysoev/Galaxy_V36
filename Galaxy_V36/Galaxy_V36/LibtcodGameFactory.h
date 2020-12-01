#ifndef LIBTCOD_GAME_FACTORY_H
#define LIBTCOD_GAME_FACTORY_H

#include "GameFactory.h"

namespace galaxy_v36
{
	class GalaxyFactory;

	class LibtcodGameFactory : public GameFactory
	{
	public:
		LibtcodGameFactory(GalaxyFactory* galaxyFactory);
		virtual ~LibtcodGameFactory();


	protected:
		virtual game::Game*             buildGame();
		virtual game::UpdateManager*    buildUpdateManager();
		virtual game::DrawManager*      buildDrawManager();
		virtual game::CommandProcessor* buildCommandProcessor();

	private:
		GalaxyFactory* galaxyFactory;
	};
}

#endif  // !LIBTCOD_GAME_FACTORY_H
