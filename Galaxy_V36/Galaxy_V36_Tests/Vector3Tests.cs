using Galaxy_V36.Service;
using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36_Tests
{
    [TestFixture]
    class Vector3Tests
    {
        [TestCase]
        public void Vector3_ZeroVector_ComponentsEqualsZero()
        {
            Assert.AreEqual(0, Vector3.Zero.X);
            Assert.AreEqual(0, Vector3.Zero.Y);
            Assert.AreEqual(0, Vector3.Zero.Z);
        }
        [TestCase]
        public void Vector3_BuildVithValues_ComponentsSetCorrect()
        {
            Vector3 vector = new Vector3(1, 2, 3);
            Assert.AreEqual(1, vector.X);
            Assert.AreEqual(2, vector.Y);
            Assert.AreEqual(3, vector.Z);
        }
    }
}
