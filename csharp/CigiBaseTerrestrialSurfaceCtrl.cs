//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiBaseTerrestrialSurfaceCtrl : CigiBasePacket {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiBaseTerrestrialSurfaceCtrl(global::System.IntPtr cPtr, bool cMemoryOwn) : base(ccl_dllDPINVOKE.CigiBaseTerrestrialSurfaceCtrl_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiBaseTerrestrialSurfaceCtrl obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiBaseTerrestrialSurfaceCtrl obj) {
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
          ccl_dllDPINVOKE.delete_CigiBaseTerrestrialSurfaceCtrl(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = ccl_dllDPINVOKE.CigiBaseTerrestrialSurfaceCtrl_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = ccl_dllDPINVOKE.CigiBaseTerrestrialSurfaceCtrl_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int GetCnvt(CigiVersionID CnvtVersion, SWIGTYPE_p_CigiCnvtInfoType__Type CnvtInfo) {
    int ret = ccl_dllDPINVOKE.CigiBaseTerrestrialSurfaceCtrl_GetCnvt(swigCPtr, CigiVersionID.getCPtr(CnvtVersion), SWIGTYPE_p_CigiCnvtInfoType__Type.getCPtr(CnvtInfo));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetEntityRgnID(SWIGTYPE_p_unsigned___int16 EntityRgnIDIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseTerrestrialSurfaceCtrl_SetEntityRgnID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(EntityRgnIDIn), bndchk);
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetEntityRgnID(SWIGTYPE_p_unsigned___int16 EntityRgnIDIn) {
    int ret = ccl_dllDPINVOKE.CigiBaseTerrestrialSurfaceCtrl_SetEntityRgnID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(EntityRgnIDIn));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetEntityRgnID() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(ccl_dllDPINVOKE.CigiBaseTerrestrialSurfaceCtrl_GetEntityRgnID(swigCPtr), true);
    return ret;
  }

  public int SetSurfaceCondID(SWIGTYPE_p_unsigned___int16 SurfaceCondIDIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseTerrestrialSurfaceCtrl_SetSurfaceCondID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(SurfaceCondIDIn), bndchk);
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetSurfaceCondID(SWIGTYPE_p_unsigned___int16 SurfaceCondIDIn) {
    int ret = ccl_dllDPINVOKE.CigiBaseTerrestrialSurfaceCtrl_SetSurfaceCondID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(SurfaceCondIDIn));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetSurfaceCondID() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(ccl_dllDPINVOKE.CigiBaseTerrestrialSurfaceCtrl_GetSurfaceCondID(swigCPtr), true);
    return ret;
  }

  public int SetSurfaceCondEn(bool SurfaceCondEnIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseTerrestrialSurfaceCtrl_SetSurfaceCondEn__SWIG_0(swigCPtr, SurfaceCondEnIn, bndchk);
    return ret;
  }

  public int SetSurfaceCondEn(bool SurfaceCondEnIn) {
    int ret = ccl_dllDPINVOKE.CigiBaseTerrestrialSurfaceCtrl_SetSurfaceCondEn__SWIG_1(swigCPtr, SurfaceCondEnIn);
    return ret;
  }

  public bool GetSurfaceCondEn() {
    bool ret = ccl_dllDPINVOKE.CigiBaseTerrestrialSurfaceCtrl_GetSurfaceCondEn(swigCPtr);
    return ret;
  }

  public int SetScope(CigiBaseTerrestrialSurfaceCtrl.ScopeGrp ScopeIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseTerrestrialSurfaceCtrl_SetScope__SWIG_0(swigCPtr, (int)ScopeIn, bndchk);
    return ret;
  }

  public int SetScope(CigiBaseTerrestrialSurfaceCtrl.ScopeGrp ScopeIn) {
    int ret = ccl_dllDPINVOKE.CigiBaseTerrestrialSurfaceCtrl_SetScope__SWIG_1(swigCPtr, (int)ScopeIn);
    return ret;
  }

  public CigiBaseTerrestrialSurfaceCtrl.ScopeGrp GetScope() {
    CigiBaseTerrestrialSurfaceCtrl.ScopeGrp ret = (CigiBaseTerrestrialSurfaceCtrl.ScopeGrp)ccl_dllDPINVOKE.CigiBaseTerrestrialSurfaceCtrl_GetScope(swigCPtr);
    return ret;
  }

  public int SetSeverity(SWIGTYPE_p_unsigned___int8 SeverityIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseTerrestrialSurfaceCtrl_SetSeverity__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(SeverityIn), bndchk);
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetSeverity(SWIGTYPE_p_unsigned___int8 SeverityIn) {
    int ret = ccl_dllDPINVOKE.CigiBaseTerrestrialSurfaceCtrl_SetSeverity__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(SeverityIn));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int8 GetSeverity() {
    SWIGTYPE_p_unsigned___int8 ret = new SWIGTYPE_p_unsigned___int8(ccl_dllDPINVOKE.CigiBaseTerrestrialSurfaceCtrl_GetSeverity(swigCPtr), true);
    return ret;
  }

  public int SetCoverage(SWIGTYPE_p_unsigned___int8 CoverageIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseTerrestrialSurfaceCtrl_SetCoverage__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(CoverageIn), bndchk);
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetCoverage(SWIGTYPE_p_unsigned___int8 CoverageIn) {
    int ret = ccl_dllDPINVOKE.CigiBaseTerrestrialSurfaceCtrl_SetCoverage__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(CoverageIn));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int8 GetCoverage() {
    SWIGTYPE_p_unsigned___int8 ret = new SWIGTYPE_p_unsigned___int8(ccl_dllDPINVOKE.CigiBaseTerrestrialSurfaceCtrl_GetCoverage(swigCPtr), true);
    return ret;
  }

  public enum ScopeGrp {
    Global = 0,
    Regional = 1,
    Entity = 2
  }

}
