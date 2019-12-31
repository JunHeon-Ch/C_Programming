using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CircularElevator
{
    internal enum ECommand : byte
    {
        None = 0,
        Elevator = 1,
        RemainingTime = 2,
        GetIn = 3,
        GetOut = 4,
    }
}
