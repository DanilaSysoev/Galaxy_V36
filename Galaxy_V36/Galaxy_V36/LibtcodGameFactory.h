#ifndef LIBTCOD_GAME_FACTORY_H
#define LIBTCOD_GAME_FACTORY_H

#include "GameFactory.h"

namespace galaxy_v36
{
	class GalaxyFactory;
	class DrawablesFactory;

	namespace game
	{
		namespace libtcod
		{
			class LibtcodGame;
			class LibtcodUpdateManager;
			class LibtcodDrawManager;
			class LibtcodCommandProcessor;
		}
	}

	class LibtcodGameFactory : public GameFactory
	{
	public:
		LibtcodGameFactory(GalaxyFactory* galaxyFactory, DrawablesFactory* drawablesFactory);
		virtual ~LibtcodGameFactory();


	protected:
		virtual game::Game*             buildGame()             override;
		virtual game::UpdateManager*    buildUpdateManager()    override;
		virtual game::DrawManager*      buildDrawManager()      override;
		virtual game::CommandProcessor* buildCommandProcessor() override;
		virtual void                    linkCommands()          override;


	private:
		GalaxyFactory* galaxyFactory;
		DrawablesFactory* drawablesFactory;

		game::libtcod::LibtcodGame*             game;
		game::libtcod::LibtcodUpdateManager*    updateManager;
		game::libtcod::LibtcodDrawManager*      drawManager;
		game::libtcod::LibtcodCommandProcessor* commandProcessor;
	};
}

#endif  // !LIBTCOD_GAME_FACTORY_H
