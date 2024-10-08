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
 *  FILENAME:   CigiLosVectReqV4.cpp
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
 *  Based on CigiLosVectReqV3.cpp"
 *  
 *  06/23/2006 Greg Basler                       Version 1.7.1
 *  Changed native char and unsigned char types to CIGI types Cigi_int8 and 
 *  Cigi_uint8.
 *  
 *  05/15/2008 Greg Basler                       Version 2.2.0
 *  Corrected Version number
 *  
 *  07/29/2015 Chas Whitley                      Version 4.0.0
 *  Initial Release for CIGI 4.0 compatibility.
 *  Based on CigiLosVectReqV3_2.cpp"
 *  
 * </pre>
 *  Author: The Boeing Company
 *
 */

#define _EXPORT_CCL_

#include "CigiLosVectReqV4.h"
#include "CigiSwapping.h"
#include "CigiExceptions.h"


// ====================================================================
// Construction/Destruction
// ====================================================================


// ================================================
// CigiLosVectReqV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiLosVectReqV4::CigiLosVectReqV4()
{

   PacketID = CIGI_LOS_VECT_REQ_PACKET_ID_V4;
   PacketSize = CIGI_LOS_VECT_REQ_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;

   LosID = 0;
   ReqType = Basic;
   SrcCoordSys = Geodetic;
   ResponseCoordSys = Geodetic;
   AlphaThresh = 0;
   EntityID = 0;
   VectAz = 0.0;
   VectEl = 0.0;
   MinRange = 0.0;
   MaxRange = 0.0;
   SrcXLat = 0.0;
   SrcYLon = 0.0;
   SrcZAlt = 0.0;
   Mask = 0;
   UpdatePeriod = 0;
   ValidV1or2 = true;

}

// ================================================
// ~CigiLosVectReqV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiLosVectReqV4::~CigiLosVectReqV4()
{

}

// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiLosVectReqV4::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   PackPointer CDta;

   CigiBaseLosVectReq * Data = ( CigiBaseLosVectReq *)Base;

   CDta.c = Buff;

   *CDta.s++ = PacketSize;
   *CDta.s++ = PacketID;

   *CDta.s++ = Data->LosID;
   *CDta.s++ = Data->EntityID;

   Cigi_uint8 HDta = (Cigi_uint8)(Data->ReqType & 0x01);
   HDta |= (Cigi_uint8)((Data->SrcCoordSys << 1) & 0x02);
   HDta |= (Cigi_uint8)((Data->ResponseCoordSys << 2) & 0x04);
   *CDta.c++ = HDta;

   *CDta.c++ = Data->AlphaThresh;
   *CDta.c++ = Data->UpdatePeriod;

   *CDta.c++ = 0; // reserved
   *CDta.l++ = 0; // reserved

   if(Data->VectAz > 180.0f)
      Data->VectAz -= 360.0f;
   *CDta.f++ = Data->VectAz;
   *CDta.f++ = Data->VectEl;
   *CDta.f++ = Data->MinRange;
   *CDta.f++ = Data->MaxRange;
   *CDta.d++ = Data->SrcXLat;
   *CDta.d++ = Data->SrcYLon;
   *CDta.d++ = Data->SrcZAlt;
   *CDta.l++ = Data->Mask;
   *CDta.l++ = 0; // reserved

   return(PacketSize);

}

// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiLosVectReqV4::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{
   PackPointer CDta;

   CDta.c = Buff;

   CDta.c += 4;  // Step over packet id and size

   if(!Swap)
   {
      LosID = *CDta.s++;
      EntityID = *CDta.s++;

      Cigi_uint16 HDta = *CDta.c++;
      ReqType = (ReqTypeGrp)(HDta & 0x01);
      SrcCoordSys = (CoordSysGrp)((HDta >> 1) & 0x01);
      ResponseCoordSys = (CoordSysGrp)((HDta >> 2) & 0x01);

      AlphaThresh = *CDta.c++;
      UpdatePeriod = *CDta.c++;

      *CDta.c++; // reserved
      *CDta.l++; // reserved

      VectAz = *CDta.f++;
      VectEl = *CDta.f++;
      MinRange = *CDta.f++;
      MaxRange = *CDta.f++;
      SrcXLat = *CDta.d++;
      SrcYLon = *CDta.d++;
      SrcZAlt = *CDta.d++;
      Mask = *CDta.l++;
   }
   else
   {
      CigiSwap2(&LosID, CDta.s++);
      CigiSwap2(&EntityID, CDta.s++);

      Cigi_uint16 HDta = *CDta.c++;
      ReqType = (ReqTypeGrp)(HDta & 0x01);
      SrcCoordSys = (CoordSysGrp)((HDta >> 1) & 0x01);
      ResponseCoordSys = (CoordSysGrp)((HDta >> 2) & 0x01);

      AlphaThresh = *CDta.c++;
      UpdatePeriod = *CDta.c++;

      *CDta.c++; // reserved

      CigiSwap4(&VectAz, CDta.f++);
      CigiSwap4(&VectEl, CDta.f++);
      CigiSwap4(&MinRange, CDta.f++);
      CigiSwap4(&MaxRange, CDta.f++);
      CigiSwap8(&SrcXLat, CDta.d++);
      CigiSwap8(&SrcYLon, CDta.d++);
      CigiSwap8(&SrcZAlt, CDta.d++);
      CigiSwap4(&Mask, CDta.l++);
   }

   ValidV1or2 = (SrcCoordSys == Geodetic);

   return(PacketSize);

}



// ====================================================================
// Accessors
// ====================================================================


// ================================================
// ReqType
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiLosVectReqV4::SetReqType(const ReqTypeGrp ReqTypeIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((ReqTypeIn < 0)||(ReqTypeIn > 1)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("ReqType",(ReqTypeGrp)ReqTypeIn,0,1);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   ReqType = ReqTypeIn;
   return(CIGI_SUCCESS);

}


// ================================================
// SrcCoordSys
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiLosVectReqV4::SetSrcCoordSys(const CoordSysGrp SrcCoordSysIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((SrcCoordSysIn < 0)||(SrcCoordSysIn > 1)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("SrcCoordSys",(CoordSysGrp)SrcCoordSysIn,0,1);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   SrcCoordSys = SrcCoordSysIn;
   return(CIGI_SUCCESS);

}


// ================================================
// ResponseCoordSys
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiLosVectReqV4::SetResponseCoordSys(const CoordSysGrp ResponseCoordSysIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((ResponseCoordSysIn < 0)||(ResponseCoordSysIn > 1)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("ResponseCoordSys",(CoordSysGrp)ResponseCoordSysIn,0,1);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   ResponseCoordSys = ResponseCoordSysIn;
   return(CIGI_SUCCESS);

}


// ================================================
// VectAz
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiLosVectReqV4::SetVectAz(const float VectAzIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((VectAzIn < -180.0f)||(VectAzIn > 180.0f)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("VectAz",(float)VectAzIn,-180.0,180.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   VectAz = VectAzIn;
   return(CIGI_SUCCESS);

}


