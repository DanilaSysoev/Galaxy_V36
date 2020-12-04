#ifndef DIRECTION_H
#define DIRECTION_H

#include "Vector.h"

namespace galaxy_v36
{
	namespace service
	{
		class Direction
		{
		public:
			Vector getPositionDelta() const;
			const Direction& getOpposite() const;

			static const Direction& getUp();
			static const Direction& getUpRight();
			static const Direction& getRight();
			static const Direction& getDownRight();
			static const Direction& getDown();
			static const Direction& getDownLeft();
			static const Direction& getLeft();
			static const Direction& getUpLeft();

		private:
			Direction(const Vector& posiotionDelta, const Direction& opposite);
			Direction(const Direction& other) = delete;

			Vector posiotionDelta;
			const Direction& opposite;

			static const Direction& up;
			static const Direction& upRight;
			static const Direction& right;
			static const Direction& downRight;
			static const Direction& down;
			static const Direction& downLeft;
			static const Direction& left;
			static const Direction& upLeft;
		};
	}
}

#endif // !DIRECTION_H

