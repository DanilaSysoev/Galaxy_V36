#ifndef STAR_SYSTEM_DRAWABLE_H
#define STAR_SYSTEM_DRAWABLE_H

#include "Drawable.h"

namespace galaxy_v36
{
	namespace entities
	{
		class StarSystem;
	}

	namespace game
	{
		class StarSystemDrawable : public Drawable
		{
		public:
			StarSystemDrawable(entities::StarSystem* starSystem);
			entities::StarSystem* getStarSystem();


		private:
			entities::StarSystem* starSystem;
		};
	}
}

#endif // !STAR_SYSTEM_DRAWABLE_H

