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
        [TearDown]
        public void Destroy()
        {
            Game.DestroyGame();
        }

        [TestCase]
        public void Game_Create_FlagsFalse()
        {
            Game game = Game.CreateGame(new FakeUserInterface());
            Assert.IsFalse(game.Prepared);
            Assert.IsFalse(game.Loaded);
            Assert.IsFalse(game.Initialized);            
        }
        [TestCase]
        public void FakeUserInterface_Create_FlagsFalse()
        {
            var fui = new FakeUserInterface();
            Assert.IsFalse(fui.PrepareStartCallIsOk);
            Assert.IsFalse(fui.PrepareEndCallIsOk);
            Assert.IsFalse(fui.LoadStartCallIsOk);
            Assert.IsFalse(fui.LoadEndCallIsOk);
            Assert.IsFalse(fui.InitializeStartCallIsOk);
            Assert.IsFalse(fui.InitializeEndCallIsOk);
        }

        [TestCase]
        public void Prepare_CallFirst_FlagSetup()
        {
            Game game = Game.CreateGame(new FakeUserInterface());
            game.Prepare();
            Assert.IsTrue(game.Prepared);
            Assert.IsFalse(game.Loaded);
            Assert.IsFalse(game.Initialized);
        }

        [TestCase]
        public void Load_CallFirst_ThrowsException()
        {
            Game game = Game.CreateGame(new FakeUserInterface());
            
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
            Game game = Game.CreateGame(new FakeUserInterface());
            game.Prepare();
            game.Load();
            Assert.IsTrue(game.Prepared);
            Assert.IsTrue(game.Loaded);
            Assert.IsFalse(game.Initialized);
        }

        [TestCase]
        public void Initialize_CallFirst_ThrowsException()
        {
            Game game = Game.CreateGame(new FakeUserInterface());

            var exception = Assert.Throws<InvalidOperationException>(
                () => game.Initialize()
            );
            Assert.IsTrue(
                exception.Message.ToLower().Contains("call prepare first")
            );
        }
        [TestCase]
        public void Initialize_CallSecond_ThrowsException()
        {
            Game game = Game.CreateGame(new FakeUserInterface());
            game.Prepare();
            var exception = Assert.Throws<InvalidOperationException>(
                () => game.Initialize()
            );
            Assert.IsTrue(
                exception.Message.ToLower().Contains("call load first")
            ); ;
        }
        [TestCase]
        public void Load_CallThird_FlagsSetup()
        {
            Game game = Game.CreateGame(new FakeUserInterface());
            game.Prepare();
            game.Load();
            game.Initialize();
            Assert.IsTrue(game.Prepared);
            Assert.IsTrue(game.Loaded);
            Assert.IsTrue(game.Initialized);
        }

        [TestCase]
        public void Tick_CallBeforePrepare_ThrowsException()
        {
            Game game = Game.CreateGame(new FakeUserInterface());

            var exception = Assert.Throws<InvalidOperationException>(
                () => game.Tick()
            );
            Assert.IsTrue(
                exception.Message.ToLower().Contains("call prepare first")
            );
        }
        [TestCase]
        public void Tick_CallBeforeLoad_ThrowsException()
        {
            Game game = Game.CreateGame(new FakeUserInterface());
            game.Prepare();
            var exception = Assert.Throws<InvalidOperationException>(
                () => game.Tick()
            );
            Assert.IsTrue(
                exception.Message.ToLower().Contains("call load first")
            ); ;
        }
        [TestCase]
        public void Tick_CallBeforeInitialize_ThrowsException()
        {
            Game game = Game.CreateGame(new FakeUserInterface());
            game.Prepare();
            game.Load();
            var exception = Assert.Throws<InvalidOperationException>(
                () => game.Tick()
            );
            Assert.IsTrue(
                exception.Message.ToLower().Contains("call initialize first")
            ); ;
        }

        [TestCase]
        public void Run_RunAfterCreation_FlagsSetup()
        {
            Game game = Game.CreateGame(new FakeUserInterface());
            game.Run();
            Assert.IsTrue(game.Prepared);
            Assert.IsTrue(game.Loaded);
            Assert.IsTrue(game.Initialized);
        }

    }
}
