using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36.Service
{
    public class Vector3
    {
        public long X
        {
            get
            {
                return x;
            }
        }
        public long Y
        {
            get
            {
                return y;
            }
        }
        public long Z
        {
            get
            {
                return z;
            }
        }

        public Vector3(long x, long y, long z)
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
            return
                ((Vector3)obj).x == x &&
                ((Vector3)obj).y == y &&
                ((Vector3)obj).z == z;
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

        private long x;
        private long y;
        private long z;

        private static Vector3 zero;

        static Vector3()
        {
            zero = new Vector3(0, 0, 0);
        }
    }
}
