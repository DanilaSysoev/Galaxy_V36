#ifndef LIBTCOD_DRAWABLES_FACTORY_H
#define LIBTCOD_DRAWABLES_FACTORY_H

#include <string>
#include <map>

#include <nlohmann/json.hpp>

#include "DrawablesFactory.h"

namespace galaxy_v36
{
	namespace game
	{
		class CommandHandler;
	}

	class LibtcodDrawablesFactory : public DrawablesFactory
	{
	public:
		LibtcodDrawablesFactory();

		void prepareBuilding();

		virtual game::Camera*             getGalaxyCamera()                                                  override;
		virtual game::GalaxyDrawable*     getGalaxyDrawable(entities::Galaxy* galaxy)                        override;

		virtual game::Camera*             getStarSystemCamera()                                              override;
		virtual game::StarSystemDrawable* getStarSystemDrawable(entities::StarSystem* starSystem)            override;

		virtual game::Camera*             getSpaceBodyCamera()                                               override;
		virtual game::SpaceBodyDrawable*  getSpaceBodyDrawable(entities::SpaceBody* spaceBody, int priority) override;

		virtual game::CommandHandler*     getHandler(const std::string& tag)                                 override;

	private:
		nlohmann::json drawablesConfigs;
		std::map<std::string, game::CommandHandler*> commandHandlers;

		std::string getDrawablesConfigFileName() const;

		static const std::string GALAXY_KEYWORD;
		static const std::string CAMERA_KEYWORD;
		static const std::string HANDLER_TAG_KEYWORD;
		static const std::string HANDLER_ORDER_KEYWORD;
	};
}

#endif // !LIBTCOD_DRAWABLES_FACTORY_H

