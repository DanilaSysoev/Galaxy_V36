#ifndef DRAW_MANAGER_H
#define DRAW_MANAGER_H

namespace galaxy_v36
{
	namespace game
	{
		class Drawable;
		class Tile;

		class DrawManager
		{
		public:
			virtual void prepareDrawing() = 0;
			virtual void flush() = 0;

			void draw(Drawable* drawable);

			virtual ~DrawManager();
		private:
		};
	}
}
#endif  // !DRAW_MANAGER
