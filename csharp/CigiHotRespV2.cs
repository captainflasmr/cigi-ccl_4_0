//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiHotRespV2 : CigiBaseHatHotResp {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiHotRespV2(global::System.IntPtr cPtr, bool cMemoryOwn) : base(example_modulePINVOKE.CigiHotRespV2_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiHotRespV2 obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiHotRespV2 obj) {
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
          example_modulePINVOKE.delete_CigiHotRespV2(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public CigiHotRespV2() : this(example_modulePINVOKE.new_CigiHotRespV2(), true) {
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiHotRespV2_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiHotRespV2_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int GetCnvt(CigiVersionID CnvtVersion, SWIGTYPE_p_CigiCnvtInfoType__Type CnvtInfo) {
    int ret = example_modulePINVOKE.CigiHotRespV2_GetCnvt(swigCPtr, CigiVersionID.getCPtr(CnvtVersion), SWIGTYPE_p_CigiCnvtInfoType__Type.getCPtr(CnvtInfo));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetHot(double HotIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiHotRespV2_SetHot__SWIG_0(swigCPtr, HotIn, bndchk);
    return ret;
  }

  public int SetHot(double HotIn) {
    int ret = example_modulePINVOKE.CigiHotRespV2_SetHot__SWIG_1(swigCPtr, HotIn);
    return ret;
  }

  public double GetHot() {
    double ret = example_modulePINVOKE.CigiHotRespV2_GetHot(swigCPtr);
    return ret;
  }

  public int SetMaterial(SWIGTYPE_p_unsigned___int32 MaterialIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiHotRespV2_SetMaterial__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int32.getCPtr(MaterialIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetMaterial(SWIGTYPE_p_unsigned___int32 MaterialIn) {
    int ret = example_modulePINVOKE.CigiHotRespV2_SetMaterial__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int32.getCPtr(MaterialIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int32 GetMaterial() {
    SWIGTYPE_p_unsigned___int32 ret = new SWIGTYPE_p_unsigned___int32(example_modulePINVOKE.CigiHotRespV2_GetMaterial(swigCPtr), true);
    return ret;
  }

}
