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

	using namespace game;
	using namespace entities;

	class LibtcodDrawablesFactory : public DrawablesFactory
	{
	public:
		LibtcodDrawablesFactory();

		void prepareBuilding();

		virtual Camera* getGalaxyCamera() override;
		virtual Camera* getStarSystemCamera() override;
		virtual Camera* getSpaceBodyCamera() override;

		virtual GalaxyDrawable* 
			getGalaxyDrawable(Galaxy* galaxy) override;
		virtual StarSystemDrawable*	
			getStarSystemDrawable(StarSystem* starSystem) override;
		virtual SpaceBodyDrawable*
			getSpaceBodyDrawable(SpaceBody* spaceBody, int priority) override;

		virtual CommandHandler* getHandler(const std::string& tag) override;

	private:
		nlohmann::json drawablesConfigs;
		std::map<std::string, CommandHandler*> commandHandlers;

		std::string getDrawablesConfigFileName() const;

		static const std::string GALAXY_KEYWORD;
		static const std::string CAMERA_KEYWORD;
		static const std::string HANDLER_TAG_KEYWORD;
		static const std::string HANDLER_ORDER_KEYWORD;
	};
}

#endif // !LIBTCOD_DRAWABLES_FACTORY_H

