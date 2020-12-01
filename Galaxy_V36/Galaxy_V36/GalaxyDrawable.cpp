#include "GalaxyDrawable.h"

galaxy_v36::game::GalaxyDrawable::GalaxyDrawable(entities::Galaxy* galaxy)
	: galaxy(galaxy)
{
}

galaxy_v36::entities::Galaxy* 
galaxy_v36::game::GalaxyDrawable::getGalaxy()
{
	return galaxy;
}

int galaxy_v36::game::GalaxyDrawable::getDrawPriority() const
{
	return GALAXY_HIGHEST_DRAW_PRIORITY;
}

const int galaxy_v36::game::GalaxyDrawable::GALAXY_HIGHEST_DRAW_PRIORITY = 1000000;