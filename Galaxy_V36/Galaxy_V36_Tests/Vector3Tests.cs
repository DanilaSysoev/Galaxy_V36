﻿using Galaxy_V36.Service;
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
    }
}