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

#include "CigiEntityCtrlV4.h"
#include "CigiExceptions.h"
#include "CigiSwapping.h"
#include "CigiAnimationTable.h"


// ====================================================================
// Construction/Destruction
// ====================================================================


// ================================================
// CigiEntityCtrlV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiEntityCtrlV4::CigiEntityCtrlV4()
{

   PacketID = CIGI_ENTITY_CTRL_PACKET_ID_V4;
   PacketSize = CIGI_ENTITY_CTRL_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;

   Alpha = 255;
   EntityID = 0;
   EntityKind = 0;
   EntityDomain = 0;
   EntityType = 0;
   EntityCategory = 0;
   EntitySubcategory = 0;
   EntitySpecific = 0;
   EntityExtra = 0;
   ParentID = 0;

   EntityState = Standby;
   CollisionDetectEn = Disable;
   InheritAlpha = NoInherit;
   SmoothingEn = false;
   ExtendedEntityType = Short;


   Opacity = 100.0f;
   Temperature = 0.0f;

   Roll = 0.0f;
   Pitch = 0.0f;
   Yaw = 0.0f;
   LatOrXoff = 0.0f;
   LonOrYoff = 0.0f;
   AltOrZoff = 0.0f;

   AttachState = Detach;
   InheritAlpha = NoInherit;
   GrndClamp = NoClamp;
   AnimationDir = Forward;
   AnimationLoopMode = OneShot;
   AnimationState = Stop;
   PastAnimationState = Stop;

}

// ================================================
// ~CigiEntityCtrlV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiEntityCtrlV4::~CigiEntityCtrlV4()
{

}


// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiEntityCtrlV4::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   PackPointer CDta;

   CigiEntityCtrlV4 *Data = ( CigiEntityCtrlV4 *) Base;

   CDta.c = Buff;

   *CDta.s++ = PacketSize;
   *CDta.s++ = PacketID;

   Cigi_uint8 HDta = (Cigi_uint8) (Data->EntityState & 0x03);
   HDta |= (Cigi_uint8) ((Data->CollisionDetectEn << 2) & 0x04);
   HDta |= (Cigi_uint8) ((Data->InheritAlpha << 3) & 0x08);
   HDta |= (Data->SmoothingEn) ? 0x10 : 0;
   HDta |= (Cigi_uint8) ((Data->ExtendedEntityType << 5) & 0x20);
   *CDta.c++ = HDta;

   *CDta.c++ = Data->Alpha;
   *CDta.s++ = Data->EntityID;

   *CDta.c++ = Data->EntityKind;
   *CDta.c++ = Data->EntityDomain;
   *CDta.s++ = Data->EntityType;

   *CDta.c++ = Data->EntityCategory;
   *CDta.c++ = Data->EntitySubcategory;
   *CDta.c++ = Data->EntitySpecific;
   *CDta.c++ = Data->EntityExtra;

   return(PacketSize);

}


// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiEntityCtrlV4::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{

   PackPointer CDta;

   Cigi_uint8 HDta;

   CDta.c = Buff;

   CDta.c += 4;  // Step over packet id and size

   HDta = *CDta.c++;
   EntityState = (EntityStateGrp) (HDta & 0x03);
   CollisionDetectEn = (CollisionDetectGrp) ((HDta >> 2) & 0x01);
   InheritAlpha = (InheritAlphaGrp) ((HDta >> 3) & 0x01);
   SmoothingEn = (HDta & 0x10) ? true : false;
   ExtendedEntityType = (ExtendedEntityTypeGrp) ((HDta >> 5) & 0x01);

   if( !Swap )
   {
	   Alpha = *CDta.c++;
	   EntityID = *CDta.s++;
	
	   EntityKind = *CDta.c++;
	   EntityDomain = *CDta.c++;
	   EntityType = *CDta.s++;
	
	   EntityCategory = *CDta.c++;
	   EntitySubcategory = *CDta.c++;
	   EntitySpecific = *CDta.c++;
	   EntityExtra = *CDta.c++;
   }
   else
   {
	   Alpha = *CDta.c++;
	   CigiSwap2(&EntityID, CDta.s++);
	
	   EntityKind = *CDta.c++;
	   EntityDomain = *CDta.c++;
	   CigiSwap2(&EntityType, CDta.s++);
	
	   EntityCategory = *CDta.c++;
	   EntitySubcategory = *CDta.c++;
	   EntitySpecific = *CDta.c++;
	   EntityExtra = *CDta.c++;
   }


   return(CIGI_SUCCESS);

}


// ====================================================================
// Accessors
// ====================================================================


// ================================================
// SetEntityState
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiEntityCtrlV4::SetEntityState(const EntityStateGrp EntityStateIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((EntityStateIn < 0)||(EntityStateIn > 2)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("EntityState",EntityStateIn,0,2);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   EntityState = EntityStateIn;

   return(CIGI_SUCCESS);

}


// ================================================
// SetInheritAlpha
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiEntityCtrlV4::SetInheritAlpha(const InheritAlphaGrp InheritAlphaIn, bool bndchk)
{
   
#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((InheritAlphaIn < 0)||(InheritAlphaIn > 1)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("InheritAlpha",(int)InheritAlphaIn,0,1);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   InheritAlpha = InheritAlphaIn;
   return(CIGI_SUCCESS);

}

// ================================================
// SetRoll
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiEntityCtrlV4::SetExtendedEntityType(const ExtendedEntityTypeGrp ExtendedEntityTypeIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((ExtendedEntityTypeIn < 0)||(ExtendedEntityTypeIn > 2)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Roll",ExtendedEntityTypeIn,0,2);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   ExtendedEntityType = ExtendedEntityTypeIn;

   return(CIGI_SUCCESS);

}

