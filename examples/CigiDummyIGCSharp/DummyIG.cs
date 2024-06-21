using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

class Program
{
    static void Main()
    {
        TcpListener server = null;
        try
        {
            Int32 port = 8000;
            IPAddress localAddr = IPAddress.Parse("127.0.0.1");

            server = new TcpListener(localAddr, port);
            server.Start();

            Console.WriteLine("Waiting for a connection... ");

            while (true)
            {
                TcpClient client = server.AcceptTcpClient();
                Console.WriteLine("Connected!");

                NetworkStream stream = client.GetStream();

                byte[] bytes = new byte[256];
                int i;

                while ((i = stream.Read(bytes, 0, bytes.Length)) != 0)
                {
                    string data = Encoding.ASCII.GetString(bytes, 0, i);
                    Console.WriteLine($"Received: {data}");

                    data = data.ToUpper();
                    byte[] msg = Encoding.ASCII.GetBytes(data);

                    stream.Write(msg, 0, msg.Length);
                    Console.WriteLine($"Sent: {data}");
                }

                client.Close();
            }
        }
        catch (SocketException e)
        {
            Console.WriteLine($"SocketException: {e}");
        }
        finally
        {
            server.Stop();
        }
    }
}
