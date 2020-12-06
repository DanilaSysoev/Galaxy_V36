#include "GameFactory.h"
#include "Game.h"

using namespace galaxy_v36;
using namespace galaxy_v36::game;


Game* GameFactory::createGame()
{
	prepareBuilding();

	auto game = buildGame();
	auto commandProcessor = buildCommandProcessor();
	auto drawManager = buildDrawManager();
	auto updateManager = buildUpdateManager();

	game->initialize(drawManager, commandProcessor, updateManager);

	linkCommands();

	return game;
}

GameFactory::~GameFactory()
{
}