#ifndef STAR_SYSTEM_H
#define STAR_SYSTEM_H

#include <string>
#include <vector>
#include <map>

#include "libtcod.hpp"
#include "Vector.h"

namespace galaxy_v36
{
	namespace entities
	{
		class SpaceBody;

		class StarSystem
		{
		public:
			StarSystem(const std::string& name, const service::Vector& position, std::vector<SpaceBody*> spaceBodies);

			std::string getName() const;
			service::Vector getPosition() const;

			int getSpaceBodiesCount() const;

			SpaceBody* getSpaceBody(int index) const;
			SpaceBody* getSpaceBody(const std::string& name) const;
			SpaceBody* getSpaceBody(const service::Vector& position) const;

			~StarSystem();

		private:
			std::vector<SpaceBody*> spaceBodies;
			std::map<std::string, SpaceBody*> spaceBodiesNamed;
			std::map<service::Vector, SpaceBody*> spaceBodiesPositioned;

			std::string name;
			service::Vector position;
		};
	}
}


#endif // !STAR_SYSTEM_H
