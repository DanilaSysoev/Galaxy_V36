#ifndef LIBTCOD_GALAXY_DRAWABLE_H
#define LIBTCOD_GALAXY_DRAWABLE_H

#include "GalaxyDrawable.h"

namespace galaxy_v36
{
	namespace game
	{
		namespace libtcod
		{
			class LibtcodGalaxyDrawable : GalaxyDrawable
			{
				virtual void draw() override;
			};
		}
	}
}

#endif // !LIBTCOD_GALAXY_DRAWABLE_H

