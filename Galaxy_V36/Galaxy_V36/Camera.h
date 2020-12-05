#ifndef CAMERA_H
#define CAMERA_H

#include <string>

#include "Vector.h"
#include "Direction.h"

namespace galaxy_v36
{
	namespace game
	{
		class Camera
		{
		public:
			virtual service::Vector getPosition() = 0;
			virtual void moveTo(const service::Direction& direction) = 0;

			virtual ~Camera();
		};
	}
}

#endif // !CAMERA_H
