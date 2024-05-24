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
 *  FILENAME:   CigiEntityCtrlV4.cpp
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
 *  05/09/2008 Greg Basler                       Version 2.2.0
 *  Initial Release for CIGI 3.3 compatibility.
 *  Based on CigiEntityCtrlV3.cpp"
 *  
 *  05/15/2008 Greg Basler                       Version 2.2.0
 *  Corrected Version Number
 *  
 *  07/29/2015 Chas Whitley                      Version 4.0.0
 *  Initial Release for CIGI 4.0 compatibility.
 *  Based on CigiEntityCtrlV3_3.cpp
 *
 *  12/10/2018 Paul Slade                      Version 4.0.2
 *  Added byte swap capability.
 *
 * </pre>
 *  Author: The Boeing Company
 *
 */

#define _EXPORT_CCL_

#include "CigiEntityPositionCtrlV4.h"
#include "CigiExceptions.h"
#include "CigiSwapping.h"


// ====================================================================
// Construction/Destruction
// ====================================================================


// ================================================
// CigiEntityPositionCtrlV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiEntityPositionCtrlV4::CigiEntityPositionCtrlV4()
{

   PacketID = CIGI_ENTITY_POSITION_CTRL_PACKET_ID_V4;
   PacketSize = CIGI_ENTITY_POSITION_CTRL_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;

   EntityID = 0;
   ParentID = 0;

   Roll = 0.0f;
   Pitch = 0.0f;
   Yaw = 0.0f;
   LatOrXoff = 0.0f;
   LonOrYoff = 0.0f;
   AltOrZoff = 0.0f;

   AttachState = Detach;
   ClampState = NoClamp;
}

// ================================================
// ~CigiEntityPositionCtrlV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiEntityPositionCtrlV4::~CigiEntityPositionCtrlV4()
{

}


// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiEntityPositionCtrlV4::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   PackPointer CDta;

   CigiBaseEntityPositionCtrl *Data = ( CigiBaseEntityPositionCtrl *) Base;

   CDta.c = Buff;

   *CDta.s++ = PacketSize;
   *CDta.s++ = PacketID;

   Cigi_uint8 HDta = (Cigi_uint8)((Data->AttachState & 0x01) |
                                 ((Data->ClampState << 1) & 0x06));

   *CDta.c++ = HDta;
   *CDta.c++ = 0; // reserved
   *CDta.s++ = Data->EntityID;
   
   *CDta.s++ = Data->ParentID;
   *CDta.s++ = 0; // reserved
   *CDta.f++ = Data->Roll;
   *CDta.f++ = Data->Pitch;
   *CDta.f++ = Data->Yaw;
   *CDta.d++ = Data->LatOrXoff;
   *CDta.d++ = Data->LonOrYoff;
   *CDta.d++ = Data->AltOrZoff;

   return(PacketSize);

}


// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiEntityPositionCtrlV4::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{

   PackPointer CDta;

   Cigi_uint8 HDta;

   CDta.c = Buff;

   CDta.c += 4;  // Step over packet id and size

   if(!Swap)
   {
	   HDta = *CDta.c++;
	   *CDta.c++; // reserved

	   EntityID = *CDta.s++;
	   ParentID = *CDta.s++;
	   *CDta.s++; // reserved
	   Roll = *CDta.f++;
	   Pitch = *CDta.f++;
	   Yaw = *CDta.f++;
	   LatOrXoff = *CDta.d++;
	   LonOrYoff = *CDta.d++;
	   AltOrZoff = *CDta.d++;
   }
   else
   {
	   HDta = *CDta.c++;
	   *CDta.c++; // reserved

	   CigiSwap2(&EntityID, CDta.s++);
	   CigiSwap2(&ParentID, CDta.s++);
	   *CDta.s++; // reserved
	   CigiSwap4(&Roll, CDta.f++);
	   CigiSwap4(&Pitch, CDta.f++);
	   CigiSwap4(&Yaw, CDta.f++);
	   CigiSwap8(&LatOrXoff, CDta.d++);
	   CigiSwap8(&LonOrYoff, CDta.d++);
	   CigiSwap8(&AltOrZoff, CDta.d++);
   }

   AttachState = (AttachStateGrp)(HDta & 0x01);
   ClampState = (ClampStateGrp)((HDta >> 1) & 0x03);
   return(CIGI_SUCCESS);

}


// ====================================================================
// Accessors
// ====================================================================

