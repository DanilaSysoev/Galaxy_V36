#ifndef LIBTCOD_STAR_SYSTEM_DRAWABLE_H
#define LIBTCOD_STAR_SYSTEM_DRAWABLE_H

#include <map>
#include <string>

#include "StarSystemDrawable.h"
#include "LibtcodDrawablesComponent.h"

namespace galaxy_v36
{
	namespace game
	{
		namespace libtcod
		{
			class LibtcodStarSystemDrawable 
				: public StarSystemDrawable
				, public LibtcodDrawablesComponent
			{
			public:
				LibtcodStarSystemDrawable(
					Camera* camera, 
					entities::StarSystem* starSystem
				);

				virtual int getDrawPriority() const override;
				virtual void draw() override;

				static const int STAR_SYSTEM_LIBTCOD_HIGHEST_DRAW_PRIORITY;
				static void initializeImages(
					std::map<std::string, char>& namedSpaceBodyImages
				);

			private:
				static std::map<std::string, char> namedSpaceBodyImages;
			};
		}
	}
}

#endif  // !LIBTCOD_STAR_SYSTEM_DRAWABLE_H

