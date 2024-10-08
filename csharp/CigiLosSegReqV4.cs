//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiLosSegReqV4 : CigiBaseLosSegReq {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiLosSegReqV4(global::System.IntPtr cPtr, bool cMemoryOwn) : base(ccl_dllDPINVOKE.CigiLosSegReqV4_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiLosSegReqV4 obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiLosSegReqV4 obj) {
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
          ccl_dllDPINVOKE.delete_CigiLosSegReqV4(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public CigiLosSegReqV4() : this(ccl_dllDPINVOKE.new_CigiLosSegReqV4(), true) {
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public int SetReqType(CigiBaseLosSegReq.ReqTypeGrp ReqTypeIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetReqType__SWIG_0(swigCPtr, (int)ReqTypeIn, bndchk);
    return ret;
  }

  public int SetReqType(CigiBaseLosSegReq.ReqTypeGrp ReqTypeIn) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetReqType__SWIG_1(swigCPtr, (int)ReqTypeIn);
    return ret;
  }

  public CigiBaseLosSegReq.ReqTypeGrp GetReqType() {
    CigiBaseLosSegReq.ReqTypeGrp ret = (CigiBaseLosSegReq.ReqTypeGrp)ccl_dllDPINVOKE.CigiLosSegReqV4_GetReqType(swigCPtr);
    return ret;
  }

  public int SetSrcCoordSys(CigiBaseLosSegReq.CoordSysGrp SrcCoordSysIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetSrcCoordSys__SWIG_0(swigCPtr, (int)SrcCoordSysIn, bndchk);
    return ret;
  }

  public int SetSrcCoordSys(CigiBaseLosSegReq.CoordSysGrp SrcCoordSysIn) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetSrcCoordSys__SWIG_1(swigCPtr, (int)SrcCoordSysIn);
    return ret;
  }

  public CigiBaseLosSegReq.CoordSysGrp GetSrcCoordSys() {
    CigiBaseLosSegReq.CoordSysGrp ret = (CigiBaseLosSegReq.CoordSysGrp)ccl_dllDPINVOKE.CigiLosSegReqV4_GetSrcCoordSys(swigCPtr);
    return ret;
  }

  public int SetDstCoordSys(CigiBaseLosSegReq.CoordSysGrp DstCoordSysIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetDstCoordSys__SWIG_0(swigCPtr, (int)DstCoordSysIn, bndchk);
    return ret;
  }

  public int SetDstCoordSys(CigiBaseLosSegReq.CoordSysGrp DstCoordSysIn) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetDstCoordSys__SWIG_1(swigCPtr, (int)DstCoordSysIn);
    return ret;
  }

  public CigiBaseLosSegReq.CoordSysGrp GetDstCoordSys() {
    CigiBaseLosSegReq.CoordSysGrp ret = (CigiBaseLosSegReq.CoordSysGrp)ccl_dllDPINVOKE.CigiLosSegReqV4_GetDstCoordSys(swigCPtr);
    return ret;
  }

  public int SetResponseCoordSys(CigiBaseLosSegReq.CoordSysGrp ResponseCoordSysIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetResponseCoordSys__SWIG_0(swigCPtr, (int)ResponseCoordSysIn, bndchk);
    return ret;
  }

  public int SetResponseCoordSys(CigiBaseLosSegReq.CoordSysGrp ResponseCoordSysIn) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetResponseCoordSys__SWIG_1(swigCPtr, (int)ResponseCoordSysIn);
    return ret;
  }

  public CigiBaseLosSegReq.CoordSysGrp GetResponseCoordSys() {
    CigiBaseLosSegReq.CoordSysGrp ret = (CigiBaseLosSegReq.CoordSysGrp)ccl_dllDPINVOKE.CigiLosSegReqV4_GetResponseCoordSys(swigCPtr);
    return ret;
  }

  public int SetDestEntityIDValid(bool DestEntityIDValidIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetDestEntityIDValid__SWIG_0(swigCPtr, DestEntityIDValidIn, bndchk);
    return ret;
  }

  public int SetDestEntityIDValid(bool DestEntityIDValidIn) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetDestEntityIDValid__SWIG_1(swigCPtr, DestEntityIDValidIn);
    return ret;
  }

  public bool GetDestEntityIDValid() {
    bool ret = ccl_dllDPINVOKE.CigiLosSegReqV4_GetDestEntityIDValid(swigCPtr);
    return ret;
  }

  public int SetAlphaThresh(SWIGTYPE_p_unsigned___int8 AlphaThreshIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetAlphaThresh__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(AlphaThreshIn), bndchk);
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetAlphaThresh(SWIGTYPE_p_unsigned___int8 AlphaThreshIn) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetAlphaThresh__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(AlphaThreshIn));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int8 GetAlphaThresh() {
    SWIGTYPE_p_unsigned___int8 ret = new SWIGTYPE_p_unsigned___int8(ccl_dllDPINVOKE.CigiLosSegReqV4_GetAlphaThresh(swigCPtr), true);
    return ret;
  }

  public int SetEntityID(SWIGTYPE_p_unsigned___int16 EntityIDIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetEntityID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(EntityIDIn), bndchk);
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetEntityID(SWIGTYPE_p_unsigned___int16 EntityIDIn) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetEntityID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(EntityIDIn));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetEntityID() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(ccl_dllDPINVOKE.CigiLosSegReqV4_GetEntityID(swigCPtr), true);
    return ret;
  }

  public int SetSrcXoff(double SrcXoffIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetSrcXoff__SWIG_0(swigCPtr, SrcXoffIn, bndchk);
    return ret;
  }

  public int SetSrcXoff(double SrcXoffIn) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetSrcXoff__SWIG_1(swigCPtr, SrcXoffIn);
    return ret;
  }

  public double GetSrcXoff() {
    double ret = ccl_dllDPINVOKE.CigiLosSegReqV4_GetSrcXoff(swigCPtr);
    return ret;
  }

  public int SetSrcYoff(double SrcYoffIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetSrcYoff__SWIG_0(swigCPtr, SrcYoffIn, bndchk);
    return ret;
  }

  public int SetSrcYoff(double SrcYoffIn) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetSrcYoff__SWIG_1(swigCPtr, SrcYoffIn);
    return ret;
  }

  public double GetSrcYoff() {
    double ret = ccl_dllDPINVOKE.CigiLosSegReqV4_GetSrcYoff(swigCPtr);
    return ret;
  }

  public int SetSrcZoff(double SrcZoffIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetSrcZoff__SWIG_0(swigCPtr, SrcZoffIn, bndchk);
    return ret;
  }

  public int SetSrcZoff(double SrcZoffIn) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetSrcZoff__SWIG_1(swigCPtr, SrcZoffIn);
    return ret;
  }

  public double GetSrcZoff() {
    double ret = ccl_dllDPINVOKE.CigiLosSegReqV4_GetSrcZoff(swigCPtr);
    return ret;
  }

  public int SetDstXoff(double DstXoffIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetDstXoff__SWIG_0(swigCPtr, DstXoffIn, bndchk);
    return ret;
  }

  public int SetDstXoff(double DstXoffIn) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetDstXoff__SWIG_1(swigCPtr, DstXoffIn);
    return ret;
  }

  public double GetDstXoff() {
    double ret = ccl_dllDPINVOKE.CigiLosSegReqV4_GetDstXoff(swigCPtr);
    return ret;
  }

  public int SetDstYoff(double DstYoffIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetDstYoff__SWIG_0(swigCPtr, DstYoffIn, bndchk);
    return ret;
  }

  public int SetDstYoff(double DstYoffIn) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetDstYoff__SWIG_1(swigCPtr, DstYoffIn);
    return ret;
  }

  public double GetDstYoff() {
    double ret = ccl_dllDPINVOKE.CigiLosSegReqV4_GetDstYoff(swigCPtr);
    return ret;
  }

  public int SetDstZoff(double DstZoffIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetDstZoff__SWIG_0(swigCPtr, DstZoffIn, bndchk);
    return ret;
  }

  public int SetDstZoff(double DstZoffIn) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetDstZoff__SWIG_1(swigCPtr, DstZoffIn);
    return ret;
  }

  public double GetDstZoff() {
    double ret = ccl_dllDPINVOKE.CigiLosSegReqV4_GetDstZoff(swigCPtr);
    return ret;
  }

  public int SetMask(SWIGTYPE_p_unsigned___int32 MaskIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetMask__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int32.getCPtr(MaskIn), bndchk);
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetMask(SWIGTYPE_p_unsigned___int32 MaskIn) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetMask__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int32.getCPtr(MaskIn));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int32 GetMask() {
    SWIGTYPE_p_unsigned___int32 ret = new SWIGTYPE_p_unsigned___int32(ccl_dllDPINVOKE.CigiLosSegReqV4_GetMask(swigCPtr), true);
    return ret;
  }

  public int SetUpdatePeriod(SWIGTYPE_p_unsigned___int8 UpdatePeriodIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetUpdatePeriod__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(UpdatePeriodIn), bndchk);
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetUpdatePeriod(SWIGTYPE_p_unsigned___int8 UpdatePeriodIn) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetUpdatePeriod__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(UpdatePeriodIn));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int8 GetUpdatePeriod() {
    SWIGTYPE_p_unsigned___int8 ret = new SWIGTYPE_p_unsigned___int8(ccl_dllDPINVOKE.CigiLosSegReqV4_GetUpdatePeriod(swigCPtr), true);
    return ret;
  }

  public int SetDestEntityID(SWIGTYPE_p_unsigned___int16 DestEntityIDIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetDestEntityID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(DestEntityIDIn), bndchk);
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetDestEntityID(SWIGTYPE_p_unsigned___int16 DestEntityIDIn) {
    int ret = ccl_dllDPINVOKE.CigiLosSegReqV4_SetDestEntityID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(DestEntityIDIn));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetDestEntityID() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(ccl_dllDPINVOKE.CigiLosSegReqV4_GetDestEntityID(swigCPtr), true);
    return ret;
  }

}
