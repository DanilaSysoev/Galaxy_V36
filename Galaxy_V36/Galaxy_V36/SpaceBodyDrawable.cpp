#include "SpaceBodyDrawable.h"
#include "Camera.h"

using namespace galaxy_v36::game;
using namespace galaxy_v36::entities;


SpaceBodyDrawable::SpaceBodyDrawable(
	Camera* camera,
	entities::SpaceBody* spaceBody
)
	: camera(camera)
	, spaceBody(spaceBody)
{
}

SpaceBody* SpaceBodyDrawable::getSpaceBody()
{
	return spaceBody;
}

Camera* SpaceBodyDrawable::getCamera() const
{
	return camera;
}

SpaceBodyDrawable::~SpaceBodyDrawable()
{
	delete camera;
}
