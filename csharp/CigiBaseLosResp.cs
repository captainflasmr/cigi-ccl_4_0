//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiBaseLosResp : CigiBasePacket {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiBaseLosResp(global::System.IntPtr cPtr, bool cMemoryOwn) : base(example_modulePINVOKE.CigiBaseLosResp_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiBaseLosResp obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiBaseLosResp obj) {
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
          example_modulePINVOKE.delete_CigiBaseLosResp(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiBaseLosResp_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiBaseLosResp_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public int SetLosID(SWIGTYPE_p_unsigned___int16 LosIDIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseLosResp_SetLosID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(LosIDIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetLosID(SWIGTYPE_p_unsigned___int16 LosIDIn) {
    int ret = example_modulePINVOKE.CigiBaseLosResp_SetLosID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(LosIDIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetLosID() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(example_modulePINVOKE.CigiBaseLosResp_GetLosID(swigCPtr), true);
    return ret;
  }

  public int SetValid(bool ValidIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseLosResp_SetValid__SWIG_0(swigCPtr, ValidIn, bndchk);
    return ret;
  }

  public int SetValid(bool ValidIn) {
    int ret = example_modulePINVOKE.CigiBaseLosResp_SetValid__SWIG_1(swigCPtr, ValidIn);
    return ret;
  }

  public bool GetValid() {
    bool ret = example_modulePINVOKE.CigiBaseLosResp_GetValid(swigCPtr);
    return ret;
  }

  public int SetVisible(bool VisibleIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseLosResp_SetVisible__SWIG_0(swigCPtr, VisibleIn, bndchk);
    return ret;
  }

  public int SetVisible(bool VisibleIn) {
    int ret = example_modulePINVOKE.CigiBaseLosResp_SetVisible__SWIG_1(swigCPtr, VisibleIn);
    return ret;
  }

  public bool GetVisible() {
    bool ret = example_modulePINVOKE.CigiBaseLosResp_GetVisible(swigCPtr);
    return ret;
  }

  public int SetRange(double RangeIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseLosResp_SetRange__SWIG_0(swigCPtr, RangeIn, bndchk);
    return ret;
  }

  public int SetRange(double RangeIn) {
    int ret = example_modulePINVOKE.CigiBaseLosResp_SetRange__SWIG_1(swigCPtr, RangeIn);
    return ret;
  }

  public double GetRange() {
    double ret = example_modulePINVOKE.CigiBaseLosResp_GetRange(swigCPtr);
    return ret;
  }

  public int SetLatitude(double LatitudeIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseLosResp_SetLatitude__SWIG_0(swigCPtr, LatitudeIn, bndchk);
    return ret;
  }

  public int SetLatitude(double LatitudeIn) {
    int ret = example_modulePINVOKE.CigiBaseLosResp_SetLatitude__SWIG_1(swigCPtr, LatitudeIn);
    return ret;
  }

  public double GetLatitude() {
    double ret = example_modulePINVOKE.CigiBaseLosResp_GetLatitude(swigCPtr);
    return ret;
  }

  public int SetLongitude(double LongitudeIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseLosResp_SetLongitude__SWIG_0(swigCPtr, LongitudeIn, bndchk);
    return ret;
  }

  public int SetLongitude(double LongitudeIn) {
    int ret = example_modulePINVOKE.CigiBaseLosResp_SetLongitude__SWIG_1(swigCPtr, LongitudeIn);
    return ret;
  }

  public double GetLongitude() {
    double ret = example_modulePINVOKE.CigiBaseLosResp_GetLongitude(swigCPtr);
    return ret;
  }

  public int SetAltitude(double AltitudeIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseLosResp_SetAltitude__SWIG_0(swigCPtr, AltitudeIn, bndchk);
    return ret;
  }

  public int SetAltitude(double AltitudeIn) {
    int ret = example_modulePINVOKE.CigiBaseLosResp_SetAltitude__SWIG_1(swigCPtr, AltitudeIn);
    return ret;
  }

  public double GetAltitude() {
    double ret = example_modulePINVOKE.CigiBaseLosResp_GetAltitude(swigCPtr);
    return ret;
  }

  public bool GetValidV1or2() {
    bool ret = example_modulePINVOKE.CigiBaseLosResp_GetValidV1or2(swigCPtr);
    return ret;
  }

  public enum LOSCoordGrp {
    Geodetic = 0,
    Entity = 1
  }

}