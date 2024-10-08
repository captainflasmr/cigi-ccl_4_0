//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiBaseHatHotResp : CigiBasePacket {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiBaseHatHotResp(global::System.IntPtr cPtr, bool cMemoryOwn) : base(ccl_dllDPINVOKE.CigiBaseHatHotResp_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiBaseHatHotResp obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiBaseHatHotResp obj) {
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
          ccl_dllDPINVOKE.delete_CigiBaseHatHotResp(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = ccl_dllDPINVOKE.CigiBaseHatHotResp_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = ccl_dllDPINVOKE.CigiBaseHatHotResp_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public int SetHatHotID(SWIGTYPE_p_unsigned___int16 HatHotIDIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseHatHotResp_SetHatHotID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(HatHotIDIn), bndchk);
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetHatHotID(SWIGTYPE_p_unsigned___int16 HatHotIDIn) {
    int ret = ccl_dllDPINVOKE.CigiBaseHatHotResp_SetHatHotID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(HatHotIDIn));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetHatHotID() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(ccl_dllDPINVOKE.CigiBaseHatHotResp_GetHatHotID(swigCPtr), true);
    return ret;
  }

  public int SetValid(bool ValidIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseHatHotResp_SetValid__SWIG_0(swigCPtr, ValidIn, bndchk);
    return ret;
  }

  public int SetValid(bool ValidIn) {
    int ret = ccl_dllDPINVOKE.CigiBaseHatHotResp_SetValid__SWIG_1(swigCPtr, ValidIn);
    return ret;
  }

  public bool GetValid() {
    bool ret = ccl_dllDPINVOKE.CigiBaseHatHotResp_GetValid(swigCPtr);
    return ret;
  }

  public enum ReqTypeGrp {
    HAT = 0,
    HOT = 1
  }

}
