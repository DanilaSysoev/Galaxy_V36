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

        public void Run()
        {
            Prepare();
            Load();
            Initialize();
            while (Tick()) ;
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
                throw new InvalidOperationException("Call Prepare first");
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
                throw new InvalidOperationException("Call Prepare first");
            if (!Loaded)
                throw new InvalidOperationException("Call Load first");

            Initialized = true;
        }

        public bool Tick()
        {
            if (!Prepared)
                throw new InvalidOperationException("Call Prepare first");
            if (!Loaded)
                throw new InvalidOperationException("Call Load first");
            if (!Initialized)
                throw new InvalidOperationException("Call Initialize first");

            if(waitCommand)
                GetAndProcessCommand();
            else
                ProcessTask();

            return false;
        }

        public static Game Instance { get; private set; }
        public static Game CreateGame(IUserInterface userInterface)
        {
            if (Instance == null)
                Instance = new Game(userInterface);
            return Instance;
        }
        public static void DestroyGame()
        {
            if (Instance != null)
                Instance.Destroy();
            Instance = null;
        }

        private IUserInterface userInterface;
        private ICommandProcessor commandProcessor;
        private bool waitCommand;

        private Game(IUserInterface userInterface)
        {
            this.userInterface = userInterface;
            this.commandProcessor = new CommandProcessor();
            Prepared = false;
            Loaded = false;
            Initialized = false;
        }
        private Game(
            IUserInterface userInterface,
            ICommandProcessor commandProcessor
        )
        {
            this.userInterface = userInterface;
            this.commandProcessor = commandProcessor;
            Prepared = false;
            Loaded = false;
            Initialized = false;
        }
        private void GetAndProcessCommand()
        {
            string command = userInterface.GetCommand();
            ProcessCommand(command);
        }
        private void ProcessCommand(string command) 
        {
            commandProcessor.ProcessCommand(command);
        }
        private void ProcessTask() { }
        private void Destroy() { }
    }
}
