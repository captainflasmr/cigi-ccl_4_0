//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiBaseEarthModelDef : CigiBasePacket {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiBaseEarthModelDef(global::System.IntPtr cPtr, bool cMemoryOwn) : base(example_modulePINVOKE.CigiBaseEarthModelDef_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiBaseEarthModelDef obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiBaseEarthModelDef obj) {
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
          example_modulePINVOKE.delete_CigiBaseEarthModelDef(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiBaseEarthModelDef_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiBaseEarthModelDef_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int GetCnvt(CigiVersionID CnvtVersion, SWIGTYPE_p_CigiCnvtInfoType__Type CnvtInfo) {
    int ret = example_modulePINVOKE.CigiBaseEarthModelDef_GetCnvt(swigCPtr, CigiVersionID.getCPtr(CnvtVersion), SWIGTYPE_p_CigiCnvtInfoType__Type.getCPtr(CnvtInfo));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetCustomERMEn(bool CustomERMEnIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseEarthModelDef_SetCustomERMEn__SWIG_0(swigCPtr, CustomERMEnIn, bndchk);
    return ret;
  }

  public int SetCustomERMEn(bool CustomERMEnIn) {
    int ret = example_modulePINVOKE.CigiBaseEarthModelDef_SetCustomERMEn__SWIG_1(swigCPtr, CustomERMEnIn);
    return ret;
  }

  public bool GetCustomERMEn() {
    bool ret = example_modulePINVOKE.CigiBaseEarthModelDef_GetCustomERMEn(swigCPtr);
    return ret;
  }

  public int SetEquatorialRadius(double EquatorialRadiusIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseEarthModelDef_SetEquatorialRadius__SWIG_0(swigCPtr, EquatorialRadiusIn, bndchk);
    return ret;
  }

  public int SetEquatorialRadius(double EquatorialRadiusIn) {
    int ret = example_modulePINVOKE.CigiBaseEarthModelDef_SetEquatorialRadius__SWIG_1(swigCPtr, EquatorialRadiusIn);
    return ret;
  }

  public double GetEquatorialRadius() {
    double ret = example_modulePINVOKE.CigiBaseEarthModelDef_GetEquatorialRadius(swigCPtr);
    return ret;
  }

  public int SetFlattening(double FlatteningIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseEarthModelDef_SetFlattening__SWIG_0(swigCPtr, FlatteningIn, bndchk);
    return ret;
  }

  public int SetFlattening(double FlatteningIn) {
    int ret = example_modulePINVOKE.CigiBaseEarthModelDef_SetFlattening__SWIG_1(swigCPtr, FlatteningIn);
    return ret;
  }

  public double GetFlattening() {
    double ret = example_modulePINVOKE.CigiBaseEarthModelDef_GetFlattening(swigCPtr);
    return ret;
  }

}
