#ifndef UPDATE_MANAGER_H
#define UPDATE_MANAGER_H

namespace galaxy_v36
{
	namespace game
	{
		class Updatable;

		class UpdateManager
		{
		public:
			virtual void prepareUpdate() = 0;
			virtual void update(Updatable* updatable) = 0;
			virtual void endUpdate() = 0;

			virtual ~UpdateManager();
		};
	}
}
#endif // !UPDATE_MANAGER_H

