using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CircularElevator
{
    internal sealed class Elevator
    {
        public static int TotalCount { get; private set; } = 0;

        public int Id { get; }
        public int Floor { get; set; }
        public EHorizontalPosition HorizontalPosition { get; set; }
        public EElevatorState State { get; set; }
        public EIconId IconId { get; set; }

        public Elevator()
        {
            Id = TotalCount++;

            Floor = 1;
            HorizontalPosition = EHorizontalPosition.Left;
            State = EElevatorState.Running;
        }

        public Elevator(int floor, EHorizontalPosition horizontalPosition, EElevatorState state)
        {
            Id = TotalCount++;

            Floor = floor;
            HorizontalPosition = horizontalPosition;
            State = state;

            IconId = EIconId.Normal;
        }
    }
}
