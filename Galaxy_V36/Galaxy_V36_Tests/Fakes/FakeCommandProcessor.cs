using Galaxy_V36.Engine;
using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36_Tests.Fakes
{
    public class FakeCommandProcessor : ICommandProcessor
    {
        public bool CommandProcessed { get; private set; }
        public string LastProcessedCommand { get; private set; }

        public FakeCommandProcessor()
        {
            CommandProcessed = false;
            LastProcessedCommand = null;
        }

        public void ProcessCommand(string command)
        {
            CommandProcessed = true;
            LastProcessedCommand = command;
        }
    }
}
