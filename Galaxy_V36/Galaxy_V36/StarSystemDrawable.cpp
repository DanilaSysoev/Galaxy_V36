#include "StarSystemDrawable.h"

galaxy_v36::game::StarSystemDrawable::StarSystemDrawable(entities::StarSystem* starSystem)
	: starSystem(starSystem)
{
}

galaxy_v36::entities::StarSystem*
galaxy_v36::game::StarSystemDrawable::getStarSystem()
{
	return starSystem;
}