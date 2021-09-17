using Galaxy_V36;
using Galaxy_V36.Entities;
using Galaxy_V36.Service;
using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36_Tests
{
    [TestFixture]
    class SpaceShipTests
    {
        [TestCase]
        public void SpaceShip_CreationShip_PositionPropertyReturnsZeroVector()
        {
            SpaceShip spaceShip = GameEntityBuilder.CreateSpaceShip();
            Assert.AreEqual(Vector3.Zero, spaceShip.Position);
        }

        [TestCase]
        public void Move_MoveOnCorrectVector_MotonIsOk()
        {
            SpaceShip spaceShip = GameEntityBuilder.CreateSpaceShip();
            Vector3 motion = new Vector3(1, 1, 1);
            spaceShip.MoveOn(motion);
            Assert.AreEqual(motion, spaceShip.Position);
        }
        [TestCase]
        public void Move_DoubleMoveOnCorrectVector_MotonIsOk()
        {
            SpaceShip spaceShip = GameEntityBuilder.CreateSpaceShip();
            Vector3 motion = new Vector3(1, 1, 1);
            spaceShip.MoveOn(motion);
            spaceShip.MoveOn(motion);
            Assert.AreEqual(new Vector3(2, 2, 2), spaceShip.Position);
        }
    }
}
