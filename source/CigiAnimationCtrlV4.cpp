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
 *  FILENAME:   CigiAnimationCtrlV4.cpp
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
 *  07/29/2015 Chas Whitley                      Version 4.0.0
 *  Initial Release for CIGI 4.0 compatibility.
 *
 * </pre>
 *  Author: TJ Inc.
 *
 */

#define _EXPORT_CCL_

#include "CigiAnimationCtrlV4.h"
#include "CigiExceptions.h"
#include "CigiSwapping.h"
#include "CigiAnimationTable.h"


// ====================================================================
// Construction/Destruction
// ====================================================================


// ================================================
// CigiAnimationCtrlV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiAnimationCtrlV4::CigiAnimationCtrlV4()
{

   PacketID = CIGI_ANIMATION_CTRL_PACKET_ID_V4;
   PacketSize = CIGI_ANIMATION_CTRL_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;

   Alpha = 255;
   EntityID = 0;

   AnimationID = 0;
   AnimationSpeed = 0.0;
   InheritAlpha = NoInherit;
   AnimationFrameResetMode =Continue;
   AnimationLoopMode = OneShot;
   AnimationState = Stop;
}

// ================================================
// ~CigiAnimationCtrlV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiAnimationCtrlV4::~CigiAnimationCtrlV4()
{

}


// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiAnimationCtrlV4::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   PackPointer CDta;

   CigiBaseAnimationCtrl *Data = ( CigiBaseAnimationCtrl *) Base;

   CDta.c = Buff;

   *CDta.s++ = PacketSize;
   *CDta.s++ = PacketID;

   Cigi_uint8 HDta = 0;
   HDta =  (Cigi_uint8)  (Data->AnimationState & 0x01);
   HDta |= (Cigi_uint8) ((Data->AnimationFrameResetMode << 1) & 0x02);
   HDta |= (Cigi_uint8) ((Data->AnimationLoopMode << 2) & 0x04);
   HDta |= (Cigi_uint8) ((Data->InheritAlpha << 3 ) & 0x08);
   *CDta.c++ = HDta;

   *CDta.c++ = Data->Alpha;
   *CDta.s++ = Data->EntityID;

   *CDta.s++ = Data->AnimationID;
   *CDta.s++; // reserved
   *CDta.f++ = Data->AnimationSpeed;

   return(PacketSize);

}


// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiAnimationCtrlV4::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{

   PackPointer CDta;

   Cigi_uint8 HDta;

   CDta.c = Buff;

   CDta.c += 4;  // Step over packet id and size

   HDta = *CDta.c++;
   AnimationState = (AnimationStateGrp) (HDta & 0x01);
   AnimationFrameResetMode = (AnimationFramePositionResetGrp) ((HDta >> 1) & 0x01);
   AnimationLoopMode = (AnimationLoopModeGrp) ((HDta >> 2) & 0x01);
   InheritAlpha = (InheritAlphaGrp) ((HDta >> 3 ) & 0x01);

   if( !Swap )
   {
	   Alpha = *CDta.c++;
	   EntityID = *CDta.s++;
	
	   AnimationID = *CDta.s++;
       *CDta.s++; // reserved
       AnimationSpeed = *CDta.f++;
   }
   else
   {
	   Alpha = *CDta.c++;
	   CigiSwap2(&EntityID, CDta.s++);
	   CigiSwap2(&AnimationID, CDta.s++);
       *CDta.s++; // reserved
       CigiSwap4(&AnimationSpeed, CDta.f++);
   }


   return(CIGI_SUCCESS);

}


// ====================================================================
// Accessors
// ====================================================================
