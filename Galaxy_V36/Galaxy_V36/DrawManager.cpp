#include "Drawable.h"
#include"DrawManager.h"

using namespace galaxy_v36::game;


DrawManager::DrawManager()
	: game(nullptr)
{
}

void DrawManager::draw(Drawable* drawable)
{
	if (drawable != nullptr)
		drawable->draw();
}

Game* DrawManager::getGame()
{
	return game;
}

void DrawManager::initialize(Game* game)
{
	this->game = game;
}

DrawManager::~DrawManager() 
{
}