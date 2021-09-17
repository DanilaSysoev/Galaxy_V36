using Galaxy_V36.UI;
using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36.Engine
{
    public class Game
    {
        public bool Prepared { get; private set; }
        public bool Loaded { get; private set; }
        public bool Initialized { get; private set; }

        public Game(IUserInterface userInterface)
        {
            this.userInterface = userInterface;
            Prepared = false;
            Loaded = false;
            Initialized = false;
        }

        public void Run()
        {
            Prepare();
            Load();
            Initialize();
            while (Tik()) ;
        }

        public void Prepare()
        {
            userInterface.PrepareStart();
            PreparationProcedure();
            userInterface.PrepareEnd();
        }
        private void PreparationProcedure()
        {

            Prepared = true;
        }

        public void Load()
        {
            userInterface.LoadStart();
            LoadingProcedure();
            userInterface.LoadEnd();
        }
        private void LoadingProcedure()
        {
            if (!Prepared)
                throw new InvalidOperationException("Call prepare first");
            Loaded = true;
        }

        public void Initialize()
        {
            userInterface.InitializeStart();
            InitializationProcedure();
            userInterface.InitializeEnd();
        }
        private void InitializationProcedure()
        {
            if (!Prepared)
                throw new InvalidOperationException("Call prepare first");
            if (!Loaded)
                throw new InvalidOperationException("Call load first");

            Initialized = true;
        }

        public bool Tik()
        {
            return false;
        }

        private IUserInterface userInterface;
    }
}
