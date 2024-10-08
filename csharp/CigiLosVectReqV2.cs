//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiLosVectReqV2 : CigiBaseLosVectReq {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiLosVectReqV2(global::System.IntPtr cPtr, bool cMemoryOwn) : base(ccl_dllDPINVOKE.CigiLosVectReqV2_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiLosVectReqV2 obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiLosVectReqV2 obj) {
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
          ccl_dllDPINVOKE.delete_CigiLosVectReqV2(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public CigiLosVectReqV2() : this(ccl_dllDPINVOKE.new_CigiLosVectReqV2(), true) {
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = ccl_dllDPINVOKE.CigiLosVectReqV2_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = ccl_dllDPINVOKE.CigiLosVectReqV2_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public int SetVectAz(float VectAzIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiLosVectReqV2_SetVectAz__SWIG_0(swigCPtr, VectAzIn, bndchk);
    return ret;
  }

  public int SetVectAz(float VectAzIn) {
    int ret = ccl_dllDPINVOKE.CigiLosVectReqV2_SetVectAz__SWIG_1(swigCPtr, VectAzIn);
    return ret;
  }

  public float GetVectAz() {
    float ret = ccl_dllDPINVOKE.CigiLosVectReqV2_GetVectAz(swigCPtr);
    return ret;
  }

  public int SetMinRange(float MinRangeIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiLosVectReqV2_SetMinRange__SWIG_0(swigCPtr, MinRangeIn, bndchk);
    return ret;
  }

  public int SetMinRange(float MinRangeIn) {
    int ret = ccl_dllDPINVOKE.CigiLosVectReqV2_SetMinRange__SWIG_1(swigCPtr, MinRangeIn);
    return ret;
  }

  public float GetMinRange() {
    float ret = ccl_dllDPINVOKE.CigiLosVectReqV2_GetMinRange(swigCPtr);
    return ret;
  }

}
