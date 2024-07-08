//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiSymbolCircleDefV4 : CigiBaseSymbolCircleDef {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiSymbolCircleDefV4(global::System.IntPtr cPtr, bool cMemoryOwn) : base(example_modulePINVOKE.CigiSymbolCircleDefV4_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiSymbolCircleDefV4 obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiSymbolCircleDefV4 obj) {
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
          example_modulePINVOKE.delete_CigiSymbolCircleDefV4(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public CigiSymbolCircleDefV4() : this(example_modulePINVOKE.new_CigiSymbolCircleDefV4__SWIG_0(), true) {
  }

  public CigiSymbolCircleDefV4(CigiSymbolCircleDefV4 BaseIn) : this(example_modulePINVOKE.new_CigiSymbolCircleDefV4__SWIG_1(CigiSymbolCircleDefV4.getCPtr(BaseIn)), true) {
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiSymbolCircleDefV4_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiSymbolCircleDefV4_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override CigiBaseCircleSymbolData AddCircle() {
    global::System.IntPtr cPtr = example_modulePINVOKE.CigiSymbolCircleDefV4_AddCircle(swigCPtr);
    CigiBaseCircleSymbolData ret = (cPtr == global::System.IntPtr.Zero) ? null : new CigiBaseCircleSymbolData(cPtr, false);
    return ret;
  }

  public override int RemoveCircle(int CircleIndex, bool bndchk) {
    int ret = example_modulePINVOKE.CigiSymbolCircleDefV4_RemoveCircle__SWIG_0(swigCPtr, CircleIndex, bndchk);
    return ret;
  }

  public override int RemoveCircle(int CircleIndex) {
    int ret = example_modulePINVOKE.CigiSymbolCircleDefV4_RemoveCircle__SWIG_1(swigCPtr, CircleIndex);
    return ret;
  }

}