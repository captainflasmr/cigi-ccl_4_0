using System;
using System.IO;
using System.Text;
using System.Threading;
using System.Net;
using System.Net.Sockets;
using System.Runtime.InteropServices;
using System.Collections;
using System.Collections.Generic;
using System.Xml;

// ------------------
// Class declaration
// ------------------

namespace MiniHostBuild
{
    public class MiniHostCIGI
    {
        static bool ftt = true;

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

        // int seconds = 0;
		  // static int minutes = 0;
        static double hours = 6.0;
        static int cigi_sensor = 0;
        static bool black_hot = true;

        class Network
        {
            private UdpClient udpreceiver;
            private UdpClient udpsender;
            private IPEndPoint remoteEP;

            public bool OpenSocket(string hostIpAddr, int portToHost, int localPort)
            {
                try
                {
                    remoteEP = new IPEndPoint(IPAddress.Parse(hostIpAddr), portToHost);

                    udpreceiver = new UdpClient(localPort);
                    udpreceiver.Client.ReceiveTimeout = 2000;

                    udpsender = new UdpClient();
                    udpsender.Connect(remoteEP);

                    Console.WriteLine($"Successfully opened socket for comm with CIGI IG server at {hostIpAddr}:{portToHost}:{localPort}");
                    return true;
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Could not open socket for comm with CIGI IG server.  Exception:{ex.Message}");
                    Environment.Exit(1);
                    return false;
                }
            }

            public int Receive(out byte[] buffer, int bufferSize)
            {
                // buffer = new byte[RECV_BUFFER_SIZE];
                // if (udpreceiver == null) return 0;
                buffer = udpreceiver.Receive(ref remoteEP);
                return buffer.Length;
            }

            public int Send(byte[] buffer, int bufferSize)
            {
                // if (udpsender == null) return 0;
                udpsender.Send(buffer, bufferSize);
                return bufferSize;
            }

            public void CloseSocket()
            {
                //stream?.Close();
                //client?.Close();
                udpsender.Close();
                udpreceiver.Close();
            }
            public void Dispose()
            {
                CloseSocket();
            }
        }

        static string HexStr;
        static readonly int RECV_BUFFER_SIZE = 32768;
        static byte[] CigiInBuf = new byte[RECV_BUFFER_SIZE];
        static byte[] CigiOutBuf = new byte[RECV_BUFFER_SIZE];
        // static char* CigiOutBuf;
        static int CigiInSz;
        static ushort CigiOutSz;
        static int Port_H2IG;
        static int Port_IG2H;
        static string IGAddr;
        static List<DbInfo> dbList = new List<DbInfo>();
        static CigiHostSession HostSn;
        static CigiViewDefV4 CSensor;
        static CigiCompCtrlV4 CSensorCtrlGain;
        static CigiCompCtrlV4 CSensorCtrlContrast;
        static CigiWeatherCtrlV4 CWeather;
        static CigiWeatherCtrlV4 CWeatherCloud;
        static CigiAtmosCtrlV4 CAtmos;
        static CigiCompCtrlV4 CCompSeaState;
        static CigiViewCtrlV4 CView;
        static CigiEntityPositionCtrlV4 COwn;
        static CigiEntityPositionCtrlV4 CVeh;
        static CigiEntityCtrlV4 COwnCtrl;
        static CigiEntityCtrlV4 CVehCtrl;
        static CigiCelestialCtrlV4 CEnv;
        static CigiSymbolSurfaceDefV4 CSymbolSurface;
        static CigiSymbolCircleDefV4 CSymbolCircle;
        static CigiBaseCircleSymbolData CSymbolCircleData;
        static CigiSymbolCtrlV4 CSymbolCtrl;
        static CigiSymbolPolygonDefV4 CSymbolPoly;
        static CigiBaseVertexSymbolData CSymbolPolyData;
        static CigiCompCtrlV4 CSymbolCompLineStyle;
        static CigiSymbolTextDefV4 CSymbolText;
        static CigiIGCtrlV4 CIGC;
        static CigiOutgoingMsg Omsg;
        static CigiIncomingMsg Imsg;
        static SWIGTYPE_p_int swigOutSize;
        static SWIGTYPE_p_unsigned___int8 swigInBuffer_p;
        static SWIGTYPE_p_unsigned___int8 swigOutBuffer_p;
        static SWIGTYPE_p_p_unsigned___int8 swigOutBuffer_p_p;

        static Network network = new Network();

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

        public static byte[] SWIGTYPEToByteArray_p_p(SWIGTYPE_p_p_unsigned___int8 swigType, int Length)
        {
            IntPtr ptr = SWIGTYPE_p_p_unsigned___int8.getCPtr(swigType).Handle;
            byte[] byteArray = new byte[Length];
            Marshal.Copy(ptr, byteArray, 0, Length);
            Marshal.FreeHGlobal(ptr);
            return byteArray;
        }

        public static byte[] SWIGTYPEToByteArray_p(SWIGTYPE_p_unsigned___int8 swigType, int Length)
        {
            IntPtr ptr = SWIGTYPE_p_unsigned___int8.getCPtr(swigType).Handle;
            byte[] byteArray = new byte[Length];
            Marshal.Copy(ptr, byteArray, 0, Length);
            Marshal.FreeHGlobal(ptr);
            return byteArray;
        }

        public static SWIGTYPE_p_int SetValue_int(ushort value)
        {
            GCHandle handle = GCHandle.Alloc(value, GCHandleType.Pinned);
            IntPtr ptr = handle.AddrOfPinnedObject();
            SWIGTYPE_p_int instance = new SWIGTYPE_p_int(ptr, true);
            handle.Free();
            return instance;
        }

        public static SWIGTYPE_p_unsigned___int8 SetValue_int8(ushort value)
        {
            GCHandle handle = GCHandle.Alloc(value, GCHandleType.Pinned);
            IntPtr ptr = handle.AddrOfPinnedObject();
            SWIGTYPE_p_unsigned___int8 instance = new SWIGTYPE_p_unsigned___int8(ptr, true);
            handle.Free();
            return instance;
        }

        public static SWIGTYPE_p_unsigned___int16 SetValue_int16(ushort value)
        {
            GCHandle handle = GCHandle.Alloc(value, GCHandleType.Pinned);
            IntPtr ptr = handle.AddrOfPinnedObject();
            SWIGTYPE_p_unsigned___int16 instance = new SWIGTYPE_p_unsigned___int16(ptr, true);
            handle.Free();
            return instance;
        }

        public static SWIGTYPE_p_std__string SetValue_string(string value)
        {
            Console.WriteLine("poop: 01");
            var nullTerm = $"{value}{Convert.ToChar(0x0).ToString()}";
            Console.WriteLine("poop: 02");
            byte[] strbuf = Encoding.UTF8.GetBytes(nullTerm);
            Console.WriteLine("poop: 03");
            IntPtr unmanagedArray = Marshal.AllocHGlobal(strbuf.Length);
            Console.WriteLine("poop: 04");
            Marshal.Copy(strbuf, 0, unmanagedArray, strbuf.Length);
            Console.WriteLine("poop: 05");
            SWIGTYPE_p_std__string instance = new SWIGTYPE_p_std__string(unmanagedArray, true);
            Console.WriteLine("poop: 06");
            return instance;
        }

        public static ushort GetValue(SWIGTYPE_p_int instance)
        {
            IntPtr ptr = SWIGTYPE_p_int.getCPtr(instance).Handle;
            return (ushort)Marshal.ReadInt16(ptr);
        }

        public static ushort GetValue(SWIGTYPE_p_unsigned___int16 instance)
        {
            IntPtr ptr = SWIGTYPE_p_unsigned___int16.getCPtr(instance).Handle;
            return (ushort)Marshal.ReadInt16(ptr);
        }

        public static string GetValue(SWIGTYPE_p_std__string instance)
        {
            IntPtr ptr = SWIGTYPE_p_std__string.getCPtr(instance).Handle;
            return (string)Marshal.PtrToStringAnsi(ptr);
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
                    Port_H2IG = int.Parse(configNode["Port_To_IG"]?.InnerText ?? "8003");
                    Port_IG2H = int.Parse(configNode["Port_From_IG"]?.InnerText ?? "8004");
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

        static void CigiSetSymbolCtrl (ushort id, ushort layer, double x, double y,
                                       ushort red=255, ushort green=255, ushort blue=255, ushort alpha=255,
                                       double scaleX=1.0, double scaleY=1.0, double graticule=100)
        {
            CSymbolCtrl.SetLayer(SetValue_int8(layer));
            CSymbolCtrl.SetSymbolID(SetValue_int16(id));
            CSymbolCtrl.SetUPosition((float)x);
            CSymbolCtrl.SetVPosition((float)y);
            CSymbolCtrl.SetColor(SetValue_int8((ushort)red),
                                 SetValue_int8((ushort)green),
                                 SetValue_int8((ushort)blue),
                                 SetValue_int8((ushort)(graticule * 2.5)));
            CSymbolCtrl.SetSymbolState(CigiBaseSymbolCtrl.SymbolStateGrp.Visible);
            CSymbolCtrl.SetScaleU((float)scaleX);
            CSymbolCtrl.SetScaleV((float)scaleY);
        }

        // fontId
        //
        // Proportional:
        // 1: Sans Serif
        // 2: Serif Bold
        // 3: Sans Serif Italic
        // 4: Sans Serif Bold Italic
        // 5: Serif
        // 6: Serif Bold
        // 7: Serif Italic
        // 8: Serif Bold Italic

        // Monospace:
        // 9: Sans Serif
        // 10: Serif Bold
        // 11: Sans Serif Italic
        // 12: Sans Serif Bold Italic
        // 13: Serif
        // 14: Serif Bold
        // 15: Serif Italic
        // 16: Serif Bold Italic
        static void CigiSetText (ushort id, ushort layer, string str, double x, double y,
                                 ushort red=255, ushort green=255, ushort blue=255, ushort alpha=255,
                                 ushort fontSize = 50, ushort fontId = 0, double graticule=100)
        {
            Console.WriteLine("poop: 101");
            CSymbolText.SetSymbolID(SetValue_int16(id));
            Console.WriteLine("poop: 102" + str);
            CSymbolText.SetText(SetValue_string(str));
            Console.WriteLine("poop: 103");
            CSymbolText.SetFontID(SetValue_int8(fontId));
            CSymbolText.SetFontSize((float)fontSize);

            CigiSetSymbolCtrl(id, layer, x, y, red, green, blue, alpha, 1.0, 1.0, graticule);

            Omsg.pack(CSymbolText);
            Omsg.pack(CSymbolCtrl);
        }

        static void CigiSetCircle (ushort id, ushort layer, double innerRadius, double radius, double x, double y,
                                   ushort red=255, ushort green=255, ushort blue=255, ushort alpha=255, double graticule=100)
        {
            CSymbolCircle.SetSymbolID(SetValue_int16(id));
            CSymbolCircle.SetDrawingStyle(CigiBaseSymbolCircleDef.DrawingStyleGrp.Fill);
            CSymbolCircleData = CSymbolCircle.GetCircle(0);
            CSymbolCircleData.SetCenterUPosition((float)0.0);
            CSymbolCircleData.SetCenterVPosition((float)0.0);
            CSymbolCircleData.SetRadius((float)radius);
            CSymbolCircleData.SetInnerRadius((float)innerRadius);
            CSymbolCircleData.SetStartAngle((float)0.0);
            CSymbolCircleData.SetEndAngle((float)0.0);

            CigiSetSymbolCtrl(id, layer, x, y, red, green, blue, alpha, 1.0, 1.0, graticule);

            Omsg.pack(CSymbolCircle);
            Omsg.pack(CSymbolCtrl);
        }

        static void CigiSetPoly (ushort id, ushort layer, ushort stipple, double stipplePatternLength,
                                 double lineWidth, double x, double y,
                                 ushort red=255, ushort green=255, ushort blue=255, ushort alpha=255,
                                 double scaleX=1.0, double scaleY=1.0, double graticule=100)
        {
            CSymbolPoly.SetSymbolID(SetValue_int16(id));
            CSymbolPoly.SetStipplePattern(SetValue_int16(stipple));
            CSymbolPoly.SetLineWidth((float)lineWidth);
            CSymbolPoly.SetStipplePatternLen((float)stipplePatternLength);

            CigiSetSymbolCtrl(id, layer, x, y, red, green, blue, alpha, scaleX, scaleY, graticule);

            Omsg.pack(CSymbolPoly);
            Omsg.pack(CSymbolCompLineStyle);
            Omsg.pack(CSymbolCtrl);
        }

        public MiniHostCIGI()
        {
            CigiInSz = 0;

            ReadConfig();

            if (dbList.Count == 0)
            {
                Console.WriteLine("\n\nNo Database Information!\n\n");
                return;
            }

            Console.WriteLine("Initialising interface to CIGI...");

            bool netstatus = network.OpenSocket(IGAddr, Port_H2IG, Port_IG2H);

            if (!netstatus)
            {
                Console.WriteLine("could not open socket for comm with CIGI IG server\n");
                Environment.Exit(1);
            }
            else
            {
                Console.WriteLine("successfully open socket for comm with CIGI IG server\n");
            }

            HostSn = new CigiHostSession(1, 32768, 2, 32768);
            Omsg = HostSn.GetOutgoingMsgMgr();
            Imsg = HostSn.GetIncomingMsgMgr();

            HostSn.SetCigiVersion(4, 0);
            HostSn.SetSynchronous(true);

            Imsg.SetReaderCigiVersion(4, 0);
            Imsg.UsingIteration(false);

            CIGC = new CigiIGCtrlV4();
            CIGC.SetIGMode(CigiBaseIGCtrl.IGModeGrp.Operate);

            // set Ownship control
            COwnCtrl = new CigiEntityCtrlV4();
            COwnCtrl.SetEntityID(SetValue_int16(0));
            COwnCtrl.SetEntityType(SetValue_int16(0));
            COwnCtrl.SetEntityState(CigiBaseEntityCtrl.EntityStateGrp.Active);

            // init the Ownship position
            COwn = new CigiEntityPositionCtrlV4();
            COwn.SetEntityID(SetValue_int16(0));

            // init a vehicle position
            CVeh = new CigiEntityPositionCtrlV4();
            CVehCtrl = new CigiEntityCtrlV4();

            CView = new CigiViewCtrlV4();
            CView.SetViewID(SetValue_int16(1));
            CView.SetEntityID(SetValue_int16(0));

            CEnv = new CigiCelestialCtrlV4();
            CEnv.SetEphemerisEn(false);

            CAtmos = new CigiAtmosCtrlV4();

            CSensor = new CigiViewDefV4();
            CWeather = new CigiWeatherCtrlV4();
            CWeatherCloud = new CigiWeatherCtrlV4();

            // Sensor Control gain
            CSensorCtrlGain = new CigiCompCtrlV4();
            // Component class to view
            CSensorCtrlGain.SetCompClassV4(CigiBaseCompCtrl.CompClassV4Grp.ViewV4);
             // Component to Sensor Parameters (11)
            CSensorCtrlGain.SetCompID(SetValue_int16((ushort)11));
            // View ID
            CSensorCtrlGain.SetInstanceID(SetValue_int16((ushort)1));

            // Sensor Control contrast
            CSensorCtrlContrast = new CigiCompCtrlV4();
            // Component class to view
            CSensorCtrlContrast.SetCompClassV4(CigiBaseCompCtrl.CompClassV4Grp.ViewV4);
             // Component to Sensor Parameters (11)
            CSensorCtrlContrast.SetCompID(SetValue_int16((ushort)11));
            // View ID
            CSensorCtrlContrast.SetInstanceID(SetValue_int16((ushort)1));

            //
            // draw overlays
            //
            //
            // symbol surface attached to the main viewport
            //
            CSymbolSurface = new CigiSymbolSurfaceDefV4();
            CSymbolSurface.SetSurfaceID(SetValue_int16(0));
            CSymbolSurface.SetViewID(SetValue_int16(1));
            CSymbolSurface.SetSurfaceState(CigiBaseSymbolSurfaceDef.StateGrp.Active);
            CSymbolSurface.SetAttached(CigiBaseSymbolSurfaceDef.AttachStateGrp.ViewAttached);
            CSymbolSurface.SetLeftEdgePosition((float)0.0);
            CSymbolSurface.SetRightEdgePosition((float)1.0);
            CSymbolSurface.SetTopEdgePosition((float)1.0);
            CSymbolSurface.SetBottomEdgePosition((float)0.0);
            CSymbolSurface.SetMinU((float)-960.0);
            CSymbolSurface.SetMaxU((float)960.0);
            CSymbolSurface.SetMinV((float)-540.0);
            CSymbolSurface.SetMaxV((float)540.0);

            // basic symbol control for symbol placement default values
            CSymbolCtrl = new CigiSymbolCtrlV4();
            CSymbolCtrl.SetSurfaceID(SetValue_int16(0));
            // CSymbolCtrl.SetSymbolState(CigiBaseSymbolCtrl.SymbolStateGrp.Visible);
            CSymbolCtrl.SetFlashDutyCycle(SetValue_int8((ushort)100));

            //
            // basic setup for a circle
            //
            CSymbolCircle = new CigiSymbolCircleDefV4();
            CSymbolCircle.AddCircle();

            //
            // basic setup for text
            //
            CSymbolText = new CigiSymbolTextDefV4();
            CSymbolText.SetAlignment(CigiBaseSymbolTextDef.AlignmentGrp.Center);
            CSymbolText.SetOrientation(CigiBaseSymbolTextDef.OrientationGrp.LeftToRight);

            //
            // lines
            //
            CSymbolPoly = new CigiSymbolPolygonDefV4();
            CSymbolPoly.SetPrimitive(CigiBaseSymbolLineDef.PrimitiveGrp.Lines);
            CSymbolPoly.AddVertex();
            CSymbolPolyData = CSymbolPoly.GetVertex(0);
            CSymbolPolyData.SetVertexU((float)0.0);
            CSymbolPolyData.SetVertexV((float)0.0);
            CSymbolPoly.AddVertex();
            CSymbolPolyData = CSymbolPoly.GetVertex(1);
            CSymbolPolyData.SetVertexU((float)200.0);
            CSymbolPolyData.SetVertexV((float)0.0);
            CSymbolPoly.AddVertex();
            CSymbolPolyData = CSymbolPoly.GetVertex(2);
            CSymbolPolyData.SetVertexU((float)0.0);
            CSymbolPolyData.SetVertexV((float)0.0);
            CSymbolPoly.AddVertex();
            CSymbolPolyData = CSymbolPoly.GetVertex(3);
            CSymbolPolyData.SetVertexU((float)200.0);
            CSymbolPolyData.SetVertexV((float)0.0);
            CSymbolCompLineStyle = new CigiCompCtrlV4();
            // (15)(SymbolV4) Symbol
            CSymbolCompLineStyle.SetCompClassV4(CigiBaseCompCtrl.CompClassV4Grp.SymbolV4);
            // (1) line style
            CSymbolCompLineStyle.SetCompID(SetValue_int16((ushort)1));
            // SymbolID
            CSymbolCompLineStyle.SetInstanceID(SetValue_int16((ushort)1));
            // Joint Style (1) - Miltered - Lines are joined by sharp, pointed corners
            CSymbolCompLineStyle.SetCompData(SetValue_int8(1), 0, CigiBaseCompCtrl.BytePos.MSB);

            CCompSeaState = new CigiCompCtrlV4();
            CCompSeaState.SetCompClassV4(CigiBaseCompCtrl.CompClassV4Grp.GlobalSeaSurfaceV4);
            Console.WriteLine("Interface Successful...");
        }

        public void ProcessCIGI()
        {
            if (CigiInSz > 0)
            {
                try
                {
                    swigInBuffer_p = ByteArrayToSWIGTYPE_p(CigiInBuf);
                    Imsg.ProcessIncomingMsg(swigInBuffer_p, CigiInSz);
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"getNetMessages - Exception: {ex.Message}");
                }
            }

            Omsg.BeginMsg();

            // Set Values From Simulation
            CEnv.SetDateVld(true);
            CEnv.SetMoonEn(true);
            CEnv.SetSunEn(true);

            try
				{
					 // CEnv.SetHour(SetValue_int8((ushort)hours));
                CEnv.SetHour(SetValue_int8(0));
                CEnv.SetMinute(SetValue_int8(1));
                CEnv.SetSeconds((float)20.0);
                // CEnv.SetDay(SetValue_int8(m_SimControl.m_PIGEnvDay.GetResultValue()));
                CEnv.SetDay(SetValue_int8(3));
                CEnv.SetMonth(SetValue_int8(4));
                CEnv.SetYear(SetValue_int16((ushort)2024));
                // CEnv.SetMonth(SetValue_int8(m_SimControl.m_PIGEnvMonth.GetResultValue()));
                Console.WriteLine("PLONG #1");
				}
				catch (Exception ex)
				{
					 Console.WriteLine($"getNetMessages - Exception: {ex.Message}");
				}

            // lets try the sea state
            CCompSeaState.SetCompState(SetValue_int8(3));

            // and some atmosphere
            CAtmos.SetVisibility((float)10000.0);
            CAtmos.SetWindDir((float)20.0);
            CAtmos.SetHorizWindSp((float)10.0);
            CAtmos.SetVertWindSp((float)5.0);

            // now the sensor view
            // first we need to map the sensor to something CIGI like
            cigi_sensor = 0;
            black_hot = true;

            CSensor.SetViewID(SetValue_int16(1));
            CSensor.SetViewType(SetValue_int8((ushort)cigi_sensor));
            CSensor.SetFOVLeftEn(true);
            CSensor.SetFOVLeft((float)-45.0);
            CSensor.SetFOVRightEn(true);
            CSensor.SetFOVRight((float)45.0);
            CSensor.SetFOVTopEn(true);
            CSensor.SetFOVTop((float)30.0);
            CSensor.SetFOVBottomEn(true);
            CSensor.SetFOVBottom((float)-30.0);

            // and sensor control
            // which sensor to configure (view type)
            CSensorCtrlGain.SetCompState(SetValue_int8((ushort)cigi_sensor));
            // the Gain will have to be mapped based on sensor type
            // Optical
            if (cigi_sensor == 0) {
                // Set to exposure
                CSensorCtrlGain.SetCompData(SetValue_int16(16), 0, CigiBaseCompCtrl.HalfWordPos.MSHW);
            }
            // LLTV
            if (cigi_sensor == 1) {
                // Set to gain
                CSensorCtrlGain.SetCompData(SetValue_int16(10), 0, CigiBaseCompCtrl.HalfWordPos.MSHW);
            }
            // TI
            if (cigi_sensor == 2) {
                // Set to black level
                CSensorCtrlGain.SetCompData(SetValue_int16(4), 0, CigiBaseCompCtrl.HalfWordPos.MSHW);
            }
            // Now set the Gain
            CSensorCtrlGain.SetCompData((float)10.0, 1);

            // which sensor to configure (view type)
            CSensorCtrlContrast.SetCompState(SetValue_int8((ushort)cigi_sensor));
            // the Contrast will have to be mapped based on sensor type
            // Optical
            if (cigi_sensor == 0) {
                // Set to contrast
                CSensorCtrlContrast.SetCompData(SetValue_int16(17), 0, CigiBaseCompCtrl.HalfWordPos.MSHW);
            }
            // LLTV
            if (cigi_sensor == 1) {
                // Set to contrast
                CSensorCtrlContrast.SetCompData(SetValue_int16(43), 0, CigiBaseCompCtrl.HalfWordPos.MSHW);
            }
            // TI
            if (cigi_sensor == 2) {
                // Set to black level offset
                CSensorCtrlContrast.SetCompData(SetValue_int16(10), 0, CigiBaseCompCtrl.HalfWordPos.MSHW);
            }
            // Now set the Contrast
            CSensorCtrlContrast.SetCompData(SetValue_int8((ushort)20), 0, CigiBaseCompCtrl.BytePos.MSB);

            // now the view, which is basically moving the periscope around
            CView.SetYawEn(true);
            CView.SetYaw((float)90.0);
            CView.SetPitchEn(true);
            CView.SetPitch((float)0.1);

            Console.WriteLine("PLONG #2");

            // and some weather

            // Defining Clear
            CWeatherCloud.SetLayerID(SetValue_int8((ushort)CigiWeatherCtrlV4.LayerIDGrp.CloudLayer1));
            CWeatherCloud.SetWeatherEn(true);
            CWeather.SetWeatherEn(false);
            CWeatherCloud.SetScope(CigiBaseWeatherCtrl.ScopeGrp.Global);
            CWeatherCloud.SetCloudType(CigiBaseWeatherCtrl.CloudTypeGrp.Cumulus);
            CWeatherCloud.SetSeverity(SetValue_int8(5));
            CWeatherCloud.SetBaseElev((float)1000.0);
            CWeatherCloud.SetVisibilityRng((float)10000.0);
            CWeatherCloud.SetThickness((float)0.0);
            CWeatherCloud.SetCoverage((float)0.0);

            // Some symbol things jsut for fun!
            // CSymbolCtrl.SetAlpha(SetValue_int8(m_SimControl.m_PIGPeriGratIntensity.GetResultValue()));

            Console.WriteLine("PLONG #3");

            // load the IG Control
            Omsg.pack(CIGC);

            Console.WriteLine("poop: 4");

            /* Update ownship position */
            // double olat = COwn.GetLat();
            COwn.SetLat(1.0);

            Console.WriteLine("poop: 5");
            COwn.SetLon(2.0);
            COwn.SetPitch((float)0.2);
            COwn.SetRoll((float)0.3);
            COwn.SetAlt(0.5);
            COwn.SetYaw((float)100.0);

            Console.WriteLine("poop: 6");
            double olon = CVeh.GetLon();
            // CVeh.SetLon(olon + 0.000001);

            Omsg.pack(COwn);
            Omsg.pack(COwnCtrl);

            Console.WriteLine("poop: 7");
            if (ftt) {
                // ftt lets destroy everything we can!
                // first all vehicles - of course the number currently is arbitrary
                for (int tnum=1; tnum <= 10; tnum++) {
                    CVehCtrl.SetEntityID(SetValue_int16((ushort)tnum));
                    CVehCtrl.SetEntityState(CigiBaseEntityCtrl.EntityStateGrp.Remove);
                    Omsg.pack(CVeh);
                    Omsg.pack(CVehCtrl);
                }
                ftt = false;
            }
            else {
                CVehCtrl.SetEntityID(SetValue_int16((ushort)1));
                CVehCtrl.SetEntityType(SetValue_int16((ushort)42));
                CVehCtrl.SetSmoothingEn(true);

                CVeh.SetEntityID(SetValue_int16((ushort)1));
                CVeh.SetLat(0.001);
                CVeh.SetLon(0.002);
                CVeh.SetYaw((float)45.0);
                CVeh.SetAlt((double)2.0);
                CVeh.SetPitch((float)3.0);
                CVeh.SetRoll((float)0.3);

                CVehCtrl.SetEntityState(CigiBaseEntityCtrl.EntityStateGrp.Active);

                Omsg.pack(CVeh);
                Omsg.pack(CVehCtrl);
            }

            Console.WriteLine("poop: 8");
            Omsg.pack(CView);
            Omsg.pack(CSensor);
            Omsg.pack(CSensorCtrlGain);
            Console.WriteLine("poop: 9");
            Omsg.pack(CSensorCtrlContrast);
            Omsg.pack(CEnv);
            Omsg.pack(CCompSeaState);
            Omsg.pack(CAtmos);
            Console.WriteLine("poop: 10");
            Omsg.pack(CWeather);
            Omsg.pack(CWeatherCloud);

            // now the overlays!
            Omsg.pack(CSymbolSurface);

            // some lines - polygons - simulating graticule split
            CSymbolPolyData = CSymbolPoly.GetVertex(2);
            CSymbolPolyData.SetVertexU((float)0.0);
            CSymbolPolyData.SetVertexV((float)200.0);
            Console.WriteLine("poop: 12");
            CSymbolPolyData = CSymbolPoly.GetVertex(3);
            CSymbolPolyData.SetVertexU((float)200.0);
            CSymbolPolyData.SetVertexV((float)400.0);

            Console.WriteLine("poop: 13");
            CigiSetPoly(1, 0, 43690, 50.0, 0.3, -960.0, 0.0,
                        255, 255, 255, 255, 10.0, 10.0, 90.0);

            Console.WriteLine("poop: 14");
            // CigiSetText(7, 4, string.Format("Stad Elevation {0:F2}", 23.0), 750.0, 450.0,
                        // 255, 255, 255, 255, 30, 9, 90.0);

            Console.WriteLine("poop: 15");
            // Periscope Viewport
            CigiSetCircle(5, 1, 600.0, 2000.0, 0.0, 0.0,
                          55, 55, 55, 255, 90.0);

            // Some other circles, for fun!
            CigiSetCircle(6, 2, 60.0, 150.0, 750.0, -360.0,
                          75, 55, 55, 30, 90.0);
            // CigiSetText(8, 2, "Periscope", 750.0, -270.0,
                        // 255, 255, 255, 255, 20, 9, 90.0);

            // CigiSetText(4, 3, string.Format("Elevation {0:F2}", 90.0), 750.0, -330.0,
                        // 200, 0, 0, 155, 30, 9, 90.0);

            // CigiSetText(3, 3, string.Format("Bearing {0:F2}", 31.0), 750.0, -380.0,
                        // 0, 200, 0, 155, 40, 0, 90.0);

            Console.WriteLine("PLONG #4");
            try
            {
                try
                {
                    swigOutSize = SetValue_int(0);
                    swigOutBuffer_p_p = ByteArrayToSWIGTYPE_p_p(CigiOutBuf);
                    Omsg.PackageMsg(swigOutBuffer_p_p, swigOutSize);
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"getNetMessages - Exception: {ex.Message}");
                }

                Console.WriteLine("Packed : " + GetValue(Omsg.GetBufferString()));

                CigiOutSz = GetValue(swigOutSize);
                Console.WriteLine("PackageMsgSz : " + CigiOutSz);

                // Receive message
                try
                {
                    CigiInSz = network.Receive(out CigiInBuf, RECV_BUFFER_SIZE);
                }
                catch (SocketException ex) when (ex.SocketErrorCode == SocketError.TimedOut)
                                           {
                                               Console.WriteLine("No data received, timed out!!");
                                           }
                catch (Exception e)
                {
                    Console.WriteLine($"A receive error occurred!! : {e.Message}");
                }

                // update out with in message
                if (swigOutBuffer_p_p != null)
                {
                    swigOutBuffer_p = ByteArrayToSWIGTYPE_p(CigiOutBuf);
                    swigInBuffer_p = ByteArrayToSWIGTYPE_p(CigiInBuf);
                    if (CigiInSz > 0)
                    {
                        HexStr = BitConverter.ToString(CigiInBuf).Replace("-", " ");
                        // Console.WriteLine("Received size : " + CigiInSz + " : " + HexStr);
                        Omsg.UpdateIGCtrl(swigOutBuffer_p, swigInBuffer_p);
                    }
                    else
                    {
                        Omsg.UpdateIGCtrl(swigOutBuffer_p, null);
                    }
                }
                Console.WriteLine("PLONG #5");
                CigiOutBuf = SWIGTYPEToByteArray_p_p(swigOutBuffer_p_p, CigiOutSz);
                HexStr = BitConverter.ToString(CigiOutBuf).Replace("-", " ");
                // Console.WriteLine("Send size : " + CigiOutSz + " : " + HexStr);
                network.Send(CigiOutBuf, CigiOutSz);
                Console.WriteLine("PLONG #6");

                Console.WriteLine("Tick");
                Omsg.FreeMsg();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"getNetMessages - Exception: {ex.Message}");
            }
        }
    }
}
