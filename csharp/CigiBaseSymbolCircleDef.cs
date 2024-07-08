//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiBaseSymbolCircleDef : CigiBaseVariableSizePckt {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiBaseSymbolCircleDef(global::System.IntPtr cPtr, bool cMemoryOwn) : base(example_modulePINVOKE.CigiBaseSymbolCircleDef_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiBaseSymbolCircleDef obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiBaseSymbolCircleDef obj) {
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
          example_modulePINVOKE.delete_CigiBaseSymbolCircleDef(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiBaseSymbolCircleDef_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiBaseSymbolCircleDef_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int GetTruePacketSize(CigiBaseVariableSizePckt refPacket) {
    int ret = example_modulePINVOKE.CigiBaseSymbolCircleDef_GetTruePacketSize(swigCPtr, CigiBaseVariableSizePckt.getCPtr(refPacket));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public override int GetCnvt(CigiVersionID CnvtVersion, SWIGTYPE_p_CigiCnvtInfoType__Type CnvtInfo) {
    int ret = example_modulePINVOKE.CigiBaseSymbolCircleDef_GetCnvt(swigCPtr, CigiVersionID.getCPtr(CnvtVersion), SWIGTYPE_p_CigiCnvtInfoType__Type.getCPtr(CnvtInfo));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetSymbolID(SWIGTYPE_p_unsigned___int16 SymbolIDIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseSymbolCircleDef_SetSymbolID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(SymbolIDIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetSymbolID(SWIGTYPE_p_unsigned___int16 SymbolIDIn) {
    int ret = example_modulePINVOKE.CigiBaseSymbolCircleDef_SetSymbolID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(SymbolIDIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetSymbolID() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(example_modulePINVOKE.CigiBaseSymbolCircleDef_GetSymbolID(swigCPtr), true);
    return ret;
  }

  public int SetDrawingStyle(CigiBaseSymbolCircleDef.DrawingStyleGrp DrawingStyleIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseSymbolCircleDef_SetDrawingStyle__SWIG_0(swigCPtr, (int)DrawingStyleIn, bndchk);
    return ret;
  }

  public int SetDrawingStyle(CigiBaseSymbolCircleDef.DrawingStyleGrp DrawingStyleIn) {
    int ret = example_modulePINVOKE.CigiBaseSymbolCircleDef_SetDrawingStyle__SWIG_1(swigCPtr, (int)DrawingStyleIn);
    return ret;
  }

  public CigiBaseSymbolCircleDef.DrawingStyleGrp GetDrawingStyle() {
    CigiBaseSymbolCircleDef.DrawingStyleGrp ret = (CigiBaseSymbolCircleDef.DrawingStyleGrp)example_modulePINVOKE.CigiBaseSymbolCircleDef_GetDrawingStyle(swigCPtr);
    return ret;
  }

  public int SetStipplePattern(SWIGTYPE_p_unsigned___int16 StipplePatternIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseSymbolCircleDef_SetStipplePattern__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(StipplePatternIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetStipplePattern(SWIGTYPE_p_unsigned___int16 StipplePatternIn) {
    int ret = example_modulePINVOKE.CigiBaseSymbolCircleDef_SetStipplePattern__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(StipplePatternIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetStipplePattern() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(example_modulePINVOKE.CigiBaseSymbolCircleDef_GetStipplePattern(swigCPtr), true);
    return ret;
  }

  public int SetLineWidth(float LineWidthIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseSymbolCircleDef_SetLineWidth__SWIG_0(swigCPtr, LineWidthIn, bndchk);
    return ret;
  }

  public int SetLineWidth(float LineWidthIn) {
    int ret = example_modulePINVOKE.CigiBaseSymbolCircleDef_SetLineWidth__SWIG_1(swigCPtr, LineWidthIn);
    return ret;
  }

  public float GetLineWidth() {
    float ret = example_modulePINVOKE.CigiBaseSymbolCircleDef_GetLineWidth(swigCPtr);
    return ret;
  }

  public int SetStipplePatternLen(float StipplePatternLenIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseSymbolCircleDef_SetStipplePatternLen__SWIG_0(swigCPtr, StipplePatternLenIn, bndchk);
    return ret;
  }

  public int SetStipplePatternLen(float StipplePatternLenIn) {
    int ret = example_modulePINVOKE.CigiBaseSymbolCircleDef_SetStipplePatternLen__SWIG_1(swigCPtr, StipplePatternLenIn);
    return ret;
  }

  public float GetStipplePatternLen() {
    float ret = example_modulePINVOKE.CigiBaseSymbolCircleDef_GetStipplePatternLen(swigCPtr);
    return ret;
  }

  public int GetCircleCount() {
    int ret = example_modulePINVOKE.CigiBaseSymbolCircleDef_GetCircleCount(swigCPtr);
    return ret;
  }

  public virtual CigiBaseCircleSymbolData AddCircle() {
    global::System.IntPtr cPtr = example_modulePINVOKE.CigiBaseSymbolCircleDef_AddCircle(swigCPtr);
    CigiBaseCircleSymbolData ret = (cPtr == global::System.IntPtr.Zero) ? null : new CigiBaseCircleSymbolData(cPtr, false);
    return ret;
  }

  public virtual int RemoveCircle(int CircleIndex, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseSymbolCircleDef_RemoveCircle__SWIG_0(swigCPtr, CircleIndex, bndchk);
    return ret;
  }

  public virtual int RemoveCircle(int CircleIndex) {
    int ret = example_modulePINVOKE.CigiBaseSymbolCircleDef_RemoveCircle__SWIG_1(swigCPtr, CircleIndex);
    return ret;
  }

  public CigiBaseCircleSymbolData GetCircle(int CircleIndex, bool bndchk) {
    global::System.IntPtr cPtr = example_modulePINVOKE.CigiBaseSymbolCircleDef_GetCircle__SWIG_0(swigCPtr, CircleIndex, bndchk);
    CigiBaseCircleSymbolData ret = (cPtr == global::System.IntPtr.Zero) ? null : new CigiBaseCircleSymbolData(cPtr, false);
    return ret;
  }

  public CigiBaseCircleSymbolData GetCircle(int CircleIndex) {
    global::System.IntPtr cPtr = example_modulePINVOKE.CigiBaseSymbolCircleDef_GetCircle__SWIG_1(swigCPtr, CircleIndex);
    CigiBaseCircleSymbolData ret = (cPtr == global::System.IntPtr.Zero) ? null : new CigiBaseCircleSymbolData(cPtr, false);
    return ret;
  }

  public void ClearCircles() {
    example_modulePINVOKE.CigiBaseSymbolCircleDef_ClearCircles(swigCPtr);
  }

  public enum DrawingStyleGrp {
    Line = 0,
    Fill = 1
  }

}
