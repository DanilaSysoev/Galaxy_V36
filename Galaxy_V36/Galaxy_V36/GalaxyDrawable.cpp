#include "Camera.h"
#include "GalaxyDrawable.h"

using namespace galaxy_v36::game;
using namespace galaxy_v36::entities;


GalaxyDrawable::GalaxyDrawable(Camera* camera, Galaxy* galaxy)
	: camera(camera)
	, galaxy(galaxy)
{
}

Camera* GalaxyDrawable::getCamera() const
{
	return camera;
}

Galaxy* GalaxyDrawable::getGalaxy()
{
	return galaxy;
}

GalaxyDrawable::~GalaxyDrawable()
{
	delete camera;
}
