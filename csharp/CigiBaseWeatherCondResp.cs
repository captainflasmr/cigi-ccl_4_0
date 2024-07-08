//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiBaseWeatherCondResp : CigiBasePacket {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiBaseWeatherCondResp(global::System.IntPtr cPtr, bool cMemoryOwn) : base(example_modulePINVOKE.CigiBaseWeatherCondResp_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiBaseWeatherCondResp obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiBaseWeatherCondResp obj) {
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
          example_modulePINVOKE.delete_CigiBaseWeatherCondResp(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCondResp_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCondResp_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int GetCnvt(CigiVersionID CnvtVersion, SWIGTYPE_p_CigiCnvtInfoType__Type CnvtInfo) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCondResp_GetCnvt(swigCPtr, CigiVersionID.getCPtr(CnvtVersion), SWIGTYPE_p_CigiCnvtInfoType__Type.getCPtr(CnvtInfo));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetRequestID(SWIGTYPE_p_unsigned___int8 RequestIDIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCondResp_SetRequestID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(RequestIDIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetRequestID(SWIGTYPE_p_unsigned___int8 RequestIDIn) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCondResp_SetRequestID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(RequestIDIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int8 GetRequestID() {
    SWIGTYPE_p_unsigned___int8 ret = new SWIGTYPE_p_unsigned___int8(example_modulePINVOKE.CigiBaseWeatherCondResp_GetRequestID(swigCPtr), true);
    return ret;
  }

  public int SetHumidity(SWIGTYPE_p_unsigned___int8 HumidityIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCondResp_SetHumidity__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(HumidityIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetHumidity(SWIGTYPE_p_unsigned___int8 HumidityIn) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCondResp_SetHumidity__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(HumidityIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int8 GetHumidity() {
    SWIGTYPE_p_unsigned___int8 ret = new SWIGTYPE_p_unsigned___int8(example_modulePINVOKE.CigiBaseWeatherCondResp_GetHumidity(swigCPtr), true);
    return ret;
  }

  public int SetAirTemp(float AirTempIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCondResp_SetAirTemp__SWIG_0(swigCPtr, AirTempIn, bndchk);
    return ret;
  }

  public int SetAirTemp(float AirTempIn) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCondResp_SetAirTemp__SWIG_1(swigCPtr, AirTempIn);
    return ret;
  }

  public float GetAirTemp() {
    float ret = example_modulePINVOKE.CigiBaseWeatherCondResp_GetAirTemp(swigCPtr);
    return ret;
  }

  public int SetVisibility(float VisibilityIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCondResp_SetVisibility__SWIG_0(swigCPtr, VisibilityIn, bndchk);
    return ret;
  }

  public int SetVisibility(float VisibilityIn) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCondResp_SetVisibility__SWIG_1(swigCPtr, VisibilityIn);
    return ret;
  }

  public float GetVisibility() {
    float ret = example_modulePINVOKE.CigiBaseWeatherCondResp_GetVisibility(swigCPtr);
    return ret;
  }

  public int SetHorizWindSp(float HorizWindSpIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCondResp_SetHorizWindSp__SWIG_0(swigCPtr, HorizWindSpIn, bndchk);
    return ret;
  }

  public int SetHorizWindSp(float HorizWindSpIn) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCondResp_SetHorizWindSp__SWIG_1(swigCPtr, HorizWindSpIn);
    return ret;
  }

  public float GetHorizWindSp() {
    float ret = example_modulePINVOKE.CigiBaseWeatherCondResp_GetHorizWindSp(swigCPtr);
    return ret;
  }

  public int SetVertWindSp(float VertWindSpIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCondResp_SetVertWindSp__SWIG_0(swigCPtr, VertWindSpIn, bndchk);
    return ret;
  }

  public int SetVertWindSp(float VertWindSpIn) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCondResp_SetVertWindSp__SWIG_1(swigCPtr, VertWindSpIn);
    return ret;
  }

  public float GetVertWindSp() {
    float ret = example_modulePINVOKE.CigiBaseWeatherCondResp_GetVertWindSp(swigCPtr);
    return ret;
  }

  public int SetWindDir(float WindDirIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCondResp_SetWindDir__SWIG_0(swigCPtr, WindDirIn, bndchk);
    return ret;
  }

  public int SetWindDir(float WindDirIn) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCondResp_SetWindDir__SWIG_1(swigCPtr, WindDirIn);
    return ret;
  }

  public float GetWindDir() {
    float ret = example_modulePINVOKE.CigiBaseWeatherCondResp_GetWindDir(swigCPtr);
    return ret;
  }

  public int SetBaroPress(float BaroPressIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCondResp_SetBaroPress__SWIG_0(swigCPtr, BaroPressIn, bndchk);
    return ret;
  }

  public int SetBaroPress(float BaroPressIn) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCondResp_SetBaroPress__SWIG_1(swigCPtr, BaroPressIn);
    return ret;
  }

  public float GetBaroPress() {
    float ret = example_modulePINVOKE.CigiBaseWeatherCondResp_GetBaroPress(swigCPtr);
    return ret;
  }

}