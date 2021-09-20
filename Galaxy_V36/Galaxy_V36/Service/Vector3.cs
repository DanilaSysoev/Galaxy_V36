using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36.Service
{
    public class Vector3
    {
        public float X { get; private set; }
        public float Y { get; private set; }
        public float Z { get; private set; }

        public Vector3()
        {
            X = Y = Z = 0;
        }
        public Vector3(float x, float y, float z)
        {
            X = x;
            Y = y;
            Z = z;
        }

        public override int GetHashCode()
        {
            return ((int)X * 31 + (int)Y) * 31 + (int)Z;
        }
        public override string ToString()
        {
            return string.Format(
                System.Globalization.NumberFormatInfo.InvariantInfo, 
                "Vector3({0:F1}, {1:F1}, {2:F1})", 
                X, Y, Z
            );
        }
        public override bool Equals(object obj)
        {
            if (!(obj is Vector3))
                return false;
            Vector3 v3 = obj as Vector3;
            return
                MathF.Abs(v3.X - X) < Epsilon &&
                MathF.Abs(v3.Y - Y) < Epsilon &&
                MathF.Abs(v3.Z - Z) < Epsilon;
        }

        private const float Epsilon = .000001f;
    }
}
