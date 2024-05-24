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
 *  FILENAME:   CigiViewDefV4.cpp
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
 *  07/29/2015 Chas Whitley                      Version 4.0.0
 *  Initial Release for CIGI 4.0 compatibility.
 *  Based on CigiViewDefV3.cpp"
 *
 *  12/10/2018 Paul Slade                      Version 4.0.2
 *  Added byte swap capability.
 *
 * </pre>
 *  Author: The Boeing Company
 *
 */

#define _EXPORT_CCL_

#include "CigiViewDefV4.h"
#include "CigiSwapping.h"
#include "CigiExceptions.h"


// ====================================================================
// Construction/Destruction
// ====================================================================


// ================================================
// CigiViewDefV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiViewDefV4::CigiViewDefV4()
{

   PacketID = CIGI_VIEW_DEF_PACKET_ID_V4;
   PacketSize = CIGI_VIEW_DEF_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;

   ViewID = 0;
   GroupID = 0;
   FOVNearEn = false;
   FOVFarEn = false;
   FOVLeftEn = false;
   FOVRightEn = false;
   FOVTopEn = false;
   FOVBottomEn = false;
   MirrorMode = MirrorNone;
   PixelReplicateMode = ReplicateNone;
   ProjectionType = Perspective;
   Reorder = false;
   ViewType = 0;
   TrackerAssigned = false;
   FOVNear = 0.0;
   FOVFar = 0.0;
   FOVLeft = 0.0;
   FOVRight = 0.0;
   FOVTop = 0.0;
   FOVBottom = 0.0;

}

// ================================================
// ~CigiViewDefV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiViewDefV4::~CigiViewDefV4()
{

}

// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiViewDefV4::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   PackPointer CDta;

   CigiBaseViewDef * Data = ( CigiBaseViewDef *)Base;

   CDta.c = Buff;

   *CDta.s++ = PacketSize;
   *CDta.s++ = PacketID;

   *CDta.s++ = Data->ViewID;
   *CDta.c++ = Data->GroupID;

   Cigi_uint8 HDta = (Cigi_uint8)((Data->MirrorMode << 6) & 0xc0);

   if(Data->FOVBottomEn)
      HDta |= 0x20;

   if(Data->FOVTopEn)
      HDta |= 0x10;

   if(Data->FOVRightEn)
      HDta |= 0x08;

   if(Data->FOVLeftEn)
      HDta |= 0x04;

   if(Data->FOVFarEn)
      HDta |= 0x02;

   if(Data->FOVNearEn)
      HDta |= 0x01;

   *CDta.c++ = HDta;

   HDta = (Cigi_uint8)((Data->ViewType << 5) & 0xe0);

   if(Data->Reorder)
      HDta |= 0x10;

   if(Data->ProjectionType == Orthographic)
      HDta |= 0x08;

   HDta |= (Cigi_uint8)(Data->PixelReplicateMode & 0x07);

   *CDta.c++ = HDta;
   *CDta.c++ = 0; // reserved
   *CDta.s++ = 0; // reserved


   *CDta.f++ = Data->FOVNear;
   *CDta.f++ = Data->FOVFar;
   *CDta.f++ = Data->FOVLeft;
   *CDta.f++ = Data->FOVRight;
   *CDta.f++ = Data->FOVTop;
   *CDta.f++ = Data->FOVBottom;
   *CDta.l++ = 0; // reserved

   return(PacketSize);

}

// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiViewDefV4::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{
   PackPointer CDta;

   CDta.c = Buff;

   CDta.c += 4;  // Skip over packet id and size;
   Cigi_uint8 HDta1, HDta2;

   if (!Swap)
   {
       ViewID = *CDta.s++;

       GroupID = *CDta.c++;

       HDta1 = *CDta.c++;
       HDta2 = *CDta.c++;

       CDta.c++;
       CDta.s++;

       FOVNear = *CDta.f++;
       FOVFar = *CDta.f++;
       FOVLeft = *CDta.f++;
       FOVRight = *CDta.f++;
       FOVTop = *CDta.f++;
       FOVBottom = *CDta.f++;
   }
   else {
       CigiSwap2(&ViewID, CDta.s++);

       GroupID = *CDta.c++;

       HDta1 = *CDta.c++;
       HDta2 = *CDta.c++;

       CDta.c++;
       CDta.s++;

       CigiSwap4(&FOVNear, CDta.f++);
       CigiSwap4(&FOVFar, CDta.f++);
       CigiSwap4(&FOVLeft, CDta.f++);
       CigiSwap4(&FOVRight, CDta.f++);
       CigiSwap4(&FOVTop, CDta.f++);
       CigiSwap4(&FOVBottom, CDta.f++);
   }
   MirrorMode = (MirrorModeGrp)((HDta1 >> 6) & 0x03);
   FOVBottomEn = ((HDta1 & 0x20) != 0);
   FOVTopEn = ((HDta1 & 0x10) != 0);
   FOVRightEn = ((HDta1 & 0x08) != 0);
   FOVLeftEn = ((HDta1 & 0x04) != 0);
   FOVFarEn = ((HDta1 & 0x02) != 0);
   FOVNearEn = ((HDta1 & 0x01) != 0);

   ViewType = (HDta2 >> 5) & 0x07;
   Reorder = ((HDta2 & 0x10) != 0);
   ProjectionType = (ProjectionTypeGrp)((HDta2 >> 3) & 0x01);
   PixelReplicateMode = (PixelReplicateModeGrp)(HDta2 & 0x07);

   return(CIGI_VIEW_DEF_PACKET_SIZE_V4);


}



// ====================================================================
// Accessors
// ====================================================================


// ================================================
// ProjectionType
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiViewDefV4::SetProjectionType(const ProjectionTypeGrp ProjectionTypeIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((ProjectionType < 0)||(ProjectionType > 1)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("ProjectionType",(ProjectionTypeGrp)ProjectionTypeIn,0,1);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   ProjectionType = ProjectionTypeIn;
   return(CIGI_SUCCESS);

}


