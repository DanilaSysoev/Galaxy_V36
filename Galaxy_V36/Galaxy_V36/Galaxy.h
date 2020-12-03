#ifndef GALAXY_H
#define GALAXY_H

#include <string>
#include <vector>
#include <map>

#include "Vector.h"

namespace galaxy_v36
{
	namespace game
	{
		class Drawable;
		class GalaxyDrawable;
	}

	namespace entities
	{
		class StarSystem;

		class Galaxy
		{
		public:
			Galaxy(std::vector<StarSystem*> starSystems);

			int getStarSystemsCount() const;

			StarSystem* getStarSystem(int index) const;
			StarSystem* getStarSystem(const std::string& name) const;
			StarSystem* getStarSystem(const service::Vector& position) const;

			game::Drawable* getDrawable();
			void setDrawable(game::GalaxyDrawable* drawable);

			~Galaxy();


		private:
			std::vector<StarSystem*> starSystems;
			std::map<std::string, StarSystem*> starSystemsNamed;
			std::map<service::Vector, StarSystem*> starSystemsPositioned;

			game::GalaxyDrawable* drawable;
		};
	}
}


#endif // !GALAXY_H

