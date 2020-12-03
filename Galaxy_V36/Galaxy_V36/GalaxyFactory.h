#ifndef GALAXY_FACTORY_H
#define GALAXY_FACTORY_H

namespace galaxy_v36
{
	namespace entities
	{
		class Galaxy;
	}

	class DrawablesFactory;

	class GalaxyFactory
	{
	public:
		virtual entities::Galaxy* buildGalaxy(DrawablesFactory* drawablesFactory) = 0;
	};
}

#endif // !GALAXY_FACTORY_H

