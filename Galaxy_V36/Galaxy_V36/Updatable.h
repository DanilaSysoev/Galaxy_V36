#ifndef UPDATABLE_H
#define UPDATABLE_H

namespace galaxy_v36
{
	namespace game
	{
		class Game;

		class Updatable
		{
		public:
			virtual void update(Game* game) = 0;
			virtual int getUpdatePriority() const = 0;

			virtual ~Updatable();
		};
	}
}

#endif // !UPDATABLE_H
