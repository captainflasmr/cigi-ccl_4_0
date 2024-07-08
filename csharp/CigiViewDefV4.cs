//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiViewDefV4 : CigiBaseViewDef {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiViewDefV4(global::System.IntPtr cPtr, bool cMemoryOwn) : base(example_modulePINVOKE.CigiViewDefV4_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiViewDefV4 obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiViewDefV4 obj) {
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
          example_modulePINVOKE.delete_CigiViewDefV4(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public CigiViewDefV4() : this(example_modulePINVOKE.new_CigiViewDefV4(), true) {
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiViewDefV4_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiViewDefV4_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public int SetViewID(SWIGTYPE_p_unsigned___int16 ViewIDIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiViewDefV4_SetViewID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(ViewIDIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetViewID(SWIGTYPE_p_unsigned___int16 ViewIDIn) {
    int ret = example_modulePINVOKE.CigiViewDefV4_SetViewID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(ViewIDIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetViewID() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(example_modulePINVOKE.CigiViewDefV4_GetViewID(swigCPtr), true);
    return ret;
  }

  public int SetGroupID(SWIGTYPE_p_unsigned___int8 GroupIDIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiViewDefV4_SetGroupID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(GroupIDIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetGroupID(SWIGTYPE_p_unsigned___int8 GroupIDIn) {
    int ret = example_modulePINVOKE.CigiViewDefV4_SetGroupID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(GroupIDIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int8 GetGroupID() {
    SWIGTYPE_p_unsigned___int8 ret = new SWIGTYPE_p_unsigned___int8(example_modulePINVOKE.CigiViewDefV4_GetGroupID(swigCPtr), true);
    return ret;
  }

  public int SetFOVNearEn(bool FOVNearEnIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiViewDefV4_SetFOVNearEn__SWIG_0(swigCPtr, FOVNearEnIn, bndchk);
    return ret;
  }

  public int SetFOVNearEn(bool FOVNearEnIn) {
    int ret = example_modulePINVOKE.CigiViewDefV4_SetFOVNearEn__SWIG_1(swigCPtr, FOVNearEnIn);
    return ret;
  }

  public bool GetFOVNearEn() {
    bool ret = example_modulePINVOKE.CigiViewDefV4_GetFOVNearEn(swigCPtr);
    return ret;
  }

  public int SetFOVFarEn(bool FOVFarEnIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiViewDefV4_SetFOVFarEn__SWIG_0(swigCPtr, FOVFarEnIn, bndchk);
    return ret;
  }

  public int SetFOVFarEn(bool FOVFarEnIn) {
    int ret = example_modulePINVOKE.CigiViewDefV4_SetFOVFarEn__SWIG_1(swigCPtr, FOVFarEnIn);
    return ret;
  }

  public bool GetFOVFarEn() {
    bool ret = example_modulePINVOKE.CigiViewDefV4_GetFOVFarEn(swigCPtr);
    return ret;
  }

  public int SetFOVLeftEn(bool FOVLeftEnIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiViewDefV4_SetFOVLeftEn__SWIG_0(swigCPtr, FOVLeftEnIn, bndchk);
    return ret;
  }

  public int SetFOVLeftEn(bool FOVLeftEnIn) {
    int ret = example_modulePINVOKE.CigiViewDefV4_SetFOVLeftEn__SWIG_1(swigCPtr, FOVLeftEnIn);
    return ret;
  }

  public bool GetFOVLeftEn() {
    bool ret = example_modulePINVOKE.CigiViewDefV4_GetFOVLeftEn(swigCPtr);
    return ret;
  }

  public int SetFOVRightEn(bool FOVRightEnIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiViewDefV4_SetFOVRightEn__SWIG_0(swigCPtr, FOVRightEnIn, bndchk);
    return ret;
  }

  public int SetFOVRightEn(bool FOVRightEnIn) {
    int ret = example_modulePINVOKE.CigiViewDefV4_SetFOVRightEn__SWIG_1(swigCPtr, FOVRightEnIn);
    return ret;
  }

  public bool GetFOVRightEn() {
    bool ret = example_modulePINVOKE.CigiViewDefV4_GetFOVRightEn(swigCPtr);
    return ret;
  }

  public int SetFOVTopEn(bool FOVTopEnIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiViewDefV4_SetFOVTopEn__SWIG_0(swigCPtr, FOVTopEnIn, bndchk);
    return ret;
  }

  public int SetFOVTopEn(bool FOVTopEnIn) {
    int ret = example_modulePINVOKE.CigiViewDefV4_SetFOVTopEn__SWIG_1(swigCPtr, FOVTopEnIn);
    return ret;
  }

  public bool GetFOVTopEn() {
    bool ret = example_modulePINVOKE.CigiViewDefV4_GetFOVTopEn(swigCPtr);
    return ret;
  }

  public int SetFOVBottomEn(bool FOVBottomEnIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiViewDefV4_SetFOVBottomEn__SWIG_0(swigCPtr, FOVBottomEnIn, bndchk);
    return ret;
  }

  public int SetFOVBottomEn(bool FOVBottomEnIn) {
    int ret = example_modulePINVOKE.CigiViewDefV4_SetFOVBottomEn__SWIG_1(swigCPtr, FOVBottomEnIn);
    return ret;
  }

  public bool GetFOVBottomEn() {
    bool ret = example_modulePINVOKE.CigiViewDefV4_GetFOVBottomEn(swigCPtr);
    return ret;
  }

  public int SetProjectionType(CigiBaseViewDef.ProjectionTypeGrp ProjectionTypeIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiViewDefV4_SetProjectionType__SWIG_0(swigCPtr, (int)ProjectionTypeIn, bndchk);
    return ret;
  }

  public int SetProjectionType(CigiBaseViewDef.ProjectionTypeGrp ProjectionTypeIn) {
    int ret = example_modulePINVOKE.CigiViewDefV4_SetProjectionType__SWIG_1(swigCPtr, (int)ProjectionTypeIn);
    return ret;
  }

  public CigiBaseViewDef.ProjectionTypeGrp GetProjectionType() {
    CigiBaseViewDef.ProjectionTypeGrp ret = (CigiBaseViewDef.ProjectionTypeGrp)example_modulePINVOKE.CigiViewDefV4_GetProjectionType(swigCPtr);
    return ret;
  }

  public int SetReorder(bool ReorderIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiViewDefV4_SetReorder__SWIG_0(swigCPtr, ReorderIn, bndchk);
    return ret;
  }

  public int SetReorder(bool ReorderIn) {
    int ret = example_modulePINVOKE.CigiViewDefV4_SetReorder__SWIG_1(swigCPtr, ReorderIn);
    return ret;
  }

  public bool GetReorder() {
    bool ret = example_modulePINVOKE.CigiViewDefV4_GetReorder(swigCPtr);
    return ret;
  }

}