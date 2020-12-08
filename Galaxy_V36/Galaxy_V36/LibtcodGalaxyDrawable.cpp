#include "LibtcodGalaxyDrawable.h"
#include "LibtcodDrawManager.h"
#include "Galaxy.h"
#include "StarSystem.h"
#include "LibtcodCamera.h"
#include "Game.h"

#include "libtcod.hpp"

using namespace galaxy_v36::game;
using namespace galaxy_v36::entities;
using namespace galaxy_v36::game::libtcod;

LibtcodGalaxyDrawable::LibtcodGalaxyDrawable(
	Camera* camera, 
	Galaxy* galaxy
)
	: GalaxyDrawable(camera, galaxy)
	, LibtcodDrawablesComponent()
{
}

int LibtcodGalaxyDrawable::getDrawPriority() const
{
	return GALAXY_HIGHEST_DRAW_PRIORITY;
}

void LibtcodGalaxyDrawable::draw()
{
	auto console =
		static_cast<LibtcodDrawManager*>(
			Game::getGame()->getDrawManager()
		)->getConsole(getConsoleName());

	for (int i = 0; i < getGalaxy()->getStarSystemsCount(); ++i)
	{
		auto position = getGalaxy()->getStarSystem(i)->getPosition();		
		console->putChar(
			position.getX() - getCamera()->getPosition().getX(), 
			position.getY() - getCamera()->getPosition().getY(), 
			TCOD_CHAR_LIGHT
		);
		console->setCharForeground(
			position.getX() - getCamera()->getPosition().getX(), 
			position.getY() - getCamera()->getPosition().getY(),
			TCODColor::gold
		);
		console->printf(
			position.getX() - getCamera()->getPosition().getX() + 1,
			position.getY() - getCamera()->getPosition().getY() + 1,
			getGalaxy()->getStarSystem(i)->getName().c_str()
		);
	}
}


const int
LibtcodGalaxyDrawable::GALAXY_HIGHEST_DRAW_PRIORITY = 1000000;