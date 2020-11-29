#ifndef GALAXY_H
#define GALAXY_H

#include <string>
#include <vector>
#include <map>

#include "Vector.h"

namespace galaxy_v36
{
	namespace entities
	{
		class StarSystem;

		class Galaxy
		{
		public:
			Galaxy(std::vector<StarSystem*> starSystems);

			int gaeStarSystemsCount() const;

			StarSystem* getStarSystem(int index) const;
			StarSystem* getStarSystem(const std::string& name) const;
			StarSystem* getStarSystem(const service::Vector& position) const;

			~Galaxy();


		private:
			std::vector<StarSystem*> starSystems;
			std::map<std::string, StarSystem*> starSystemsNamed;
			std::map<service::Vector, StarSystem*> starSystemsPositioned;
		};
	}
}


#endif // !GALAXY_H

