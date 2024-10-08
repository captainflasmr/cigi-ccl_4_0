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
 *  FILENAME:   CigiVertexSymbolDataV4.cpp
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


#include "CigiVertexSymbolDataV4.h"
#include "CigiExceptions.h"
#include "CigiSwapping.h"



// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiBaseEntityCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiVertexSymbolDataV4::CigiVertexSymbolDataV4(void)
{
   VertexU = 0.0f;
   VertexV = 0.0f;
}

// ================================================
// ~CigiBaseEntityCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiVertexSymbolDataV4::~CigiVertexSymbolDataV4(void)
{
}


// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiVertexSymbolDataV4::Pack(CigiBaseVertexSymbolData * Base, Cigi_uint8 * Buff) const
{
   PackPointer CDta;

   CigiVertexSymbolDataV4 * Data =
      ( CigiVertexSymbolDataV4 *)Base;

   CDta.c = Buff;

   *CDta.f++ = Data->VertexU;
   *CDta.f++ = Data->VertexV;

   return(CIGI_VERTEX_SYMBOL_DATA_SIZE_V4);

}

// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiVertexSymbolDataV4::Unpack(Cigi_uint8 * Buff, bool Swap)
{
   PackPointer CDta;
   unsigned char HDta = 0;

   CDta.c = Buff;

   if(!Swap)
   {
      VertexU = *CDta.f++;
      VertexV = *CDta.f++;
   }
   else
   {
      CigiSwap4(&VertexU, CDta.f++);
      CigiSwap4(&VertexV, CDta.f++);
   }

   return(CIGI_VERTEX_SYMBOL_DATA_SIZE_V4);

}




