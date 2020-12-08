#ifndef LIBTCOD_DRAWABLES_COMPONENT_H
#define LIBTCOD_DRAWABLES_COMPONENT_H

#include <string>

namespace galaxy_v36
{
	namespace game
	{
		namespace libtcod
		{
			class LibtcodDrawablesComponent
			{
			public:
				std::string getConsoleName() const;
				void setConsoleName(const std::string& consoleName);

			private:
				std::string consoleName;
			};
		}
	}
}

#endif // !LIBTCOD_DRAWABLES_COMPONENT_H

