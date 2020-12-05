#include "Drawable.h"
#include"DrawManager.h"

galaxy_v36::game::DrawManager::DrawManager()
	: game(nullptr)
{
}

void
galaxy_v36::game::DrawManager::draw(Drawable* drawable)
{
	if (drawable != nullptr)
		drawable->draw();
}

galaxy_v36::game::Game*
galaxy_v36::game::DrawManager::getGame()
{
	return game;
}

void 
galaxy_v36::game::DrawManager::setGame(Game* game)
{
	this->game = game;
}

galaxy_v36::game::DrawManager::~DrawManager() 
{
}