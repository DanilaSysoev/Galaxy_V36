#ifndef LIBTCOD_GAME_FACTORY_H
#define LIBTCOD_GAME_FACTORY_H

#include <string>
#include <nlohmann/json.hpp>
#include "libtcod.hpp"
#include "GameFactory.h"
#include "CommandHandlerProvider.h"

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

		class CommandHandler;
	}

	class LibtcodGameFactory : 
		public GameFactory, 
		public game::CommandHandlerProvider
	{
	public:
		LibtcodGameFactory(
			GalaxyFactory* galaxyFactory,
			DrawablesFactory* drawablesFactory
		);

		virtual game::CommandHandler* getHandler(const std::string& tag);

		virtual ~LibtcodGameFactory();


	protected:
		virtual void                    prepareBuilding()       override;
		virtual game::Game*             buildGame()             override;
		virtual game::UpdateManager*    buildUpdateManager()    override;
		virtual game::DrawManager*      buildDrawManager()      override;
		virtual game::CommandProcessor* buildCommandProcessor() override;
		virtual void                    postprocess()           override;


	private:
		GalaxyFactory* galaxyFactory;
		DrawablesFactory* drawablesFactory;

		nlohmann::json commandLinksConfigs;
		nlohmann::json commandAssignsConfigs;
		nlohmann::json consolesConfigs;
		nlohmann::json gameConfigs;

		game::libtcod::LibtcodGame*             game;
		game::libtcod::LibtcodUpdateManager*    updateManager;
		game::libtcod::LibtcodDrawManager*      drawManager;
		game::libtcod::LibtcodCommandProcessor* commandProcessor;
		
		std::map<std::string, game::CommandHandler*> commandHandlers;


		static std::string getCommandLinksFileName();
		static std::string getCommandAssignsFileName();
		static std::string getConsolesFileName();
		static std::string getGameFileName();

		void linkCommands();
		void assignKeys();
		void setupConsoles();

		void setupRoot(const nlohmann::json& consoleConfig);
		void setupConsole(const nlohmann::json& consoleConfig);

		TCODColor parseColor(const nlohmann::json& consoleConfig);

		static const std::string KEYBOARD_COMMAND_TYPE_KEYWORD;

		static const std::string GAME_KEYWORD;

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
