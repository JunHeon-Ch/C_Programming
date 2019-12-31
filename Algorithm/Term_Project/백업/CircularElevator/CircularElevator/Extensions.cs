using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Numerics;

namespace CircularElevator
{
    internal static class Extensions
    {
        internal static void DrawHorizontalLine(this Graphics graphics, Pen pen, Point offset, int length)
        {
            graphics.DrawLine(pen, offset.X, offset.Y, offset.X + length, offset.Y);
        }

        internal static void DrawVerticalLine(this Graphics graphics, Pen pen, Point offset, int length)
        {
            graphics.DrawLine(pen, offset.X, offset.Y, offset.X, offset.Y + length);
        }
    }
}
