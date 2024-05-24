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
 *  FILENAME:   CigiAccelerationCtrlV4.cpp
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

#include <math.h>

#define _EXPORT_CCL_

#include "CigiAccelerationCtrlV4.h"
#include "CigiExceptions.h"
#include "CigiSwapping.h"


// ====================================================================
// Construction/Destruction
// ====================================================================


// ================================================
// CigiAccelerationCtrlV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiAccelerationCtrlV4::CigiAccelerationCtrlV4()
{

   PacketID = CIGI_ACCELERATION_CTRL_PACKET_ID_V4;
   PacketSize = CIGI_ACCELERATION_CTRL_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;

   EntityID = 0;
   ArtPartID = 0;
   Accel = 0.0;
   RetardationRate = 0.0;
   TermVel = 0.0;
   AccelX = 0.0f;
   AccelY = 0.0f;
   AccelZ = 0.0f;
   AccelRoll = 0.0;
   AccelPitch = 0.0;
   AccelYaw = 0.0;
   Xoff = 0.0f;
   Yoff = 0.0f;
   Zoff = 0.0f;
   CoordSys = World;
   ArtPartApplyEn = false;
}

// ================================================
// ~CigiTrajectoryDefV3
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiAccelerationCtrlV4::~CigiAccelerationCtrlV4()
{

}

// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiAccelerationCtrlV4::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   PackPointer CDta;

   CigiBaseTrajectoryDef * Data = (CigiBaseTrajectoryDef *)Base;

   CDta.c = Buff;

   *CDta.s++ = PacketSize;
   *CDta.s++ = PacketID;

   *CDta.s++ = Data->EntityID;
   *CDta.c++ = Data->ArtPartID;

   Cigi_uint8 HDta = (Cigi_uint8)((Data->ArtPartApplyEn & 0x01) |
                                 ((Data->CoordSys << 1) & 0x02));
   *CDta.c++ = HDta;

   *CDta.f++ = Data->AccelX;
   *CDta.f++ = Data->AccelY;
   *CDta.f++ = Data->AccelZ;
   *CDta.f++ = Data->AccelRoll;
   *CDta.f++ = Data->AccelPitch;
   *CDta.f++ = Data->AccelYaw;

   return(PacketSize);

}

// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiAccelerationCtrlV4::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{
   PackPointer CDta;

   CDta.c = Buff;

   CDta.c += 4;  // Step over packet id and size

   Cigi_uint8 HDta;

   if (!Swap)
   {
       EntityID = *CDta.s++;
       ArtPartID = *CDta.c++;

       HDta = *CDta.c++;

       AccelX = *CDta.f++;
       AccelY = *CDta.f++;
       AccelZ = *CDta.f++;
       AccelRoll = *CDta.f++;
       AccelPitch = *CDta.f++;
       AccelYaw = *CDta.f++;
   }
   else {
       CigiSwap2(&EntityID, CDta.s++);
       ArtPartID = *CDta.c++;

       HDta = *CDta.c++;

       CigiSwap4(&AccelX, CDta.f++);
       CigiSwap4(&AccelY, CDta.f++);
       CigiSwap4(&AccelZ, CDta.f++);
       CigiSwap4(&AccelRoll, CDta.f++);
       CigiSwap4(&AccelPitch, CDta.f++);
       CigiSwap4(&AccelYaw, CDta.f++);
   }
   ArtPartApplyEn = (HDta & 0x01);
   CoordSys = (HDta & 0x02) ? Local : World;

   Accel = (float)sqrt((double)((AccelX*AccelX) + (AccelY*AccelY) + (AccelZ*AccelZ)));


   return(PacketSize);

}



// ====================================================================
// Accessors
// ====================================================================


// ================================================
// AccelX
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiAccelerationCtrlV4::SetAccelX(const float AccelIn, bool bndchk)
{
   AccelX = AccelIn;
   Accel = (float)sqrt((double)((AccelX*AccelX) + (AccelY*AccelY) + (AccelZ*AccelZ)));

   return(CIGI_SUCCESS);
}


// ================================================
// AccelY
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiAccelerationCtrlV4::SetAccelY(const float AccelIn, bool bndchk)
{
   AccelY = AccelIn;
   Accel = (float)sqrt((double)((AccelX*AccelX) + (AccelY*AccelY) + (AccelZ*AccelZ)));

   return(CIGI_SUCCESS);
}


// ================================================
// AccelZ
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiAccelerationCtrlV4::SetAccelZ(const float AccelIn, bool bndchk)
{
   AccelZ = AccelIn;
   Accel = (float)sqrt((double)((AccelX*AccelX) + (AccelY*AccelY) + (AccelZ*AccelZ)));

   return(CIGI_SUCCESS);
}

// ================================================
// AccelRoll
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiAccelerationCtrlV4::SetAccelRoll(const float AccelIn, bool bndchk)
{
   AccelRoll = AccelIn;

   return(CIGI_SUCCESS);
}


// ================================================
// AccelPitch
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiAccelerationCtrlV4::SetAccelPitch(const float AccelIn, bool bndchk)
{
   AccelPitch = AccelIn;

   return(CIGI_SUCCESS);
}


// ================================================
// AccelYaw
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiAccelerationCtrlV4::SetAccelYaw(const float AccelIn, bool bndchk)
{
   AccelYaw = AccelIn;

   return(CIGI_SUCCESS);
}
