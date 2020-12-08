#ifndef LIBTCOD_GAME_FACTORY_H
#define LIBTCOD_GAME_FACTORY_H

#include <string>
#include <nlohmann/json.hpp>
#include "libtcod.hpp"
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
		virtual void                    postprocess()          override;


	private:
		GalaxyFactory* galaxyFactory;
		DrawablesFactory* drawablesFactory;

		nlohmann::json commandLinks;
		nlohmann::json commandAssigns;
		nlohmann::json consoles;

		game::libtcod::LibtcodGame*             game;
		game::libtcod::LibtcodUpdateManager*    updateManager;
		game::libtcod::LibtcodDrawManager*      drawManager;
		game::libtcod::LibtcodCommandProcessor* commandProcessor;

		static std::string getCommandLinksFileName();
		static std::string getCommandAssignsFileName();
		static std::string getConsolesFileName();

		void linkCommands();
		void assignKeys();
		void setupConsoles();

		void setupRoot(const nlohmann::json& consoleConfig);
		void setupConsole(const nlohmann::json& consoleConfig);

		TCODColor parseColor(const nlohmann::json& consoleConfig);

		static const std::string KEYBOARD_COMMAND_TYPE_KEYWORD;

		static const std::string LINKS_KEYWORD;
		static const std::string ASSIGNS_KEYWORD;
		static const std::string COMMAND_NAME_KEYWORD;
		static const std::string HANDLER_TAG_KEYWORD;
		static const std::string TYPE_KEYWORD;
		static const std::string KEY_KEYWORD;

		static const std::string WIDTH_KEYWORD;
		static const std::string HEIGHT_KEYWORD;
		static const std::string X_KEYWORD;
		static const std::string Y_KEYWORD;
		static const std::string BACKGROUND_KEYWORD;
		static const std::string FOREGROUND_KEYWORD;
		static const std::string TITLE_KEYWORD;
		static const std::string CONSOLES_KEYWORD;
		static const std::string NAME_KEYWORD;
		static const std::string PARENT_KEYWORD;

		static const std::string ROOT_CONSOLE_NAME;
	};
}

#endif  // !LIBTCOD_GAME_FACTORY_H
