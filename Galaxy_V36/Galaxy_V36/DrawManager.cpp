#include "Drawable.h"
#include"DrawManager.h"

void 
galaxy_v36::game::DrawManager::draw(Drawable* drawable)
{
	if (drawable != nullptr)
		drawable->draw();
}

galaxy_v36::game::DrawManager::~DrawManager() 
{
}