using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36_Tests
{
    [TestFixture]
    class BlueprintTests
    {
        [TestCase]
        public void Build_BuildFromstringWithNameEnergyAndUniversalRecords_BuildingOk()
        {
            string bpDescr = 
                "Name: Default\n" +
                "Type: Ship\n" +
                "Universal: 2\n" +
                "Energy: 5";
            Blueprint blueprint = Blueprint.Build(bpDescr);
            Assert.AreEqual("Default", blueprint.Name);
            Assert.AreEqual(BlueprintType.Ship, blueprint.Type);
            Assert.AreEqual(2, blueprint.UniversalInterfacesCount);
            Assert.AreEqual(5, blueprint.EnergyInterfacesCount);

        }
    }
}
