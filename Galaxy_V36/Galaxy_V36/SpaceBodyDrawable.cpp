#include "SpaceBodyDrawable.h"

galaxy_v36::game::SpaceBodyDrawable::SpaceBodyDrawable(entities::SpaceBody* spaceBody)
	: spaceBody(spaceBody)
{
}

galaxy_v36::entities::SpaceBody*
galaxy_v36::game::SpaceBodyDrawable::getSpaceBody()
{
	return spaceBody;
}
