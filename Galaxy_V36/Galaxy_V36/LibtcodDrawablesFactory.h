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
		
		namespace libtcod
		{
			class LibtcodDrawManager;
		}
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
		Camera* galaxyCamera;
		Camera* starSystemCamera;
		Camera* spaceBodyCamera;

		nlohmann::json drawablesConfigs;
		std::map<std::string, CommandHandler*> commandHandlers;

		void buildStarSystemImages();
		Camera* buildCamera(const nlohmann::json& config);

		static std::string getDrawablesConfigFileName();

		static const std::string GALAXY_KEYWORD;
		static const std::string STAR_SYSTEM_KEYWORD;
		static const std::string CAMERA_KEYWORD;
		static const std::string HANDLER_TAG_KEYWORD;
		static const std::string HANDLER_ORDER_KEYWORD;
		static const std::string CONSOLE_KEYWORD;
		static const std::string IMAGES_KEYWORD;
	};
}

#endif // !LIBTCOD_DRAWABLES_FACTORY_H

