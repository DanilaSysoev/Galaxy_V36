using Galaxy_V36.Engine;
using Galaxy_V36.Service;
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
        [TestCase]
        public void Player_CreateWithShip_PositionIsZero()
        {
            SpaceShip ship = new SpaceShip(10);
            Player player = new Player(ship);
            Assert.AreEqual(new Vector3(0, 0, 0), player.Position);
        }
    }
}
