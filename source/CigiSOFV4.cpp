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
 *  FILENAME:   CigiSOFV3_2.cpp
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
 *  04/14/2006 Greg Basler                       Version 1.7
 *  Initial Release for CIGI 3.2 compatibility.
 *  Based on CigiSOFV3.cpp"
 *  
 *  06/23/2006 Greg Basler                       Version 1.7.1
 *  Changed native char and unsigned char types to CIGI types Cigi_int8 and 
 *  Cigi_uint8.
 *  
 *  08/11/2006 Greg Basler                       Version 1.7.3
 *  Corrected the packing routine so that the Minor Version number is
 *  is packed from the packing object (a CigiSOFV3_2 object in this case)
 *  not the object with the user filled data.  This will put the correct
 *  Minor Version number in the ig to host message.
 *  
 *  01/22/2007 Greg Basler                       Version 1.7.5
 *  Corrected a bug noted by C. Schroeder.  When byteswapping, the
 *  Unpack() method now unpacks the CIGI Version 3 timestamp not the
 *  version 2 timestamp.
 *  
 *  06/18/2008 Greg Basler                       Version 2.2.0
 *  Corrected a bug noted on SourceForge.  When byteswapping, the
 *  Unpack() method now unpacks on unsigned long CIGI Version 3
 *  timestamp not the float timestamp.
 *
 *  07/29/2015 Chas Whitley                       Version 4.0.0
 *  Initial Release for CIGI 4.0 compatibility.
 *  Based on CigiSOFV3.cpp"
 *
 *  12/07/2018 Paul Slade                       Version 4.0.2
 *  Fixed error in endian determination
 *
 *  12/10/2018 Paul Slade                      Version 4.0.2
 *  Added byte swap capability.
 *
 *  Removed TimeStampV4 (must now use TimeStampV3 instead) to allow correct version conversion
 *
 * </pre>
 *  Author: The Boeing Company
 *
 */

#define _EXPORT_CCL_

#include "CigiSOFV4.h"
#include "CigiExceptions.h"
#include "CigiSwapping.h"
#include "CigiVersionID.h"


// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiSOFV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSOFV4::CigiSOFV4()
{

   PacketID = CIGI_SOF_PACKET_ID_V4;
   PacketSize = CIGI_SOF_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;

   BSwapEn = false;
   DatabaseID = 0;
   FrameCntr = 0;
   TimeStampV2 = 0.0f;
   TimeStampV3 = 0;
   ByteSwap = 0x0000; // unused
   IGMode = Standby;
   TimestampValid = false;
   EarthRefModel = WGS84;
   LastRcvdHostFrame = 0;
   OverframingCondition = 0;
   PagingCondition = 0;
   ExcessVarLenDataCondition = 0;
}

// ================================================
// ~CigiSOFV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSOFV4::~CigiSOFV4()
{

}





// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSOFV4::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   PackPointer CDta;
   CigiVersionID PackingVer = *((CigiVersionID *)Spec);

   CigiBaseSOF *Data = ( CigiBaseSOF *) Base;

   if(PackingVer.GetCombinedCigiVersion() < 0x0400)
      PackingVer.SetCigiVersion(4,0);

   CDta.c = Buff;

   *CDta.s++ = PacketSize;
   *CDta.s++ = PacketID;

   *CDta.c++ = PackingVer.CigiMajorVersion;
   *CDta.b++ = Data->DatabaseID;
   *CDta.c++ = 0;  //reserved
   {
   Cigi_uint8 HDta = 0;
   HDta |= (Cigi_uint8) (Data->IGMode & 0x03);
   HDta |=              (Data->TimestampValid) ? 0x04 : 0;
   HDta |= (Cigi_uint8)((Data->EarthRefModel << 3) & 0x08);
   HDta |= (Cigi_uint8)((PackingVer.CigiMinorVersion << 4) & 0xf0);
   *CDta.c++ = HDta;
   }

   *CDta.l++ = Data->FrameCntr;
   *CDta.l++ = Data->TimeStampV3;
   *CDta.l++ = Data->LastRcvdHostFrame;

   {
   Cigi_uint16 HDta = (Data->OverframingCondition << 8 ) & 0x0100;
   HDta |= (Data->PagingCondition << 9 ) & 0x0200;
   HDta |= (Data->ExcessVarLenDataCondition << 10 ) & 0x0400;
   *CDta.s++ = HDta;
   }
   *CDta.s++ = 0;


   return(PacketSize);

}


// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSOFV4::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{

   PackPointer CDta;

   CDta.c = Buff;

   Cigi_uint16 incomingPacketSize = *CDta.s;
   if (incomingPacketSize & 0xff00)	// if zero in the "leftmost" byte,
       BSwapEn = true;			// Big Endian (swap)

   CDta.s += 2; // Skip packet size and packet ID

   CDta.c++;  // skip over Major Version

   DatabaseID = *CDta.b++;
   CDta.c++;  // reserved

   {
       Cigi_uint8 HDta = *CDta.c++;

       IGMode = (IGModeGrp)(HDta & 0x03);
       EarthRefModel = (EarthRefModelGrp)((HDta >> 3) & 0x01);
       TimestampValid = ((HDta & 0x04) != 0);
   }

   if(!BSwapEn)
   {
      FrameCntr = *CDta.l++;
      TimeStampV3 = *CDta.l++;
      LastRcvdHostFrame = *CDta.l++;
   }
   else
   {
      CigiSwap4(&FrameCntr,CDta.l++);
      CigiSwap4(&TimeStampV3,CDta.l++);
      CigiSwap4(&LastRcvdHostFrame,CDta.l++);
   }

   TimeStampV2 = ((float)TimeStampV3) * 10.0f;

   {
       Cigi_uint16 HDta = *CDta.s++;

       OverframingCondition = ( HDta >> 8 ) & 0x0001;
       PagingCondition = ( HDta >> 9 ) & 0x0001;
       ExcessVarLenDataCondition = ( HDta >> 10 ) & 0x0001;
   }
   return(CIGI_SUCCESS);

}




// ====================================================================
// Accessors
// ====================================================================



// ================================================
// SetTimeStamp
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSOFV4::SetTimeStamp(const Cigi_uint32 TimeStamp, bool bndchk)
{

   TimeStampV3 = TimeStamp;
   TimeStampV2 = ((float)TimeStampV3) * 10.0f;

   return(CIGI_SUCCESS);

}

// ================================================
// SetEarthRefModel
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSOFV4::SetEarthRefModel(const EarthRefModelGrp EarthRefModelIn,
                                bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((EarthRefModelIn < 0)||(EarthRefModelIn > 1)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("EarthRefModel",EarthRefModelIn,0,1);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   EarthRefModel = EarthRefModelIn;

   return(CIGI_SUCCESS);

}

