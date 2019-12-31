using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CircularElevator
{
    internal class FloorInfo
    {
        public event EventHandler<int> SelectionChanged = null;
        protected virtual void OnSelectionChanged(int floor)
        {
            SelectionChanged?.Invoke(this, floor);
        }

        private bool[] selections = null;

        public int FloorCount { get; } = 0;

        public FloorInfo(int floorCount)
        {
            FloorCount = floorCount;

            selections = new bool[floorCount];
        }

        public bool this[int floor]
        {
            get
            {
                floor--;

                if (floor < 0 || FloorCount <= floor)
                {
                    throw new IndexOutOfRangeException();
                }

                return selections[floor];
            }
            set
            {
                floor--;
                if (floor < 0 || FloorCount <= floor)
                {
                    throw new IndexOutOfRangeException();
                }

                if (selections[floor] != value)
                {
                    selections[floor] = value;
                    OnSelectionChanged(floor + 1);
                }
            }
        }
    }
}
