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
 *  FILENAME:   CigiSymbolSurfaceDefV4.cpp
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
 *  03/11/2008 Greg Basler                       CIGI_SYM_1
 *  Initial Release.
 *  
 *  07/29/2015 Chas Whitley                      Version 4.0.0
 *  Initial Release for CIGI 4.0 compatibility.
 *  Based on v.cpp
 *  
 * </pre>
 *  Author: The Boeing Company
 *
 */


#define _EXPORT_CCL_


#include "CigiSymbolSurfaceDefV4.h"
#include "CigiSwapping.h"
#include "CigiExceptions.h"



// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiBaseEntityCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSymbolSurfaceDefV4::CigiSymbolSurfaceDefV4(void)
{
   PacketID = CIGI_SYMBOL_SURFACE_DEF_PACKET_ID_V4;
   PacketSize = CIGI_SYMBOL_SURFACE_DEF_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;
   SurfaceID = 0;
   SurfaceState = CigiBaseSymbolSurfaceDef::Active;
   Attached = CigiBaseSymbolSurfaceDef::EntityAttached;
   BillboardState = CigiBaseSymbolSurfaceDef::NotBillboard;
   PerspectiveGrowth = CigiBaseSymbolSurfaceDef::Enable;
   EntityViewID = 0;
   XLeft = 0.0;
   YRight = 0.0;
   ZTop = 0.0;
   YawBottom = 0.0;
   Pitch = 0.0;
   Roll = 0.0;
   Width = 0.0;
   Height = 0.0;
   MinU = 0.0;
   MaxU = 0.0;
   MinV = 0.0;
   MaxV = 0.0;
}

// ================================================
// ~CigiBaseEntityCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSymbolSurfaceDefV4::~CigiSymbolSurfaceDefV4(void)
{
}



// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSymbolSurfaceDefV4::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   PackPointer CDta;

   CigiSymbolSurfaceDefV4 * Data = ( CigiSymbolSurfaceDefV4 *)Base;

   CDta.c = Buff;

   *CDta.s++ = PacketSize;
   *CDta.s++ = PacketID;

   *CDta.s++ = Data->SurfaceID;
   *CDta.s++ = Data->EntityViewID;

   unsigned char HDta = 0;
   HDta |= (Data->SurfaceState & 0x01);
   HDta |= ((Data->Attached << 1) & 0x02);
   HDta |= ((Data->BillboardState << 2) & 0x04);
   HDta |= ((Data->PerspectiveGrowth << 3) & 0x08);
   *CDta.c++ = HDta;

   *CDta.c++ = 0; // reserved
   *CDta.s++ = 0; // reserved

   *CDta.f++ = Data->XLeft;
   *CDta.f++ = Data->YRight;
   *CDta.f++ = Data->ZTop;
   *CDta.f++ = Data->YawBottom;

   if(Attached == Data->EntityAttached)
   {
      *CDta.f++ = Data->Pitch;
      *CDta.f++ = Data->Roll;
      *CDta.f++ = Data->Width;
      *CDta.f++ = Data->Height;
   }
   else
   {
      *CDta.l++ = 0;
      *CDta.l++ = 0;
      *CDta.l++ = 0;
      *CDta.l++ = 0;
   }

   *CDta.f++ = Data->MinU;
   *CDta.f++ = Data->MaxU;
   *CDta.f++ = Data->MinV;
   *CDta.f++ = Data->MaxV;
   *CDta.l++ = 0; // reserved

   return(PacketSize);

}

// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSymbolSurfaceDefV4::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{
   PackPointer CDta;
   unsigned char HDta = 0;

   CDta.c = Buff;

   CDta.c += 4;  // Step over packet id and size

   if(!Swap)
   {
      SurfaceID = *CDta.s++;
      EntityViewID = *CDta.s++;

      HDta = *CDta.c++;
      Attached = (AttachStateGrp)((HDta >> 1) & 0x01);
      CDta.c++;
      CDta.s++;

      XLeft = *CDta.f++;
      YRight = *CDta.f++;
      ZTop = *CDta.f++;
      YawBottom = *CDta.f++;

      if(Attached == EntityAttached)
      {
         Pitch = *CDta.f++;
         Roll = *CDta.f++;
         Width = *CDta.f++;
         Height = *CDta.f++;
      }
      else
      {
         CDta.l += 4;

         Pitch = 0.0f;
         Roll = 0.0f;
         Width = 0.0f;
         Height = 0.0f;
      }

      MinU = *CDta.f++;
      MaxU = *CDta.f++;
      MinV = *CDta.f++;
      MaxV = *CDta.f++;
   }
   else
   {
      CigiSwap2(&SurfaceID, CDta.s++);
      CigiSwap2(&EntityViewID, CDta.s++);

      HDta = *CDta.c++;
      Attached = (AttachStateGrp)((HDta >> 1) & 0x01);
      CDta.c++;
      CDta.s++;

      CigiSwap4(&XLeft, CDta.f++);
      CigiSwap4(&YRight, CDta.f++);
      CigiSwap4(&ZTop, CDta.f++);
      CigiSwap4(&YawBottom, CDta.f++);

      if(Attached == EntityAttached)
      {
         CigiSwap4(&Pitch, CDta.f++);
         CigiSwap4(&Roll, CDta.f++);
         CigiSwap4(&Width, CDta.f++);
         CigiSwap4(&Height, CDta.f++);
      }
      else
      {
         CDta.l += 4;

         Pitch = 0.0f;
         Roll = 0.0f;
         Width = 0.0f;
         Height = 0.0f;
      }

      CigiSwap4(&MinU, CDta.f++);
      CigiSwap4(&MaxU, CDta.f++);
      CigiSwap4(&MinV, CDta.f++);
      CigiSwap4(&MaxV, CDta.f++);
   }

   SurfaceState = (StateGrp)(HDta & 0x01);
   BillboardState = (BillboardStateGrp)((HDta >> 2) & 0x01);
   PerspectiveGrowth = (PerspectiveGrowthStateGrp)((HDta >> 3) & 0x01);

   return(PacketSize);

}




