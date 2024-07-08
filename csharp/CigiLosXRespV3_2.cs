//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiLosXRespV3_2 : CigiBaseLosResp {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiLosXRespV3_2(global::System.IntPtr cPtr, bool cMemoryOwn) : base(example_modulePINVOKE.CigiLosXRespV3_2_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiLosXRespV3_2 obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiLosXRespV3_2 obj) {
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
          example_modulePINVOKE.delete_CigiLosXRespV3_2(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public CigiLosXRespV3_2() : this(example_modulePINVOKE.new_CigiLosXRespV3_2(), true) {
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int GetCnvt(CigiVersionID CnvtVersion, SWIGTYPE_p_CigiCnvtInfoType__Type CnvtInfo) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_GetCnvt(swigCPtr, CigiVersionID.getCPtr(CnvtVersion), SWIGTYPE_p_CigiCnvtInfoType__Type.getCPtr(CnvtInfo));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetEntityIDValid(bool EntityIDValidIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetEntityIDValid__SWIG_0(swigCPtr, EntityIDValidIn, bndchk);
    return ret;
  }

  public int SetEntityIDValid(bool EntityIDValidIn) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetEntityIDValid__SWIG_1(swigCPtr, EntityIDValidIn);
    return ret;
  }

  public bool GetEntityIDValid() {
    bool ret = example_modulePINVOKE.CigiLosXRespV3_2_GetEntityIDValid(swigCPtr);
    return ret;
  }

  public int SetRangeValid(bool RangeValidIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetRangeValid__SWIG_0(swigCPtr, RangeValidIn, bndchk);
    return ret;
  }

  public int SetRangeValid(bool RangeValidIn) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetRangeValid__SWIG_1(swigCPtr, RangeValidIn);
    return ret;
  }

  public bool GetRangeValid() {
    bool ret = example_modulePINVOKE.CigiLosXRespV3_2_GetRangeValid(swigCPtr);
    return ret;
  }

  public int SetHostFrame(SWIGTYPE_p_unsigned___int8 HostFrameIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetHostFrame__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(HostFrameIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetHostFrame(SWIGTYPE_p_unsigned___int8 HostFrameIn) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetHostFrame__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(HostFrameIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int8 GetHostFrame() {
    SWIGTYPE_p_unsigned___int8 ret = new SWIGTYPE_p_unsigned___int8(example_modulePINVOKE.CigiLosXRespV3_2_GetHostFrame(swigCPtr), true);
    return ret;
  }

  public int SetRespCount(SWIGTYPE_p_unsigned___int8 RespCountIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetRespCount__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(RespCountIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetRespCount(SWIGTYPE_p_unsigned___int8 RespCountIn) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetRespCount__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(RespCountIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int8 GetRespCount() {
    SWIGTYPE_p_unsigned___int8 ret = new SWIGTYPE_p_unsigned___int8(example_modulePINVOKE.CigiLosXRespV3_2_GetRespCount(swigCPtr), true);
    return ret;
  }

  public int SetEntityID(SWIGTYPE_p_unsigned___int16 EntityIDIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetEntityID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(EntityIDIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetEntityID(SWIGTYPE_p_unsigned___int16 EntityIDIn) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetEntityID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(EntityIDIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetEntityID() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(example_modulePINVOKE.CigiLosXRespV3_2_GetEntityID(swigCPtr), true);
    return ret;
  }

  public int SetXoff(double XoffIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetXoff__SWIG_0(swigCPtr, XoffIn, bndchk);
    return ret;
  }

  public int SetXoff(double XoffIn) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetXoff__SWIG_1(swigCPtr, XoffIn);
    return ret;
  }

  public double GetXoff() {
    double ret = example_modulePINVOKE.CigiLosXRespV3_2_GetXoff(swigCPtr);
    return ret;
  }

  public int SetYoff(double YoffIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetYoff__SWIG_0(swigCPtr, YoffIn, bndchk);
    return ret;
  }

  public int SetYoff(double YoffIn) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetYoff__SWIG_1(swigCPtr, YoffIn);
    return ret;
  }

  public double GetYoff() {
    double ret = example_modulePINVOKE.CigiLosXRespV3_2_GetYoff(swigCPtr);
    return ret;
  }

  public int SetZoff(double ZoffIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetZoff__SWIG_0(swigCPtr, ZoffIn, bndchk);
    return ret;
  }

  public int SetZoff(double ZoffIn) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetZoff__SWIG_1(swigCPtr, ZoffIn);
    return ret;
  }

  public double GetZoff() {
    double ret = example_modulePINVOKE.CigiLosXRespV3_2_GetZoff(swigCPtr);
    return ret;
  }

  public int SetRed(SWIGTYPE_p_unsigned___int8 RedIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetRed__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(RedIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetRed(SWIGTYPE_p_unsigned___int8 RedIn) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetRed__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(RedIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int8 GetRed() {
    SWIGTYPE_p_unsigned___int8 ret = new SWIGTYPE_p_unsigned___int8(example_modulePINVOKE.CigiLosXRespV3_2_GetRed(swigCPtr), true);
    return ret;
  }

  public int SetGreen(SWIGTYPE_p_unsigned___int8 GreenIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetGreen__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(GreenIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetGreen(SWIGTYPE_p_unsigned___int8 GreenIn) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetGreen__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(GreenIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int8 GetGreen() {
    SWIGTYPE_p_unsigned___int8 ret = new SWIGTYPE_p_unsigned___int8(example_modulePINVOKE.CigiLosXRespV3_2_GetGreen(swigCPtr), true);
    return ret;
  }

  public int SetBlue(SWIGTYPE_p_unsigned___int8 BlueIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetBlue__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(BlueIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetBlue(SWIGTYPE_p_unsigned___int8 BlueIn) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetBlue__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(BlueIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int8 GetBlue() {
    SWIGTYPE_p_unsigned___int8 ret = new SWIGTYPE_p_unsigned___int8(example_modulePINVOKE.CigiLosXRespV3_2_GetBlue(swigCPtr), true);
    return ret;
  }

  public int SetAlpha(SWIGTYPE_p_unsigned___int8 AlphaIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetAlpha__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(AlphaIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetAlpha(SWIGTYPE_p_unsigned___int8 AlphaIn) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetAlpha__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(AlphaIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int8 GetAlpha() {
    SWIGTYPE_p_unsigned___int8 ret = new SWIGTYPE_p_unsigned___int8(example_modulePINVOKE.CigiLosXRespV3_2_GetAlpha(swigCPtr), true);
    return ret;
  }

  public int SetMaterial(SWIGTYPE_p_unsigned___int32 MaterialIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetMaterial__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int32.getCPtr(MaterialIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetMaterial(SWIGTYPE_p_unsigned___int32 MaterialIn) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetMaterial__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int32.getCPtr(MaterialIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int32 GetMaterial() {
    SWIGTYPE_p_unsigned___int32 ret = new SWIGTYPE_p_unsigned___int32(example_modulePINVOKE.CigiLosXRespV3_2_GetMaterial(swigCPtr), true);
    return ret;
  }

  public int SetNormalAz(float NormalAzIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetNormalAz__SWIG_0(swigCPtr, NormalAzIn, bndchk);
    return ret;
  }

  public int SetNormalAz(float NormalAzIn) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetNormalAz__SWIG_1(swigCPtr, NormalAzIn);
    return ret;
  }

  public float GetNormalAz() {
    float ret = example_modulePINVOKE.CigiLosXRespV3_2_GetNormalAz(swigCPtr);
    return ret;
  }

  public int SetNormalEl(float NormalElIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetNormalEl__SWIG_0(swigCPtr, NormalElIn, bndchk);
    return ret;
  }

  public int SetNormalEl(float NormalElIn) {
    int ret = example_modulePINVOKE.CigiLosXRespV3_2_SetNormalEl__SWIG_1(swigCPtr, NormalElIn);
    return ret;
  }

  public float GetNormalEl() {
    float ret = example_modulePINVOKE.CigiLosXRespV3_2_GetNormalEl(swigCPtr);
    return ret;
  }

}
