//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class CigiOutgoingMsg : CigiMessage {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal CigiOutgoingMsg(global::System.IntPtr cPtr, bool cMemoryOwn) : base(example_modulePINVOKE.CigiOutgoingMsg_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(CigiOutgoingMsg obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(CigiOutgoingMsg obj) {
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
          example_modulePINVOKE.delete_CigiOutgoingMsg(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public CigiOutgoingMsg() : this(example_modulePINVOKE.new_CigiOutgoingMsg(), true) {
  }

  public CigiOutgoingMsg pack(CigiBaseIGCtrl refPacket) {
    CigiOutgoingMsg ret = new CigiOutgoingMsg(example_modulePINVOKE.CigiOutgoingMsg_pack__SWIG_0(swigCPtr, CigiBaseIGCtrl.getCPtr(refPacket)), false);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public CigiOutgoingMsg pack(CigiBaseSOF refPacket) {
    CigiOutgoingMsg ret = new CigiOutgoingMsg(example_modulePINVOKE.CigiOutgoingMsg_pack__SWIG_1(swigCPtr, CigiBaseSOF.getCPtr(refPacket)), false);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public CigiOutgoingMsg pack(CigiBaseEntityCtrl refPacket) {
    CigiOutgoingMsg ret = new CigiOutgoingMsg(example_modulePINVOKE.CigiOutgoingMsg_pack__SWIG_2(swigCPtr, CigiBaseEntityCtrl.getCPtr(refPacket)), false);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public CigiOutgoingMsg pack(CigiBaseEnvCtrl refPacket) {
    CigiOutgoingMsg ret = new CigiOutgoingMsg(example_modulePINVOKE.CigiOutgoingMsg_pack__SWIG_3(swigCPtr, CigiBaseEnvCtrl.getCPtr(refPacket)), false);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public CigiOutgoingMsg pack(CigiBaseVariableSizePckt refPacket) {
    CigiOutgoingMsg ret = new CigiOutgoingMsg(example_modulePINVOKE.CigiOutgoingMsg_pack__SWIG_4(swigCPtr, CigiBaseVariableSizePckt.getCPtr(refPacket)), false);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public CigiOutgoingMsg pack(CigiBasePacket refBasePacket) {
    CigiOutgoingMsg ret = new CigiOutgoingMsg(example_modulePINVOKE.CigiOutgoingMsg_pack__SWIG_5(swigCPtr, CigiBasePacket.getCPtr(refBasePacket)), false);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int BeginMsg() {
    int ret = example_modulePINVOKE.CigiOutgoingMsg_BeginMsg(swigCPtr);
    return ret;
  }

  public int UpdateFrameCntr() {
    int ret = example_modulePINVOKE.CigiOutgoingMsg_UpdateFrameCntr__SWIG_0(swigCPtr);
    return ret;
  }

  public int UpdateFrameCntr(SWIGTYPE_p_unsigned___int8 OutgoingMsg, SWIGTYPE_p_unsigned___int8 IncomingMsg) {
    int ret = example_modulePINVOKE.CigiOutgoingMsg_UpdateFrameCntr__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(OutgoingMsg), SWIGTYPE_p_unsigned___int8.getCPtr(IncomingMsg));
    return ret;
  }

  public int UpdateFrameCntr(SWIGTYPE_p_unsigned___int8 OutgoingMsg) {
    int ret = example_modulePINVOKE.CigiOutgoingMsg_UpdateFrameCntr__SWIG_2(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(OutgoingMsg));
    return ret;
  }

  public int UpdateIGCtrl(SWIGTYPE_p_unsigned___int8 OutgoingMsg, SWIGTYPE_p_unsigned___int8 IncomingMsg) {
    int ret = example_modulePINVOKE.CigiOutgoingMsg_UpdateIGCtrl(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(OutgoingMsg), SWIGTYPE_p_unsigned___int8.getCPtr(IncomingMsg));
    return ret;
  }

  public int UpdateSOF(SWIGTYPE_p_unsigned___int8 OutgoingMsg, SWIGTYPE_p_unsigned___int8 IncomingMsg) {
    int ret = example_modulePINVOKE.CigiOutgoingMsg_UpdateSOF__SWIG_0(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(OutgoingMsg), SWIGTYPE_p_unsigned___int8.getCPtr(IncomingMsg));
    return ret;
  }

  public int UpdateSOF(SWIGTYPE_p_unsigned___int8 OutgoingMsg) {
    int ret = example_modulePINVOKE.CigiOutgoingMsg_UpdateSOF__SWIG_1(swigCPtr, SWIGTYPE_p_unsigned___int8.getCPtr(OutgoingMsg));
    return ret;
  }

  public int LockMsg() {
    int ret = example_modulePINVOKE.CigiOutgoingMsg_LockMsg(swigCPtr);
    return ret;
  }

  public SWIGTYPE_p_unsigned___int8 GetMsg(SWIGTYPE_p_int length) {
    global::System.IntPtr cPtr = example_modulePINVOKE.CigiOutgoingMsg_GetMsg(swigCPtr, SWIGTYPE_p_int.getCPtr(length));
    SWIGTYPE_p_unsigned___int8 ret = (cPtr == global::System.IntPtr.Zero) ? null : new SWIGTYPE_p_unsigned___int8(cPtr, false);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_unsigned___int8 GetBuffer() {
    global::System.IntPtr cPtr = example_modulePINVOKE.CigiOutgoingMsg_GetBuffer(swigCPtr);
    SWIGTYPE_p_unsigned___int8 ret = (cPtr == global::System.IntPtr.Zero) ? null : new SWIGTYPE_p_unsigned___int8(cPtr, false);
    return ret;
  }

  public int GetMsgLength() {
    int ret = example_modulePINVOKE.CigiOutgoingMsg_GetMsgLength(swigCPtr);
    return ret;
  }

  public SWIGTYPE_p_std__string GetBufferString() {
    SWIGTYPE_p_std__string ret = new SWIGTYPE_p_std__string(example_modulePINVOKE.CigiOutgoingMsg_GetBufferString(swigCPtr), true);
    return ret;
  }

  public int UnlockMsg() {
    int ret = example_modulePINVOKE.CigiOutgoingMsg_UnlockMsg(swigCPtr);
    return ret;
  }

  public int PackageMsg(SWIGTYPE_p_p_unsigned___int8 Msg, SWIGTYPE_p_int length) {
    int ret = example_modulePINVOKE.CigiOutgoingMsg_PackageMsg(swigCPtr, SWIGTYPE_p_p_unsigned___int8.getCPtr(Msg), SWIGTYPE_p_int.getCPtr(length));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int GetCurrentlyPackagedMsg(SWIGTYPE_p_p_unsigned___int8 Msg, SWIGTYPE_p_int length) {
    int ret = example_modulePINVOKE.CigiOutgoingMsg_GetCurrentlyPackagedMsg(swigCPtr, SWIGTYPE_p_p_unsigned___int8.getCPtr(Msg), SWIGTYPE_p_int.getCPtr(length));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int FreeMsg() {
    int ret = example_modulePINVOKE.CigiOutgoingMsg_FreeMsg(swigCPtr);
    return ret;
  }

  public void SetFrameCnt(SWIGTYPE_p_unsigned___int32 FrameCntIn) {
    example_modulePINVOKE.CigiOutgoingMsg_SetFrameCnt(swigCPtr, SWIGTYPE_p_unsigned___int32.getCPtr(FrameCntIn));
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
  }

  public SWIGTYPE_p_unsigned___int32 GetFrameCnt() {
    SWIGTYPE_p_unsigned___int32 ret = new SWIGTYPE_p_unsigned___int32(example_modulePINVOKE.CigiOutgoingMsg_GetFrameCnt(swigCPtr), true);
    return ret;
  }

  public void SetSynchronous(bool Sync) {
    example_modulePINVOKE.CigiOutgoingMsg_SetSynchronous(swigCPtr, Sync);
  }

  public bool IsSynchronous() {
    bool ret = example_modulePINVOKE.CigiOutgoingMsg_IsSynchronous(swigCPtr);
    return ret;
  }

  public override int RegisterUserPacket(CigiBasePacket Packet, SWIGTYPE_p_unsigned___int16 PacketID, bool HostSend, bool IGSend) {
    int ret = example_modulePINVOKE.CigiOutgoingMsg_RegisterUserPacket(swigCPtr, CigiBasePacket.getCPtr(Packet), SWIGTYPE_p_unsigned___int16.getCPtr(PacketID), HostSend, IGSend);
    if (example_modulePINVOKE.SWIGPendingException.Pending) throw example_modulePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

}
