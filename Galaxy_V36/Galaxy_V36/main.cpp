#include "libtcod.hpp"
#include "GameFactory.h"
#include "GameFactoryBuilder.h"
#include "Game.h"

#include "LibtcodGame.h"

int main()
{
	galaxy_v36::game::Game* game = 
		galaxy_v36::buildGameFactory(
			galaxy_v36::GameType::LIBTCOD, 
			galaxy_v36::GalaxyBuildType::DUMMY,
			galaxy_v36::DrawablesType::LIBTCOD)->createGame();
	
	game->run();

	return 0;
}