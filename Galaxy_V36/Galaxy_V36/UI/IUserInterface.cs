using System;
using System.Collections.Generic;
using System.Text;

namespace Galaxy_V36.UI
{
    public interface IUserInterface
    {
        void PrepareStart() { }
        void PrepareEnd() { }

        void LoadStart() { }
        void LoadEnd() { }

        void InitializeStart() { }
        void InitializeEnd() { }
    }
}
