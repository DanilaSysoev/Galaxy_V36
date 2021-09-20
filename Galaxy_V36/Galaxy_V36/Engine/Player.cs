using Galaxy_V36.Service;
using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36.Engine
{
    public class Player
    {
        public Vector3 Position { get; private set; } 
        public SpaceShip Ship { get; set; }

        public Player(SpaceShip ship)
        {
            Position = new Vector3();
            Ship = ship;
        }
    }
}
