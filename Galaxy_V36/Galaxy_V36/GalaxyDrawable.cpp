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