using Galaxy_V36.Engine;
using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36_Tests.Fakes
{
    [TestFixture]
    class FakeUserInterfaceTests
    {
        [SetUp]
        public void SetUp()
        {
            Game.DestroyGame();
        }

        [TestCase]
        public void PrepareStart_CallBeforeGameCreation_ThrowsException()
        {
            FakeUserInterface userInterface = new FakeUserInterface();
            var exception = Assert.Throws<InvalidOperationException>(
                () => userInterface.PrepareStart()
            );
            Assert.IsTrue(exception.Message.ToLower().Contains(
                "preparestart call before game creation"
            ));
        }
        [TestCase]
        public void PrepareStart_CallAterGamePrepare_ThrowsException()
        {
            FakeUserInterface userInterface = new FakeUserInterface();
            Game game = Game.CreateGame(userInterface);
            game.Prepare();
            var exception = Assert.Throws<InvalidOperationException>(
                () => userInterface.PrepareStart()
            );
            Assert.IsTrue(exception.Message.ToLower().Contains(
                "preparestart call after preparation"
            ));
        }
        [TestCase]
        public void PrepareStart_CallSecondTime_ThrowsException()
        {
            FakeUserInterface userInterface = new FakeUserInterface();
            Game game = Game.CreateGame(userInterface);
            userInterface.PrepareStart();

            var exception = Assert.Throws<InvalidOperationException>(
                () => userInterface.PrepareStart()
            );
            Assert.IsTrue(exception.Message.ToLower().Contains(
                "preparestart already called"
            ));
        }

        [TestCase]
        public void PrepareEnd_CallBeforePrepareStart_ThrowsException()
        {
            FakeUserInterface userInterface = new FakeUserInterface();
            Game game = Game.CreateGame(userInterface);
            
            var exception = Assert.Throws<InvalidOperationException>(
                () => userInterface.PrepareEnd()
            );
            Assert.IsTrue(exception.Message.ToLower().Contains(
                "prepareend call before preparestart"
            ));
        }
        [TestCase]
        public void PrepareEnd_CallBeforeGamePrepare_ThrowsException()
        {
            FakeUserInterface userInterface = new FakeUserInterface();
            Game game = Game.CreateGame(userInterface);
            userInterface.PrepareStart();

            var exception = Assert.Throws<InvalidOperationException>(
                () => userInterface.PrepareEnd()
            );
            Assert.IsTrue(exception.Message.ToLower().Contains(
                "prepareend call before preparation"
            ));
        }
        [TestCase]
        public void PrepareEnd_CallSecondTime_ThrowsException()
        {
            FakeUserInterface userInterface = new FakeUserInterface();
            Game game = Game.CreateGame(userInterface);
            game.Prepare();

            var exception = Assert.Throws<InvalidOperationException>(
                () => userInterface.PrepareEnd()
            );
            Assert.IsTrue(exception.Message.ToLower().Contains(
                "prepareend already called"
            ));
        }

        [TestCase]
        public void LoadStart_CallAterGameLoading_ThrowsException()
        {
            FakeUserInterface userInterface = new FakeUserInterface();
            Game game = Game.CreateGame(userInterface);
            game.Prepare();
            game.Load();
            var exception = Assert.Throws<InvalidOperationException>(
                () => userInterface.LoadStart()
            );
            Assert.IsTrue(exception.Message.ToLower().Contains(
                "loadstart call after loading"
            ));
        }
        [TestCase]
        public void LoadStart_CallSecondTime_ThrowsException()
        {
            FakeUserInterface userInterface = new FakeUserInterface();
            Game game = Game.CreateGame(userInterface);
            game.Prepare();
            userInterface.LoadStart();

            var exception = Assert.Throws<InvalidOperationException>(
                () => userInterface.LoadStart()
            );
            Assert.IsTrue(exception.Message.ToLower().Contains(
                "loadstart already called"
            ));
        }

        [TestCase]
        public void LoadEnd_CallBeforeLoadStart_ThrowsException()
        {
            FakeUserInterface userInterface = new FakeUserInterface();
            Game game = Game.CreateGame(userInterface);
            game.Prepare();

            var exception = Assert.Throws<InvalidOperationException>(
                () => userInterface.LoadEnd()
            );
            Assert.IsTrue(exception.Message.ToLower().Contains(
                "loadend call before loadstart"
            ));
        }
        [TestCase]
        public void LoadEnd_CallBeforeGameLoad_ThrowsException()
        {
            FakeUserInterface userInterface = new FakeUserInterface();
            Game game = Game.CreateGame(userInterface);
            game.Prepare();
            userInterface.LoadStart();

            var exception = Assert.Throws<InvalidOperationException>(
                () => userInterface.LoadEnd()
            );
            Assert.IsTrue(exception.Message.ToLower().Contains(
                "loadend call before loading"
            ));
        }
        [TestCase]
        public void LoadEnd_CallSecondTime_ThrowsException()
        {
            FakeUserInterface userInterface = new FakeUserInterface();
            Game game = Game.CreateGame(userInterface);
            game.Prepare();
            game.Load();

            var exception = Assert.Throws<InvalidOperationException>(
                () => userInterface.LoadEnd()
            );
            Assert.IsTrue(exception.Message.ToLower().Contains(
                "loadend already called"
            ));
        }
    }
}
