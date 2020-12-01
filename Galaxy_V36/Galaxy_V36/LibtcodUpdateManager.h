#ifndef LIBTCOD_UPDATE_MANAGER_H
#define LIBTCOD_UPDATE_MANAGER_H

#include "UpdateManager.h"

namespace galaxy_v36
{
	namespace game
	{
		namespace libtcod
		{
			class LibtcodUpdateManager : public UpdateManager
			{
			public:
				virtual void prepareUpdate() override;
				virtual void endUpdate() override;
			};
		}
	}
}

#endif  // !LIBTCOD_UPDATE_MANAGER_H

