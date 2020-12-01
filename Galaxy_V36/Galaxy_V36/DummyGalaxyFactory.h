#ifndef DYMMY_GALAXY_FACTORY_H
#define DYMMY_GALAXY_FACTORY_H

#include "GalaxyFactory.h"

namespace galaxy_v36
{
	class DummyGalaxyFactory : public GalaxyFactory
	{
	public:
		virtual entities::Galaxy* buildGalaxy() override;
	};
}

#endif // !DYMMY_GALAXY_FACTORY_H

