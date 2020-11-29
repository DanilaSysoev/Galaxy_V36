#include "libtcod.hpp"
#include "GameFactory.h"
#include "Game.h"

#include "LibtcodGame.h"

int main()
{
	galaxy_v36::game::Game* game = 
		galaxy_v36::GameFactory::getFactory(galaxy_v36::GameType::LIBTCOD)->createGame();
	
	game->run();

	return 0;
}