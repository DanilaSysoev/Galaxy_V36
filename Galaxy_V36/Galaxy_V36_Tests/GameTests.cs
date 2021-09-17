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

        [TestCase]
        public void Prepare_CallFirst_FlagSetup()
        {
            Game game = new Game(new FakeUserInterface());
            game.Prepare();
            Assert.IsTrue(game.Prepared);
            Assert.IsFalse(game.Loaded);
            Assert.IsFalse(game.Initialized);
        }

        [TestCase]
        public void Load_CallFirst_ThrowsException()
        {
            Game game = new Game(new FakeUserInterface());
            
            var exception = Assert.Throws<InvalidOperationException>(
                () => game.Load()
            );
            Assert.IsTrue(
                exception.Message.ToLower().Contains("call prepare first")
            );
        }
        [TestCase]
        public void Load_CallSecond_FlagsSetup()
        {
            Game game = new Game(new FakeUserInterface());
            game.Prepare();
            game.Load();
            Assert.IsTrue(game.Prepared);
            Assert.IsTrue(game.Loaded);
            Assert.IsFalse(game.Initialized);
        }


        [TestCase]
        public void Initialize_CallFirst_ThrowsException()
        {
            Game game = new Game(new FakeUserInterface());

            var exception = Assert.Throws<InvalidOperationException>(
                () => game.Initialize()
            );
            Assert.IsTrue(
                exception.Message.ToLower().Contains("call prepare first")
            );
        }
        [TestCase]
        public void Initialize_CallSecond_FlagsSetup()
        {
            Game game = new Game(new FakeUserInterface());
            game.Prepare();
            var exception = Assert.Throws<InvalidOperationException>(
                () => game.Initialize()
            );
            Assert.IsTrue(
                exception.Message.ToLower().Contains("call load first")
            ); ;
        }

    }
}
