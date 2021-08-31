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
        public void Move_MoveOnSomeVector_PositionChangeCorrect()
        {
            SpaceShip spaceShip = GameEntityBuilder.CreateSpaceShip();
            Vector3 motion = new Vector3(1, 2, 3);
            spaceShip.Move(motion);
            Assert.AreEqual(motion, spaceShip.Position);
        }
    }
}
