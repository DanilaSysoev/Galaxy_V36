#include "LibtcodSpaceBodyDrawable.h"

galaxy_v36::game::libtcod::LibtcodSpaceBodyDrawable::LibtcodSpaceBodyDrawable(entities::SpaceBody* spaceBody, int drawPriority)
	: SpaceBodyDrawable(spaceBody)
	, drawPriority(drawPriority)
{
}

int 
galaxy_v36::game::libtcod::LibtcodSpaceBodyDrawable::getDrawPriority() const
{
	return drawPriority;
}

void 
galaxy_v36::game::libtcod::LibtcodSpaceBodyDrawable::draw()
{
	// TODO
}
