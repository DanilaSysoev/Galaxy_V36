#ifndef DRAWABLE_H
#define DRAWABLE_H

namespace galaxy_v36
{
	namespace game
	{
		class Game;

		class Drawable
		{
		public:
			virtual void draw() = 0;
			virtual int getDrawPriority() const = 0;

			virtual ~Drawable();
		};
	}
}

#endif // !DRAWABLE_H
