#ifndef LIBTCOD_DRAWABLES_FACTORY_H
#define LIBTCOD_DRAWABLES_FACTORY_H

#include "DrawablesFactory.h"

namespace galaxy_v36
{
	class LibtcodDrawablesFactory : public DrawablesFactory
	{
	public:
		virtual game::GalaxyDrawable*     getGalaxyDrawable(entities::Galaxy* galaxy)                        override;
		virtual game::StarSystemDrawable* getStarSystemDrawable(entities::StarSystem* starSystem)            override;
		virtual game::SpaceBodyDrawable*  getSpaceBodyDrawable(entities::SpaceBody* spaceBody, int priority) override;
	};
}

#endif // !LIBTCOD_DRAWABLES_FACTORY_H

