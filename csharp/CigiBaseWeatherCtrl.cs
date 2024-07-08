//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiBaseWeatherCtrl : CigiBasePacket {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiBaseWeatherCtrl(global::System.IntPtr cPtr, bool cMemoryOwn) : base(example_modulePINVOKE.CigiBaseWeatherCtrl_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiBaseWeatherCtrl obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiBaseWeatherCtrl obj) {
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
          example_modulePINVOKE.delete_CigiBaseWeatherCtrl(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int GetCnvt(CigiVersionID CnvtVersion, SWIGTYPE_p_CigiCnvtInfoType__Type CnvtInfo) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_GetCnvt(swigCPtr, CigiVersionID.getCPtr(CnvtVersion), SWIGTYPE_p_CigiCnvtInfoType__Type.getCPtr(CnvtInfo));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetEntityID(SWIGTYPE_p_unsigned___int16 EntityIDIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetEntityID__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(EntityIDIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetEntityID(SWIGTYPE_p_unsigned___int16 EntityIDIn) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetEntityID__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int16.getCPtr(EntityIDIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int16 GetEntityID() {
    SWIGTYPE_p_unsigned___int16 ret = new SWIGTYPE_p_unsigned___int16(example_modulePINVOKE.CigiBaseWeatherCtrl_GetEntityID(swigCPtr), true);
    return ret;
  }

  public int SetWeatherEn(bool WeatherEnIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetWeatherEn__SWIG_0(swigCPtr, WeatherEnIn, bndchk);
    return ret;
  }

  public int SetWeatherEn(bool WeatherEnIn) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetWeatherEn__SWIG_1(swigCPtr, WeatherEnIn);
    return ret;
  }

  public bool GetWeatherEn() {
    bool ret = example_modulePINVOKE.CigiBaseWeatherCtrl_GetWeatherEn(swigCPtr);
    return ret;
  }

  public int SetScudEn(bool ScudEnIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetScudEn__SWIG_0(swigCPtr, ScudEnIn, bndchk);
    return ret;
  }

  public int SetScudEn(bool ScudEnIn) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetScudEn__SWIG_1(swigCPtr, ScudEnIn);
    return ret;
  }

  public bool GetScudEn() {
    bool ret = example_modulePINVOKE.CigiBaseWeatherCtrl_GetScudEn(swigCPtr);
    return ret;
  }

  public int SetRandomWindsEn(bool RandomWindsEnIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetRandomWindsEn__SWIG_0(swigCPtr, RandomWindsEnIn, bndchk);
    return ret;
  }

  public int SetRandomWindsEn(bool RandomWindsEnIn) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetRandomWindsEn__SWIG_1(swigCPtr, RandomWindsEnIn);
    return ret;
  }

  public bool GetRandomWindsEn() {
    bool ret = example_modulePINVOKE.CigiBaseWeatherCtrl_GetRandomWindsEn(swigCPtr);
    return ret;
  }

  public int SetSeverity(SWIGTYPE_p_unsigned___int8 SeverityIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetSeverity__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(SeverityIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetSeverity(SWIGTYPE_p_unsigned___int8 SeverityIn) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetSeverity__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(SeverityIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int8 GetSeverity() {
    SWIGTYPE_p_unsigned___int8 ret = new SWIGTYPE_p_unsigned___int8(example_modulePINVOKE.CigiBaseWeatherCtrl_GetSeverity(swigCPtr), true);
    return ret;
  }

  public int SetAirTemp(float AirTempIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetAirTemp__SWIG_0(swigCPtr, AirTempIn, bndchk);
    return ret;
  }

  public int SetAirTemp(float AirTempIn) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetAirTemp__SWIG_1(swigCPtr, AirTempIn);
    return ret;
  }

  public float GetAirTemp() {
    float ret = example_modulePINVOKE.CigiBaseWeatherCtrl_GetAirTemp(swigCPtr);
    return ret;
  }

  public int SetVisibilityRng(float VisibilityRngIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetVisibilityRng__SWIG_0(swigCPtr, VisibilityRngIn, bndchk);
    return ret;
  }

  public int SetVisibilityRng(float VisibilityRngIn) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetVisibilityRng__SWIG_1(swigCPtr, VisibilityRngIn);
    return ret;
  }

  public float GetVisibilityRng() {
    float ret = example_modulePINVOKE.CigiBaseWeatherCtrl_GetVisibilityRng(swigCPtr);
    return ret;
  }

  public int SetScudFreq(float ScudFreqIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetScudFreq__SWIG_0(swigCPtr, ScudFreqIn, bndchk);
    return ret;
  }

  public int SetScudFreq(float ScudFreqIn) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetScudFreq__SWIG_1(swigCPtr, ScudFreqIn);
    return ret;
  }

  public float GetScudFreq() {
    float ret = example_modulePINVOKE.CigiBaseWeatherCtrl_GetScudFreq(swigCPtr);
    return ret;
  }

  public int SetCoverage(float CoverageIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetCoverage__SWIG_0(swigCPtr, CoverageIn, bndchk);
    return ret;
  }

  public int SetCoverage(float CoverageIn) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetCoverage__SWIG_1(swigCPtr, CoverageIn);
    return ret;
  }

  public float GetCoverage() {
    float ret = example_modulePINVOKE.CigiBaseWeatherCtrl_GetCoverage(swigCPtr);
    return ret;
  }

  public int SetBaseElev(float BaseElevIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetBaseElev__SWIG_0(swigCPtr, BaseElevIn, bndchk);
    return ret;
  }

  public int SetBaseElev(float BaseElevIn) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetBaseElev__SWIG_1(swigCPtr, BaseElevIn);
    return ret;
  }

  public float GetBaseElev() {
    float ret = example_modulePINVOKE.CigiBaseWeatherCtrl_GetBaseElev(swigCPtr);
    return ret;
  }

  public int SetThickness(float ThicknessIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetThickness__SWIG_0(swigCPtr, ThicknessIn, bndchk);
    return ret;
  }

  public int SetThickness(float ThicknessIn) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetThickness__SWIG_1(swigCPtr, ThicknessIn);
    return ret;
  }

  public float GetThickness() {
    float ret = example_modulePINVOKE.CigiBaseWeatherCtrl_GetThickness(swigCPtr);
    return ret;
  }

  public int SetTransition(float TransitionIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetTransition__SWIG_0(swigCPtr, TransitionIn, bndchk);
    return ret;
  }

  public int SetTransition(float TransitionIn) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetTransition__SWIG_1(swigCPtr, TransitionIn);
    return ret;
  }

  public float GetTransition() {
    float ret = example_modulePINVOKE.CigiBaseWeatherCtrl_GetTransition(swigCPtr);
    return ret;
  }

  public int SetHorizWindSp(float HorizWindSpIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetHorizWindSp__SWIG_0(swigCPtr, HorizWindSpIn, bndchk);
    return ret;
  }

  public int SetHorizWindSp(float HorizWindSpIn) {
    int ret = example_modulePINVOKE.CigiBaseWeatherCtrl_SetHorizWindSp__SWIG_1(swigCPtr, HorizWindSpIn);
    return ret;
  }

  public float GetHorizWindSp() {
    float ret = example_modulePINVOKE.CigiBaseWeatherCtrl_GetHorizWindSp(swigCPtr);
    return ret;
  }

  public enum CloudTypeGrp {
    None = 0,
    Altocumulus = 1,
    Altostratus = 2,
    Cirrocumulus = 3,
    Cirrostratus = 4,
    Cirrus = 5,
    Cumulonimbus = 6,
    Cumulus = 7,
    Nimbostratus = 8,
    Stratocumulus = 9,
    Stratus = 10,
    DefA = 11,
    DefB = 12,
    DefC = 13,
    DefD = 14,
    DefE = 15
  }

  public enum ScopeGrp {
    Global = 0,
    Regional = 1,
    Entity = 2
  }

  public enum LayerIDGrp {
    GroundFog = 0,
    CloudLayer1 = 1,
    CloudLayer2 = 2,
    CloudLayer3 = 3,
    Rain = 4,
    Snow = 5,
    Sleet = 6,
    Hail = 7,
    Sand = 8,
    Dust = 9
  }

}
