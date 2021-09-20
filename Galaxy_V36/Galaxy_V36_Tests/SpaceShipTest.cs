using Galaxy_V36.Engine;
using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36_Tests
{
    [TestFixture]
    class SpaceShipTest
    {
        [TestCase]
        public void SpaceShip_CreationWithSpeed_SpeedPropertySetOk()
        {
            SpaceShip ship = new SpaceShip(10.1f);
            Assert.AreEqual(10.1f, ship.Speed);
        }
    }
}
