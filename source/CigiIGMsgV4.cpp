/** <pre>
 *  The SDK is used to create and format CIGI compliant messages.
 *  Copyright (c) 2001-2005 The Boeing Company
 *  
 *  This library is free software; you can redistribute it and/or modify it 
 *  under the terms of the GNU Lesser General Public License as published by 
 *  the Free Software Foundation; either version 2.1 of the License, or (at 
 *  your option) any later version.
 *  
 *  This library is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 *  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser Public License for more 
 *  details.
 *  
 *  You should have received a copy of the GNU Lesser General Public License 
 *  along with this library; if not, write to the Free Software Foundation, 
 *  Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *  
 *  FILENAME:   CigiIGMsgV4.cpp
 *  LANGUAGE:   C++
 *  CLASS:      UNCLASSIFIED
 *  PROJECT:    Common Image Generator Interface (CIGI) SDK
 *  
 *  PROGRAM DESCRIPTION: 
 *  ...
 *  
 *  MODIFICATION NOTES:
 *  DATE     NAME                                SCR NUMBER
 *  DESCRIPTION OF CHANGE........................
 *  
 *  09/17/2003 Greg Basler                       CIGI_CR_DR_1
 *  Initial Release.
 *  
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Defined _EXPORT_CCL_ for exporting the class in a Windows DLL.
 *  
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Removed the inline defnitions for the PackedPointer union.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Modified the class constructor to initialize the MinorVersion member 
 *  variable.
 *  
 *  06/23/2006 Greg Basler                       Version 1.7.1
 *  Changed native char and unsigned char types to CIGI types Cigi_int8 and 
 *  Cigi_uint8.
 *  
 *  11/20/2007 Greg Basler                       Version 2.0.0
 *  Corrected a few initialization and message setting problems.
 *  Added Variable length packet processing
 *  
 *  07/29/2015 Chas Whitley                      Version 4.0.0
 *  Initial Release for CIGI 4.0 compatibility.
 *  Based on CigiIGMsgV3.cpp
 *  
 *  01/02/2019 Paul Slade                      Version 4.0.2
 *  Switched to using STL vector for Msg. 
 *  Version conversion fixes.
 *  
 *  
 * </pre>
 *  Author: The Boeing Company
 *
 */

#define _EXPORT_CCL_

#include "CigiIGMsgV4.h"
#include "CigiSwapping.h"
#include "CigiExceptions.h"
#include <algorithm>


// ====================================================================
// Construction/Destruction
// ====================================================================


// ================================================
// CigiIGMsgV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiIGMsgV4::CigiIGMsgV4()
{

   PacketID = CIGI_IG_MSG_PACKET_ID_V4;
   VariableDataSize = 8;
   PacketSize = VariableDataSize + PacketHeaderSize;
   Version = 4;
   MinorVersion = 0;

   MsgID = 0;

   Msg.resize(1);
   Msg[0] = 0;


}

// ================================================
// ~CigiIGMsgV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiIGMsgV4::~CigiIGMsgV4()
{

}

// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiIGMsgV4::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{

   PackPointer CDta;

   CigiBaseIGMsg * Data = ( CigiBaseIGMsg *)Base;

   CDta.c = Buff;
   Cigi_uint16 msgSize = std::min(Cigi_uint16(Data->Msg.size()), Cigi_uint16(MaxMessageSize));
   Data->Msg[msgSize-1] = 0;

   // Make sure data is aligned correctly
   Data->VariableDataSize = (msgSize + 7) & ~7;
   Cigi_uint16 packetSizeAdjust = Data->VariableDataSize - msgSize;

   Data->PacketSize = PacketHeaderSize + Data->VariableDataSize;

   *CDta.s++ = Data->PacketSize;
   *CDta.s++ = PacketID;

   *CDta.s++ = Data->MsgID;

   *CDta.s++ = 0; // reserved

   memcpy(CDta.c,&Data->Msg[0],msgSize);

   if(packetSizeAdjust) {
	   CDta.c += msgSize;
	   memset(CDta.c, 0, packetSizeAdjust);
   }

   return(Data->PacketSize);

}

// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiIGMsgV4::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{

   PackPointer CDta;


   int tPktSz;

   CDta.c = Buff;

   tPktSz = *CDta.s++;  // Get packet size
   CDta.c += 2;  // Step over packet id

   if(!Swap)
      MsgID = *CDta.s++;
   else
      CigiSwap2(&MsgID, CDta.s++);

   *CDta.s++; // reserved

   if(tPktSz > PacketHeaderSize + MaxMessageSize)
   {
      PacketSize = PacketHeaderSize + MaxMessageSize;
 	  Msg.resize(MaxMessageSize);
      memcpy(&Msg,CDta.c,MaxMessageSize);
      Msg[MaxMessageSize - 1] = 0;
   }
   else if(tPktSz <= PacketHeaderSize + 1)
   {
      PacketSize = tPktSz;
 	  Msg.resize(1,0);
	  Msg[0] = 0;
   }
   else
   {
      PacketSize = tPktSz;
	  Msg.resize(tPktSz - PacketHeaderSize);
      memcpy(&Msg[0],CDta.c,(tPktSz - PacketHeaderSize));
      Msg[(tPktSz - PacketHeaderSize - 1)] = 0;
   }

   VariableDataSize = (Msg.size() + 7) & ~7;

   return(tPktSz);

}


// ================================================
// GetTruePacketSize
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiIGMsgV4::GetTruePacketSize(CigiBaseVariableSizePckt &refPacket)
{
   return(refPacket.GetVariableDataSize() + PacketHeaderSize);
}



// ====================================================================
// Accessors
// ====================================================================


// ================================================
// SetMsg
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiIGMsgV4::SetMsg(const Cigi_Ascii *MsgIn, bool bndchk)
{

   int MsgLen = (int)strlen(MsgIn) + 1;

   if(MsgLen >= MaxMessageSize)
   {
      MsgLen = MaxMessageSize;
 	  Msg.resize(MsgLen);
      memcpy(&Msg[0],MsgIn,MaxMessageSize - 1);
      Msg[MaxMessageSize - 1] = 0;
   }
   else
   {
	  Msg.resize(MsgLen);
      memcpy(&Msg[0],MsgIn,MsgLen);

   }

   VariableDataSize = (MsgLen + 7) & ~7;
   PacketSize = VariableDataSize + PacketHeaderSize;

   return(CIGI_SUCCESS);
}

