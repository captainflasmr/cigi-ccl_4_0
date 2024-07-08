//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiBaseSymbolClone : CigiBasePacket {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiBaseSymbolClone(global::System.IntPtr cPtr, bool cMemoryOwn) : base(example_modulePINVOKE.CigiBaseSymbolClone_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiBaseSymbolClone obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiBaseSymbolClone obj) {
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
          example_modulePINVOKE.delete_CigiBaseSymbolClone(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiBaseSymbolClone_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiBaseSymbolClone_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int GetCnvt(CigiVersionID CnvtVersion, SWIGTYPE_p_CigiCnvtInfoType__Type CnvtInfo) {
    int ret = example_modulePINVOKE.CigiBaseSymbolClone_GetCnvt(swigCPtr, CigiVersionID.getCPtr(CnvtVersion), SWIGTYPE_p_CigiCnvtInfoType__Type.getCPtr(CnvtInfo));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetSymbolID(SWIGTYPE_p_unsigned___int16 SymbolIDIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseSymbolClone_SetSymbolID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(SymbolIDIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetSymbolID(SWIGTYPE_p_unsigned___int16 SymbolIDIn) {
    int ret = example_modulePINVOKE.CigiBaseSymbolClone_SetSymbolID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(SymbolIDIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetSymbolID() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(example_modulePINVOKE.CigiBaseSymbolClone_GetSymbolID(swigCPtr), true);
    return ret;
  }

  public int SetSourceType(CigiBaseSymbolClone.SymbolSourceGrp SourceTypeIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseSymbolClone_SetSourceType__SWIG_0(swigCPtr, (int)SourceTypeIn, bndchk);
    return ret;
  }

  public int SetSourceType(CigiBaseSymbolClone.SymbolSourceGrp SourceTypeIn) {
    int ret = example_modulePINVOKE.CigiBaseSymbolClone_SetSourceType__SWIG_1(swigCPtr, (int)SourceTypeIn);
    return ret;
  }

  public CigiBaseSymbolClone.SymbolSourceGrp GetSourceType() {
    CigiBaseSymbolClone.SymbolSourceGrp ret = (CigiBaseSymbolClone.SymbolSourceGrp)example_modulePINVOKE.CigiBaseSymbolClone_GetSourceType(swigCPtr);
    return ret;
  }

  public int SetSourceID(SWIGTYPE_p_unsigned___int16 SourceIDIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseSymbolClone_SetSourceID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(SourceIDIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetSourceID(SWIGTYPE_p_unsigned___int16 SourceIDIn) {
    int ret = example_modulePINVOKE.CigiBaseSymbolClone_SetSourceID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(SourceIDIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetSourceID() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(example_modulePINVOKE.CigiBaseSymbolClone_GetSourceID(swigCPtr), true);
    return ret;
  }

  public enum SymbolSourceGrp {
    SymbolSrc = 0,
    SymbolTemplateSrc = 1
  }

}
