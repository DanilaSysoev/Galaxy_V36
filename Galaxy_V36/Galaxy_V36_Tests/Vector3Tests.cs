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
        public void Vector3_CreationWithoutParams_CoordinatesEqualsZero()
        {
            Vector3 vector3 = new Vector3();
            Assert.AreEqual(0, vector3.X);
            Assert.AreEqual(0, vector3.Y);
            Assert.AreEqual(0, vector3.Z);
        }
    }
}
