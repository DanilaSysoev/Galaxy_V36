#ifndef LIBTCOD_GAME_FACTORY_H
#define LIBTCOD_GAME_FACTORY_H

#include <string>

#include "nlohmann/json.hpp"

#include "GameFactory.h"

namespace galaxy_v36
{
	class GalaxyFactory;
	class DrawablesFactory;

	namespace game
	{
		namespace libtcod
		{
			class LibtcodGame;
			class LibtcodUpdateManager;
			class LibtcodDrawManager;
			class LibtcodCommandProcessor;
		}
	}

	class LibtcodGameFactory : public GameFactory
	{
	public:
		LibtcodGameFactory(
			GalaxyFactory* galaxyFactory,
			DrawablesFactory* drawablesFactory
		);

		virtual ~LibtcodGameFactory();


	protected:
		virtual void                    prepareBuilding()       override;
		virtual game::Game*             buildGame()             override;
		virtual game::UpdateManager*    buildUpdateManager()    override;
		virtual game::DrawManager*      buildDrawManager()      override;
		virtual game::CommandProcessor* buildCommandProcessor() override;
		virtual void                    linkCommands()          override;


	private:
		GalaxyFactory* galaxyFactory;
		DrawablesFactory* drawablesFactory;

		nlohmann::json commandLinks;
		nlohmann::json commandAssigns;

		game::libtcod::LibtcodGame*             game;
		game::libtcod::LibtcodUpdateManager*    updateManager;
		game::libtcod::LibtcodDrawManager*      drawManager;
		game::libtcod::LibtcodCommandProcessor* commandProcessor;

		std::string getCommandLinksFileName() const;
		std::string getCommandAssignsFileName() const;

		void readJson(const std::string& filename, nlohmann::json& jsonObject);

		static const std::string KEYBOARD_COMMAND_TYPE_KEYWORD;

		static const std::string LINKS_KEYWORD;
		static const std::string ASSIGNS_KEYWORD;
		static const std::string COMMAND_NAME_KEYWORD;
		static const std::string HANDLER_TAG_KEYWORD;
		static const std::string TYPE_KEYWORD;
		static const std::string KEY_KEYWORD;
	};
}

#endif  // !LIBTCOD_GAME_FACTORY_H
