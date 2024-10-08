//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiWeatherCtrlV2 : CigiBaseWeatherCtrl {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiWeatherCtrlV2(global::System.IntPtr cPtr, bool cMemoryOwn) : base(ccl_dllDPINVOKE.CigiWeatherCtrlV2_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiWeatherCtrlV2 obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiWeatherCtrlV2 obj) {
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
          ccl_dllDPINVOKE.delete_CigiWeatherCtrlV2(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public CigiWeatherCtrlV2() : this(ccl_dllDPINVOKE.new_CigiWeatherCtrlV2(), true) {
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = ccl_dllDPINVOKE.CigiWeatherCtrlV2_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = ccl_dllDPINVOKE.CigiWeatherCtrlV2_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public int SetPhenomenonType(SWIGTYPE_p_unsigned___int16 PhenomenonTypeIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiWeatherCtrlV2_SetPhenomenonType__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(PhenomenonTypeIn), bndchk);
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetPhenomenonType(SWIGTYPE_p_unsigned___int16 PhenomenonTypeIn) {
    int ret = ccl_dllDPINVOKE.CigiWeatherCtrlV2_SetPhenomenonType__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(PhenomenonTypeIn));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetPhenomenonType() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(ccl_dllDPINVOKE.CigiWeatherCtrlV2_GetPhenomenonType(swigCPtr), true);
    return ret;
  }

  public int SetOpacity(float OpacityIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiWeatherCtrlV2_SetOpacity__SWIG_0(swigCPtr, OpacityIn, bndchk);
    return ret;
  }

  public int SetOpacity(float OpacityIn) {
    int ret = ccl_dllDPINVOKE.CigiWeatherCtrlV2_SetOpacity__SWIG_1(swigCPtr, OpacityIn);
    return ret;
  }

  public float GetOpacity() {
    float ret = ccl_dllDPINVOKE.CigiWeatherCtrlV2_GetOpacity(swigCPtr);
    return ret;
  }

  public int SetWindDir(float WindDirIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiWeatherCtrlV2_SetWindDir__SWIG_0(swigCPtr, WindDirIn, bndchk);
    return ret;
  }

  public int SetWindDir(float WindDirIn) {
    int ret = ccl_dllDPINVOKE.CigiWeatherCtrlV2_SetWindDir__SWIG_1(swigCPtr, WindDirIn);
    return ret;
  }

  public float GetWindDir() {
    float ret = ccl_dllDPINVOKE.CigiWeatherCtrlV2_GetWindDir(swigCPtr);
    return ret;
  }

}
