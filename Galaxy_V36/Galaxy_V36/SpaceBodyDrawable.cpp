#include "SpaceBodyDrawable.h"

galaxy_v36::game::SpaceBodyDrawable::SpaceBodyDrawable(Camera* camera, entities::SpaceBody* spaceBody)
	: camera(camera)
	, spaceBody(spaceBody)
{
}

galaxy_v36::entities::SpaceBody*
galaxy_v36::game::SpaceBodyDrawable::getSpaceBody()
{
	return spaceBody;
}

galaxy_v36::game::Camera*
galaxy_v36::game::SpaceBodyDrawable::getCamera() const
{
	return camera;
}

galaxy_v36::game::SpaceBodyDrawable::~SpaceBodyDrawable()
{
	delete camera;
}
