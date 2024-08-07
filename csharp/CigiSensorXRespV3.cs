//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiSensorXRespV3 : CigiBaseSensorResp {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiSensorXRespV3(global::System.IntPtr cPtr, bool cMemoryOwn) : base(ccl_dllDPINVOKE.CigiSensorXRespV3_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiSensorXRespV3 obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiSensorXRespV3 obj) {
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

  protected override void Dispose(bool disposing) {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          ccl_dllDPINVOKE.delete_CigiSensorXRespV3(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public CigiSensorXRespV3() : this(ccl_dllDPINVOKE.new_CigiSensorXRespV3(), true) {
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = ccl_dllDPINVOKE.CigiSensorXRespV3_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = ccl_dllDPINVOKE.CigiSensorXRespV3_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int GetCnvt(CigiVersionID CnvtVersion, SWIGTYPE_p_CigiCnvtInfoType__Type CnvtInfo) {
    int ret = ccl_dllDPINVOKE.CigiSensorXRespV3_GetCnvt(swigCPtr, CigiVersionID.getCPtr(CnvtVersion), SWIGTYPE_p_CigiCnvtInfoType__Type.getCPtr(CnvtInfo));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetViewID(SWIGTYPE_p_unsigned___int16 ViewIDIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiSensorXRespV3_SetViewID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(ViewIDIn), bndchk);
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetViewID(SWIGTYPE_p_unsigned___int16 ViewIDIn) {
    int ret = ccl_dllDPINVOKE.CigiSensorXRespV3_SetViewID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(ViewIDIn));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetViewID() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(ccl_dllDPINVOKE.CigiSensorXRespV3_GetViewID(swigCPtr), true);
    return ret;
  }

  public int SetEntityTgt(bool EntityTgtIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiSensorXRespV3_SetEntityTgt__SWIG_0(swigCPtr, EntityTgtIn, bndchk);
    return ret;
  }

  public int SetEntityTgt(bool EntityTgtIn) {
    int ret = ccl_dllDPINVOKE.CigiSensorXRespV3_SetEntityTgt__SWIG_1(swigCPtr, EntityTgtIn);
    return ret;
  }

  public bool GetEntityTgt() {
    bool ret = ccl_dllDPINVOKE.CigiSensorXRespV3_GetEntityTgt(swigCPtr);
    return ret;
  }

  public int SetEntityID(SWIGTYPE_p_unsigned___int16 EntityIDIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiSensorXRespV3_SetEntityID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(EntityIDIn), bndchk);
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetEntityID(SWIGTYPE_p_unsigned___int16 EntityIDIn) {
    int ret = ccl_dllDPINVOKE.CigiSensorXRespV3_SetEntityID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(EntityIDIn));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetEntityID() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(ccl_dllDPINVOKE.CigiSensorXRespV3_GetEntityID(swigCPtr), true);
    return ret;
  }

  public int SetFrameCntr(SWIGTYPE_p_unsigned___int32 FrameCntrIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiSensorXRespV3_SetFrameCntr__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int32.getCPtr(FrameCntrIn), bndchk);
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetFrameCntr(SWIGTYPE_p_unsigned___int32 FrameCntrIn) {
    int ret = ccl_dllDPINVOKE.CigiSensorXRespV3_SetFrameCntr__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int32.getCPtr(FrameCntrIn));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int32 GetFrameCntr() {
    SWIGTYPE_p_unsigned___int32 ret = new SWIGTYPE_p_unsigned___int32(ccl_dllDPINVOKE.CigiSensorXRespV3_GetFrameCntr(swigCPtr), true);
    return ret;
  }

  public int SetTrackPntLat(double TrackPntLatIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiSensorXRespV3_SetTrackPntLat__SWIG_0(swigCPtr, TrackPntLatIn, bndchk);
    return ret;
  }

  public int SetTrackPntLat(double TrackPntLatIn) {
    int ret = ccl_dllDPINVOKE.CigiSensorXRespV3_SetTrackPntLat__SWIG_1(swigCPtr, TrackPntLatIn);
    return ret;
  }

  public double GetTrackPntLat() {
    double ret = ccl_dllDPINVOKE.CigiSensorXRespV3_GetTrackPntLat(swigCPtr);
    return ret;
  }

  public int SetTrackPntLon(double TrackPntLonIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiSensorXRespV3_SetTrackPntLon__SWIG_0(swigCPtr, TrackPntLonIn, bndchk);
    return ret;
  }

  public int SetTrackPntLon(double TrackPntLonIn) {
    int ret = ccl_dllDPINVOKE.CigiSensorXRespV3_SetTrackPntLon__SWIG_1(swigCPtr, TrackPntLonIn);
    return ret;
  }

  public double GetTrackPntLon() {
    double ret = ccl_dllDPINVOKE.CigiSensorXRespV3_GetTrackPntLon(swigCPtr);
    return ret;
  }

  public int SetTrackPntAlt(double TrackPntAltIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiSensorXRespV3_SetTrackPntAlt__SWIG_0(swigCPtr, TrackPntAltIn, bndchk);
    return ret;
  }

  public int SetTrackPntAlt(double TrackPntAltIn) {
    int ret = ccl_dllDPINVOKE.CigiSensorXRespV3_SetTrackPntAlt__SWIG_1(swigCPtr, TrackPntAltIn);
    return ret;
  }

  public double GetTrackPntAlt() {
    double ret = ccl_dllDPINVOKE.CigiSensorXRespV3_GetTrackPntAlt(swigCPtr);
    return ret;
  }

}
