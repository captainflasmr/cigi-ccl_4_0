using System;
using System.Collections.Generic;
using System.Net.Sockets;
using System.Xml;
using System.Threading;
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
    private TcpClient client;
    private NetworkStream stream;

    public bool OpenSocket(string hostIpAddr, int portToHost, int localPort)
    {
        try
        {
            client = new TcpClient();
            client.Connect(hostIpAddr, 8000);
            stream = client.GetStream();
            Console.WriteLine($"Successfully opened socket for comm with CIGI IG server at {hostIpAddr}:{portToHost}");
            return true;
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Could not open socket for comm with CIGI IG server. Exception: {ex.Message}");
            Environment.Exit(1);
            return false;
        }
    }

    public int Receive(byte[] buffer, int bufferSize)
    {
        if (stream == null) return 0;
        return stream.Read(buffer, 0, bufferSize);
    }

    public int Send(byte[] buffer, int bufferSize)
    {
        if (stream == null) return 0;
        stream.Write(buffer, 0, bufferSize);
        return bufferSize;
    }

    public void CloseSocket()
    {
        stream?.Close();
        client?.Close();
    }
}

class Program
{
    static readonly int RECV_BUFFER_SIZE = 32768;
    static byte[] CInBuf = new byte[RECV_BUFFER_SIZE];
    static byte[] pCigiOutBuf = new byte[RECV_BUFFER_SIZE];
    static int CigiInSz;
    static ushort CigiOutSz;
    static int Port_H2IG;
    static int Port_IG2H;
    static string IGAddr;
    static List<DbInfo> dbList = new List<DbInfo>();
    static CigiHostSession HostSn;
    static CigiOutgoingMsg OmsgPtr;
    static CigiIncomingMsg ImsgPtr;
    static CigiEntityCtrlV3_3 COwn;
    static CigiIGCtrlV3_2 CIGC;
    static Network network = new Network();

public static SWIGTYPE_p_p_unsigned___int8 ByteArrayToSWIGTYPE(byte[] byteArray)
{
    IntPtr unmanagedArray = Marshal.AllocHGlobal(byteArray.Length);
    Marshal.Copy(byteArray, 0, unmanagedArray, byteArray.Length);
    return new SWIGTYPE_p_p_unsigned___int8(unmanagedArray, true);
}

public static byte[] SWIGTYPEToByteArray(SWIGTYPE_p_p_unsigned___int8 swigType, int length)
{
    IntPtr ptr = SWIGTYPE_p_p_unsigned___int8.getCPtr(swigType).Handle;
    byte[] byteArray = new byte[length];
    Marshal.Copy(ptr, byteArray, 0, length);
    Marshal.FreeHGlobal(ptr); // Free the unmanaged memory
    return byteArray;
}

public static SWIGTYPE_p_int CreateInstance_int(ushort value)
    {
        GCHandle handle = GCHandle.Alloc(value, GCHandleType.Pinned);
        IntPtr ptr = handle.AddrOfPinnedObject();
        SWIGTYPE_p_int instance = new SWIGTYPE_p_int(ptr, true);
        handle.Free();
        return instance;
    }

    public static SWIGTYPE_p_unsigned___int16 CreateInstance(ushort value)
    {
        GCHandle handle = GCHandle.Alloc(value, GCHandleType.Pinned);
        IntPtr ptr = handle.AddrOfPinnedObject();
        SWIGTYPE_p_unsigned___int16 instance = new SWIGTYPE_p_unsigned___int16(ptr, true);
        handle.Free();
        return instance;
    }

public static ushort GetValue_int(SWIGTYPE_p_int instance)
    {
        IntPtr ptr = SWIGTYPE_p_int.getCPtr(instance).Handle;
        return (ushort)Marshal.ReadInt16(ptr);
    }

    public static ushort GetValue(SWIGTYPE_p_unsigned___int16 instance)
    {
        IntPtr ptr = SWIGTYPE_p_unsigned___int16.getCPtr(instance).Handle;
        return (ushort)Marshal.ReadInt16(ptr);
    }

    static void Main(string[] args)
    {
        CigiInSz = 0;
        ReadConfig();

        if (dbList.Count == 0)
        {
            Console.WriteLine("\n\nNo Database Information!\n\n");
            return;
        }

        InitCigiIf();

        // var idbl = dbList[0];
        // COwn.SetLat(idbl.Lat);
        // COwn.SetLon(idbl.Lon);
        // COwn.SetAlt(idbl.Alt);
        // COwn.SetYaw(0.0);
        // COwn.SetPitch(0.0);
        // COwn.SetRoll(0.0);

        OmsgPtr.BeginMsg();

        while (true)
        {
            // if (CigiInSz > 0)
            // {
            //     try
            //     {
            //         ImsgPtr.ProcessIncomingMsg(CInBuf, CigiInSz);
            //     }
            //     catch (Exception ex)
            //     {
            //         Console.WriteLine($"getNetMessages - Exception: {ex.Message}");
            //     }
            // }

            OmsgPtr.pack(CIGC);

            // double olat = COwn.GetLat();
            // COwn.SetLat(olat + 0.0000137);
            OmsgPtr.pack(COwn);

            try
            {
                // Convert byte array to SWIG type
                SWIGTYPE_p_p_unsigned___int8 swigPBuffer = ByteArrayToSWIGTYPE(pCigiOutBuf);
                SWIGTYPE_p_int swigOutSize = CreateInstance_int(0);

                OmsgPtr.PackageMsg(swigPBuffer, swigOutSize);
                CigiOutSz = GetValue_int(swigOutSize);
                Console.WriteLine("PackageMsgSz : " + CigiOutSz);
                // CigiInSz = network.Receive(CInBuf, RECV_BUFFER_SIZE);

                // if (CigiInSz > 0)
                // OmsgPtr.UpdateIGCtrl(pCigiOutBuf, CInBuf);
                // else
                // OmsgPtr.UpdateIGCtrl(pCigiOutBuf, null);

                // Convert back to byte array
                pCigiOutBuf = SWIGTYPEToByteArray(swigPBuffer, CigiOutSz);

                network.Send(pCigiOutBuf, CigiOutSz);
                Console.WriteLine("Tick");
                OmsgPtr.FreeMsg();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"getNetMessages - Exception: {ex.Message}");
            }

            Thread.Sleep(1000);
        }

        network.CloseSocket();
    }

    static void ReadConfig()
    {
        XmlDocument doc = new XmlDocument();
        doc.Load("MiniHost.def");
        XmlNode bnode = doc.SelectSingleNode("MiniHostInitialization");

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

        bool netstatus = network.OpenSocket(IGAddr, Port_H2IG, Port_IG2H);

        if (!netstatus)
        {
            Console.WriteLine("Failed to open socket.");
            Environment.Exit(1);
        }

        HostSn = new CigiHostSession(1, 32768, 2, 32768);
        CigiOutgoingMsg Omsg = HostSn.GetOutgoingMsgMgr();
        CigiIncomingMsg Imsg = HostSn.GetIncomingMsgMgr();
        OmsgPtr = Omsg;
        ImsgPtr = Imsg;

        HostSn.SetCigiVersion(3, 3);
        HostSn.SetSynchronous(true);

        Imsg.SetReaderCigiVersion(3, 3);
        Imsg.UsingIteration(false);

        COwn = new CigiEntityCtrlV3_3();
        COwn.SetEntityID(CreateInstance(43));
        // COwn.SetEntityType(0);
        // COwn.SetEntityState(CigiBaseEntityCtrl.Active);

        CIGC = new CigiIGCtrlV3_2();

        Console.WriteLine("Interface Successful...");
    }
}
