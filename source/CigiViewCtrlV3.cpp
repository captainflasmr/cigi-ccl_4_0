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
 *  FILENAME:   CigiViewCtrlV3.cpp
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
 * </pre>
 *  Author: The Boeing Company
 *
 */

#define _EXPORT_CCL_

#include "CigiViewCtrlV3.h"
#include "CigiSwapping.h"
#include "CigiExceptions.h"


// ====================================================================
// Construction/Destruction
// ====================================================================


// ================================================
// CigiViewCtrlV3
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiViewCtrlV3::CigiViewCtrlV3()
{

   PacketID = CIGI_VIEW_CTRL_PACKET_ID_V3;
   PacketSize = CIGI_VIEW_CTRL_PACKET_SIZE_V3;
   Version = 3;
   MinorVersion = 0;

   EntityID = 0;
   ViewID = 0;
   GroupID = 0;
   XOffEn = false;
   YOffEn = false;
   ZOffEn = false;
   RollEn = false;
   PitchEn = false;
   YawEn = false;
   XOff = 0.0;
   YOff = 0.0;
   ZOff = 0.0;
   Roll = 0.0;
   Pitch = 0.0;
   Yaw = 0.0;

}

// ================================================
// ~CigiViewCtrlV3
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiViewCtrlV3::~CigiViewCtrlV3()
{

}

// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiViewCtrlV3::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   PackPointer CDta;

   CigiBaseViewCtrl * Data = ( CigiBaseViewCtrl *)Base;

   CDta.c = Buff;

   *CDta.c++ = ( Cigi_uint8 ) PacketID;
   *CDta.c++ = ( Cigi_uint8 ) PacketSize;

   *CDta.s++ = Data->ViewID;
   *CDta.c++ = Data->GroupID;

   Cigi_uint8 HDta = 0;

   if(Data->XOffEn)
      HDta |= 0x01;

   if(Data->YOffEn)
      HDta |= 0x02;

   if(Data->ZOffEn)
      HDta |= 0x04;

   if(Data->RollEn)
      HDta |= 0x08;

   if(Data->PitchEn)
      HDta |= 0x10;

   if(Data->YawEn)
      HDta |= 0x20;

   *CDta.c++ = HDta;

   *CDta.s++ = Data->EntityID;

   *CDta.f++ = Data->XOff;
   *CDta.f++ = Data->YOff;
   *CDta.f++ = Data->ZOff;
   *CDta.f++ = Data->Roll;
   *CDta.f++ = Data->Pitch;
   *CDta.f++ = Data->Yaw;

   return(PacketSize);

}

// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiViewCtrlV3::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{
   PackPointer CDta;

   CDta.c = Buff;

   CDta.c += 2;  // Step over packet id and size

   if(!Swap)
   {
      ViewID = *CDta.s++;
      GroupID = *CDta.c++;

      Cigi_uint8 HDta = *CDta.c++;

      XOffEn  = ((HDta & 0x01) != 0);
      YOffEn  = ((HDta & 0x02) != 0);
      ZOffEn  = ((HDta & 0x04) != 0);
      RollEn  = ((HDta & 0x08) != 0);
      PitchEn = ((HDta & 0x10) != 0);
      YawEn   = ((HDta & 0x20) != 0);

      EntityID = *CDta.s++;

      XOff = *CDta.f++;
      YOff = *CDta.f++;
      ZOff = *CDta.f++;
      Roll = *CDta.f++;
      Pitch = *CDta.f++;
      Yaw = *CDta.f++;
   }
   else
   {
      CigiSwap2(&ViewID, CDta.s++);
      GroupID = *CDta.c++;

      Cigi_uint8 HDta = *CDta.c++;

      XOffEn  = ((HDta & 0x01) != 0);
      YOffEn  = ((HDta & 0x02) != 0);
      ZOffEn  = ((HDta & 0x04) != 0);
      RollEn  = ((HDta & 0x08) != 0);
      PitchEn = ((HDta & 0x10) != 0);
      YawEn   = ((HDta & 0x20) != 0);

      CigiSwap2(&EntityID, CDta.s++);

      CigiSwap4(&XOff, CDta.f++);
      CigiSwap4(&YOff, CDta.f++);
      CigiSwap4(&ZOff, CDta.f++);
      CigiSwap4(&Roll, CDta.f++);
      CigiSwap4(&Pitch, CDta.f++);
      CigiSwap4(&Yaw, CDta.f++);
   }

   return(PacketSize);

}


