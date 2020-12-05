#include "GameFactory.h"
#include "Game.h"

galaxy_v36::game::Game* 
galaxy_v36::GameFactory::createGame()
{
	auto game = buildGame();
	auto commandProcessor = buildCommandProcessor();
	auto drawManager = buildDrawManager();
	auto updateManager = buildUpdateManager();

	game->initialize(drawManager, commandProcessor, updateManager);

	linkCommands();

	return game;
}

galaxy_v36::GameFactory::~GameFactory()
{}