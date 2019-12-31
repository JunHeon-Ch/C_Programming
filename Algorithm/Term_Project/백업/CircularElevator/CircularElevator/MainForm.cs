//  TODO: 
//      render elevator -> after confirm

#define CONNECT_SERVER

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Net;
using System.Net.Sockets;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CircularElevator
{
    public partial class MainForm : Form
    {
        #region Image Resources

        private static readonly Image ActivatedFloorButtonBackground = Properties.Resources.selectedFloorBtn;
        private static readonly Image DeactivatedFloorButtonBackground = Properties.Resources.unselectedFloorBtn;

        private static readonly Image ActivatedArrowImage = Properties.Resources.actUpLed;
        private static readonly Image DeactivatedArrowImage = Properties.Resources.inactUpLed;

        private static readonly Dictionary<EIconId, Image> ElevatorImages = new Dictionary<EIconId, Image>
        {
            { EIconId.Normal, Properties.Resources.closedElevator },
            { EIconId.GetIn, Properties.Resources.loadElevator },
            { EIconId.GetOut, Properties.Resources.unloadElevator },
            { EIconId.Occupied, Properties.Resources.occupiedElevator }
        };

        private static Size FullElevatorImageSize => ElevatorImages[EIconId.Normal].Size;

        #endregion

        private const int BorderWidth = 25;
        private const int ElevatorHeight = 100;

        private const int FloorCount = 6;
        private readonly List<Panel> CommonFloorBtns = null;
        private readonly List<Panel> CallingFloorBtns = null;
        private readonly FloorInfo[] Floors = null;

        private int selectedFloor = 1;
        private Panel SelectedFloorBtn => CommonFloorBtns[selectedFloor - 1];

        private const int ElevatorCount = 3;

        private Socket socket = null;
        private CommandReader cmdReader = null;
        private Elevator[] elevators = new Elevator[ElevatorCount] { new Elevator(), new Elevator(), new Elevator() };

        public MainForm()
        {
            InitializeComponent();

            Floors = new FloorInfo[FloorCount];
            for (int i = 0; i < FloorCount; i++)
            {
                Floors[i] = new FloorInfo(FloorCount);
                Floors[i].SelectionChanged += Floors_SelectionChagned;
            }

            CallingFloorBtns = new List<Panel> { f1Btn, f2Btn, f3Btn, f4Btn, f5Btn, f6Btn };
            foreach (var FloorButton in CallingFloorBtns)
            {
                FloorButton.Paint += FloorButton_Paint;
            }

            CommonFloorBtns = new List<Panel> { cF1Btn, cF2Btn, cF3Btn, cF4Btn, cF5Btn, cF6Btn };
            foreach (var CommonFloorButton in CommonFloorBtns)
            {
                CommonFloorButton.Paint += CommonFloorButton_Paint;
            }
        }

        protected override void OnLoad(EventArgs e)
        {
#if CONNECT_SERVER
            try
            {
                socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                socket.Connect(IPAddress.Loopback, 10501);

                cmdReader = new CommandReader(new NetworkStream(socket));
            }
            catch (SocketException)
            {
                MessageBox.Show("서버를 찾을 수 없습니다.", "접속 오류", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Close();
            }

            // initialize floors

            simulationView.Invalidate();

            Task.Run(() =>
            {
                while (true)
                {
                    using (var stream = new NetworkStream(socket))
                    {
                        var cmd = cmdReader.ReadCommand();

                        System.Diagnostics.Debug.WriteLine($"{cmd.Cmd}, {string.Join(", ", cmd.Arguments)}");

                        switch (cmd.Cmd)
                        {
                            case ECommand.Elevator:
                                {
                                    var id = cmd[0];
                                    var iconId = (EIconId)cmd[1];
                                    var floor = cmd[2];
                                    var horPos = (EHorizontalPosition)cmd[3];
                                    var state = (EElevatorState)cmd[4];

                                    elevators[id].Floor = floor;
                                    elevators[id].HorizontalPosition = horPos;
                                    elevators[id].State = state;
                                    elevators[id].IconId = iconId;

                                    simulationView.Invoke((Action)simulationView.Invalidate);
                                    break;
                                }

                            case ECommand.RemainingTime:
                                {
                                    var min = cmd[0];
                                    var sec = cmd[1];

                                    estimatedTimeLabel.Invoke((Action<byte, byte>)ShowRemainingTime, min, sec);
                                    break;
                                }

                            case ECommand.GetIn:
                                {
                                    var start = (int)cmd[0];
                                    var end = (int)cmd[1];

                                    Invoke((Action<int, int>)TurnLightOff, start, end);
                                    simulationView.Invoke((Action)simulationView.Invalidate);
                                    break;
                                }

                            case ECommand.GetOut:
                                {
                                    var dest = (int)cmd[0];

                                    simulationView.Invoke((Action)simulationView.Invalidate);
                                    break;
                                }

                            default:
                                break;
                        }
                    }

                    using (var delay = Task.Delay(10))
                    {
                        delay.Wait();
                    }
                }
            });
#endif

            base.OnLoad(e);
        }

        private void CommonFloorButton_Click(object sender, EventArgs e)
        {
            Panel btn = sender as Panel;
            Panel prev = SelectedFloorBtn;

            GotoFloor(CommonFloorBtns.IndexOf(btn) + 1);

            prev.Invalidate();
            btn.Invalidate();
        }

        private void CallingFloorButton_Click(object sender, EventArgs e)
        {
            Panel btn = sender as Panel;
            int floor = CallingFloorBtns.IndexOf(btn) + 1;

            if (selectedFloor != floor)
            {
                if (!Floors[selectedFloor - 1][floor])
                {
                    Floors[selectedFloor - 1][floor] = true;

                    upLed.Invalidate();
                    downLed.Invalidate();

#if CONNECT_SERVER
                    using (var writer = new StreamWriter(new NetworkStream(socket)))
                    {
                        writer.WriteLine(selectedFloor); // current
                        writer.WriteLine(floor); // dest
                        writer.Flush();
                    }
#endif
                }
            }
        }

        private void Floors_SelectionChagned(object sender, int floor)
        {
            CallingFloorBtns[floor - 1].Invalidate();
        }

        #region Paint

        private void CommonFloorButton_Paint(object sender, PaintEventArgs e)
        {
            Panel btn = sender as Panel;
            int floor = CommonFloorBtns.IndexOf(btn) + 1;
            string floorString = $"{floor}F";

            using (var blackBrush = new SolidBrush(Color.Black))
            {
                SizeF size = e.Graphics.MeasureString(floorString, btn.Font);
                e.Graphics.DrawString(floorString, btn.Font, blackBrush, (btn.Width - size.Width) / 2, (btn.Height - size.Height) / 2);

                if (SelectedFloorBtn == btn)
                {
                    using (var transparentWhiteBrush = new SolidBrush(Color.FromArgb(150, Color.White)))
                    {
                        e.Graphics.FillRectangle(transparentWhiteBrush, new Rectangle(Point.Empty, btn.Size));
                    }
                }
            }
        }

        private void FloorButton_Paint(object sender, PaintEventArgs e)
        {
            Panel btn = sender as Panel;
            int floor = CallingFloorBtns.IndexOf(btn) + 1;
            string floorString = $"{floor}F";

            btn.BackgroundImage = Floors[selectedFloor - 1][floor] ? ActivatedFloorButtonBackground : DeactivatedFloorButtonBackground;

            using (var colorBrush = new SolidBrush(Floors[selectedFloor - 1][floor] ? Color.Red : Color.FromArgb(100, 0, 0)))
            {
                SizeF size = e.Graphics.MeasureString(floorString, btn.Font);
                e.Graphics.DrawString(floorString, btn.Font, colorBrush, (btn.Width - size.Width) / 2, (btn.Height - size.Height) / 2);

                if (SelectedFloorBtn == btn)
                {
                    using (var transparentWhiteBrush = new SolidBrush(Color.FromArgb(150, Color.White)))
                    {
                        e.Graphics.FillRectangle(transparentWhiteBrush, new Rectangle(Point.Empty, btn.Size));
                    }
                }
            }
        }

        private void DirectionLed_Paint(object sender, PaintEventArgs e)
        {
            Panel led = sender as Panel;
            Func<int, bool> compareFloor;
            bool isUp = led.Equals(upLed);

            if (isUp)
            {
                compareFloor = (floor) => floor > selectedFloor;
            }
            else
            {
                compareFloor = (floor) => floor < selectedFloor;
            }

            bool bOn = false;
            for (int f = 1; f <= FloorCount; f++)
            {
                if (Floors[selectedFloor - 1][f])
                {
                    if (compareFloor(f))
                    {
                        bOn = true;
                        break;
                    }
                }
            }

            using (var arrow = (bOn ? ActivatedArrowImage : DeactivatedArrowImage).Clone() as Image)
            {
                if (!isUp)
                {
                    arrow.RotateFlip(RotateFlipType.Rotate180FlipX);
                }

                e.Graphics.DrawImage(arrow,
                    new Rectangle(Point.Empty, led.Size),
                    new Rectangle(Point.Empty, arrow.Size),
                    GraphicsUnit.Pixel);
            }
        }

        private void SimulationView_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.SmoothingMode = SmoothingMode.AntiAlias;

            int halfBorderWidth = BorderWidth / 2;
            int doubleBorderWidth = BorderWidth * 2;
            float halfDiagonal = (float)(Math.Sqrt(2) * halfBorderWidth * 0.75);
            int quarterWidth = (simulationView.Width - doubleBorderWidth) / 4;

            int floorStep = (simulationView.Height - BorderWidth - ElevatorHeight) / (FloorCount - 1);

            // Elevator movement line
            using (var wirePen = new Pen(Brushes.Black, 3))
            {
                Size lineLength = new Size(simulationView.Width - (quarterWidth + BorderWidth) * 2, simulationView.Height - BorderWidth);

                // Virtical wire
                e.Graphics.DrawVerticalLine(wirePen,
                    new Point(BorderWidth + quarterWidth, halfBorderWidth),
                    lineLength.Height);
                e.Graphics.DrawVerticalLine(wirePen,
                    new Point(simulationView.Width - BorderWidth - quarterWidth, halfBorderWidth),
                    lineLength.Height);

                // Mask dash
                wirePen.DashPattern = new float[] { 7F, 7F };

                // Horizontal wire
                e.Graphics.DrawHorizontalLine(wirePen,
                    new Point(BorderWidth + quarterWidth, halfBorderWidth),
                    lineLength.Width);
                e.Graphics.DrawHorizontalLine(wirePen,
                    new Point(BorderWidth + quarterWidth, simulationView.Height - halfBorderWidth - floorStep),
                    lineLength.Width);
            }

            // Floor separator
            using (var floorSepPen = new Pen(Color.FromArgb(150, Color.White), 2F))
            using (var floorSepBrush = new SolidBrush(Color.FromArgb(70, Color.White)))
            {
                int offsetY = simulationView.Height - halfBorderWidth;

                using (var floorFont = new Font("맑은 고딕", 15, FontStyle.Regular, GraphicsUnit.Point))
                {
                    float ratio = 1;
                    float ratStep = 2F / (FloorCount - 1);

                    Rectangle elevRect = new Rectangle(0, 0, floorStep * FullElevatorImageSize.Width / FullElevatorImageSize.Height, floorStep);
                    for (int i = 1; i <= FloorCount + 1; i++)
                    {
                        int floor = i - 1;
                        Elevator[] toDraw = (from el in elevators where el.Floor == floor select el).ToArray();

                        float diagonalOffset = halfDiagonal * ratio;
                        ratio -= ratStep;
                        PointF[] points =
                        {
                            new PointF(0, offsetY + diagonalOffset),
                            new PointF(BorderWidth, offsetY - diagonalOffset),
                            new PointF(simulationView.Width - BorderWidth, offsetY - diagonalOffset),
                            new PointF(simulationView.Width, offsetY + diagonalOffset),
                        };

                        // set position of elevator to draw
                        elevRect.Y = offsetY;

                        if (floor <= FloorCount / 2 || true)
                        {
                            foreach (var elevator in toDraw)
                            {
                                Image imageToDraw = ElevatorImages[elevator.IconId];

                                switch (elevator.HorizontalPosition)
                                {
                                    case EHorizontalPosition.Left:
                                        elevRect.X = quarterWidth;
                                        break;

                                    case EHorizontalPosition.Right:
                                        elevRect.X = quarterWidth * 3;
                                        break;

                                    case EHorizontalPosition.Center:
                                        elevRect.X = quarterWidth * 2;
                                        break;

                                    default:
                                        break;
                                }

                                elevRect.X += BorderWidth - elevRect.Width / 2;

                                e.Graphics.DrawImage(imageToDraw, elevRect);
                            }
                        }

                        if (i != 7)
                        {
                            using (var path = new GraphicsPath())
                            {
                                path.AddPolygon(points);
                                e.Graphics.DrawPath(floorSepPen, path);

                                using (var region = new Region(path))
                                {
                                    e.Graphics.FillRegion(floorSepBrush, region);
                                }

                                string floorString = $"{i}F";
                                SizeF floorSize = e.Graphics.MeasureString(floorString, floorFont);
                                e.Graphics.DrawString(floorString, floorFont, Brushes.GhostWhite, 0, path.GetBounds().Top - floorSize.Height);
                            }
                        }

                        offsetY -= floorStep;
                    }
                }
            }
        }

        #endregion

        private void ShowRemainingTime(byte minutes, byte seconds)
        {
            estimatedTimeLabel.Text = minutes.ToString("00") + ':' + seconds.ToString("00");
            estimatedTimeLabel.ForeColor = Color.Red;
        }

        private void TurnLightOff(int floor, int destination)
        {
            Floors[floor - 1][destination] = false;
            foreach (Panel btn in CallingFloorBtns)
            {
                btn.Invalidate();
            }

            upLed.Invalidate();
            downLed.Invalidate();
        }

        private void GotoFloor(int floor)
        {
            selectedFloor = floor;
            for (int i = 0; i < FloorCount; i++)
            {
                CallingFloorBtns[i].Invalidate();
            }

            upLed.Invalidate();
            downLed.Invalidate();
        }
    }
}
