using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Runtime.InteropServices;

namespace CircularElevator
{
    internal sealed class CommandReader : IDisposable
    {
        public struct Command
        {
            public ECommand Cmd { get; set; }
            public byte[] Arguments { get; set; }

            public Command(ECommand cmd, params byte[] args)
            {
                Cmd = cmd;
                Arguments = args;
            }

            public byte this[int idx]
            {
                get => Arguments[idx];
            }

            public static readonly Command Empty = new Command(ECommand.None, null);
        }

        private Stream stream = null;

        public CommandReader(Stream stream)
        {
            this.stream = stream;
        }

        public Command ReadCommand()
        {
            Command cmd = new Command();

            cmd.Cmd = (ECommand)stream.ReadByte();
            var args = new List<byte>();

            for (int arg = stream.ReadByte(); arg != 255; arg = stream.ReadByte())
            {
                args.Add((byte)arg);
            }

            cmd.Arguments = args.ToArray();

            return cmd;
        }

        #region IDisposable Support
        private bool disposedValue = false;

        void Dispose(bool disposing)
        {
            if (!disposedValue)
            {
                if (disposing)
                {
                    stream.Dispose();
                }

                disposedValue = true;
            }
        }

        public void Dispose()
        {
            Dispose(true);
        }
        #endregion
    }
}
