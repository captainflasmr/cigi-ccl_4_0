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
 *  FILENAME:   CigiSymbolTexturedCircleDefV4.cpp
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
 *  03/11/2008 Greg Basler                       CIGI_SYM_1
 *  Initial Release.
 *  
 *  04/03/2008 Greg Basler                       2.1.0
 *  Corrected pointer incrementing.
 *  
 *  07/29/2015 Chas Whitley                      Version 4.0.0
 *  Initial Release for CIGI 4.0 compatibility.
 *  Based on CigiSymbolCircleDefV3_3.cpp
 *
 *  05/14/2019 Elliot Catalano					 Version 4.0.3
 *  Modified Pack method to properly pack TextureWrap into HDta rather than packing
 *  TextureFilter twice.
 *  
 * </pre>
 *  Author: The Boeing Company
 *
 */


#define _EXPORT_CCL_


#include "CigiSymbolTexturedCircleDefV4.h"
#include "CigiSwapping.h"
#include "CigiExceptions.h"

using namespace std;

// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiBaseEntityCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSymbolTexturedCircleDefV4::CigiSymbolTexturedCircleDefV4(void)
{
   PacketID = CIGI_SYMBOL_TEXTURED_CIRCLE_DEFINITION_PACKET_ID_V4;
   PacketSize = CIGI_SYMBOL_TEXTURED_CIRCLE_DEFINITION_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;
   VariableDataSize = 0;

   SymbolID = 0;
   TextureID = 0;
   TextureFilter = Nearest;
   TextureWrap = Clamp;
}

// ================================================
// ~CigiBaseEntityCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSymbolTexturedCircleDefV4::~CigiSymbolTexturedCircleDefV4(void)
{
}

// ================================================
// CigiSymbolCircleDefV4 - Copy constructor
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSymbolTexturedCircleDefV4::CigiSymbolTexturedCircleDefV4(const CigiSymbolTexturedCircleDefV4 &BaseIn)
: CigiBaseSymbolTexturedCircleDef((CigiBaseSymbolTexturedCircleDef &)BaseIn)
{
   PacketID = CIGI_SYMBOL_TEXTURED_CIRCLE_DEFINITION_PACKET_ID_V4;
   PacketSize = CIGI_SYMBOL_TEXTURED_CIRCLE_DEFINITION_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;

   VariableDataSize = 0;

   SymbolID = BaseIn.SymbolID;
   TextureID = BaseIn.TextureID;
   TextureFilter = BaseIn.TextureFilter;
   TextureWrap = BaseIn.TextureWrap;

   CigiCircleSymbolTextureDataV4 *NewCircle = NULL;
   CigiCircleSymbolTextureDataV4 *pCircle;
   vector<CigiBaseCircleSymbolTextureData *>::const_iterator iCircle;
   for(iCircle=BaseIn.Circles.begin();iCircle!=BaseIn.Circles.end();iCircle++)
   {
      pCircle = (CigiCircleSymbolTextureDataV4 *)*iCircle;
      if(pCircle != NULL)
      {
         NewCircle = new CigiCircleSymbolTextureDataV4;
         *NewCircle = *pCircle;
         Circles.push_back((CigiBaseCircleSymbolTextureData *)NewCircle);
         VariableDataSize += CIGI_CIRCLE_SYMBOL_TEXTURE_DATA_SIZE_V4;
      }
   }
}

// ================================================
// Copy Operator
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSymbolTexturedCircleDefV4 & CigiSymbolTexturedCircleDefV4::operator=(const CigiSymbolTexturedCircleDefV4 &BaseIn)
{
   PacketID = CIGI_SYMBOL_TEXTURED_CIRCLE_DEFINITION_PACKET_ID_V4;
   PacketSize = CIGI_SYMBOL_TEXTURED_CIRCLE_DEFINITION_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;

   CigiBaseCircleSymbolTextureData *pbCircle;
   vector<CigiBaseCircleSymbolTextureData *>::iterator ibCircle;
   for(ibCircle=Circles.begin();ibCircle!=Circles.end();ibCircle++)
   {
      pbCircle = *ibCircle;
      if(pbCircle != NULL)
         delete pbCircle;
   }
   Circles.clear();
   VariableDataSize = 0;

   SymbolID = BaseIn.SymbolID;
   TextureID = BaseIn.TextureID;
   TextureFilter = BaseIn.TextureFilter;
   TextureWrap = BaseIn.TextureWrap;

   CigiCircleSymbolTextureDataV4 *NewCircle = NULL;
   CigiCircleSymbolTextureDataV4 *pCircle;
   vector<CigiBaseCircleSymbolTextureData *>::const_iterator iCircle;
   for(iCircle=BaseIn.Circles.begin();iCircle!=BaseIn.Circles.end();iCircle++)
   {
      pCircle = (CigiCircleSymbolTextureDataV4 *)*iCircle;
      if(pCircle != NULL)
      {
         NewCircle = new CigiCircleSymbolTextureDataV4;
         *NewCircle = *pCircle;
         Circles.push_back((CigiBaseCircleSymbolTextureData *)NewCircle);
         VariableDataSize += CIGI_CIRCLE_SYMBOL_TEXTURE_DATA_SIZE_V4;
      }
   }

   return(*this);
}



// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSymbolTexturedCircleDefV4::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   PackPointer CDta;

   CigiSymbolTexturedCircleDefV4 * Data = ( CigiSymbolTexturedCircleDefV4 *)Base;

   CDta.c = Buff;

   *CDta.s++ = (PacketSize + Data->VariableDataSize);
   *CDta.s++ =  PacketID;

   *CDta.s++ = Data->SymbolID;
   *CDta.s++ = Data->TextureID;

   Cigi_uint8 HDta = Data->TextureFilter & 0x01;
   HDta |= ( ( Data->TextureWrap << 1 ) & 0x02 );
   *CDta.c++ = HDta;

   *CDta.c++ = 0; // reserved
   *CDta.s++ = 0; // reserved
   *CDta.l++ = 0; // reserved

   int Cnt;
   CigiCircleSymbolTextureDataV4 *pCircle;
   vector<CigiBaseCircleSymbolTextureData *>::iterator iCircle;
   for(iCircle=Data->Circles.begin();iCircle!=Data->Circles.end();iCircle++)
   {
      pCircle = (CigiCircleSymbolTextureDataV4 *)*iCircle;
      if(pCircle != NULL)
      {
         Cnt = pCircle->Pack((CigiCircleSymbolTextureDataV4 *)pCircle,CDta.c);
         CDta.c += Cnt;
      }
   }

   return(PacketSize + Data->VariableDataSize);

}

// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSymbolTexturedCircleDefV4::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{
   PackPointer CDta;
   Cigi_uint8 HDta = 0;

   CDta.c = Buff;

   // Clear the current Circle Vector
   CigiBaseCircleSymbolTextureData *pbCircle;
   vector<CigiBaseCircleSymbolTextureData *>::iterator ibCircle;
   for(ibCircle=Circles.begin();ibCircle!=Circles.end();ibCircle++)
   {
      pbCircle = *ibCircle;
      if(pbCircle != NULL)
         delete pbCircle;
   }
   Circles.clear();
   VariableDataSize = 0;


   // Determine variable data size;
   unsigned int PcktRemain = *CDta.s;
   PcktRemain -= CIGI_SYMBOL_TEXTURED_CIRCLE_DEFINITION_PACKET_SIZE_V4;
   VariableDataSize = PcktRemain;


   CDta.c += 4;  // Step over packet id and size

   if(!Swap)
   {
      SymbolID = *CDta.s++;
      TextureID = *CDta.s++;
      HDta = *CDta.c++;
      CDta.c++; // reserved
      CDta.s++; // reserved
      CDta.l++; // reserved
   }
   else
   {
      CigiSwap2(&SymbolID, CDta.s++);
      CigiSwap2(&TextureID, CDta.s++);
      HDta = *CDta.c++;
      CDta.c++; // reserved
      CDta.s++; // reserved
      CDta.l++; // reserved
   }

   TextureFilter = (HDta & 0x01) ? Linear : Nearest;
   TextureWrap = ((HDta >> 1 ) & 0x01) ? Clamp : Repeat;

   // Unpack Circles
   int cnt = 0;
   CigiCircleSymbolTextureDataV4 *pCircle;
   while(PcktRemain >= CIGI_CIRCLE_SYMBOL_TEXTURE_DATA_SIZE_V4)
   {
      pCircle = new CigiCircleSymbolTextureDataV4;
      Circles.push_back((CigiBaseCircleSymbolTextureData *)pCircle);
      cnt = pCircle->Unpack(CDta.c,Swap);
      PcktRemain -= cnt;
      CDta.c += cnt;
   }

   return(PacketSize + VariableDataSize);

}



// ====================================================================
// Circle Operation
// ====================================================================

// ================================================
// AddCircle
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseCircleSymbolTextureData * CigiSymbolTexturedCircleDefV4::AddCircle(void)
{
   CigiCircleSymbolTextureDataV4 *NewCircle = NULL;
   int Cnt = (int)Circles.size();

   if(Cnt < 10)
   {
      NewCircle = new CigiCircleSymbolTextureDataV4;
      Circles.push_back((CigiBaseCircleSymbolTextureData *)NewCircle);
      VariableDataSize += CIGI_CIRCLE_SYMBOL_TEXTURE_DATA_SIZE_V4;
   }

   return((CigiBaseCircleSymbolTextureData *)NewCircle);
}

// ================================================
// RemoveCircle
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSymbolTexturedCircleDefV4::RemoveCircle(int CircleIndex, bool bndchk)
{
   int stat = CIGI_SUCCESS;

   int Cnt = (int)Circles.size();

   if((CircleIndex >= 0) && (CircleIndex < Cnt))
   {
      vector<CigiBaseCircleSymbolTextureData *>::iterator iCircle = Circles.begin();

      iCircle += CircleIndex;

      CigiCircleSymbolTextureDataV4 *pCircle =
         (CigiCircleSymbolTextureDataV4 *)*iCircle;
      if(pCircle != NULL)
         delete pCircle;

      Circles.erase(iCircle);

      VariableDataSize -= CIGI_CIRCLE_SYMBOL_TEXTURE_DATA_SIZE_V4;
      if(VariableDataSize < 0)
         VariableDataSize = 0;

   }
   else
   {
#ifndef CIGI_NO_BND_CHK
      if(bndchk)
      {
#ifndef CIGI_NO_EXCEPT
         throw CigiValueOutOfRangeException("CircleIndex", (int)CircleIndex,0,Cnt);
#endif
         stat = CIGI_ERROR_VALUE_OUT_OF_RANGE;
      }
#endif
   }

   return(stat);
}



