#ifndef STAR_GATE_H
#define STAR_GATE_H

#include "SpaceBody.h"

namespace galaxy_v36
{
	namespace entities
	{
		class StarSystem;

		class StarGate : public SpaceBody
		{
		public:
			StarGate(
				std::string name,
				const service::Vector& position,
				int diameter,
				StarSystem* starSystemOfLocation,
				StarSystem* destinationStarSystem
			);

			StarSystem* getStarSystemOfLocation();
			StarSystem* getDestinationStarSystem();

			virtual service::Vector getPosition() const;
			virtual int getDiameter() const;


		private:
			StarSystem* starSystemOfLocation;
			StarSystem* destinationStarSystem;

			service::Vector position;
			int diameter;

			static const std::string GATE_TYPE;
		};
	}
}

#endif // !STAR_GATE_H

