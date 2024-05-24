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
 *  FILENAME:   CigiWeatherCtrlV4.cpp
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
 *  Based on CigiWeatherCtrlV3.cpp"
 *
 *  12/10/2018 Paul Slade                      Version 4.0.2
 *  Added byte swap capability.
 *
 * </pre>
 *  Author: The Boeing Company
 *
 */

#define _EXPORT_CCL_

#include "CigiWeatherCtrlV4.h"
#include "CigiSwapping.h"
#include "CigiExceptions.h"


// ====================================================================
// Construction/Destruction
// ====================================================================


// ================================================
// CigiWeatherCtrlV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiWeatherCtrlV4::CigiWeatherCtrlV4()
{

   PacketID = CIGI_WEATHER_CTRL_PACKET_ID_V4;
   PacketSize = CIGI_WEATHER_CTRL_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;

   EntityID = 0;
   RegionID = 0;
   LayerID = 0;
   Humidity = 0;
   PhenomenonType = 0;
   WeatherEn = false;
   ScudEn = false;
   TopScudEn = false;
   RandomWindsEn = false;
   RandomLightningEn = false;
   CloudType = None;
   Scope = Global;
   Severity = 0;
   AirTemp = 0.0;
   VisibilityRng = 0.0;
   Opacity = 0.0;
   ScudFreq = 0.0;
   TopScudFreq = 0.0;
   Coverage = 0.0;
   BaseElev = 0.0;
   Thickness = 0.0;
   Transition = 0.0;
   TopTransition = 0.0;
   HorizWindSp = 0.0;
   VertWindSp = 0.0;
   WindDir = 0.0;
   BaroPress = 1013.25;
   Aerosol = 0.0;
}

// ================================================
// ~CigiWeatherCtrlV3
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiWeatherCtrlV4::~CigiWeatherCtrlV4()
{

}

// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiWeatherCtrlV4::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   PackPointer CDta;

   CigiBaseWeatherCtrl * Data = ( CigiBaseWeatherCtrl *)Base;

   CDta.c = Buff;

   *CDta.s++ = PacketSize;
   *CDta.s++ = PacketID;

   *CDta.c++ = Data->LayerID;
   *CDta.c++ = Data->Humidity;

   Cigi_uint8 HDta = (Data->WeatherEn) ? 0x01 : 0x00;
   HDta |= (Data->ScudEn) ? 0x02 : 0x00;
   HDta |= (Data->RandomWindsEn) ? 0x04 : 0x00;
   HDta |= (Data->RandomLightningEn) ? 0x08 : 0x00;
   HDta |= (Data->CloudType << 4) & 0xf0;

   *CDta.c++ = HDta;

   HDta = 0;
   HDta = Data->Scope & 0x03;
   HDta |= (Data->Severity << 2) & 0x1c;
   HDta |= (Data->TopScudEn) ? 0x20 : 0x00;

   *CDta.c++ = HDta;

   if(Data->Scope == Global)
      *CDta.s++ = 0;
   else if(Data->Scope == Regional)
      *CDta.s++ = Data->RegionID;
   else
      *CDta.s++ = Data->EntityID;

   *CDta.s++ = 0; // reserved

   *CDta.f++ = Data->AirTemp;
   *CDta.f++ = Data->VisibilityRng;
   *CDta.f++ = Data->ScudFreq;
   *CDta.f++ = Data->Coverage;
   *CDta.f++ = Data->BaseElev;
   *CDta.f++ = Data->Thickness;
   *CDta.f++ = Data->Transition;
   *CDta.f++ = Data->HorizWindSp;
   *CDta.f++ = Data->VertWindSp;

   float Wndir = Data->WindDir;
   if(Wndir > 180.0)
      Wndir -= 360.0;
   *CDta.f++ = Wndir;

   *CDta.f++ = Data->BaroPress;
   *CDta.f++ = Data->Aerosol;
   *CDta.f++ = Data->TopScudFreq;
   *CDta.f++ = Data->TopTransition;
   *CDta.f++ = 0.0;

   return(PacketSize);

}

// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiWeatherCtrlV4::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{
   PackPointer CDta;

   static Cigi_uint8 PhenTbl[10] = { 3,1,2,2,4,5,5,5,6,6 };

   CDta.c = Buff;

   CDta.c += 4;  // Step over packet id and size

      LayerID = *CDta.c++;
      Humidity = *CDta.c++;

      Cigi_uint8 HDta = *CDta.c++;
      WeatherEn = ((HDta & 0x01) != 0);
      ScudEn = ((HDta & 0x02) != 0);
      RandomWindsEn = ((HDta & 0x04) != 0);
      RandomLightningEn = ((HDta & 0x08) != 0);
      CloudType = (CloudTypeGrp)((HDta >> 4) & 0x0f);

      HDta = *CDta.c++;
      Scope = (ScopeGrp)(HDta & 0x03);
      Severity = (HDta >> 2) & 0x07;
      TopScudEn = (HDta >> 5) & 0x01;

      if (!Swap)
      {
	  EntityID = *CDta.s++;
	  CDta.s++; // reserved

	  AirTemp = *CDta.f++;
	  VisibilityRng = *CDta.f++;
	  ScudFreq = *CDta.f++;
	  Coverage = *CDta.f++;
	  BaseElev = *CDta.f++;
	  Thickness = *CDta.f++;
	  Transition = *CDta.f++;
	  HorizWindSp = *CDta.f++;
	  VertWindSp = *CDta.f++;
	  WindDir = *CDta.f++;
	  BaroPress = *CDta.f++;
	  Aerosol = *CDta.f++;
	  TopScudFreq = *CDta.f++;
	  TopTransition = *CDta.f++;
      }
      else {
	  CigiSwap2(&EntityID, CDta.s++);
	  CDta.s++; // reserved

	  CigiSwap4(&AirTemp, CDta.f++);
	  CigiSwap4(&VisibilityRng, CDta.f++);
	  CigiSwap4(&ScudFreq, CDta.f++);
	  CigiSwap4(&Coverage, CDta.f++);
	  CigiSwap4(&BaseElev, CDta.f++);
	  CigiSwap4(&Thickness, CDta.f++);
	  CigiSwap4(&Transition, CDta.f++);
	  CigiSwap4(&HorizWindSp, CDta.f++);
	  CigiSwap4(&VertWindSp, CDta.f++);
	  CigiSwap4(&WindDir, CDta.f++);
	  CigiSwap4(&BaroPress, CDta.f++);
	  CigiSwap4(&Aerosol, CDta.f++);
	  CigiSwap4(&TopScudFreq, CDta.f++);
	  CigiSwap4(&TopTransition, CDta.f++);
      }

   RegionID = EntityID;

   if(Scope == Entity)
      PhenomenonType = 0;
   else if(LayerID < 10)
   {
      PhenomenonType = PhenTbl[LayerID];
   }
   else
      PhenomenonType = LayerID;

   Opacity = ((VisibilityRng/70000.0f)*100.0f);



   return(PacketSize);

}



// ====================================================================
// Accessors
// ====================================================================


// ================================================
// Layer ID
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiWeatherCtrlV4::SetLayerID(const Cigi_uint8 LayerIDIn, bool bndchk)
{
   LayerID = LayerIDIn;

   return(CIGI_SUCCESS);
}


// ================================================
// Humidity
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiWeatherCtrlV4::SetHumidity(const Cigi_uint8 HumidityIn, bool bndchk)
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
// CloudType
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiWeatherCtrlV4::SetCloudType(const CloudTypeGrp CloudTypeIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((CloudTypeIn < 0)||(CloudTypeIn > 15)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("CloudType",(CloudTypeGrp)CloudTypeIn,0,15);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   CloudType = CloudTypeIn;
   return(CIGI_SUCCESS);

}


// ================================================
// Scope
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiWeatherCtrlV4::SetScope(const ScopeGrp ScopeIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((ScopeIn < 0)||(ScopeIn > 2)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Scope",(ScopeGrp)ScopeIn,0,2);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   Scope = ScopeIn;
   return(CIGI_SUCCESS);

}


// ================================================
// WindDir
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiWeatherCtrlV4::SetWindDir(const float WindDirIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((WindDirIn < -180.0)||(WindDirIn > 180.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("WindDir",(float)WindDirIn,-180.0,180.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   WindDir = WindDirIn;
   return(CIGI_SUCCESS);

}

// ================================================
// BottomScudFreq
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiWeatherCtrlV4::SetBottomScudFreq(const float BottomScudFreqIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((BottomScudFreqIn < 0.0)||(BottomScudFreqIn > 100.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("BottomScudFreq",(float)BottomScudFreqIn,0.0,100.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   ScudFreq = BottomScudFreqIn;
   return(CIGI_SUCCESS);

}

// ================================================
// TopScudFreq
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiWeatherCtrlV4::SetTopScudFreq(const float TopScudFreqIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((TopScudFreqIn < 0.0)||(TopScudFreqIn > 100.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("TopScudFreq",(float)TopScudFreqIn,0.0,100.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   TopScudFreq = TopScudFreqIn;
   return(CIGI_SUCCESS);

}

