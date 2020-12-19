#ifndef LOBTCOD_GAMEPLAY_H
#define LOBTCOD_GAMEPLAY_H

#include <set>
#include <string>

namespace galaxy_v36
{
	namespace game
	{
		class CommandHandler;
		class Drawable;

		namespace libtcod
		{
			class LibtcodGame;

			class LibtcodGameplay
			{
			public:
				LibtcodGameplay(const std::string& name);

				std::string getName() const;

				LibtcodGame* getGame() const;
				void setGame(LibtcodGame* game);

				void activate();
				void deactivate();
				bool isActive();

				void addHandler(CommandHandler* handler);
				void deleteHandler(CommandHandler* handler);

				const std::set<Drawable*>& getDrawables() const;
				void addDrawable(Drawable* drawable);
				void deleteDrawable(Drawable* drawable);


			private:
				std::string name;

				LibtcodGame* game;
				bool active;

				std::set<CommandHandler*> handlers;
				std::set<Drawable*> drawables;
			};
		}
	}
}

#endif // !LOBTCOD_GAMEPLAY_H

