#ifndef LIBTCOD_DRAWABLES_FACTORY_H
#define LIBTCOD_DRAWABLES_FACTORY_H

#include <string>

#include <nlohmann/json.hpp>

#include "DrawablesFactory.h"

namespace galaxy_v36
{
	class LibtcodDrawablesFactory : public DrawablesFactory
	{
	public:
		void readConfig();

		virtual game::Camera*             getGalaxyCamera()                                                  override;
		virtual game::GalaxyDrawable*     getGalaxyDrawable(entities::Galaxy* galaxy)                        override;

		virtual game::Camera* getStarSystemCamera()                                                          override;
		virtual game::StarSystemDrawable* getStarSystemDrawable(entities::StarSystem* starSystem)            override;

		virtual game::Camera*  getSpaceBodyCamera()                                                          override;
		virtual game::SpaceBodyDrawable*  getSpaceBodyDrawable(entities::SpaceBody* spaceBody, int priority) override;


	private:
		nlohmann::json drawablesConfigs;

		std::string getDrawablesConfigFileName() const;
	};
}

#endif // !LIBTCOD_DRAWABLES_FACTORY_H

