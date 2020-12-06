#include "StarSystemDrawable.h"
#include "Camera.h"

using namespace galaxy_v36::game;
using namespace galaxy_v36::entities;


StarSystemDrawable::StarSystemDrawable(
	Camera* camera,
	StarSystem* starSystem
)
	: camera(camera)
	, starSystem(starSystem)
{
}

StarSystem* StarSystemDrawable::getStarSystem()
{
	return starSystem;
}

Camera* StarSystemDrawable::getCamera() const
{
	return camera;
}

StarSystemDrawable::~StarSystemDrawable()
{
	delete camera;
}
