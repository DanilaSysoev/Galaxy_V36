using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36.Engine
{
    public interface ICommandProcessor
    {
        void ProcessCommand(string command);
    }
}
