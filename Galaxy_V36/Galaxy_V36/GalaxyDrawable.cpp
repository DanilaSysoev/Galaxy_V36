#include "GalaxyDrawable.h"

galaxy_v36::game::GalaxyDrawable::GalaxyDrawable(Camera* camera, entities::Galaxy* galaxy)
	: camera(camera)
	, galaxy(galaxy)
{
}

galaxy_v36::game::Camera*
galaxy_v36::game::GalaxyDrawable::getCamera()
{
	return camera;
}

galaxy_v36::entities::Galaxy*
galaxy_v36::game::GalaxyDrawable::getGalaxy()
{
	return galaxy;
}

galaxy_v36::game::GalaxyDrawable::~GalaxyDrawable()
{
	delete camera;
}
