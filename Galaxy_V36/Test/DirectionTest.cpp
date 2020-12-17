#include "pch.h"
#include "../Galaxy_V36/Direction.h"

using namespace galaxy_v36::service;


TEST(DirectionFromStringTest, UpFromStringTest)
{
	EXPECT_EQ(Direction::get("Up"), Direction::getUp());
}
TEST(DirectionFromStringTest, DownFromStringTest)
{
	EXPECT_EQ(Direction::get("Down"), Direction::getDown());
}
TEST(DirectionFromStringTest, LeftFromStringTest)
{
	EXPECT_EQ(Direction::get("Left"), Direction::getLeft());
}
TEST(DirectionFromStringTest, RightFromStringTest)
{
	EXPECT_EQ(Direction::get("Right"), Direction::getRight());
}
TEST(DirectionFromStringTest, UpLeftFromStringTest)
{
	EXPECT_EQ(Direction::get("UpLeft"), Direction::getUpLeft());
}
TEST(DirectionFromStringTest, DownLeftFromStringTest)
{
	EXPECT_EQ(Direction::get("DownLeft"), Direction::getDownLeft());
}
TEST(DirectionFromStringTest, UpRightFromStringTest)
{
	EXPECT_EQ(Direction::get("UpRight"), Direction::getUpRight());
}
TEST(DirectionFromStringTest, DownRightFromStringTest)
{
	EXPECT_EQ(Direction::get("DownRight"), Direction::getDownRight());
}


TEST(DirectionGetOppositeTest, UpOppositeTest)
{
	EXPECT_EQ(Direction::getUp().getOpposite(), Direction::getDown());
}
TEST(DirectionGetOppositeTest, DownOppositeTest)
{
	EXPECT_EQ(Direction::getDown().getOpposite(), Direction::getUp());
}
TEST(DirectionGetOppositeTest, LeftOppositeTest)
{
	EXPECT_EQ(Direction::getLeft().getOpposite(), Direction::getRight());
}
TEST(DirectionGetOppositeTest, RightOppositeTest)
{
	EXPECT_EQ(Direction::getRight().getOpposite(), Direction::getLeft());
}
TEST(DirectionGetOppositeTest, UpLeftOppositeTest)
{
	EXPECT_EQ(Direction::getUpLeft().getOpposite(), Direction::getDownRight());
}
TEST(DirectionGetOppositeTest, DownLeftOppositeTest)
{
	EXPECT_EQ(Direction::getDownLeft().getOpposite(), Direction::getUpRight());
}
TEST(DirectionGetOppositeTest, UpRightOppositeTest)
{
	EXPECT_EQ(Direction::getUpRight().getOpposite(), Direction::getDownLeft());
}
TEST(DirectionGetOppositeTest, DownRightOppositeTest)
{
	EXPECT_EQ(Direction::getDownRight().getOpposite(), Direction::getUpLeft());
}