using Galaxy_V36.Service;
using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36.Entities
{
    public class  SpaceShip
    {
        public Vector3 Position
        {
            get
            {
                return position;
            }
        }

        public SpaceShip()
        {
            position = Vector3.Zero;
        }
        public void MoveOn(Vector3 motion)
        {
            position = position.Add(motion);
        }

        private Vector3 position;
    }
}
