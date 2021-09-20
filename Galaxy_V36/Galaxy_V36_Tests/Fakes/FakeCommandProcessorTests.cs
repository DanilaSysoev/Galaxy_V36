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
        [TestCase]
        public void Create_Creation_LastCommandProcessedIsNull()
        {
            FakeCommandProcessor fcp = new FakeCommandProcessor();
            Assert.IsNull(fcp.LastProcessedCommand);
        }

        [TestCase]
        public void ProcessComand_ProcessCommand_LastCommandProcessedEqualCommand()
        {
            FakeCommandProcessor fcp = new FakeCommandProcessor();
            fcp.ProcessCommand("command");
            Assert.AreEqual("command", fcp.LastProcessedCommand);
        }
        [TestCase]
        public void ProcessComand_ProcessCommand_CommandProcessedIsTrue()
        {
            FakeCommandProcessor fcp = new FakeCommandProcessor();
            fcp.ProcessCommand("command");
            Assert.IsTrue(fcp.CommandProcessed);
        }
        [TestCase]
        public void ProcessComand_ProcessTwoTimes_LastCommandProcessedEqualSecondCommand()
        {
            FakeCommandProcessor fcp = new FakeCommandProcessor();
            fcp.ProcessCommand("command");
            fcp.ProcessCommand("command_2");
            Assert.AreEqual("command_2", fcp.LastProcessedCommand);
        }
        [TestCase]
        public void ProcessComand_ProcessTwoTimes_CommandProcessedIsTrue()
        {
            FakeCommandProcessor fcp = new FakeCommandProcessor();
            fcp.ProcessCommand("command");
            fcp.ProcessCommand("command_2");
            Assert.IsTrue(fcp.CommandProcessed);
        }
    }
}
