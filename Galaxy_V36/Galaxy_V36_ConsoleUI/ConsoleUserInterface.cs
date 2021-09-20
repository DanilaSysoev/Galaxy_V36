using Galaxy_V36.UI;
using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36_ConsoleUI
{
    public class ConsoleUserInterface : IUserInterface
    {
        public void InitializeEnd()
        {
        }

        public void InitializeStart()
        {
        }

        public void LoadEnd()
        {
        }

        public void LoadStart()
        {
        }

        public void PrepareEnd()
        {
        }

        public void PrepareStart()
        {
        }

        public string GetCommand()
        {
            return Console.ReadLine();
        }
    }
}
