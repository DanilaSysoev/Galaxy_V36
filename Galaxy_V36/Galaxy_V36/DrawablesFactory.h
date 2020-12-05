#ifndef DRAWABLES_FACTORY_H
#define DRAWABLES_FACTORY_H

#include <string>

namespace galaxy_v36
{
	namespace game
	{
		class GalaxyDrawable;
		class StarSystemDrawable;
		class SpaceBodyDrawable;
		class Camera;
		class CommandHandler;
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
		virtual game::Camera*             getGalaxyCamera()                                                  = 0;
		virtual game::GalaxyDrawable*     getGalaxyDrawable(entities::Galaxy* galaxy)                        = 0;

		virtual game::Camera*             getStarSystemCamera()                                              = 0;
		virtual game::StarSystemDrawable* getStarSystemDrawable(entities::StarSystem* starSystem)            = 0;

		virtual game::Camera*             getSpaceBodyCamera()                                               = 0;
		virtual game::SpaceBodyDrawable*  getSpaceBodyDrawable(entities::SpaceBody* spaceBody, int priority) = 0;

		virtual game::CommandHandler*     getHandler(const std::string& tag)                                 = 0;

		virtual ~DrawablesFactory();
	};
}

#endif // !DRAWABLES_FACTORY_H

