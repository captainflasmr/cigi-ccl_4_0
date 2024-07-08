//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiCollDetVolRespV3 : CigiBaseCollDetVolResp {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiCollDetVolRespV3(global::System.IntPtr cPtr, bool cMemoryOwn) : base(example_modulePINVOKE.CigiCollDetVolRespV3_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiCollDetVolRespV3 obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiCollDetVolRespV3 obj) {
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
          example_modulePINVOKE.delete_CigiCollDetVolRespV3(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public CigiCollDetVolRespV3() : this(example_modulePINVOKE.new_CigiCollDetVolRespV3(), true) {
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiCollDetVolRespV3_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiCollDetVolRespV3_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public int SetVolID(SWIGTYPE_p_unsigned___int8 VolIDIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiCollDetVolRespV3_SetVolID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(VolIDIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetVolID(SWIGTYPE_p_unsigned___int8 VolIDIn) {
    int ret = example_modulePINVOKE.CigiCollDetVolRespV3_SetVolID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(VolIDIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int8 GetVolID() {
    SWIGTYPE_p_unsigned___int8 ret = new SWIGTYPE_p_unsigned___int8(example_modulePINVOKE.CigiCollDetVolRespV3_GetVolID(swigCPtr), true);
    return ret;
  }

  public int SetCollVolID(SWIGTYPE_p_unsigned___int8 CollVolIDIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiCollDetVolRespV3_SetCollVolID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(CollVolIDIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetCollVolID(SWIGTYPE_p_unsigned___int8 CollVolIDIn) {
    int ret = example_modulePINVOKE.CigiCollDetVolRespV3_SetCollVolID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(CollVolIDIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int8 GetCollVolID() {
    SWIGTYPE_p_unsigned___int8 ret = new SWIGTYPE_p_unsigned___int8(example_modulePINVOKE.CigiCollDetVolRespV3_GetCollVolID(swigCPtr), true);
    return ret;
  }

}
