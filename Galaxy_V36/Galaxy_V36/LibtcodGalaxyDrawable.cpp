#include "LibtcodGalaxyDrawable.h"
#include "Galaxy.h"
#include "StarSystem.h"
#include "LibtcodCamera.h"
#include "libtcod.hpp"

galaxy_v36::game::libtcod::LibtcodGalaxyDrawable::LibtcodGalaxyDrawable(Camera* camera, entities::Galaxy* galaxy)
	: GalaxyDrawable(camera, galaxy)
{
}

int galaxy_v36::game::libtcod::LibtcodGalaxyDrawable::getDrawPriority() const
{
	return GALAXY_HIGHEST_DRAW_PRIORITY;
}

void 
galaxy_v36::game::libtcod::LibtcodGalaxyDrawable::draw()
{
	for (int i = 0; i < getGalaxy()->getStarSystemsCount(); ++i)
	{
		auto position = getGalaxy()->getStarSystem(i)->getPosition();		
		TCODConsole::root->putChar(position.getX(), position.getY(), TCOD_CHAR_LIGHT);
		TCODConsole::root->setCharForeground(position.getX(), position.getY(), TCODColor::gold);

		TCODConsole::root->printf(position.getX() + 1, position.getY() + 1, getGalaxy()->getStarSystem(i)->getName().c_str());
	}
}


const int galaxy_v36::game::libtcod::LibtcodGalaxyDrawable::GALAXY_HIGHEST_DRAW_PRIORITY = 1000000;