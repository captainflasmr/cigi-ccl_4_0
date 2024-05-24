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
 *  FILENAME:   CigiCircleSymbolTextureDataV4.cpp
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
 *  01/17/2008 Greg Basler                       CIGI_CR_DR_1
 *  Initial Release.
 *  
 *  07/29/2015 Chas Whitley                      Version 4.0.0
 *  Initial Release for CIGI 4.0 compatibility.
 *  Based on CigiCircleSymbolDataV3_3.cpp
 *  
 * </pre>
 *  Author: The Boeing Company
 *
 */


#define _EXPORT_CCL_


#include "CigiCircleSymbolTextureDataV4.h"
#include "CigiExceptions.h"
#include "CigiSwapping.h"



// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiBaseEntityCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiCircleSymbolTextureDataV4::CigiCircleSymbolTextureDataV4(void)
{
   CenterUPosition = 0.0f;
   CenterVPosition = 0.0f;
   Radius = 0.0f;
   InnerRadius = 0.0f;
   StartAngle = 0.0f;
   EndAngle = 0.0f;
   STexCoord = 0.0f;
   TTexCoord = 0.0f;
   TextureRadius = 0.0f;
   TextureRotation = 0.0f;
}

// ================================================
// ~CigiBaseEntityCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiCircleSymbolTextureDataV4::~CigiCircleSymbolTextureDataV4(void)
{
}


// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiCircleSymbolTextureDataV4::Pack(CigiBaseCircleSymbolTextureData * Base, Cigi_uint8 * Buff) const
{
   PackPointer CDta;

   CigiCircleSymbolTextureDataV4 * Data = ( CigiCircleSymbolTextureDataV4 *)Base;

   CDta.c = Buff;

   *CDta.f++ = Data->CenterUPosition;
   *CDta.f++ = Data->CenterVPosition;
   *CDta.f++ = Data->Radius;
   *CDta.f++ = Data->InnerRadius;
   *CDta.f++ = Data->StartAngle;
   *CDta.f++ = Data->EndAngle;
   *CDta.f++ = STexCoord;
   *CDta.f++ = TTexCoord;
   *CDta.f++ = TextureRadius;
   *CDta.f++ = TextureRotation;

   return(CIGI_CIRCLE_SYMBOL_TEXTURE_DATA_SIZE_V4);

}

// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiCircleSymbolTextureDataV4::Unpack(Cigi_uint8 * Buff, bool Swap)
{
   PackPointer CDta;

   CDta.c = Buff;

   if(!Swap)
   {
      CenterUPosition = *CDta.f++;
      CenterVPosition = *CDta.f++;
      Radius = *CDta.f++;
      InnerRadius = *CDta.f++;
      StartAngle = *CDta.f++;
      EndAngle = *CDta.f++;
      STexCoord = *CDta.f++;
      TTexCoord = *CDta.f++;
      TextureRadius = *CDta.f++;
      TextureRotation = *CDta.f++;
   }
   else
   {
      CigiSwap4(&CenterUPosition, CDta.f++);
      CigiSwap4(&CenterVPosition, CDta.f++);
      CigiSwap4(&Radius, CDta.f++);
      CigiSwap4(&InnerRadius, CDta.f++);
      CigiSwap4(&StartAngle, CDta.f++);
      CigiSwap4(&EndAngle, CDta.f++);
      CigiSwap4(&STexCoord, CDta.f++);
      CigiSwap4(&TTexCoord, CDta.f++);
      CigiSwap4(&TextureRadius, CDta.f++);
      CigiSwap4(&TextureRotation, CDta.f++);
   }

   return(CIGI_CIRCLE_SYMBOL_TEXTURE_DATA_SIZE_V4);

}




