//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiBaseLosVectReq : CigiBasePacket {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiBaseLosVectReq(global::System.IntPtr cPtr, bool cMemoryOwn) : base(ccl_dllDPINVOKE.CigiBaseLosVectReq_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiBaseLosVectReq obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiBaseLosVectReq obj) {
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
          ccl_dllDPINVOKE.delete_CigiBaseLosVectReq(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = ccl_dllDPINVOKE.CigiBaseLosVectReq_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = ccl_dllDPINVOKE.CigiBaseLosVectReq_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int GetCnvt(CigiVersionID CnvtVersion, SWIGTYPE_p_CigiCnvtInfoType__Type CnvtInfo) {
    int ret = ccl_dllDPINVOKE.CigiBaseLosVectReq_GetCnvt(swigCPtr, CigiVersionID.getCPtr(CnvtVersion), SWIGTYPE_p_CigiCnvtInfoType__Type.getCPtr(CnvtInfo));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetLosID(SWIGTYPE_p_unsigned___int16 LosIDIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseLosVectReq_SetLosID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(LosIDIn), bndchk);
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetLosID(SWIGTYPE_p_unsigned___int16 LosIDIn) {
    int ret = ccl_dllDPINVOKE.CigiBaseLosVectReq_SetLosID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(LosIDIn));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetLosID() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(ccl_dllDPINVOKE.CigiBaseLosVectReq_GetLosID(swigCPtr), true);
    return ret;
  }

  public int SetVectEl(float VectElIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseLosVectReq_SetVectEl__SWIG_0(swigCPtr, VectElIn, bndchk);
    return ret;
  }

  public int SetVectEl(float VectElIn) {
    int ret = ccl_dllDPINVOKE.CigiBaseLosVectReq_SetVectEl__SWIG_1(swigCPtr, VectElIn);
    return ret;
  }

  public float GetVectEl() {
    float ret = ccl_dllDPINVOKE.CigiBaseLosVectReq_GetVectEl(swigCPtr);
    return ret;
  }

  public int SetMaxRange(float MaxRangeIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseLosVectReq_SetMaxRange__SWIG_0(swigCPtr, MaxRangeIn, bndchk);
    return ret;
  }

  public int SetMaxRange(float MaxRangeIn) {
    int ret = ccl_dllDPINVOKE.CigiBaseLosVectReq_SetMaxRange__SWIG_1(swigCPtr, MaxRangeIn);
    return ret;
  }

  public float GetMaxRange() {
    float ret = ccl_dllDPINVOKE.CigiBaseLosVectReq_GetMaxRange(swigCPtr);
    return ret;
  }

  public int SetSrcLat(double SrcLatIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseLosVectReq_SetSrcLat__SWIG_0(swigCPtr, SrcLatIn, bndchk);
    return ret;
  }

  public int SetSrcLat(double SrcLatIn) {
    int ret = ccl_dllDPINVOKE.CigiBaseLosVectReq_SetSrcLat__SWIG_1(swigCPtr, SrcLatIn);
    return ret;
  }

  public double GetSrcLat() {
    double ret = ccl_dllDPINVOKE.CigiBaseLosVectReq_GetSrcLat(swigCPtr);
    return ret;
  }

  public int SetSrcLon(double SrcLonIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseLosVectReq_SetSrcLon__SWIG_0(swigCPtr, SrcLonIn, bndchk);
    return ret;
  }

  public int SetSrcLon(double SrcLonIn) {
    int ret = ccl_dllDPINVOKE.CigiBaseLosVectReq_SetSrcLon__SWIG_1(swigCPtr, SrcLonIn);
    return ret;
  }

  public double GetSrcLon() {
    double ret = ccl_dllDPINVOKE.CigiBaseLosVectReq_GetSrcLon(swigCPtr);
    return ret;
  }

  public int SetSrcAlt(double SrcAltIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseLosVectReq_SetSrcAlt__SWIG_0(swigCPtr, SrcAltIn, bndchk);
    return ret;
  }

  public int SetSrcAlt(double SrcAltIn) {
    int ret = ccl_dllDPINVOKE.CigiBaseLosVectReq_SetSrcAlt__SWIG_1(swigCPtr, SrcAltIn);
    return ret;
  }

  public double GetSrcAlt() {
    double ret = ccl_dllDPINVOKE.CigiBaseLosVectReq_GetSrcAlt(swigCPtr);
    return ret;
  }

  public enum ReqTypeGrp {
    Basic = 0,
    Extended = 1
  }

  public enum CoordSysGrp {
    Geodetic = 0,
    Entity = 1
  }

}
