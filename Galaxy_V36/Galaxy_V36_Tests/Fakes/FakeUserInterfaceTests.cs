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
    }
}
