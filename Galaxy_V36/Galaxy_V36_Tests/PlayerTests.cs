using Galaxy_V36.Engine;
using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36_Tests
{
    [TestFixture]
    class PlayerTests
    {
        [TestCase]
        public void Player_CreateWithShip_ShipPropertyIsOk()
        {
            SpaceShip ship = new SpaceShip(10);
            Player player = new Player(ship);
            Assert.AreEqual(ship, player.Ship);
        }
    }
}
