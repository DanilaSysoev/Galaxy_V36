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
        [TestCase]
        public void Vector3_CreationWithParams_CoordinatesEqualsParams()
        {
            Vector3 vector3 = new Vector3(1, 2, 3);
            Assert.AreEqual(1, vector3.X);
            Assert.AreEqual(2, vector3.Y);
            Assert.AreEqual(3, vector3.Z);
        }

        [TestCase]
        public void ToString_IntegerComponents_CorrectString()
        {
            Vector3 vector3 = new Vector3(1, 2, 3);
            Assert.AreEqual("Vector3(1.0, 2.0, 3.0)", vector3.ToString());
        }
        [TestCase]
        public void ToString_FloatComponents_CorrectString()
        {
            Vector3 vector3 = new Vector3(1.111f, 2.222f, 3.333f);
            Assert.AreEqual("Vector3(1.1, 2.2, 3.3)", vector3.ToString());
        }
        [TestCase]
        public void ToString_FloatComponentsGreater05_CorrectString()
        {
            Vector3 vector3 = new Vector3(1.16f, 2.26f, 3.333f);
            Assert.AreEqual("Vector3(1.2, 2.3, 3.3)", vector3.ToString());
        }

        [TestCase]
        public void Equals_XComponentDiif_NotEqual()
        {
            Vector3 v1 = new Vector3(1, 2, 3);
            Vector3 v2 = new Vector3(2, 2, 3);
            Assert.IsFalse(v1.Equals(v2));
            Assert.IsFalse(v2.Equals(v1));
        }
        [TestCase]
        public void Equals_YComponentDiif_NotEqual()
        {
            Vector3 v1 = new Vector3(1, 2, 3);
            Vector3 v2 = new Vector3(1, 3, 3);
            Assert.IsFalse(v1.Equals(v2));
            Assert.IsFalse(v2.Equals(v1));
        }
        [TestCase]
        public void Equals_ZComponentDiif_NotEqual()
        {
            Vector3 v1 = new Vector3(1, 2, 3);
            Vector3 v2 = new Vector3(1, 2, 2);
            Assert.IsFalse(v1.Equals(v2));
            Assert.IsFalse(v2.Equals(v1));
        }
        [TestCase]
        public void Equals_IntComponentsEquals_Equal()
        {
            Vector3 v1 = new Vector3(1, 2, 3);
            Vector3 v2 = new Vector3(1, 2, 3);
            Assert.IsTrue(v1.Equals(v2));
            Assert.IsTrue(v2.Equals(v1));
        }
        [TestCase]
        public void Equals_FloatComponentsEquals_Equal()
        {
            Vector3 v1 = new Vector3(1.1f, 2.2f, 3.3f);
            Vector3 v2 = new Vector3(1.1f, 2.2f, 3.3f);
            Assert.IsTrue(v1.Equals(v2));
            Assert.IsTrue(v2.Equals(v1));
        }
        [TestCase]
        public void Equals_FloatComponentsWithSmallDiff_Equal()
        {
            Vector3 v1 = new Vector3(1.0000005f, 2.0000007f, 2.9999992f);
            Vector3 v2 = new Vector3(1, 2, 3);
            Assert.IsTrue(v1.Equals(v2));
            Assert.IsTrue(v2.Equals(v1));
        }

        [TestCase]
        public void Add_AddIntegerComponents_ResultIsOk()
        {
            Vector3 v1 = new Vector3(1, 2, 3);
            Vector3 v2 = new Vector3(1, 2, 3);
            v1.Add(v2);
            Assert.AreEqual(new Vector3(2, 4, 6), v1);
        }
        [TestCase]
        public void Add_AddFloatComponents_ResultIsOk()
        {
            Vector3 v1 = new Vector3(1.1001f, 2.2002f, 3.3003f);
            Vector3 v2 = new Vector3(1.2001f, 2.1002f, 3.1234f);
            v1.Add(v2);
            Assert.AreEqual(new Vector3(2.3002f, 4.3004f, 6.4237f), v1);
        }

        [TestCase]
        public void Multiply_MultiplyIntegerCoefficient_ResultIsOk()
        {
            Vector3 v1 = new Vector3(1, 2, 3);
            v1.Multiply(3);
            Assert.AreEqual(new Vector3(3, 6, 9), v1);
        }
        [TestCase]
        public void Multiply_MultiplyFloatCoefficient_ResultIsOk()
        {
            Vector3 v1 = new Vector3(1.1001f, 2.2002f, 3.3003f);
            v1.Multiply(3.1f);
            Assert.AreEqual(new Vector3(3.41031f, 6.82062f, 10.23093f), v1);
        }

        [TestCase]
        public void Plus_SumIntegerComponents_ResultIsOk()
        {
            Vector3 v1 = new Vector3(1, 2, 3);
            Vector3 v2 = new Vector3(1, 2, 3);
            Assert.AreEqual(new Vector3(2, 4, 6), v1 + v2);
        }
        [TestCase]
        public void Plus_SumFloatComponents_ResultIsOk()
        {
            Vector3 v1 = new Vector3(1.1001f, 2.2002f, 3.3003f);
            Vector3 v2 = new Vector3(1.2001f, 2.1002f, 3.1234f);
            Assert.AreEqual(new Vector3(2.3002f, 4.3004f, 6.4237f), v1 + v2);
        }
        [TestCase]
        public void Plus_SumIntegerComponents_LeftOperandOk()
        {
            Vector3 v1 = new Vector3(1, 2, 3);
            Vector3 v2 = new Vector3(2, 3, 4);
            Vector3 v3 = v1 + v2;
            Assert.AreEqual(new Vector3(1, 2, 3), v1);
        }
        [TestCase]
        public void Plus_SumIntegerComponents_RoghtOperandOk()
        {
            Vector3 v1 = new Vector3(1, 2, 3);
            Vector3 v2 = new Vector3(2, 3, 4);
            Vector3 v3 = v1 + v2;
            Assert.AreEqual(new Vector3(2, 3, 4), v2);
        }

        [TestCase]
        public void Multiplication_MultiplyIntegerCoefficient_ResultIsOk()
        {
            Vector3 v1 = new Vector3(1, 2, 3);
            Assert.AreEqual(new Vector3(3, 6, 9), v1 * 3);
        }
        [TestCase]
        public void Multiplication_MultiplyFloatCoefficient_ResultIsOk()
        {
            Vector3 v1 = new Vector3(1.1001f, 2.2002f, 3.3003f);
            Assert.AreEqual(
                new Vector3(3.41031f, 6.82062f, 10.23093f), v1 * 3.1f
            );
        }
    }
}
