using Galaxy_V36.Engine;
using System;

namespace Galaxy_V36_ConsoleUI
{
    class Program
    {
        static void Main(string[] args)
        {
            Game game = Game.CreateGame(new ConsoleUserInterface());
            game.Run();
        }
    }
}
