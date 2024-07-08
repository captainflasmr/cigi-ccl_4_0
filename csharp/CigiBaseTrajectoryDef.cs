//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiBaseTrajectoryDef : CigiBasePacket {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiBaseTrajectoryDef(global::System.IntPtr cPtr, bool cMemoryOwn) : base(example_modulePINVOKE.CigiBaseTrajectoryDef_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiBaseTrajectoryDef obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiBaseTrajectoryDef obj) {
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
          example_modulePINVOKE.delete_CigiBaseTrajectoryDef(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiBaseTrajectoryDef_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiBaseTrajectoryDef_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int GetCnvt(CigiVersionID CnvtVersion, SWIGTYPE_p_CigiCnvtInfoType__Type CnvtInfo) {
    int ret = example_modulePINVOKE.CigiBaseTrajectoryDef_GetCnvt(swigCPtr, CigiVersionID.getCPtr(CnvtVersion), SWIGTYPE_p_CigiCnvtInfoType__Type.getCPtr(CnvtInfo));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetEntityID(SWIGTYPE_p_unsigned___int16 EntityIDIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseTrajectoryDef_SetEntityID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(EntityIDIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetEntityID(SWIGTYPE_p_unsigned___int16 EntityIDIn) {
    int ret = example_modulePINVOKE.CigiBaseTrajectoryDef_SetEntityID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(EntityIDIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetEntityID() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(example_modulePINVOKE.CigiBaseTrajectoryDef_GetEntityID(swigCPtr), true);
    return ret;
  }

  public int SetRetardationRate(float RetardationRateIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseTrajectoryDef_SetRetardationRate__SWIG_0(swigCPtr, RetardationRateIn, bndchk);
    return ret;
  }

  public int SetRetardationRate(float RetardationRateIn) {
    int ret = example_modulePINVOKE.CigiBaseTrajectoryDef_SetRetardationRate__SWIG_1(swigCPtr, RetardationRateIn);
    return ret;
  }

  public float GetRetardationRate() {
    float ret = example_modulePINVOKE.CigiBaseTrajectoryDef_GetRetardationRate(swigCPtr);
    return ret;
  }

  public int SetAccel(float AccelIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseTrajectoryDef_SetAccel__SWIG_0(swigCPtr, AccelIn, bndchk);
    return ret;
  }

  public int SetAccel(float AccelIn) {
    int ret = example_modulePINVOKE.CigiBaseTrajectoryDef_SetAccel__SWIG_1(swigCPtr, AccelIn);
    return ret;
  }

  public float GetAccel() {
    float ret = example_modulePINVOKE.CigiBaseTrajectoryDef_GetAccel(swigCPtr);
    return ret;
  }

  public int SetTermVel(float TermVelIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseTrajectoryDef_SetTermVel__SWIG_0(swigCPtr, TermVelIn, bndchk);
    return ret;
  }

  public int SetTermVel(float TermVelIn) {
    int ret = example_modulePINVOKE.CigiBaseTrajectoryDef_SetTermVel__SWIG_1(swigCPtr, TermVelIn);
    return ret;
  }

  public float GetTermVel() {
    float ret = example_modulePINVOKE.CigiBaseTrajectoryDef_GetTermVel(swigCPtr);
    return ret;
  }

  public enum CoordGrp {
    World = 0,
    Local = 1
  }

}