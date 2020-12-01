#ifndef LIBTCOD_DRAW_MANAGER_H
#define LIBTCOD_DRAW_MANAGER_H

#include "DrawManager.h"

namespace galaxy_v36
{
	namespace game
	{
		namespace libtcod
		{
			class LibtcodDrawManager : public DrawManager
			{
			public:
				virtual void prepareDrawing() override;
				virtual void flush() override;
			};
		}
	}
}

#endif  // !LIBTCOD_DRAW_MANAGER_H
