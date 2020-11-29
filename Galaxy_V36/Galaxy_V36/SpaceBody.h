#ifndef SPACE_BODY_H
#define SPACE_BODY_H

#include <string>

#include "Vector.h"

namespace galaxy_v36
{
	namespace entities
	{
		class SpaceBody
		{
		public:
			SpaceBody(std::string name);

			virtual std::string getName() const;
			virtual service::Vector getPosition() const = 0;
			virtual service::Vector getSize() const = 0;

			virtual bool isInside(const service::Vector& point) = 0;

			virtual ~SpaceBody();

		private:
			std::string name;
		};
	}
}

#endif // !SPACE_BODY_H

