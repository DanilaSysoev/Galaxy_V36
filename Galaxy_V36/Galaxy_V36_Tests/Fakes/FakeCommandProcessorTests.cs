using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36_Tests.Fakes
{
    [TestFixture]
    class FakeCommandProcessorTests
    {
        [TestCase]
        public void Create_Creation_CommandProcessedIsFalse()
        {
            FakeCommandProcessor fcp = new FakeCommandProcessor();
            Assert.IsFalse(fcp.CommandProcessed);
        }
    }
}
