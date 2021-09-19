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
            if(PrepareStartCallIsOk)
                throw new InvalidOperationException(
                    "PrepareStart already called"
                );

            PrepareStartCallIsOk = true;
        }
        public void PrepareEnd() 
        {
            if(!PrepareStartCallIsOk)
                throw new InvalidOperationException(
                    "PrepareEnd call before PrepareStart"
                );
            if (!Game.Instance.Prepared)
                throw new InvalidOperationException(
                    "PrepareEnd call before preparation"
                );
            if (PrepareEndCallIsOk)
                throw new InvalidOperationException(
                    "PrepareEnd already called"
                );
            PrepareEndCallIsOk = true;
        }
        
        public void LoadStart() 
        {
            if (Game.Instance.Loaded)
                throw new InvalidOperationException(
                    "LoadStart call after loading"
                );
            if (LoadStartCallIsOk)
                throw new InvalidOperationException(
                    "LoadStart already called"
                );

            LoadStartCallIsOk = true;
        }
        public void LoadEnd()
        {
            if (!LoadStartCallIsOk)
                throw new InvalidOperationException(
                    "LoadEnd call before LoadStart"
                );
            if (!Game.Instance.Loaded)
                throw new InvalidOperationException(
                    "LoadEnd call before loading"
                );
            if (LoadEndCallIsOk)
                throw new InvalidOperationException(
                    "LoadEnd already called"
                );
            LoadEndCallIsOk = true;
        }
        
        public void InitializeStart()
        {
            if (Game.Instance.Initialized)
                throw new InvalidOperationException(
                    "InitializeStart call after initialization"
                );
            if (InitializeStartCallIsOk)
                throw new InvalidOperationException(
                    "InitializeStart already called"
                );

            InitializeStartCallIsOk = true;
        }
        public void InitializeEnd() 
        {
            if (!LoadStartCallIsOk)
                throw new InvalidOperationException(
                    "InitializeEnd call before InitializeStart"
                );
            if (!Game.Instance.Loaded)
                throw new InvalidOperationException(
                    "InitializeEnd call before initialization"
                );
            if (InitializeEndCallIsOk)
                throw new InvalidOperationException(
                    "InitializeEnd already called"
                );
            InitializeEndCallIsOk = true;
        }
    }
}
