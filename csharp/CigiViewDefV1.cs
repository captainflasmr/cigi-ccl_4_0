//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiViewDefV1 : CigiBaseViewDef {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiViewDefV1(global::System.IntPtr cPtr, bool cMemoryOwn) : base(example_modulePINVOKE.CigiViewDefV1_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiViewDefV1 obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiViewDefV1 obj) {
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
          example_modulePINVOKE.delete_CigiViewDefV1(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public CigiViewDefV1() : this(example_modulePINVOKE.new_CigiViewDefV1(), true) {
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiViewDefV1_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiViewDefV1_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public int SetViewID(SWIGTYPE_p_unsigned___int8 ViewIDIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiViewDefV1_SetViewID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(ViewIDIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetViewID(SWIGTYPE_p_unsigned___int8 ViewIDIn) {
    int ret = example_modulePINVOKE.CigiViewDefV1_SetViewID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(ViewIDIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int8 GetViewID() {
    SWIGTYPE_p_unsigned___int8 ret = new SWIGTYPE_p_unsigned___int8(example_modulePINVOKE.CigiViewDefV1_GetViewID(swigCPtr), true);
    return ret;
  }

  public int SetGroupID(SWIGTYPE_p_unsigned___int8 GroupIDIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiViewDefV1_SetGroupID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(GroupIDIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetGroupID(SWIGTYPE_p_unsigned___int8 GroupIDIn) {
    int ret = example_modulePINVOKE.CigiViewDefV1_SetGroupID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(GroupIDIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int8 GetGroupID() {
    SWIGTYPE_p_unsigned___int8 ret = new SWIGTYPE_p_unsigned___int8(example_modulePINVOKE.CigiViewDefV1_GetGroupID(swigCPtr), true);
    return ret;
  }

  public int SetTrackerAssigned(bool TrackerAssignedIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiViewDefV1_SetTrackerAssigned__SWIG_0(swigCPtr, TrackerAssignedIn, bndchk);
    return ret;
  }

  public int SetTrackerAssigned(bool TrackerAssignedIn) {
    int ret = example_modulePINVOKE.CigiViewDefV1_SetTrackerAssigned__SWIG_1(swigCPtr, TrackerAssignedIn);
    return ret;
  }

  public bool GetTrackerAssigned() {
    bool ret = example_modulePINVOKE.CigiViewDefV1_GetTrackerAssigned(swigCPtr);
    return ret;
  }

}