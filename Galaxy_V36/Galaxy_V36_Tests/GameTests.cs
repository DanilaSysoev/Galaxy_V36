using Galaxy_V36.Engine;
using Galaxy_V36_Tests.Fakes;
using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36_Tests
{
    [TestFixture]
    class GameTests
    {
        [TestCase]
        public void Game_Create_FlagsFalse()
        {
            Game game = new Game(new FakeUserInterface());
            Assert.IsFalse(game.Prepared);
            Assert.IsFalse(game.Loaded);
            Assert.IsFalse(game.Initialized);            
        }

    }
}
