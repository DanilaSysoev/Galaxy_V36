#include "UpdateManager.h"
#include "Updatable.h"

galaxy_v36::game::UpdateManager::~UpdateManager() 
{
}

galaxy_v36::game::UpdateManager::UpdateManager()
	: game(nullptr)
{
}

void
galaxy_v36::game::UpdateManager::update(Updatable* updatable)
{
	if(updatable != nullptr)
		updatable->update(game);
}

galaxy_v36::game::Game* galaxy_v36::game::UpdateManager::getGame()
{
	return game;
}

void galaxy_v36::game::UpdateManager::setGame(Game* game)
{
	this->game = game;
}
