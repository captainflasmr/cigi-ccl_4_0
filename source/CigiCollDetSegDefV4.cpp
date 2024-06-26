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
 *  FILENAME:   CigiCollDetSegDefV4.cpp
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
 *  Based on CigiCollDetSegDefV3.cpp"
 *
 *  12/10/2018 Paul Slade                      Version 4.0.2
 *  Added byte swap capability.
 *
 * </pre>
 *  Author: The Boeing Company
 *
 */

#define _EXPORT_CCL_

#include "CigiCollDetSegDefV4.h"
#include "CigiExceptions.h"
#include "CigiSwapping.h"


// ====================================================================
// Construction/Destruction
// ====================================================================


// ================================================
// CigiCollDetSegDefV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiCollDetSegDefV4::CigiCollDetSegDefV4()
{

   PacketID = CIGI_COLL_DET_SEG_DEF_PACKET_ID_V4;
   PacketSize = CIGI_COLL_DET_SEG_DEF_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;

   EntityID = 0;
   SegmentID = 0;
   SegmentEn = false;
   X1 = 0.0;
   Y1 = 0.0;
   Z1 = 0.0;
   X2 = 0.0;
   Y2 = 0.0;
   Z2 = 0.0;
   Mask = 0;

}

// ================================================
// ~CigiCollDetSegDefV3
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiCollDetSegDefV4::~CigiCollDetSegDefV4()
{

}

// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiCollDetSegDefV4::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   PackPointer CDta;

   CigiBaseCollDetSegDef * Data = ( CigiBaseCollDetSegDef *)Base;

   CDta.c = Buff;

   *CDta.s++ = PacketSize;
   *CDta.s++ = PacketID;

   *CDta.c++ = Data->SegmentID;

   Cigi_uint8 HDta = (Data->SegmentEn) ? 0x01 : 0x00;
   *CDta.c++ = HDta;

   *CDta.s++ = Data->EntityID;

   *CDta.f++ = Data->X1;
   *CDta.f++ = Data->Y1;
   *CDta.f++ = Data->Z1;
   *CDta.f++ = Data->X2;
   *CDta.f++ = Data->Y2;
   *CDta.f++ = Data->Z2;
   *CDta.l++ = Data->Mask;
   *CDta.l++ = 0;

   return(PacketSize);

}

// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiCollDetSegDefV4::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{
   PackPointer CDta;

   CDta.c = Buff;

   CDta.c += 4;  // Step over packet id and size

   SegmentID = *CDta.c++;

   Cigi_uint8 HDta = *CDta.c++;
   SegmentEn = ((HDta & 0x01) != 0);

   if (!Swap)
   {
       EntityID = *CDta.s++;

       X1 = *CDta.f++;
       Y1 = *CDta.f++;
       Z1 = *CDta.f++;
       X2 = *CDta.f++;
       Y2 = *CDta.f++;
       Z2 = *CDta.f++;
       Mask = *CDta.l++;
   }
   else {
       CigiSwap2(&EntityID, CDta.s++);

       CigiSwap4(&X1, CDta.f++);
       CigiSwap4(&Y1, CDta.f++);
       CigiSwap4(&Z1, CDta.f++);
       CigiSwap4(&X2, CDta.f++);
       CigiSwap4(&Y2, CDta.f++);
       CigiSwap4(&Z2, CDta.f++);
       CigiSwap4(&Mask, CDta.l++);

   }

   return(PacketSize);

}



// ====================================================================
// Accessors
// ====================================================================

