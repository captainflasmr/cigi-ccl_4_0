using System;
using System.Collections.Generic;
using System.Net.Sockets;
using System.IO;
using System.Xml;
using System.Threading;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

public struct DbInfo
{
    public int Id;
    public double Lat;
    public double Lon;
    public double Alt;

    public override string ToString()
    {
        return $"Id: {Id}, Lat: {Lat}, Lon: {Lon}, Alt: {Alt}";
    }
}

class Network
{
    public TcpClient client;

    // Method to open a socket and connect to a server.
    public bool OpenSocket(string hostIpAddr, int portToHost, int localPort)
    {
        try
        {
            // Attempt to connect to the remote host
            client = new TcpClient();

            // Optionally, bind the client to a specific local port if necessary
            // This is less common for client sockets, but can be done by specifying the local endpoint first
            // Uncomment the line below to bind to a local port (make sure localPort is available)
            // client.Client.Bind(new IPEndPoint(IPAddress.Any, localPort));

            // Connect to the remote host
            client.Connect(hostIpAddr, portToHost);

            Console.WriteLine($"Successfully opened socket for comm with CIGI IG server at {hostIpAddr}:{portToHost}");
            return true;
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Could not open socket for comm with CIGI IG server. Exception: {ex.Message}");
            Environment.Exit(1);
            return false; // This line will not be reached due to the exit above, it's included for method completeness
        }
    }
}

class Program
{
    static byte[] pCigiOutBuf;
    static readonly int RECV_BUFFER_SIZE = 32768;
    static byte[] CInBuf = new byte[RECV_BUFFER_SIZE]; // Assuming similar size
    static int CigiInSz;
    static int CigiOutSz;
    static int Port_H2IG;
    static int Port_IG2H;
    static string IGAddr;

    static List<DbInfo> dbList = new List<DbInfo>();

    static CigiHostSession HostSn;
    static CigiOutgoingMsg OmsgPtr;
    static CigiIncomingMsg ImsgPtr;
    static CigiEntityCtrlV3_3 COwn;

    public static SWIGTYPE_p_unsigned___int16 CreateInstance(ushort value) {
        // Create a GCHandle to pin the managed ushort
        GCHandle handle = GCHandle.Alloc(value, GCHandleType.Pinned);

        // Get the pointer to the pinned memory
        IntPtr ptr = handle.AddrOfPinnedObject();

        // Create an instance of SWIGTYPE_p_unsigned___int16 using the pointer
        SWIGTYPE_p_unsigned___int16 instance = new SWIGTYPE_p_unsigned___int16(ptr, true);

        // Free the GCHandle when done
        handle.Free();

        return instance;
    }

    public static ushort GetValue(SWIGTYPE_p_unsigned___int16 instance) {
        // Get the pointer from the SWIGTYPE_p_unsigned___int16 instance
        IntPtr ptr = SWIGTYPE_p_unsigned___int16.getCPtr(instance).Handle;

        // Read the 16-bit unsigned integer value from the pointer
        return (ushort)Marshal.ReadInt16(ptr);
    }

    static void Main(string[] args)
    {
        HostSn = new CigiHostSession(1,32768,2,32768);
        COwn = new CigiEntityCtrlV3_3();

        HostSn.SetCigiVersion(3,1);
        HostSn.SetSynchronous(true);

        COwn.SetEntityID(CreateInstance(43));

        Console.WriteLine("Poopy : " + GetValue(COwn.GetEntityID()));

        Console.WriteLine("Version : " + HostSn.GetCigiVersion() + " : " + HostSn.GetCigiMinorVersion());

        CigiInSz = 0;

        ReadConfig();

        Console.WriteLine("Values : " + Port_H2IG + " " + Port_IG2H + " " + IGAddr);
        foreach (var dbInfo in dbList)
        {
            Console.WriteLine(dbInfo);
        }

        if (dbList.Count == 0)
        {
            Console.WriteLine("\n\nNo Database Information!\n\n");
            return;
        }

        InitCigiIf();

        while (true)
        {
            //await Task.Delay(1000);
            Thread.Sleep(1000);
            Console.WriteLine("Tick");
        }
    }

    static void ReadConfig()
    {
        XmlDocument doc = new XmlDocument();
        doc.Load("MiniHost.def");
        XmlNode bnode = doc.SelectSingleNode("MiniHostInitialization");

        // Default values
        Port_H2IG = 8000;
        Port_IG2H = 8001;
        IGAddr = "127.0.0.1";

        if (bnode != null)
        {
            XmlNode configNode = bnode.SelectSingleNode("Config");
            if (configNode != null)
            {
                IGAddr = configNode["IG_Addr"]?.InnerText ?? IGAddr;
                Port_H2IG = int.Parse(configNode["Port_To_IG"]?.InnerText ?? "8000");
                Port_IG2H = int.Parse(configNode["Port_From_IG"]?.InnerText ?? "8001");
            }

            foreach (XmlNode dbNode in bnode.SelectNodes("DBase"))
            {
                DbInfo dbInfo = new DbInfo
                {
                    Id = int.Parse(dbNode["ID"]?.InnerText ?? "0"),
                    Lat = double.Parse(dbNode["Lat"]?.InnerText ?? "0"),
                    Lon = double.Parse(dbNode["Lon"]?.InnerText ?? "0"),
                    Alt = double.Parse(dbNode["Alt"]?.InnerText ?? "0")
                };

                dbList.Add(dbInfo);
            }
        }
    }

    static void InitCigiIf()
    {
        Console.WriteLine("Initializing interface to CIGI...");

        //TcpClient client = new TcpClient();
        //await client.ConnectAsync("127.0.0.1", 5000);
        //Console.WriteLine("Connected to server.");

        Network network = new Network();
        bool netstatus = network.OpenSocket(IGAddr, Port_H2IG, Port_IG2H);

        // If OpenSocket fails, the program will exit due to the implementation of OpenSocket
        // So if the program continues past this point, the socket was successfully opened.

        Console.WriteLine("Interface Successful...");
    }
}
