#ifndef LIBTCOD_GALAXY_DRAWABLE_H
#define LIBTCOD_GALAXY_DRAWABLE_H

#include "GalaxyDrawable.h"

namespace galaxy_v36
{
	namespace entities
	{
		class Galaxy;
	}

	namespace game
	{
		namespace libtcod
		{
			class LibtcodGalaxyDrawable : public GalaxyDrawable
			{
			public:
				LibtcodGalaxyDrawable(entities::Galaxy* galaxy);

				virtual void draw() override;
			};
		}
	}
}

#endif // !LIBTCOD_GALAXY_DRAWABLE_H

