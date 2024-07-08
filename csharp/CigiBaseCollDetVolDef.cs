//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiBaseCollDetVolDef : CigiBasePacket {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiBaseCollDetVolDef(global::System.IntPtr cPtr, bool cMemoryOwn) : base(example_modulePINVOKE.CigiBaseCollDetVolDef_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiBaseCollDetVolDef obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiBaseCollDetVolDef obj) {
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
          example_modulePINVOKE.delete_CigiBaseCollDetVolDef(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiBaseCollDetVolDef_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiBaseCollDetVolDef_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int GetCnvt(CigiVersionID CnvtVersion, SWIGTYPE_p_CigiCnvtInfoType__Type CnvtInfo) {
    int ret = example_modulePINVOKE.CigiBaseCollDetVolDef_GetCnvt(swigCPtr, CigiVersionID.getCPtr(CnvtVersion), SWIGTYPE_p_CigiCnvtInfoType__Type.getCPtr(CnvtInfo));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetEntityID(SWIGTYPE_p_unsigned___int16 EntityIDIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseCollDetVolDef_SetEntityID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(EntityIDIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetEntityID(SWIGTYPE_p_unsigned___int16 EntityIDIn) {
    int ret = example_modulePINVOKE.CigiBaseCollDetVolDef_SetEntityID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(EntityIDIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetEntityID() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(example_modulePINVOKE.CigiBaseCollDetVolDef_GetEntityID(swigCPtr), true);
    return ret;
  }

  public int SetVolID(SWIGTYPE_p_unsigned___int8 VolIDIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseCollDetVolDef_SetVolID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(VolIDIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetVolID(SWIGTYPE_p_unsigned___int8 VolIDIn) {
    int ret = example_modulePINVOKE.CigiBaseCollDetVolDef_SetVolID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(VolIDIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int8 GetVolID() {
    SWIGTYPE_p_unsigned___int8 ret = new SWIGTYPE_p_unsigned___int8(example_modulePINVOKE.CigiBaseCollDetVolDef_GetVolID(swigCPtr), true);
    return ret;
  }

  public int SetVolEn(bool VolEnIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseCollDetVolDef_SetVolEn__SWIG_0(swigCPtr, VolEnIn, bndchk);
    return ret;
  }

  public int SetVolEn(bool VolEnIn) {
    int ret = example_modulePINVOKE.CigiBaseCollDetVolDef_SetVolEn__SWIG_1(swigCPtr, VolEnIn);
    return ret;
  }

  public bool GetVolEn() {
    bool ret = example_modulePINVOKE.CigiBaseCollDetVolDef_GetVolEn(swigCPtr);
    return ret;
  }

  public int SetXoff(float XoffIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseCollDetVolDef_SetXoff__SWIG_0(swigCPtr, XoffIn, bndchk);
    return ret;
  }

  public int SetXoff(float XoffIn) {
    int ret = example_modulePINVOKE.CigiBaseCollDetVolDef_SetXoff__SWIG_1(swigCPtr, XoffIn);
    return ret;
  }

  public float GetXoff() {
    float ret = example_modulePINVOKE.CigiBaseCollDetVolDef_GetXoff(swigCPtr);
    return ret;
  }

  public int SetYoff(float YoffIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseCollDetVolDef_SetYoff__SWIG_0(swigCPtr, YoffIn, bndchk);
    return ret;
  }

  public int SetYoff(float YoffIn) {
    int ret = example_modulePINVOKE.CigiBaseCollDetVolDef_SetYoff__SWIG_1(swigCPtr, YoffIn);
    return ret;
  }

  public float GetYoff() {
    float ret = example_modulePINVOKE.CigiBaseCollDetVolDef_GetYoff(swigCPtr);
    return ret;
  }

  public int SetZoff(float ZoffIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseCollDetVolDef_SetZoff__SWIG_0(swigCPtr, ZoffIn, bndchk);
    return ret;
  }

  public int SetZoff(float ZoffIn) {
    int ret = example_modulePINVOKE.CigiBaseCollDetVolDef_SetZoff__SWIG_1(swigCPtr, ZoffIn);
    return ret;
  }

  public float GetZoff() {
    float ret = example_modulePINVOKE.CigiBaseCollDetVolDef_GetZoff(swigCPtr);
    return ret;
  }

  public int SetHeightOrRadius(float HeightOrRadiusIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseCollDetVolDef_SetHeightOrRadius__SWIG_0(swigCPtr, HeightOrRadiusIn, bndchk);
    return ret;
  }

  public int SetHeightOrRadius(float HeightOrRadiusIn) {
    int ret = example_modulePINVOKE.CigiBaseCollDetVolDef_SetHeightOrRadius__SWIG_1(swigCPtr, HeightOrRadiusIn);
    return ret;
  }

  public float GetHeightOrRadius() {
    float ret = example_modulePINVOKE.CigiBaseCollDetVolDef_GetHeightOrRadius(swigCPtr);
    return ret;
  }

  public int SetWidth(float WidthIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseCollDetVolDef_SetWidth__SWIG_0(swigCPtr, WidthIn, bndchk);
    return ret;
  }

  public int SetWidth(float WidthIn) {
    int ret = example_modulePINVOKE.CigiBaseCollDetVolDef_SetWidth__SWIG_1(swigCPtr, WidthIn);
    return ret;
  }

  public float GetWidth() {
    float ret = example_modulePINVOKE.CigiBaseCollDetVolDef_GetWidth(swigCPtr);
    return ret;
  }

  public int SetDepth(float DepthIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseCollDetVolDef_SetDepth__SWIG_0(swigCPtr, DepthIn, bndchk);
    return ret;
  }

  public int SetDepth(float DepthIn) {
    int ret = example_modulePINVOKE.CigiBaseCollDetVolDef_SetDepth__SWIG_1(swigCPtr, DepthIn);
    return ret;
  }

  public float GetDepth() {
    float ret = example_modulePINVOKE.CigiBaseCollDetVolDef_GetDepth(swigCPtr);
    return ret;
  }

  public enum VolTypeGrp {
    Sphere = 0,
    Cuboid = 1
  }

}
