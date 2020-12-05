#ifndef DRAW_MANAGER_H
#define DRAW_MANAGER_H

namespace galaxy_v36
{
	namespace game
	{
		class Drawable;		
		class Game;

		class DrawManager
		{
		public:
			DrawManager();

			virtual void prepareDrawing() = 0;
			virtual void flush() = 0;

			void draw(Drawable* drawable);
			Game* getGame();
			void setGame(Game* game);

			virtual ~DrawManager();


		private:
			Game* game;
		};
	}
}
#endif  // !DRAW_MANAGER
