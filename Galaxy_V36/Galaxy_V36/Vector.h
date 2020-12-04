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
			Vector(long long x, long long y);

			long long getX() const;
			long long getY() const;

			Vector add(const Vector& vector) const;
			Vector negate() const;
			Vector multiply(double koefficient) const;
			long long dot(const Vector& vector) const;
			long long squareLength() const;
			long long sqaureDistance(const Vector& vector) const;

			bool operator<(const Vector& ro) const;
			bool operator<=(const Vector& ro) const;
			bool operator>(const Vector& ro) const;
			bool operator>=(const Vector& ro) const;
			bool operator==(const Vector& ro) const;
			bool operator!=(const Vector& ro) const;

			static const Vector& getZero();

		private:
			long long x;
			long long y;

			static const Vector& zero;
		};
	}
}

#endif // !VECTOR_H

