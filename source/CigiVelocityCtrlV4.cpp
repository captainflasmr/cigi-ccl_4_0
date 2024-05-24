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
 *  FILENAME:   CigiRateCtrlV4.cpp
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
 *  12/10/2018 Paul Slade                      Version 4.0.2
 *  Added byte swap capability.
 *
 * </pre>
 *  Author: TJ Inc.
 *
 */

#define _EXPORT_CCL_

#include "CigiVelocityCtrlV4.h"
#include "CigiSwapping.h"
#include "CigiExceptions.h"

// ====================================================================
// Construction/Destruction
// ====================================================================


// ================================================
// CigiRateCtrlV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiVelocityCtrlV4::CigiVelocityCtrlV4()
{

   PacketID = CIGI_VELOCITY_CTRL_PACKET_ID_V4;
   PacketSize = CIGI_VELOCITY_CTRL_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;

   EntityID = 0;
   ArtPartIDV1 = -1;
   ArtPartIDV3 = 0;
   ApplyToArtPart = false;
   CoordSys = Local;
   XRate = 0.0;
   YRate = 0.0;
   ZRate = 0.0;
   RollRate = 0.0;
   PitchRate = 0.0;
   YawRate = 0.0;

}

// ================================================
// ~CigiVelocityCtrlV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiVelocityCtrlV4::~CigiVelocityCtrlV4()
{

}

// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiVelocityCtrlV4::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   PackPointer CDta;

   CigiBaseRateCtrl * Data = ( CigiBaseRateCtrl *)Base;

   CDta.c = Buff;

   *CDta.s++ = PacketSize;
   *CDta.s++ = PacketID;

   *CDta.s++ = Data->EntityID;
   *CDta.c++ = Data->ArtPartIDV3;

   Cigi_uint8 HDta = 0;

   if(Data->ApplyToArtPart)
      HDta = 0x01;
   
   if(Data->CoordSys == Local)
      HDta |= 0x02;

   *CDta.c++ = HDta;

   *CDta.f++ = Data->XRate;
   *CDta.f++ = Data->YRate;
   *CDta.f++ = Data->ZRate;
   *CDta.f++ = Data->RollRate;
   *CDta.f++ = Data->PitchRate;
   *CDta.f++ = Data->YawRate;

   return(PacketSize);

}

// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiVelocityCtrlV4::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{
   union ArtPartConv
   {
      Cigi_uint8 uc;
      Cigi_int8 c;
   } ArtC;

   PackPointer CDta;

   CDta.c = Buff;
   Cigi_uint8 HDta;

   CDta.c += 4;  // Step over packet id and size

   if (!Swap)
   {
       EntityID = *CDta.s++;
       ArtPartIDV3 = *CDta.c++;

       HDta = *CDta.c++;

       XRate = *CDta.f++;
       YRate = *CDta.f++;
       ZRate = *CDta.f++;
       RollRate = *CDta.f++;
       PitchRate = *CDta.f++;
       YawRate = *CDta.f++;
   }
   else {
       CigiSwap2(&EntityID, CDta.s++);
       ArtPartIDV3 = *CDta.c++;

       HDta = *CDta.c++;

       CigiSwap4(&XRate, CDta.f++);
       CigiSwap4(&YRate, CDta.f++);
       CigiSwap4(&ZRate, CDta.f++);
       CigiSwap4(&RollRate, CDta.f++);
       CigiSwap4(&PitchRate, CDta.f++);
       CigiSwap4(&YawRate, CDta.f++);
   }

   ApplyToArtPart = ((HDta & 0x01) != 0);
   CoordSys = (CoordSysGrp)((HDta >> 1) & 0x01);

   if(ApplyToArtPart)
   {

      ArtC.uc = ArtPartIDV3;
      ArtPartIDV1 = ArtC.c;

   }
   else
      ArtPartIDV1 = -1;


   return(PacketSize);

}



// ====================================================================
// Accessors
// ====================================================================


// ================================================
// SetArtPartID
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiVelocityCtrlV4::SetArtPartID(const Cigi_uint8 ArtPartIDIn, bool bndchk)
{
   union ArtPartConv
   {
      Cigi_uint8 uc;
      Cigi_int8 c;
   } ArtC;

   ArtPartIDV3 = ArtPartIDIn;

   if(ApplyToArtPart)
   {

      ArtC.uc = ArtPartIDV3;
      ArtPartIDV1 = ArtC.c;

   }
   else
      ArtPartIDV1 = -1;


   return(CIGI_SUCCESS);
}

// ================================================
// SetApplyToArtPart
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiVelocityCtrlV4::SetApplyToArtPart(const bool ApplyToArtPartIn, bool bndchk)
{
   union ArtPartConv
   {
      Cigi_uint8 uc;
      Cigi_int8 c;
   } ArtC;

   ApplyToArtPart = ApplyToArtPartIn;

   if(ApplyToArtPart)
   {

      ArtC.uc = ArtPartIDV3;
      ArtPartIDV1 = ArtC.c;

   }
   else
      ArtPartIDV1 = -1;

      return(CIGI_SUCCESS);
}


// ================================================
// SrcCoordSys
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiVelocityCtrlV4::SetCoordSys(const CoordSysGrp CoordSysIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((CoordSysIn < 0)||(CoordSysIn > 1)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("CoordSys",(CoordSysGrp)CoordSysIn,0,1);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   CoordSys = CoordSysIn;

   return(CIGI_SUCCESS);

}


