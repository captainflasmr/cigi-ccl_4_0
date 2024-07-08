//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiBaseSignalProcessing : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal CigiBaseSignalProcessing(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiBaseSignalProcessing obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiBaseSignalProcessing obj) {
    if (obj != null) {
      if (!obj.swigCMemOwn)
        throw new global::System.ApplicationException("Cannot release ownership as memory is not owned");
      global::System.Runtime.InteropServices.HandleRef ptr = obj.swigCPtr;
      obj.swigCMemOwn = false;
      obj.Dispose();
      return ptr;
    } else {
      return new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
    }
  }

  ~CigiBaseSignalProcessing() {
    Dispose(false);
  }

  public void Dispose() {
    Dispose(true);
    global::System.GC.SuppressFinalize(this);
  }

  protected virtual void Dispose(bool disposing) {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          example_modulePINVOKE.delete_CigiBaseSignalProcessing(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public CigiBaseSignalProcessing() : this(example_modulePINVOKE.new_CigiBaseSignalProcessing(), true) {
  }

  public virtual void OnIGCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnIGCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnArtPartCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnArtPartCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnAtmosCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnAtmosCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnCelestialCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnCelestialCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnCollDetSegDef(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnCollDetSegDef(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnCollDetVolDef(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnCollDetVolDef(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnCompCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnCompCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnConfClampEntityCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnConfClampEntityCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnEarthModelDef(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnEarthModelDef(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnEntityCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnEntityCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnEnvCondReq(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnEnvCondReq(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnEnvCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnEnvCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnEnvRgnCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnEnvRgnCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnHatReq(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnHatReq(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnHatHotReq(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnHatHotReq(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnHatHotXReq(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnHatHotXReq(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnHotReq(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnHotReq(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnLosSegReq(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnLosSegReq(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnLosVectReq(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnLosVectReq(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnMaritimeSurfaceCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnMaritimeSurfaceCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnMotionTrackCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnMotionTrackCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnPostionReq(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnPostionReq(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnRateCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnRateCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnSensorCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnSensorCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnShortArtPartCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnShortArtPartCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnShortCompCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnShortCompCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnShortSymbolCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnShortSymbolCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnSpecEffDef(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnSpecEffDef(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnSymbolCircleDef(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnSymbolCircleDef(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnSymbolClone(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnSymbolClone(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnSymbolCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnSymbolCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnSymbolLineDef(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnSymbolLineDef(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnSymbolTextDef(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnSymbolTextDef(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnSymbolSurfaceDef(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnSymbolSurfaceDef(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnTerrestrialSurfaceCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnTerrestrialSurfaceCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnTrajectory(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnTrajectory(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnViewCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnViewCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnViewDef(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnViewDef(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnWaveCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnWaveCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnWeatherCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnWeatherCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnVelocityCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnVelocityCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnAccelerationCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnAccelerationCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnSymbolPolygonDef(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnSymbolPolygonDef(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnSymbolTexturedCircleDef(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnSymbolTexturedCircleDef(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnSymbolTexturedPolygonDef(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnSymbolTexturedPolygonDef(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnEntityPositionCtrl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnEntityPositionCtrl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnAnimationControl(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnAnimationControl(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnSOF(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnSOF(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnAerosolResp(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnAerosolResp(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnAnimationStop(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnAnimationStop(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnCollDetSegResp(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnCollDetSegResp(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnCollDetVolResp(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnCollDetVolResp(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnEventNotification(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnEventNotification(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnHatResp(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnHatResp(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnHatHotResp(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnHatHotResp(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnHatHotXResp(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnHatHotXResp(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnHotResp(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnHotResp(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnIGMsg(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnIGMsg(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnLosResp(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnLosResp(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnLosXResp(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnLosXResp(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnMaritimeSurfaceResp(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnMaritimeSurfaceResp(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnPositionResp(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnPositionResp(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnSensorResp(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnSensorResp(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnSensorXResp(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnSensorXResp(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnTerrestrialSurfaceResp(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnTerrestrialSurfaceResp(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnWeatherCondResp(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnWeatherCondResp(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

  public virtual void OnUnrecognized(CigiBasePacket Packet) {
    example_modulePINVOKE.CigiBaseSignalProcessing_OnUnrecognized(swigCPtr, CigiBasePacket.getCPtr(Packet));
  }

}