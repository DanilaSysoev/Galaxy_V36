#ifndef STAR_SYSTEM_H
#define STAR_SYSTEM_H

#include <string>
#include <vector>
#include <map>

#include "libtcod.hpp"
#include "Vector.h"

namespace galaxy_v36
{
	namespace game
	{
		class Drawable;
		class StarSystemDrawable;
	}

	namespace entities
	{
		class SpaceBody;

		using namespace service;

		class StarSystem
		{
		public:
			StarSystem(
				const std::string& name,
				const Vector& position
			);

			std::string getName() const;
			Vector getPosition() const;

			int getSpaceBodiesCount() const;

			SpaceBody* getSpaceBody(int index) const;
			SpaceBody* getSpaceBody(const std::string& name) const;
			SpaceBody* getSpaceBody(const Vector& position) const;

			void addSpaceBody(SpaceBody* spaceBody);
			void removeSpaceBody(SpaceBody* spacebody);
			void removeSpaceBody(const std::string& name);

			game::Drawable* getDrawable();
			void setDrawable(game::StarSystemDrawable* drawable);

			~StarSystem();

		private:
			std::vector<SpaceBody*> spaceBodies;
			std::map<std::string, SpaceBody*> spaceBodiesNamed;
			std::map<Vector, SpaceBody*> spaceBodiesPositioned;

			game::StarSystemDrawable* drawable;

			std::string name;
			Vector position;
		};
	}
}


#endif // !STAR_SYSTEM_H
