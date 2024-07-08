//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiTrajectoryDefV2 : CigiBaseTrajectoryDef {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiTrajectoryDefV2(global::System.IntPtr cPtr, bool cMemoryOwn) : base(example_modulePINVOKE.CigiTrajectoryDefV2_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiTrajectoryDefV2 obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiTrajectoryDefV2 obj) {
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
          example_modulePINVOKE.delete_CigiTrajectoryDefV2(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public CigiTrajectoryDefV2() : this(example_modulePINVOKE.new_CigiTrajectoryDefV2(), true) {
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiTrajectoryDefV2_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiTrajectoryDefV2_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public new int SetAccel(float AccelIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiTrajectoryDefV2_SetAccel__SWIG_0(swigCPtr, AccelIn, bndchk);
    return ret;
  }

  public new int SetAccel(float AccelIn) {
    int ret = example_modulePINVOKE.CigiTrajectoryDefV2_SetAccel__SWIG_1(swigCPtr, AccelIn);
    return ret;
  }

  public new float GetAccel() {
    float ret = example_modulePINVOKE.CigiTrajectoryDefV2_GetAccel(swigCPtr);
    return ret;
  }

}
