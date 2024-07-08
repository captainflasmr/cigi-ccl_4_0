//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiSOFV2 : CigiBaseSOF {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiSOFV2(global::System.IntPtr cPtr, bool cMemoryOwn) : base(example_modulePINVOKE.CigiSOFV2_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiSOFV2 obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiSOFV2 obj) {
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
          example_modulePINVOKE.delete_CigiSOFV2(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public CigiSOFV2() : this(example_modulePINVOKE.new_CigiSOFV2(), true) {
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiSOFV2_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiSOFV2_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public new SWIGTYPE_p_unsigned___int32 GetFrameCntr() {
    SWIGTYPE_p_unsigned___int32 ret = new SWIGTYPE_p_unsigned___int32(example_modulePINVOKE.CigiSOFV2_GetFrameCntr(swigCPtr), true);
    return ret;
  }

  public new int SetFrameCntr(SWIGTYPE_p_unsigned___int32 FrameCntrIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiSOFV2_SetFrameCntr__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int32.getCPtr(FrameCntrIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public new int SetFrameCntr(SWIGTYPE_p_unsigned___int32 FrameCntrIn) {
    int ret = example_modulePINVOKE.CigiSOFV2_SetFrameCntr__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int32.getCPtr(FrameCntrIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public float GetTimeStamp() {
    float ret = example_modulePINVOKE.CigiSOFV2_GetTimeStamp(swigCPtr);
    return ret;
  }

  public int SetTimeStamp(float TimeStamp, bool bndchk) {
    int ret = example_modulePINVOKE.CigiSOFV2_SetTimeStamp__SWIG_0(swigCPtr, TimeStamp, bndchk);
    return ret;
  }

  public int SetTimeStamp(float TimeStamp) {
    int ret = example_modulePINVOKE.CigiSOFV2_SetTimeStamp__SWIG_1(swigCPtr, TimeStamp);
    return ret;
  }

}
