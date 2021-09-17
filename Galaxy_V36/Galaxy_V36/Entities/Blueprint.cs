using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36.Entities
{
    public class Blueprint
    {
        public BlueprintType Type
        {
            get { return type; }
        }
        public int UniversalInterfacesCount
        {
            get { return universalInterfacesCount; }
        }
        public int EnergyInterfacesCount
        {
            get { return energyInterfacesCount; }
        }
        public string Name
        {
            get { return name; }
        }

        public static Blueprint Build(string descr)
        {
            return null;
        }

        private BlueprintType type;
        private int universalInterfacesCount;
        private int energyInterfacesCount;
        private string name;
    }
}
