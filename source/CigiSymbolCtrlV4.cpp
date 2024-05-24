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
 *  FILENAME:   CigiSymbolCtrlV4.cpp
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
 *  04/03/2008 Greg Basler                       2.1.0
 *  Corrected pointer incrementing.
 *  
 *  07/29/2015 Chas Whitley                      Version 4.0.0
 *  Initial Release for CIGI 4.0 compatibility.
 *  Based on CigiSymbolCtrlV3_3.cpp
 *  
 * </pre>
 *  Author: The Boeing Company
 *
 */


#define _EXPORT_CCL_


#include "CigiSymbolCtrlV4.h"
#include "CigiSwapping.h"
#include "CigiExceptions.h"



// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiBaseEntityCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSymbolCtrlV4::CigiSymbolCtrlV4(void)
{
   PacketID = CIGI_SYMBOL_CONTROL_PACKET_ID_V4;
   PacketSize = CIGI_SYMBOL_CONTROL_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;

   SymbolID = 0;
   SymbolState = CigiBaseSymbolCtrl::Hidden;
   AttachState = CigiBaseSymbolCtrl::Detach;
   FlashCtrl = CigiBaseSymbolCtrl::Continue;
   InheritColor = CigiBaseSymbolCtrl::NotInherit;
   ParentSymbolID = 0;
   SurfaceID = 0;
   Layer = 0;
   FlashDutyCycle = 0;
   FlashPeriod = 0.0;
   UPosition = 0.0;
   VPosition = 0.0;
   Rotation = 0.0;
   Red = 0;
   Green = 0;
   Blue = 0;
   Alpha = 0;
   ScaleU = 0.0;
   ScaleV = 0.0;

}

// ================================================
// ~CigiBaseEntityCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSymbolCtrlV4::~CigiSymbolCtrlV4(void)
{
}



// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSymbolCtrlV4::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   PackPointer CDta;

   CigiSymbolCtrlV4 * Data =
      ( CigiSymbolCtrlV4 *)Base;

   CDta.c = Buff;

   *CDta.s++ = PacketSize;
   *CDta.s++ = PacketID;

   *CDta.s++ = Data->SymbolID;
   *CDta.s++ = Data->ParentSymbolID;

   unsigned char HDta = 0;
   HDta |= (Data->SymbolState & 0x03);
   HDta |= ((Data->AttachState << 2) & 0x04);
   HDta |= ((Data->FlashCtrl << 3) & 0x08);
   HDta |= ((Data->InheritColor << 4) & 0x10);
   *CDta.c++ = HDta;

   *CDta.c++ = Data->Layer;
   *CDta.c++ = Data->FlashDutyCycle;
   *CDta.c++ = 0; //reserved
   *CDta.s++ = Data->SurfaceID;
   *CDta.s++ = 0; // reserved
   *CDta.f++ = Data->FlashPeriod;
   *CDta.f++ = Data->UPosition;
   *CDta.f++ = Data->VPosition;
   *CDta.f++ = Data->Rotation;
   *CDta.c++ = Data->Red;
   *CDta.c++ = Data->Green;
   *CDta.c++ = Data->Blue;
   *CDta.c++ = Data->Alpha;
   *CDta.f++ = Data->ScaleU;
   *CDta.f++ = Data->ScaleV;
   *CDta.l++ = 0; // reserved

   return(PacketSize);

}

// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSymbolCtrlV4::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{
   PackPointer CDta;
   unsigned char HDta = 0;

   CDta.c = Buff;

   CDta.c += 4;  // Step over packet id and size

   if(!Swap)
   {

      SymbolID = *CDta.s++;
      ParentSymbolID = *CDta.s++;

      HDta = *CDta.c++;

      Layer = *CDta.c++;
      FlashDutyCycle = *CDta.c++;
      CDta.c++;
      SurfaceID = *CDta.s++;
      CDta.s++;
      FlashPeriod = *CDta.f++;
      UPosition = *CDta.f++;
      VPosition = *CDta.f++;
      Rotation = *CDta.f++;
      Red = *CDta.c++;
      Green = *CDta.c++;
      Blue = *CDta.c++;
      Alpha = *CDta.c++;
      ScaleU = *CDta.f++;
      ScaleV = *CDta.f++;

   }
   else
   {

      CigiSwap2(&SymbolID, CDta.s++);

      HDta = *CDta.c++;

      CDta.c++;

      CigiSwap2(&ParentSymbolID, CDta.s++);
      CigiSwap2(&SurfaceID, CDta.s++);
      Layer = *CDta.c++;
      FlashDutyCycle = *CDta.c++;
      CigiSwap4(&FlashPeriod, CDta.f++);
      CigiSwap4(&UPosition, CDta.f++);
      CigiSwap4(&VPosition, CDta.f++);
      CigiSwap4(&Rotation, CDta.f++);
      Red = *CDta.c++;
      Green = *CDta.c++;
      Blue = *CDta.c++;
      Alpha = *CDta.c++;
      CigiSwap4(&ScaleU, CDta.f++);
      CigiSwap4(&ScaleV, CDta.f++);

   }

   SymbolState = (SymbolStateGrp)(HDta & 0x03);
   AttachState = (AttachStateGrp)((HDta >> 2) & 0x01);
   FlashCtrl = (FlashCtrlGrp)((HDta >> 3) & 0x01);
   InheritColor = (InheritColorGrp)((HDta >> 4) & 0x01);

   return(PacketSize);

}




