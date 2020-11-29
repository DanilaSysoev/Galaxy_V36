#include "GameFactory.h"
#include "Game.h"

galaxy_v36::game::Game* 
galaxy_v36::GameFactory::createGame()
{
	auto game = buildGame();
	auto drawManager = buildDrawManager();
	auto commandProcessor = buildCommandProcessor();
	auto updateManager = buildUpdateManager();

	game->initialize(drawManager, commandProcessor, updateManager);

	return game;
}

galaxy_v36::GameFactory::~GameFactory()
{}