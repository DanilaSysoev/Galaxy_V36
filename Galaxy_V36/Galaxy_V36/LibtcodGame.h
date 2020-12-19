#ifndef LIBTCOD_GAME_H
#define LIBTCOD_GAME_H

#include <map>
#include <string>

#include "Game.h"
#include "CommandHandler.h"

namespace galaxy_v36
{
	namespace entities
	{
		class Galaxy;
	}

	namespace game
	{
		namespace libtcod
		{
			class LibtcodGame : 
				public Game, 
				public CommandHandler
			{
			public:
				LibtcodGame(entities::Galaxy* galaxy);

				virtual entities::Galaxy* getGalaxy() override;
								
				virtual int getOrder() const override;

				~LibtcodGame();

				enum class Gameplay
				{
					NONE,
					GALAXY_LEVEL,
					STAR_SYSTEM_LEVEL,
					SPACE_BODY_LEVEL
				};


			protected:
				virtual void              prepareGame()     override;
				virtual void              finishGame()      override;
				virtual bool              isGameEnd() const override;
				virtual Drawables&        getDravables()    override;
				virtual Updatables&       getUpdatables()   override;

				virtual void executeProcess(
					const CommandArguments& arguments
				) override;

			private:
				Drawables drawables;
				Updatables updatables;

				entities::Galaxy* galaxy;				

				std::map<std::string, Gameplay> namedGameplays;

				Gameplay gameplay;

				void switchToGameplay(const Gameplay& gameplay);
				Gameplay getGameplayFromString(const std::string& gameplayName);

				static const std::string GALAXY_GAMEPLAY_NAME;
				static const std::string STAR_SYSTEM_GAMEPLAY_NAME;
				static const std::string SPACE_BODY_GAMEPLAY_NAME;
			};
		}
	}
}

#endif  // !LIBTCOD_GAME_H
