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
    }
}
