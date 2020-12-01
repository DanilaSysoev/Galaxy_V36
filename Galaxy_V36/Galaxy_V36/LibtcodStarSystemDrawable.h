#ifndef LIBTCOD_STAR_SYSTEM_DRAWABLE_H
#define LIBTCOD_STAR_SYSTEM_DRAWABLE_H

#include "StarSystemDrawable.h"

namespace galaxy_v36
{
	namespace game
	{
		namespace libtcod
		{
			class LibtcodStarSystemDrawable : public StarSystemDrawable
			{
			public:
				virtual int getDrawPriority() const override;
				virtual void draw() override;

				static const int STAR_SYSTEM_LIBTCOD_HIGHEST_DRAW_PRIORITY;
			};
		}
	}
}

#endif  // !LIBTCOD_STAR_SYSTEM_DRAWABLE_H

