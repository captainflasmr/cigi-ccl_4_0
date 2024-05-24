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
 *  FILENAME:   CigiAtmosCtrlV4.cpp
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
 *  Based on CigiAtmosCtrlV3.cpp"
 *
 *  12/10/2018 Paul Slade                      Version 4.0.2
 *  Added byte swap capability.
 *
 *  01/23/2019 Paul Slade                       Version 4.0.2
 *  Added GetCnvt() to allow conversion between V3 and V4
 *
 * </pre>
 *  Author: The Boeing Company
 *
 */

#define _EXPORT_CCL_

#include "CigiAtmosCtrlV4.h"
#include "CigiSwapping.h"
#include "CigiExceptions.h"


// ====================================================================
// Construction/Destruction
// ====================================================================


// ================================================
// CigiAtmosCtrlV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiAtmosCtrlV4::CigiAtmosCtrlV4()
{

   PacketID = CIGI_ATMOS_CTRL_PACKET_ID_V4;
   PacketSize = CIGI_ATMOS_CTRL_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;

   Hour = 0;
   Minute = 0;
   Seconds = 0.0;
   Month = 1;
   Day = 1;
   Year = 2000;
   StarInt = 0.0;
   EphemerisEn = false;
   SunEn = false;
   MoonEn = false;
   StarEn = false;
   DateVld = false;
   AtmosEn = false;
   Aerosol = 0.0;
   Humidity = 30;
   AirTemp = 0.0;
   Visibility = 64373.76f;
   HorizWindSp = 0.0;
   VertWindSp = 0.0;
   WindDir = 0.0;
   BaroPress = 1013.25;


}

// ================================================
// ~CigiAtmosCtrlV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiAtmosCtrlV4::~CigiAtmosCtrlV4()
{

}

// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiAtmosCtrlV4::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   PackPointer CDta;

   CigiBaseEnvCtrl * Data;
   if(Spec == NULL)
      Data = ( CigiBaseEnvCtrl *)Base;
   else
      Data = ( CigiBaseEnvCtrl *)Spec;

   CDta.c = Buff;

   *CDta.s++ = PacketSize;
   *CDta.s++ = PacketID;

   Cigi_uint8 HDta = Data->Humidity;
	HDta |= (Data->AtmosEn) ? 0x80 : 0;
   *CDta.c++ = HDta;
   *CDta.c++; // reserved
   *CDta.s++; // reserved

   *CDta.f++ = Data->AirTemp;
   *CDta.f++ = Data->Visibility;
   *CDta.f++ = Data->HorizWindSp;
   *CDta.f++ = Data->VertWindSp;
   *CDta.f++ = Data->WindDir;
   *CDta.f++ = Data->BaroPress;

   return(PacketSize);

}

// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiAtmosCtrlV4::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{
   PackPointer CDta;

   CDta.c = Buff;

   CDta.c += 4;  // Step over packet id and size

   Cigi_uint8 HDta = *CDta.c++;

   AtmosEn = ( (HDta & 0x80 ) != 0);

   Humidity = HDta & 0x7f;
   CDta.c++; // reserved
   CDta.s++; // reserved

   if (!Swap)
   {
       AirTemp = *CDta.f++;
       Visibility = *CDta.f++;
       HorizWindSp = *CDta.f++;
       VertWindSp = *CDta.f++;
       WindDir = *CDta.f++;
       BaroPress = *CDta.f++;
   }
   else
   {
       CigiSwap4(&AirTemp, CDta.f++);
       CigiSwap4(&Visibility, CDta.f++);
       CigiSwap4(&HorizWindSp, CDta.f++);
       CigiSwap4(&VertWindSp, CDta.f++);
       CigiSwap4(&WindDir, CDta.f++);
       CigiSwap4(&BaroPress, CDta.f++);
   }

   if(Spec != NULL)
   {

      CigiBaseEnvCtrl * Data = (CigiBaseEnvCtrl *)Spec;

      Data->AtmosEn = AtmosEn;

      Data->Humidity = Humidity;
      Data->AirTemp = AirTemp;
      Data->Visibility = Visibility;
      Data->HorizWindSp = HorizWindSp;
      Data->VertWindSp = VertWindSp;
      Data->WindDir = WindDir;
      Data->BaroPress = BaroPress;
   }

   return(PacketSize);

}


// ================================================
// GetCnvt
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiAtmosCtrlV4::GetCnvt(CigiVersionID &CnvtVersion,
    CigiCnvtInfoType::Type &CnvtInfo)
{
    CnvtInfo.ProcID = CigiProcessType::ProcStd;

    // Prior to V3 must use EnvCtrl packet
    if (CnvtVersion.CigiMajorVersion < 3) {
	CnvtInfo.ProcID = CigiProcessType::ProcEnvCtrl;
	CnvtInfo.CnvtPacketID = 0;
    }
    else if (CnvtVersion.CigiMajorVersion < 4) {
	CnvtInfo.ProcID = CigiProcessType::ProcStd;
	CnvtInfo.CnvtPacketID = CIGI_ATMOS_CTRL_PACKET_ID_V3;
    }
    else {
	CnvtInfo.ProcID = CigiProcessType::ProcStd;
	CnvtInfo.CnvtPacketID = CIGI_ATMOS_CTRL_PACKET_ID_V4;
    }

    return(CIGI_SUCCESS);
}

// ====================================================================
// Filling the Hold object
// ====================================================================

// ================================================
// FillHold
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiAtmosCtrlV4::FillHold(CigiBaseEnvCtrl * Hold) const
{
   Hold->AtmosEn = AtmosEn;
   Hold->Humidity = Humidity;
   Hold->AirTemp = AirTemp;
   Hold->Visibility = Visibility;
   Hold->HorizWindSp = HorizWindSp;
   Hold->VertWindSp = VertWindSp;
   Hold->WindDir = WindDir;
   Hold->BaroPress = BaroPress;
}




// ====================================================================
// Accessors
// ====================================================================


// ================================================
// Humidity
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiAtmosCtrlV4::SetHumidity(const Cigi_uint8 HumidityIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((HumidityIn < 0)||(HumidityIn > 100)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Humidity",(Cigi_uint8)HumidityIn,0,100);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   Humidity = HumidityIn;
   return(CIGI_SUCCESS);

}


// ================================================
// Visibility
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiAtmosCtrlV4::SetVisibility(const float VisibilityIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && (VisibilityIn < 0.0))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Visibility",(float)VisibilityIn,">",0.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   Visibility = VisibilityIn;
   return(CIGI_SUCCESS);

}


// ================================================
// HorizWindSp
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiAtmosCtrlV4::SetHorizWindSp(const float HorizWindSpIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && (HorizWindSpIn < 0.0))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("HorizWindSp",(float)HorizWindSpIn,">",0.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   HorizWindSp = HorizWindSpIn;
   return(CIGI_SUCCESS);

}


// ================================================
// WindDir
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiAtmosCtrlV4::SetWindDir(const float WindDirIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((WindDirIn < 0.0)||(WindDirIn > 360.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("WindDir",(float)WindDirIn,0.0,360.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   WindDir = WindDirIn;
   return(CIGI_SUCCESS);

}


// ================================================
// BaroPress
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiAtmosCtrlV4::SetBaroPress(const float BaroPressIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && (BaroPressIn < 0.0))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("BaroPress",(float)BaroPressIn,">",0.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   BaroPress = BaroPressIn;
   return(CIGI_SUCCESS);

}


