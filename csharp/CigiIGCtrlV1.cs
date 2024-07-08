//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiIGCtrlV1 : CigiBaseIGCtrl {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiIGCtrlV1(global::System.IntPtr cPtr, bool cMemoryOwn) : base(example_modulePINVOKE.CigiIGCtrlV1_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiIGCtrlV1 obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiIGCtrlV1 obj) {
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
          example_modulePINVOKE.delete_CigiIGCtrlV1(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public CigiIGCtrlV1() : this(example_modulePINVOKE.new_CigiIGCtrlV1(), true) {
  }

  public override int Pack(CigiBasePacket Base, SWIGTYPE_p_unsigned___int8 Buff, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiIGCtrlV1_Pack(swigCPtr, CigiBasePacket.getCPtr(Base), SWIGTYPE_p_unsigned___int8.getCPtr(Buff), SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public override int Unpack(SWIGTYPE_p_unsigned___int8 Buff, bool Swap, SWIGTYPE_p_void Spec) {
    int ret = example_modulePINVOKE.CigiIGCtrlV1_Unpack(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(Buff), Swap, SWIGTYPE_p_void.getCPtr(Spec));
    return ret;
  }

  public int SetFrameCntr(SWIGTYPE_p_unsigned___int32 FrameCntrIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiIGCtrlV1_SetFrameCntr__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int32.getCPtr(FrameCntrIn), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetFrameCntr(SWIGTYPE_p_unsigned___int32 FrameCntrIn) {
    int ret = example_modulePINVOKE.CigiIGCtrlV1_SetFrameCntr__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int32.getCPtr(FrameCntrIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int32 GetTimeStamp() {
    SWIGTYPE_p_unsigned___int32 ret = new SWIGTYPE_p_unsigned___int32(example_modulePINVOKE.CigiIGCtrlV1_GetTimeStamp(swigCPtr), true);
    return ret;
  }

  public int SetTimeStamp(SWIGTYPE_p_unsigned___int32 TimeStamp, bool bndchk) {
    int ret = example_modulePINVOKE.CigiIGCtrlV1_SetTimeStamp__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int32.getCPtr(TimeStamp), bndchk);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int SetTimeStamp(SWIGTYPE_p_unsigned___int32 TimeStamp) {
    int ret = example_modulePINVOKE.CigiIGCtrlV1_SetTimeStamp__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int32.getCPtr(TimeStamp));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public CigiBaseIGCtrl.TrackDeviceEnGrp GetTrackDeviceEn() {
    CigiBaseIGCtrl.TrackDeviceEnGrp ret = (CigiBaseIGCtrl.TrackDeviceEnGrp)example_modulePINVOKE.CigiIGCtrlV1_GetTrackDeviceEn(swigCPtr);
    return ret;
  }

  public int SetTrackDeviceEn(CigiBaseIGCtrl.TrackDeviceEnGrp TrackDeviceEnIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiIGCtrlV1_SetTrackDeviceEn__SWIG_0(swigCPtr, (int)TrackDeviceEnIn, bndchk);
    return ret;
  }

  public int SetTrackDeviceEn(CigiBaseIGCtrl.TrackDeviceEnGrp TrackDeviceEnIn) {
    int ret = example_modulePINVOKE.CigiIGCtrlV1_SetTrackDeviceEn__SWIG_1(swigCPtr, (int)TrackDeviceEnIn);
    return ret;
  }

  public bool GetBoresightTrackDevice() {
    bool ret = example_modulePINVOKE.CigiIGCtrlV1_GetBoresightTrackDevice(swigCPtr);
    return ret;
  }

  public int SetBoresightTrackDevice(bool BoresightTrackDeviceIn, bool bndchk) {
    int ret = example_modulePINVOKE.CigiIGCtrlV1_SetBoresightTrackDevice__SWIG_0(swigCPtr, BoresightTrackDeviceIn, bndchk);
    return ret;
  }

  public int SetBoresightTrackDevice(bool BoresightTrackDeviceIn) {
    int ret = example_modulePINVOKE.CigiIGCtrlV1_SetBoresightTrackDevice__SWIG_1(swigCPtr, BoresightTrackDeviceIn);
    return ret;
  }

}
