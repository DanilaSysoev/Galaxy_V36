using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36.Service
{
    public class Vector3
    {
        public float X
        {
            get
            {
                return x;
            }
        }
        public float Y
        {
            get
            {
                return y;
            }
        }
        public float Z
        {
            get
            {
                return z;
            }
        }

        public Vector3(float x, float y, float z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }
        public Vector3 Add(Vector3 addition)
        {
            return new Vector3(x + addition.x, y + addition.y, z + addition.z);
        }
        public override bool Equals(object obj)
        {
            if (!(obj is Vector3))
                return false;

            Vector3 v = (Vector3)obj;
            return
                MathF.Abs(x - v.x) < Configuration.FloatEpsilon &&
                MathF.Abs(y - v.y) < Configuration.FloatEpsilon &&
                MathF.Abs(z - v.z) < Configuration.FloatEpsilon;
        }
        public override int GetHashCode()
        {
            return (x.GetHashCode() + y.GetHashCode() + z.GetHashCode()) * 31;
        }
        public override string ToString()
        {
            return string.Format("({0}; {1}; {2})", x, y, z);
        }

        public static Vector3 Zero
        {
            get
            {
                return zero;
            }
        }

        private float x;
        private float y;
        private float z;

        private static Vector3 zero;

        static Vector3()
        {
            zero = new Vector3(0, 0, 0);
        }
    }
}
