//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiVertexSymbolDataV3_3 : CigiBaseVertexSymbolData {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiVertexSymbolDataV3_3(global::System.IntPtr cPtr, bool cMemoryOwn) : base(example_modulePINVOKE.CigiVertexSymbolDataV3_3_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiVertexSymbolDataV3_3 obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiVertexSymbolDataV3_3 obj) {
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
          example_modulePINVOKE.delete_CigiVertexSymbolDataV3_3(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public CigiVertexSymbolDataV3_3() : this(example_modulePINVOKE.new_CigiVertexSymbolDataV3_3(), true) {
  }

  public override int Pack(CigiBaseVertexSymbolData Base, SWIGTYPE_p_unsigned___int8 Buff) {
    int ret = example_modulePINVOKE.CigiVertexSymbolDataV3_3_Pack(swigCPtr, CigiBaseVertexSymbolData.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap) {
    int ret = example_modulePINVOKE.CigiVertexSymbolDataV3_3_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap);
    return ret;
  }

}
