#ifndef LIBTCOD_GAME_H
#define LIBTCOD_GAME_H

#include "Game.h"

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
			class LibtcodGame : public Game
			{
			public:
				LibtcodGame(entities::Galaxy* galaxy);

				virtual entities::Galaxy* getGalaxy() override;

				~LibtcodGame();


			protected:
				virtual void              prepareGame()     override;
				virtual void              finishGame()      override;
				virtual bool              isGameEnd() const override;
				virtual Drawables&        getDravables()    override;
				virtual Updatables&       getUpdatables()   override;

			private:
				Drawables drawables;
				Updatables updatables;

				entities::Galaxy* galaxy;

				enum class Gameplay
				{
					GALAXY_LEVEL,
					STAR_SYSTEM_LEVEL,
					SPACE_BODY_LEVEL
				};

				Gameplay gameplay;

				void switchToGameplay(const Gameplay& gameplay);
			};
		}
	}
}

#endif  // !LIBTCOD_GAME_H
