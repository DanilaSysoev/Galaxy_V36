#ifndef LIBTCOD_GAME_H
#define LIBTCOD_GAME_H

#include <map>
#include <string>
#include <vector>

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
			class LibtcodGameplay;

			class LibtcodGame : 
				public Game, 
				public CommandHandler
			{
			public:
				LibtcodGame(
					entities::Galaxy* galaxy,
					const std::vector<LibtcodGameplay*>& gameplays,
					const std::string& startGameplayName,
					const std::vector<Drawable*>& baseDrawables
				);

				virtual entities::Galaxy* getGalaxy() override;
								
				virtual int getOrder() const override;

				LibtcodGameplay* getGameplay(std::string name);

				~LibtcodGame();


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

				std::vector<Drawable*> baseDrawables;

				std::map<std::string, LibtcodGameplay*> namedGameplays;
				LibtcodGameplay* gameplay;

				entities::Galaxy* galaxy;				

				void switchToGameplay(const std::string& gameplayName);
			};
		}
	}
}

#endif  // !LIBTCOD_GAME_H
