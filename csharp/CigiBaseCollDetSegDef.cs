//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiBaseCollDetSegDef : CigiBasePacket {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiBaseCollDetSegDef(global::System.IntPtr cPtr, bool cMemoryOwn) : base(ccl_dllDPINVOKE.CigiBaseCollDetSegDef_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiBaseCollDetSegDef obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiBaseCollDetSegDef obj) {
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
          ccl_dllDPINVOKE.delete_CigiBaseCollDetSegDef(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int GetCnvt(CigiVersionID CnvtVersion, SWIGTYPE_p_CigiCnvtInfoType__Type CnvtInfo) {
    int ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_GetCnvt(swigCPtr, CigiVersionID.getCPtr(CnvtVersion), SWIGTYPE_p_CigiCnvtInfoType__Type.getCPtr(CnvtInfo));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetEntityID(SWIGTYPE_p_unsigned___int16 EntityIDIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_SetEntityID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(EntityIDIn), bndchk);
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetEntityID(SWIGTYPE_p_unsigned___int16 EntityIDIn) {
    int ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_SetEntityID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(EntityIDIn));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetEntityID() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(ccl_dllDPINVOKE.CigiBaseCollDetSegDef_GetEntityID(swigCPtr), true);
    return ret;
  }

  public int SetSegmentEn(bool SegmentEnIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_SetSegmentEn__SWIG_0(swigCPtr, SegmentEnIn, bndchk);
    return ret;
  }

  public int SetSegmentEn(bool SegmentEnIn) {
    int ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_SetSegmentEn__SWIG_1(swigCPtr, SegmentEnIn);
    return ret;
  }

  public bool GetSegmentEn() {
    bool ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_GetSegmentEn(swigCPtr);
    return ret;
  }

  public int SetX1(float X1In, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_SetX1__SWIG_0(swigCPtr, X1In, bndchk);
    return ret;
  }

  public int SetX1(float X1In) {
    int ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_SetX1__SWIG_1(swigCPtr, X1In);
    return ret;
  }

  public float GetX1() {
    float ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_GetX1(swigCPtr);
    return ret;
  }

  public int SetY1(float Y1In, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_SetY1__SWIG_0(swigCPtr, Y1In, bndchk);
    return ret;
  }

  public int SetY1(float Y1In) {
    int ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_SetY1__SWIG_1(swigCPtr, Y1In);
    return ret;
  }

  public float GetY1() {
    float ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_GetY1(swigCPtr);
    return ret;
  }

  public int SetZ1(float Z1In, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_SetZ1__SWIG_0(swigCPtr, Z1In, bndchk);
    return ret;
  }

  public int SetZ1(float Z1In) {
    int ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_SetZ1__SWIG_1(swigCPtr, Z1In);
    return ret;
  }

  public float GetZ1() {
    float ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_GetZ1(swigCPtr);
    return ret;
  }

  public int SetX2(float X2In, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_SetX2__SWIG_0(swigCPtr, X2In, bndchk);
    return ret;
  }

  public int SetX2(float X2In) {
    int ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_SetX2__SWIG_1(swigCPtr, X2In);
    return ret;
  }

  public float GetX2() {
    float ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_GetX2(swigCPtr);
    return ret;
  }

  public int SetY2(float Y2In, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_SetY2__SWIG_0(swigCPtr, Y2In, bndchk);
    return ret;
  }

  public int SetY2(float Y2In) {
    int ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_SetY2__SWIG_1(swigCPtr, Y2In);
    return ret;
  }

  public float GetY2() {
    float ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_GetY2(swigCPtr);
    return ret;
  }

  public int SetZ2(float Z2In, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_SetZ2__SWIG_0(swigCPtr, Z2In, bndchk);
    return ret;
  }

  public int SetZ2(float Z2In) {
    int ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_SetZ2__SWIG_1(swigCPtr, Z2In);
    return ret;
  }

  public float GetZ2() {
    float ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_GetZ2(swigCPtr);
    return ret;
  }

  public int SetMask(SWIGTYPE_p_unsigned___int32 MaskIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_SetMask__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int32.getCPtr(MaskIn), bndchk);
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetMask(SWIGTYPE_p_unsigned___int32 MaskIn) {
    int ret = ccl_dllDPINVOKE.CigiBaseCollDetSegDef_SetMask__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int32.getCPtr(MaskIn));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int32 GetMask() {
    SWIGTYPE_p_unsigned___int32 ret = new SWIGTYPE_p_unsigned___int32(ccl_dllDPINVOKE.CigiBaseCollDetSegDef_GetMask(swigCPtr), true);
    return ret;
  }

}
