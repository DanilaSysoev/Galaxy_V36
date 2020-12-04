#ifndef GALAXY_DRAWABLE_H
#define GALAXY_DRAWABLE_H

#include "Drawable.h"

namespace galaxy_v36
{
	namespace entities
	{
		class Galaxy;
	}

	namespace game
	{
		class Camera;

		class GalaxyDrawable : public Drawable
		{
		public:
			GalaxyDrawable(Camera* camera, entities::Galaxy* galaxy);

			Camera* getCamera();

			entities::Galaxy* getGalaxy();

			virtual ~GalaxyDrawable();
		private:
			entities::Galaxy* galaxy;
			Camera* camera;
		};
	}
}

#endif  // !GALAXY_DRAWABLE_H

