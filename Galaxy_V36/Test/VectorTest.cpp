#include "pch.h"
#include "../Galaxy_V36/Vector.h"
#include "../Galaxy_V36/Direction.h"

using namespace galaxy_v36::service;


TEST(VectorTest, ZeroTest)
{
	EXPECT_EQ(Vector::getZero().getX(), 0);
	EXPECT_EQ(Vector::getZero().getY(), 0);
}
TEST(VectorTest, DefaulConstructorTest)
{
	Vector v;
	EXPECT_EQ(v.getX(), 0);
	EXPECT_EQ(v.getY(), 0);
}
TEST(VectorTest, ParametrizedConstructorTest)
{
	Vector v(10, 20);
	EXPECT_EQ(v.getX(), 10);
	EXPECT_EQ(v.getY(), 20);
}

TEST(VectorTest, AddTest)
{
	Vector v1(10, 20);
	Vector v2(1, 2);
	Vector v3 = v1.add(v2);

	EXPECT_EQ(v3.getX(), 11);
	EXPECT_EQ(v3.getY(), 22);
}
TEST(VectorTest, NegateTest)
{
	Vector v(10, 20);
	Vector vNeg = v.negate();

	EXPECT_EQ(vNeg.getX(), -10);
	EXPECT_EQ(vNeg.getY(), -20);
}
TEST(VectorTest, MultiplyTest)
{
	Vector v1(10, 20);
	Vector v2 = v1.multiply(2.29);

	EXPECT_EQ(v2.getX(), 22);
	EXPECT_EQ(v2.getY(), 45);
}
TEST(VectorTest, DotTest)
{
	Vector v1(10, 20);
	Vector v2(1, 2);

	auto dot1 = v1.dot(v2);
	auto dot2 = v2.dot(v1);

	EXPECT_EQ(dot1, 50);
	EXPECT_EQ(dot2, 50);
}
TEST(VectorTest, SquareLengthTest)
{
	Vector v(10, 20);
	auto sl = v.squareLength();

	EXPECT_EQ(sl, 500);
}
TEST(VectorTest, SquareDistanceTest)
{
	Vector v1(10, 20);
	Vector v2(1, 10);

	auto sd1 = v1.sqaureDistance(v2);
	auto sd2 = v2.sqaureDistance(v1);

	EXPECT_EQ(sd1, 181);
	EXPECT_EQ(sd2, 181);
}

TEST(VectorTest, AddUpDirectionTest)
{
	Vector v1(10, 20);
	Vector v2 = v1.add(Direction::getUp().getPositionDelta());

	EXPECT_EQ(v2.getX(), 10);
	EXPECT_EQ(v2.getY(), 19);
}
TEST(VectorTest, AddDownDirectionTest)
{
	Vector v1(10, 20);
	Vector v2 = v1.add(Direction::getDown().getPositionDelta());

	EXPECT_EQ(v2.getX(), 10);
	EXPECT_EQ(v2.getY(), 21);
}
TEST(VectorTest, AddLeftDirectionTest)
{
	Vector v1(10, 20);
	Vector v2 = v1.add(Direction::getLeft().getPositionDelta());

	EXPECT_EQ(v2.getX(), 9);
	EXPECT_EQ(v2.getY(), 20);
}
TEST(VectorTest, AddRightDirectionTest)
{
	Vector v1(10, 20);
	Vector v2 = v1.add(Direction::getRight().getPositionDelta());

	EXPECT_EQ(v2.getX(), 11);
	EXPECT_EQ(v2.getY(), 20);
}
TEST(VectorTest, AddUpLeftDirectionTest)
{
	Vector v1(10, 20);
	Vector v2 = v1.add(Direction::getUpLeft().getPositionDelta());

	EXPECT_EQ(v2.getX(), 9);
	EXPECT_EQ(v2.getY(), 19);
}
TEST(VectorTest, AddDownLeftDirectionTest)
{
	Vector v1(10, 20);
	Vector v2 = v1.add(Direction::getDownLeft().getPositionDelta());

	EXPECT_EQ(v2.getX(), 9);
	EXPECT_EQ(v2.getY(), 21);
}
TEST(VectorTest, AddUpRightDirectionTest)
{
	Vector v1(10, 20);
	Vector v2 = v1.add(Direction::getUpRight().getPositionDelta());

	EXPECT_EQ(v2.getX(), 11);
	EXPECT_EQ(v2.getY(), 19);
}
TEST(VectorTest, AddDownRightDirectionTest)
{
	Vector v1(10, 20);
	Vector v2 = v1.add(Direction::getDownRight().getPositionDelta());

	EXPECT_EQ(v2.getX(), 11);
	EXPECT_EQ(v2.getY(), 21);
}

TEST(VectorTest, EqTest)
{
	Vector v1(10, 20);
	Vector v2(10, 20);

	EXPECT_EQ(v1, v2);
	EXPECT_EQ(v2, v1);
}
TEST(VectorTest, NeqTest_1)
{
	Vector v1(10, 20);
	Vector v2(11, 20);

	EXPECT_NE(v1, v2);
	EXPECT_NE(v2, v1);
}
TEST(VectorTest, NeqTest_2)
{
	Vector v1(10, 20);
	Vector v2(10, 21);

	EXPECT_NE(v1, v2);
	EXPECT_NE(v2, v1);
}
TEST(VectorTest, LTest_1)
{
	Vector v1(10, 20);
	Vector v2(11, 20);

	EXPECT_LT(v1, v2);
	EXPECT_GE(v2, v1);
}
TEST(VectorTest, LTest_2)
{
	Vector v1(10, 20);
	Vector v2(10, 21);

	EXPECT_LT(v1, v2);
	EXPECT_GE(v2, v1);
}
TEST(VectorTest, LETest_1)
{
	Vector v1(10, 20);
	Vector v2(11, 20);

	EXPECT_LE(v1, v2);
	EXPECT_GT(v2, v1);
}
TEST(VectorTest, LETest_2)
{
	Vector v1(10, 20);
	Vector v2(10, 21);

	EXPECT_LE(v1, v2);
	EXPECT_GT(v2, v1);
}
TEST(VectorTest, LETest_3)
{
	Vector v1(10, 20);
	Vector v2(10, 20);

	EXPECT_LE(v1, v2);
	EXPECT_LE(v2, v1);
}