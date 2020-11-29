#ifndef LIBTCOD_GAME_H
#define LIBTCOD_GAME_H

#include "Game.h"

namespace galaxy_v36
{
	namespace game
	{
		namespace libtcod
		{
			class LibtcodGame : public Game
			{
			public:
				LibtcodGame();
				~LibtcodGame();


			protected:
				virtual void prepareGame()          override;
				virtual void finishGame()           override;
				virtual bool isGameEnd() const      override;
				virtual Drawables& getDravables()   override;
				virtual Updatables& getUpdatables() override;


			private:
				Drawables drawables;
				Updatables updatables;
			};
		}
	}
}

#endif  // !LIBTCOD_GAME_H
