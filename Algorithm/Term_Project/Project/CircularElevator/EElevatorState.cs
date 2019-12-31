using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CircularElevator
{
    internal enum EElevatorState : byte
    {
        Running = 1,
        Stopped = 2,
        Opened = 3,
        Closed = 4,
    }
}
