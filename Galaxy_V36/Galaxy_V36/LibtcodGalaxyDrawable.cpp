#include "LibtcodGalaxyDrawable.h"

galaxy_v36::game::libtcod::LibtcodGalaxyDrawable::LibtcodGalaxyDrawable(entities::Galaxy* galaxy)
	: GalaxyDrawable(galaxy)
{
}

int galaxy_v36::game::libtcod::LibtcodGalaxyDrawable::getDrawPriority() const
{
	return GALAXY_HIGHEST_DRAW_PRIORITY;
}

const int galaxy_v36::game::libtcod::LibtcodGalaxyDrawable::GALAXY_HIGHEST_DRAW_PRIORITY = 1000000;

void 
galaxy_v36::game::libtcod::LibtcodGalaxyDrawable::draw()
{
	// TODO
}
