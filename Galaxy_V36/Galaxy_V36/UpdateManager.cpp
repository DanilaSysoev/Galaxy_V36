#include "UpdateManager.h"
#include "Updatable.h"

using namespace galaxy_v36::game;


UpdateManager::~UpdateManager() 
{
}

UpdateManager::UpdateManager()
	: game(nullptr)
{
}

void UpdateManager::update(Updatable* updatable)
{
	if(updatable != nullptr)
		updatable->update(game);
}

Game* UpdateManager::getGame()
{
	return game;
}

void UpdateManager::setGame(Game* game)
{
	this->game = game;
}
