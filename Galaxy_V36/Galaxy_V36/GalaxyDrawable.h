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
		class GalaxyDrawable : public Drawable
		{
		public:
			GalaxyDrawable(entities::Galaxy* galaxy);

			entities::Galaxy* getGalaxy();
		private:
			entities::Galaxy* galaxy;
		};
	}
}

#endif  // !GALAXY_DRAWABLE_H

