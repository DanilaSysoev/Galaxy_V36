#ifndef DRAWABLES_FACTORY_H
#define DRAWABLES_FACTORY_H

namespace galaxy_v36
{
	namespace game
	{
		class GalaxyDrawable;
		class StarSystemDrawable;
		class SpaceBodyDrawable;
	}

	namespace entities
	{
		class Galaxy;
		class StarSystem;
		class SpaceBody;
	}

	class DrawablesFactory
	{
	public:
		virtual game::GalaxyDrawable*     getGalaxyDrawable(entities::Galaxy* galaxy)                        = 0;
		virtual game::StarSystemDrawable* getStarSystemDrawable(entities::StarSystem* starSystem)            = 0;
		virtual game::SpaceBodyDrawable*  getSpaceBodyDrawable(entities::SpaceBody* spaceBody, int priority) = 0;

		virtual ~DrawablesFactory();
	};
}

#endif // !DRAWABLES_FACTORY_H

