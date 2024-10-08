//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiVertexSymbolTextureDataV4 : CigiBaseVertexSymbolData {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiVertexSymbolTextureDataV4(global::System.IntPtr cPtr, bool cMemoryOwn) : base(ccl_dllDPINVOKE.CigiVertexSymbolTextureDataV4_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiVertexSymbolTextureDataV4 obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiVertexSymbolTextureDataV4 obj) {
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
          ccl_dllDPINVOKE.delete_CigiVertexSymbolTextureDataV4(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public CigiVertexSymbolTextureDataV4() : this(ccl_dllDPINVOKE.new_CigiVertexSymbolTextureDataV4(), true) {
  }

  public override int Pack(CigiBaseVertexSymbolData Base, SWIGTYPE_p_unsigned___int8 Buff) {
    int ret = ccl_dllDPINVOKE.CigiVertexSymbolTextureDataV4_Pack(swigCPtr, CigiBaseVertexSymbolData.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap) {
    int ret = ccl_dllDPINVOKE.CigiVertexSymbolTextureDataV4_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap);
    return ret;
  }

  public int SetSTexCoord(float STexCoordIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiVertexSymbolTextureDataV4_SetSTexCoord__SWIG_0(swigCPtr, STexCoordIn, bndchk);
    return ret;
  }

  public int SetSTexCoord(float STexCoordIn) {
    int ret = ccl_dllDPINVOKE.CigiVertexSymbolTextureDataV4_SetSTexCoord__SWIG_1(swigCPtr, STexCoordIn);
    return ret;
  }

  public float GetSTexCoord() {
    float ret = ccl_dllDPINVOKE.CigiVertexSymbolTextureDataV4_GetSTexCoord(swigCPtr);
    return ret;
  }

  public int SetTTexCoord(float TTexCoordIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiVertexSymbolTextureDataV4_SetTTexCoord__SWIG_0(swigCPtr, TTexCoordIn, bndchk);
    return ret;
  }

  public int SetTTexCoord(float TTexCoordIn) {
    int ret = ccl_dllDPINVOKE.CigiVertexSymbolTextureDataV4_SetTTexCoord__SWIG_1(swigCPtr, TTexCoordIn);
    return ret;
  }

  public float GetTTexCoord() {
    float ret = ccl_dllDPINVOKE.CigiVertexSymbolTextureDataV4_GetTTexCoord(swigCPtr);
    return ret;
  }

}
