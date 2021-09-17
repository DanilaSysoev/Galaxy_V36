using Galaxy_V36.Engine;
using System;

namespace Galaxy_V36_ConsoleUI
{
    class Program
    {
        static void Main(string[] args)
        {
            Game game = new Game(new ConsoleUserInterface());
            game.Run();
        }
    }
}
