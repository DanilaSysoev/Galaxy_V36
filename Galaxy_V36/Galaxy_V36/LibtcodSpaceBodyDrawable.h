#ifndef LIBTCOD_SPACE_BODY_DRAWABLE_H
#define LIBTCOD_SPACE_BODY_DRAWABLE_H

#include "SpaceBodyDrawable.h"

namespace galaxy_v36
{
	namespace entities
	{
		class SpaceBody;
	}

	namespace game
	{
		namespace libtcod
		{
			class LibtcodSpaceBodyDrawable : public SpaceBodyDrawable
			{
			public:
				LibtcodSpaceBodyDrawable(entities::SpaceBody* spaceBody, int drawPriority);

				virtual int getDrawPriority() const override;
				virtual void draw() override;


			private:
				int drawPriority;
			};
		}
	}
}

#endif // !LIBTCOD_SPACE_BODY_DRAWABLE_H

