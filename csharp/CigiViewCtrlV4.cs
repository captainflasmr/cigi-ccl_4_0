//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiViewCtrlV4 : CigiBaseViewCtrl {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiViewCtrlV4(global::System.IntPtr cPtr, bool cMemoryOwn) : base(example_modulePINVOKE.CigiViewCtrlV4_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiViewCtrlV4 obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiViewCtrlV4 obj) {
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
          example_modulePINVOKE.delete_CigiViewCtrlV4(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public CigiViewCtrlV4() : this(example_modulePINVOKE.new_CigiViewCtrlV4(), true) {
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiViewCtrlV4_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiViewCtrlV4_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public int SetViewID(SWIGTYPE_p_unsigned___int16 ViewIDIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiViewCtrlV4_SetViewID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(ViewIDIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetViewID(SWIGTYPE_p_unsigned___int16 ViewIDIn) {
    int ret = example_modulePINVOKE.CigiViewCtrlV4_SetViewID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(ViewIDIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetViewID() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(example_modulePINVOKE.CigiViewCtrlV4_GetViewID(swigCPtr), true);
    return ret;
  }

  public int SetGroupID(SWIGTYPE_p_unsigned___int8 GroupIDIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiViewCtrlV4_SetGroupID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(GroupIDIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetGroupID(SWIGTYPE_p_unsigned___int8 GroupIDIn) {
    int ret = example_modulePINVOKE.CigiViewCtrlV4_SetGroupID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(GroupIDIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int8 GetGroupID() {
    SWIGTYPE_p_unsigned___int8 ret = new SWIGTYPE_p_unsigned___int8(example_modulePINVOKE.CigiViewCtrlV4_GetGroupID(swigCPtr), true);
    return ret;
  }

  public int SetXOffEn(bool XOffEnIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiViewCtrlV4_SetXOffEn__SWIG_0(swigCPtr, XOffEnIn, bndchk);
    return ret;
  }

  public int SetXOffEn(bool XOffEnIn) {
    int ret = example_modulePINVOKE.CigiViewCtrlV4_SetXOffEn__SWIG_1(swigCPtr, XOffEnIn);
    return ret;
  }

  public bool GetXOffEn() {
    bool ret = example_modulePINVOKE.CigiViewCtrlV4_GetXOffEn(swigCPtr);
    return ret;
  }

  public int SetYOffEn(bool YOffEnIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiViewCtrlV4_SetYOffEn__SWIG_0(swigCPtr, YOffEnIn, bndchk);
    return ret;
  }

  public int SetYOffEn(bool YOffEnIn) {
    int ret = example_modulePINVOKE.CigiViewCtrlV4_SetYOffEn__SWIG_1(swigCPtr, YOffEnIn);
    return ret;
  }

  public bool GetYOffEn() {
    bool ret = example_modulePINVOKE.CigiViewCtrlV4_GetYOffEn(swigCPtr);
    return ret;
  }

  public int SetZOffEn(bool ZOffEnIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiViewCtrlV4_SetZOffEn__SWIG_0(swigCPtr, ZOffEnIn, bndchk);
    return ret;
  }

  public int SetZOffEn(bool ZOffEnIn) {
    int ret = example_modulePINVOKE.CigiViewCtrlV4_SetZOffEn__SWIG_1(swigCPtr, ZOffEnIn);
    return ret;
  }

  public bool GetZOffEn() {
    bool ret = example_modulePINVOKE.CigiViewCtrlV4_GetZOffEn(swigCPtr);
    return ret;
  }

  public int SetRollEn(bool RollEnIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiViewCtrlV4_SetRollEn__SWIG_0(swigCPtr, RollEnIn, bndchk);
    return ret;
  }

  public int SetRollEn(bool RollEnIn) {
    int ret = example_modulePINVOKE.CigiViewCtrlV4_SetRollEn__SWIG_1(swigCPtr, RollEnIn);
    return ret;
  }

  public bool GetRollEn() {
    bool ret = example_modulePINVOKE.CigiViewCtrlV4_GetRollEn(swigCPtr);
    return ret;
  }

  public int SetPitchEn(bool PitchEnIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiViewCtrlV4_SetPitchEn__SWIG_0(swigCPtr, PitchEnIn, bndchk);
    return ret;
  }

  public int SetPitchEn(bool PitchEnIn) {
    int ret = example_modulePINVOKE.CigiViewCtrlV4_SetPitchEn__SWIG_1(swigCPtr, PitchEnIn);
    return ret;
  }

  public bool GetPitchEn() {
    bool ret = example_modulePINVOKE.CigiViewCtrlV4_GetPitchEn(swigCPtr);
    return ret;
  }

  public int SetYawEn(bool YawEnIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiViewCtrlV4_SetYawEn__SWIG_0(swigCPtr, YawEnIn, bndchk);
    return ret;
  }

  public int SetYawEn(bool YawEnIn) {
    int ret = example_modulePINVOKE.CigiViewCtrlV4_SetYawEn__SWIG_1(swigCPtr, YawEnIn);
    return ret;
  }

  public bool GetYawEn() {
    bool ret = example_modulePINVOKE.CigiViewCtrlV4_GetYawEn(swigCPtr);
    return ret;
  }

}
