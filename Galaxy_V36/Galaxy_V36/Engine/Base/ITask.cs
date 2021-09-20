using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36.Engine.Base
{
    public interface ITask
    {
        float Progress { get; }
        TaskStatus Status { get; }
        void Start();
        void Pause();
        void Stop();
    }
}
