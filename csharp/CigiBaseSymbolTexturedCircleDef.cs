//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiBaseSymbolTexturedCircleDef : CigiBaseVariableSizePckt {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiBaseSymbolTexturedCircleDef(global::System.IntPtr cPtr, bool cMemoryOwn) : base(ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiBaseSymbolTexturedCircleDef obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiBaseSymbolTexturedCircleDef obj) {
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
          ccl_dllDPINVOKE.delete_CigiBaseSymbolTexturedCircleDef(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int GetTruePacketSize(CigiBaseVariableSizePckt refPacket) {
    int ret = ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_GetTruePacketSize(swigCPtr, CigiBaseVariableSizePckt.getCPtr(refPacket));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public override int GetCnvt(CigiVersionID CnvtVersion, SWIGTYPE_p_CigiCnvtInfoType__Type CnvtInfo) {
    int ret = ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_GetCnvt(swigCPtr, CigiVersionID.getCPtr(CnvtVersion), SWIGTYPE_p_CigiCnvtInfoType__Type.getCPtr(CnvtInfo));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetSymbolID(SWIGTYPE_p_unsigned___int16 SymbolIDIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_SetSymbolID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(SymbolIDIn), bndchk);
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetSymbolID(SWIGTYPE_p_unsigned___int16 SymbolIDIn) {
    int ret = ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_SetSymbolID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(SymbolIDIn));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetSymbolID() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_GetSymbolID(swigCPtr), true);
    return ret;
  }

  public int SetTextureID(SWIGTYPE_p_unsigned___int16 TextureIDIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_SetTextureID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(TextureIDIn), bndchk);
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetTextureID(SWIGTYPE_p_unsigned___int16 TextureIDIn) {
    int ret = ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_SetTextureID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(TextureIDIn));
    if (ccl_dllDPINVOKE.SWIGPendingException.Pending) throw ccl_dllDPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetTextureID() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_GetTextureID(swigCPtr), true);
    return ret;
  }

  public int SetTextureFilter(CigiBaseSymbolTexturedCircleDef.TextureFilterMode TextureFilterIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_SetTextureFilter__SWIG_0(swigCPtr, (int)TextureFilterIn, bndchk);
    return ret;
  }

  public int SetTextureFilter(CigiBaseSymbolTexturedCircleDef.TextureFilterMode TextureFilterIn) {
    int ret = ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_SetTextureFilter__SWIG_1(swigCPtr, (int)TextureFilterIn);
    return ret;
  }

  public CigiBaseSymbolTexturedCircleDef.TextureFilterMode GetTextureFilter() {
    CigiBaseSymbolTexturedCircleDef.TextureFilterMode ret = (CigiBaseSymbolTexturedCircleDef.TextureFilterMode)ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_GetTextureFilter(swigCPtr);
    return ret;
  }

  public int SetTextureWrap(CigiBaseSymbolTexturedCircleDef.TextureWrapMode TextureWrapIn, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_SetTextureWrap__SWIG_0(swigCPtr, (int)TextureWrapIn, bndchk);
    return ret;
  }

  public int SetTextureWrap(CigiBaseSymbolTexturedCircleDef.TextureWrapMode TextureWrapIn) {
    int ret = ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_SetTextureWrap__SWIG_1(swigCPtr, (int)TextureWrapIn);
    return ret;
  }

  public CigiBaseSymbolTexturedCircleDef.TextureWrapMode GetTextureWrap() {
    CigiBaseSymbolTexturedCircleDef.TextureWrapMode ret = (CigiBaseSymbolTexturedCircleDef.TextureWrapMode)ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_GetTextureWrap(swigCPtr);
    return ret;
  }

  public int GetCircleCount() {
    int ret = ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_GetCircleCount(swigCPtr);
    return ret;
  }

  public virtual CigiBaseCircleSymbolTextureData AddCircle() {
    global::System.IntPtr cPtr = ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_AddCircle(swigCPtr);
    CigiBaseCircleSymbolTextureData ret = (cPtr == global::System.IntPtr.Zero) ? null : new CigiBaseCircleSymbolTextureData(cPtr, false);
    return ret;
  }

  public virtual int RemoveCircle(int CircleIndex, bool bndchk) {
    int ret = ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_RemoveCircle__SWIG_0(swigCPtr, CircleIndex, bndchk);
    return ret;
  }

  public virtual int RemoveCircle(int CircleIndex) {
    int ret = ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_RemoveCircle__SWIG_1(swigCPtr, CircleIndex);
    return ret;
  }

  public CigiBaseCircleSymbolTextureData GetCircle(int CircleIndex, bool bndchk) {
    global::System.IntPtr cPtr = ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_GetCircle__SWIG_0(swigCPtr, CircleIndex, bndchk);
    CigiBaseCircleSymbolTextureData ret = (cPtr == global::System.IntPtr.Zero) ? null : new CigiBaseCircleSymbolTextureData(cPtr, false);
    return ret;
  }

  public CigiBaseCircleSymbolTextureData GetCircle(int CircleIndex) {
    global::System.IntPtr cPtr = ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_GetCircle__SWIG_1(swigCPtr, CircleIndex);
    CigiBaseCircleSymbolTextureData ret = (cPtr == global::System.IntPtr.Zero) ? null : new CigiBaseCircleSymbolTextureData(cPtr, false);
    return ret;
  }

  public void ClearCircles() {
    ccl_dllDPINVOKE.CigiBaseSymbolTexturedCircleDef_ClearCircles(swigCPtr);
  }

  public enum TextureFilterMode {
    Nearest = 0,
    Linear = 1
  }

  public enum TextureWrapMode {
    Repeat = 0,
    Clamp = 1
  }

}
