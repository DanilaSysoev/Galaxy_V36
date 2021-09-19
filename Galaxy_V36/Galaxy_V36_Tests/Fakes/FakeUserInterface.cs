using Galaxy_V36.Engine;
using Galaxy_V36.UI;
using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36_Tests.Fakes
{
    class FakeUserInterface : IUserInterface
    {
        public bool PrepareStartCallIsOk { get; private set; }
        public bool PrepareEndCallIsOk { get; private set; }

        public bool LoadStartCallIsOk { get; private set; }
        public bool LoadEndCallIsOk { get; private set; }

        public bool InitializeStartCallIsOk { get; private set; }
        public bool InitializeEndCallIsOk { get; private set; }

        public void PrepareStart() 
        {
            if(Game.Instance == null)
                throw new InvalidOperationException(
                    "PrepareStart call before game creation"
                );
            if (Game.Instance.Prepared)
                throw new InvalidOperationException(
                    "PrepareStart call after preparation"
                );
                
            PrepareStartCallIsOk = true;
        }
        public void PrepareEnd() 
        {
            PrepareEndCallIsOk = true;
        }
        
        public void LoadStart() { }
        public void LoadEnd() { }
        
        public void InitializeStart() { }
        public void InitializeEnd() { }
    }
}
