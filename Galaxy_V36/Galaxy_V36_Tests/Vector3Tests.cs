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

        [TestCase]
        public void Add_AddSomeVector_ComponentsChangeCorrect()
        {
            Vector3 vector1 = new Vector3(1, 2, 3);
            Vector3 vector2 = new Vector3(3, 1, 6);
            Vector3 res = vector1.Add(vector2);
            Assert.AreEqual(new Vector3(4, 3, 9), res);
        }
        [TestCase]
        public void Add_AddSomeVector_ComponentsSourceVectorNotChanged()
        {
            Vector3 vector1 = new Vector3(1, 2, 3);
            Vector3 vector2 = new Vector3(3, 1, 6);
            Vector3 res = vector1.Add(vector2);
            Assert.AreEqual(new Vector3(1, 2, 3), vector1);
        }
        [TestCase]
        public void Add_AddSomeVector_ComponentsadditionVectorNotChanged()
        {
            Vector3 vector1 = new Vector3(1, 2, 3);
            Vector3 vector2 = new Vector3(3, 1, 6);
            Vector3 res = vector1.Add(vector2);
            Assert.AreEqual(new Vector3(3, 1, 6), vector2);
        }

        [TestCase]
        public void Equals_VectorsWithEqualsComponents_ReturnTrue()
        {
            Vector3 vector1 = new Vector3(1, 2, 3);
            Vector3 vector2 = new Vector3(1, 2, 3);
            Assert.IsTrue(vector1.Equals(vector2));
        }
    }
}
