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
 *  FILENAME:   CigiMaritimeSurfaceCtrlV4.cpp
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
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Changed native C++ types to use CCL-defined types instead where appropriate.
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
 *  Based on CigiMaritimeSurfaceCtrlV3.cpp"
 *
 *  12/10/2018 Paul Slade                      Version 4.0.2
 *  Added byte swap capability.
 *
 * </pre>
 *  Author: The Boeing Company
 *
 */

#define _EXPORT_CCL_

#include "CigiMaritimeSurfaceCtrlV4.h"
#include "CigiSwapping.h"
#include "CigiExceptions.h"


// ====================================================================
// Construction/Destruction
// ====================================================================


// ================================================
// CigiMaritimeSurfaceCtrlV3
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiMaritimeSurfaceCtrlV4::CigiMaritimeSurfaceCtrlV4()
{

   PacketID = CIGI_MARITIME_SURFACE_CTRL_PACKET_ID_V4;
   PacketSize = CIGI_MARITIME_SURFACE_CTRL_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;

   EntityRgnID = 0;
   SurfaceCondEn = false;
   WhitecapEn = false;
   Scope = Global;
   SurfaceHeight = 0.0;
   WaterTemp = 0.0;
   Clarity = 0.0;

}

// ================================================
// ~CigiMaritimeSurfaceCtrlV3
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiMaritimeSurfaceCtrlV4::~CigiMaritimeSurfaceCtrlV4()
{

}

// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiMaritimeSurfaceCtrlV4::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   PackPointer CDta;

   CigiBaseMaritimeSurfaceCtrl * Data = ( CigiBaseMaritimeSurfaceCtrl *)Base;

   CDta.c = Buff;

   *CDta.s++ = PacketSize;
   *CDta.s++ = PacketID;

   Cigi_uint8 HDta = (Data->SurfaceCondEn) ? 0x01 : 0;
   HDta |= (Data->WhitecapEn) ? 0x02 : 0;
   HDta |= (Data->Scope << 2) & 0x0c;
   *CDta.c++ = HDta;

   *CDta.s++ = Data->EntityRgnID;

   *CDta.c++ = 0;

   *CDta.f++ = Data->SurfaceHeight;
   *CDta.f++ = Data->WaterTemp;
   *CDta.f++ = Data->Clarity;
   *CDta.l++ = 0;

   return(PacketSize);

}

// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiMaritimeSurfaceCtrlV4::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{
   PackPointer CDta;

   CDta.c = Buff;

   CDta.c += 4;  // Step over packet id and size

   Cigi_uint8 HDta = *CDta.c++;
   SurfaceCondEn = ((HDta & 0x01) != 0);
   WhitecapEn = ((HDta & 0x02) != 0);
   Scope = (ScopeGrp)((HDta >> 2) & 0x03);

   CDta.c += 1; // reserved
   if (!Swap)
   {
       EntityRgnID = *CDta.s++;

       SurfaceHeight = *CDta.f++;
       WaterTemp = *CDta.f++;
       Clarity = *CDta.f++;
   }
   else {
       CigiSwap2(&EntityRgnID, CDta.s++);

       CigiSwap4(&SurfaceHeight, CDta.f++);
       CigiSwap4(&WaterTemp, CDta.f++);
       CigiSwap4(&Clarity, CDta.f++);

   }

   return(PacketSize);

}



// ====================================================================
// Accessors
// ====================================================================


