#ifndef VECTOR_H
#define VECTOR_H

namespace galaxy_v36
{
	namespace service
	{
		class Vector
		{
		public:
			Vector();
			Vector(int x, int y);

			int getX() const;
			int getY() const;

			Vector add(const Vector& vector) const;
			Vector negate() const;
			Vector multiply(double koefficient) const;
			int dot(const Vector& vector) const;
			int squareLength() const;
			int sqaureDistance(const Vector& vector) const;

			bool operator<(const Vector& ro) const;
			bool operator<=(const Vector& ro) const;
			bool operator>(const Vector& ro) const;
			bool operator>=(const Vector& ro) const;
			bool operator==(const Vector& ro) const;
			bool operator!=(const Vector& ro) const;

			static const Vector& getZero();

		private:
			int x;
			int y;

			static const Vector zero;
		};
	}
}

#endif // !VECTOR_H

