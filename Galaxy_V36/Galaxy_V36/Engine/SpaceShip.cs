using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36.Engine
{
    public class SpaceShip
    {
        public float Speed { get; private set; }

        public SpaceShip(float speed)
        {
            Speed = speed;
        }
    }
}
