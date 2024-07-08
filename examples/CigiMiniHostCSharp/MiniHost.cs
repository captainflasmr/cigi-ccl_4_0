using System;
using System.Collections.Generic;
using System.Net;
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
    private IPEndPoint remoteEP;
    private UdpClient udpReceiver;
    private UdpClient udpSender;

    public bool OpenSocket(string hostIpAddr, int portToHost, int localPort)
    {
        try
        {
            remoteEP = new IPEndPoint(IPAddress.Any, 8000);
            udpReceiver = new UdpClient(8001);
            udpSender = new UdpClient("127.0.0.1", 8000);
            //udpReceiver.Connect(hostIpAddr, 8000);

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
        if (udpReceiver == null) return 0;
        buffer = udpReceiver.Receive(ref remoteEP);
        return buffer.Length;
    }

    public int Send(byte[] buffer, int bufferSize)
    {
        if (udpSender == null) return 0;
        udpSender.Send(buffer, bufferSize);
        return bufferSize;
    }

    public void CloseSocket()
    {
        udpReceiver.Close();
        udpSender.Close();
    }
}

class Program
{
    static readonly int RECV_BUFFER_SIZE = 32768;
    static byte[] CigiInBuf = new byte[RECV_BUFFER_SIZE];
    static byte[] CigiOutBuf = new byte[RECV_BUFFER_SIZE];
    static int Port_H2IG;
    static int Port_IG2H;
    static string IGAddr;
    static List<DbInfo> dbList = new List<DbInfo>();
    static CigiHostSession HostSn;
    static CigiOutgoingMsg Omsg;
    static CigiIncomingMsg Imsg;
    static CigiEntityCtrlV3_3 COwn;
    static CigiIGCtrlV3_2 CIGC;
    static Network network = new Network();
    static SWIGTYPE_p_p_unsigned___int8 swigBufferOut_p_p;
    static SWIGTYPE_p_unsigned___int8 swigBufferOut_p;
    static SWIGTYPE_p_unsigned___int8 swigBuffer_p;
    static SWIGTYPE_p_int swigOutSize = CreateInstance_int(0);
    static int CigiInSz;
    static ushort CigiOutSz;

    public static SWIGTYPE_p_p_unsigned___int8 ByteArrayToSWIGTYPE_p_p(byte[] byteArray)
    {
        IntPtr unmanagedArray = Marshal.AllocHGlobal(byteArray.Length);
        Marshal.Copy(byteArray, 0, unmanagedArray, byteArray.Length);
        return new SWIGTYPE_p_p_unsigned___int8(unmanagedArray, true);
    }

    public static SWIGTYPE_p_unsigned___int8 ByteArrayToSWIGTYPE_p(byte[] byteArray)
    {
        IntPtr unmanagedArray = Marshal.AllocHGlobal(byteArray.Length);
        Marshal.Copy(byteArray, 0, unmanagedArray, byteArray.Length);
        return new SWIGTYPE_p_unsigned___int8(unmanagedArray, true);
    }

    public static byte[] SWIGTYPEToByteArray_p_p(SWIGTYPE_p_p_unsigned___int8 swigType, int length)
    {
        IntPtr ptr = SWIGTYPE_p_p_unsigned___int8.getCPtr(swigType).Handle;
        byte[] byteArray = new byte[length];
        Marshal.Copy(ptr, byteArray, 0, length);
        Marshal.FreeHGlobal(ptr); // Free the unmanaged memory
        return byteArray;
    }

    public static byte[] SWIGTYPEToByteArray_p(SWIGTYPE_p_unsigned___int8 swigType, int length)
    {
        IntPtr ptr = SWIGTYPE_p_unsigned___int8.getCPtr(swigType).Handle;
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

    public static SWIGTYPE_p_unsigned___int16 SetValue(ushort value)
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

        Omsg.BeginMsg();

        while (true)
        {
            if (CigiInSz > 0)
            {
                try
                {
                    swigBuffer_p = ByteArrayToSWIGTYPE_p(CigiInBuf);
                    SWIGTYPE_p_int swigOutSize = CreateInstance_int(0);

                    Imsg.ProcessIncomingMsg(swigBuffer_p, CigiInSz);
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"getNetMessages - Exception: {ex.Message}");
                }
            }

            Omsg.pack(CIGC);

            // double olat = COwn.GetLat();
            // COwn.SetLat(olat + 0.0000137);
            Omsg.pack(COwn);

            try
            {
                try
                {
                    // Convert byte array to SWIG type
                    swigBufferOut_p_p = ByteArrayToSWIGTYPE_p_p(CigiOutBuf);
                    swigBufferOut_p = ByteArrayToSWIGTYPE_p(CigiOutBuf);
                    swigOutSize = CreateInstance_int(0);
                    Omsg.PackageMsg(swigBufferOut_p_p, swigOutSize);
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"getNetMessages - Exception: {ex.Message}");
                }

                CigiOutSz = GetValue_int(swigOutSize);
                Console.WriteLine("PackageMsgSz : " + CigiOutSz);

                CigiInSz = network.Receive(CigiInBuf, RECV_BUFFER_SIZE);

                try
                {
                    swigBuffer_p = ByteArrayToSWIGTYPE_p(CigiInBuf);
                    swigOutSize = CreateInstance_int(0);

                    if (CigiInSz > 0)
                        Omsg.UpdateIGCtrl(swigBufferOut_p, swigBuffer_p);
                    else
                        Omsg.UpdateIGCtrl(swigBufferOut_p, null);
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"UpdateIGCtrl - Exception: {ex.Message}");
                }


                // Convert back to byte array
                CigiOutBuf = SWIGTYPEToByteArray_p(swigBufferOut_p, CigiOutSz);
                string hexString = BitConverter.ToString(CigiOutBuf).Replace("-", " ");
                Console.WriteLine("Out : " + hexString);


                network.Send(CigiOutBuf, CigiOutSz);
                Console.WriteLine("Tick");
                Omsg.FreeMsg();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"getNetMessages - Exception: {ex.Message}");
            }

            Thread.Sleep(1000);
        }

        // network.CloseSocket();
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
        Omsg = HostSn.GetOutgoingMsgMgr();
        Imsg = HostSn.GetIncomingMsgMgr();

        HostSn.SetCigiVersion(3, 3);
        HostSn.SetSynchronous(true);

        Imsg.SetReaderCigiVersion(3, 3);
        Imsg.UsingIteration(false);

        COwn = new CigiEntityCtrlV3_3();
        COwn.SetEntityID(SetValue(43));
        COwn.SetEntityType(SetValue(0));
        COwn.SetEntityState(CigiBaseEntityCtrl.EntityStateGrp.Active);

        // initialize the IG Control
        CIGC = new CigiIGCtrlV3_2();
        CIGC.SetIGMode(CigiBaseIGCtrl.IGModeGrp.Operate);

        Console.WriteLine("Interface Successful...");
    }
}
