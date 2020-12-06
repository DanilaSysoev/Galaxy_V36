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
				LibtcodGalaxyDrawable(
					Camera* camera, 
					entities::Galaxy* galaxy
				);

				virtual void draw() override;
				virtual int getDrawPriority() const override;

				static const int GALAXY_HIGHEST_DRAW_PRIORITY;
			};
		}
	}
}

#endif // !LIBTCOD_GALAXY_DRAWABLE_H

