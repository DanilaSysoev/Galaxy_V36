#ifndef DRAW_MANAGER_H
#define DRAW_MANAGER_H

namespace galaxy_v36
{
	namespace game
	{
		class Drawable;

		class DrawManager
		{
		public:
			virtual void prepareDrawing() = 0;
			virtual void draw(Drawable* drawable) = 0;
			virtual void flush() = 0;

			virtual ~DrawManager();
		private:
		};
	}
}
#endif  // !DRAW_MANAGER
