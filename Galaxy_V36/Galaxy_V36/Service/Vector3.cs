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
