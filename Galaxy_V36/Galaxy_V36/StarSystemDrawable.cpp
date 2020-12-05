#include "StarSystemDrawable.h"
#include "Camera.h"

galaxy_v36::game::StarSystemDrawable::StarSystemDrawable(Camera* camera, entities::StarSystem* starSystem)
	: camera(camera)
	, starSystem(starSystem)
{
}

galaxy_v36::entities::StarSystem*
galaxy_v36::game::StarSystemDrawable::getStarSystem()
{
	return starSystem;
}

galaxy_v36::game::Camera*
galaxy_v36::game::StarSystemDrawable::getCamera() const
{
	return camera;
}

galaxy_v36::game::StarSystemDrawable::~StarSystemDrawable()
{
	delete camera;
}
