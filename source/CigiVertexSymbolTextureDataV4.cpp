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
 *  FILENAME:   CigiVertexSymbolTextureDataV4.cpp
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
 *  Based on CigiVertexSymbolDataV3_3.cpp
 *  
 * </pre>
 *  Author: The Boeing Company
 *
 */


#define _EXPORT_CCL_


#include "CigiVertexSymbolTextureDataV4.h"
#include "CigiExceptions.h"
#include "CigiSwapping.h"



// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiVertexSymbolTextureDataV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiVertexSymbolTextureDataV4::CigiVertexSymbolTextureDataV4(void)
{
   VertexU = 0.0f;
   VertexV = 0.0f;
   STexCoord = 0.0f;
   TTexCoord = 0.0f;

}

// ================================================
// ~CigiVertexSymbolTextureDataV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiVertexSymbolTextureDataV4::~CigiVertexSymbolTextureDataV4(void)
{
}


// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiVertexSymbolTextureDataV4::Pack(CigiBaseVertexSymbolData * Base, Cigi_uint8 * Buff) const
{
   PackPointer CDta;

   CigiVertexSymbolTextureDataV4 * Data = ( CigiVertexSymbolTextureDataV4 *)Base;

   CDta.c = Buff;

   *CDta.f++ = Data->VertexU;
   *CDta.f++ = Data->VertexV;
   *CDta.f++ = Data->STexCoord;
   *CDta.f++ = Data->TTexCoord;

   return(CIGI_VERTEX_SYMBOL_TEXTURE_DATA_SIZE_V4);

}

// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiVertexSymbolTextureDataV4::Unpack(Cigi_uint8 * Buff, bool Swap)
{
   PackPointer CDta;
   unsigned char HDta = 0;

   CDta.c = Buff;

   if(!Swap)
   {
      VertexU = *CDta.f++;
      VertexV = *CDta.f++;
      STexCoord = *CDta.f++;
      TTexCoord = *CDta.f++;
   }
   else
   {
      CigiSwap4(&VertexU, CDta.f++);
      CigiSwap4(&VertexV, CDta.f++);
      CigiSwap4(&STexCoord, CDta.f++);
      CigiSwap4(&TTexCoord, CDta.f++);
   }

   return(CIGI_VERTEX_SYMBOL_TEXTURE_DATA_SIZE_V4);

}

// ================================================
// STexCoord;
// ================================================
int CigiVertexSymbolTextureDataV4::SetSTexCoord(const float STexCoordIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((STexCoordIn < 0.0)||(STexCoordIn > 1.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("STexCoord", (double)STexCoordIn,0.0,1.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   STexCoord = STexCoordIn;

   return(CIGI_SUCCESS);

}

// ================================================
// TTexCoord;
// ================================================
int CigiVertexSymbolTextureDataV4::SetTTexCoord(const float TTexCoordIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((TTexCoordIn < 0.0)||(TTexCoordIn > 1.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("TTexCoord", (double)TTexCoordIn,0.0,1.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   TTexCoord = TTexCoordIn;

   return(CIGI_SUCCESS);

}




