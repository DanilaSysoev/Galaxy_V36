using Galaxy_V36.Entities;
using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36
{
    public class GameEntityBuilder
    {
        public static SpaceShip CreateSpaceShip()
        {
            return new SpaceShip();
        }
    }
}
