#ifndef SPACE_BODY_DRAWABLE_H
#define SPACE_BODY_DRAWABLE_H

#include "Drawable.h"

namespace galaxy_v36
{
	namespace entities
	{
		class SpaceBody;
	}

	namespace game
	{
		class SpaceBodyDrawable : public Drawable
		{
		public:
			SpaceBodyDrawable(entities::SpaceBody* spaceBody);
			entities::SpaceBody* getSpaceBody();


		private:
			entities::SpaceBody* spaceBody;
		};
	}
}

#endif // !SPACE_BODY_DRAWABLE_H

