using Galaxy_V36.UI;
using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36.Engine
{
    public class Game
    {
        public Game(IUserInterface userInterface)
        {
            this.userInterface = userInterface;
        }

        public void Run()
        {            
            Prepare();
            Load();
            Initialize();
            while (Tik()) ;
        }

        private void Prepare()
        {
            userInterface.PrepareStart();
            PreparationProcedure();
            userInterface.PrepareEnd();
        }
        private void PreparationProcedure()
        {
        }

        private void Load()
        {
            userInterface.LoadStart();
            LoadingProcedure();
            userInterface.LoadEnd();
        }
        private void LoadingProcedure()
        {
        }

        private void Initialize()
        {
            userInterface.InitializeStart();
            InitializationProcedure();
            userInterface.InitializeEnd();
        }
        private void InitializationProcedure()
        {
        }

        private bool Tik()
        {
            return false;
        }

        private IUserInterface userInterface;
    }
}
