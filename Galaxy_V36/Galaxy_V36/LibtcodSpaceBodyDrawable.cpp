#include "LibtcodSpaceBodyDrawable.h"

using namespace galaxy_v36::game;
using namespace galaxy_v36::entities;
using namespace galaxy_v36::game::libtcod;

LibtcodSpaceBodyDrawable::LibtcodSpaceBodyDrawable(
	Camera* camera,
	SpaceBody* spaceBody,
	int drawPriority
)
	: SpaceBodyDrawable(camera, spaceBody)
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
