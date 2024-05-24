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
 *  FILENAME:   CigiSymbolTexturedPolygonDefV4.cpp
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
 *  07/29/2015 Chas Whitley                      Version 4.0.0
 *  Initial Release for CIGI 4.0 compatibility.
 *  Based on CigiSymbolPolygonDefV4.cpp
 *  
 *	05/14/2019 Elliot Catalano                   Version 4.0.3
 *  Modified Copy Constructor and Operator to copy correct corresponding data.
 *  Modified Pack method to fix data misalignment issues.
 *  
 * 
 *  
 * </pre>
 *  Author: The Boeing Company
 *
 */


#define _EXPORT_CCL_


#include "CigiSymbolTexturedPolygonDefV4.h"
#include "CigiSwapping.h"
#include "CigiExceptions.h"

using namespace std;

// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiBaseEntityCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSymbolTexturedPolygonDefV4::CigiSymbolTexturedPolygonDefV4(void)
{
   PacketID = CIGI_SYMBOL_TEXTURED_POLYGON_DEFINITION_PACKET_ID_V4;
   PacketSize = CIGI_SYMBOL_TEXTURED_POLYGON_DEFINITION_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;
   VariableDataSize = 0;

   SymbolID = 0;
   TextureID = 0;
   TextureFilter = Nearest;
   TextureWrap = Clamp;
   Primitive = Triangles;

}

// ================================================
// ~CigiBaseEntityCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSymbolTexturedPolygonDefV4::~CigiSymbolTexturedPolygonDefV4(void)
{
}

// ================================================
// CigiSymbolPolygonDefV4 - Copy constructor
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSymbolTexturedPolygonDefV4::CigiSymbolTexturedPolygonDefV4(const CigiSymbolTexturedPolygonDefV4 &BaseIn)
: CigiBaseSymbolTexturedPolygonDef((CigiBaseSymbolTexturedPolygonDef &)BaseIn)
{
   PacketID = CIGI_SYMBOL_TEXTURED_POLYGON_DEFINITION_PACKET_ID_V4;
   PacketSize = CIGI_SYMBOL_TEXTURED_POLYGON_DEFINITION_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;

   VariableDataSize = 0;

   SymbolID = BaseIn.SymbolID;
   TextureID = BaseIn.TextureID;
   TextureFilter = BaseIn.TextureFilter;
   TextureWrap = BaseIn.TextureWrap;
   Primitive = BaseIn.Primitive;

   CigiVertexSymbolTextureDataV4 *NewVertex = NULL;
   CigiVertexSymbolTextureDataV4 *pVtx;
   vector<CigiBaseVertexSymbolData *>::const_iterator iVtx;
   for(iVtx=BaseIn.Vertices.begin();iVtx!=BaseIn.Vertices.end();iVtx++)
   {
      pVtx = (CigiVertexSymbolTextureDataV4 *)*iVtx;
      if(pVtx != NULL)
      {
         NewVertex = new CigiVertexSymbolTextureDataV4;
         *NewVertex = *pVtx;
         Vertices.push_back((CigiBaseVertexSymbolData *)NewVertex);
         VariableDataSize += CIGI_VERTEX_SYMBOL_TEXTURE_DATA_SIZE_V4;
      }
   }
}

// ================================================
// Copy operator
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSymbolTexturedPolygonDefV4 & CigiSymbolTexturedPolygonDefV4::operator=(const CigiSymbolTexturedPolygonDefV4 &BaseIn)
{
   PacketID = CIGI_SYMBOL_TEXTURED_POLYGON_DEFINITION_PACKET_ID_V4;
   PacketSize = CIGI_SYMBOL_TEXTURED_POLYGON_DEFINITION_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;

   CigiBaseVertexSymbolData *pbVertex;
   vector<CigiBaseVertexSymbolData *>::iterator ibVertex;
   for(ibVertex=Vertices.begin();ibVertex!=Vertices.end();ibVertex++)
   {
      pbVertex = *ibVertex;
      if(pbVertex != NULL)
         delete pbVertex;
   }
   Vertices.clear();
   VariableDataSize = 0;

   SymbolID = BaseIn.SymbolID;
   TextureID = BaseIn.TextureID;
   TextureFilter = BaseIn.TextureFilter;
   TextureWrap = BaseIn.TextureWrap;
   Primitive = BaseIn.Primitive;

   CigiVertexSymbolTextureDataV4 *NewVertex = NULL;
   CigiVertexSymbolTextureDataV4 *pVtx;
   vector<CigiBaseVertexSymbolData *>::const_iterator iVtx;
   for(iVtx=BaseIn.Vertices.begin();iVtx!=BaseIn.Vertices.end();iVtx++)
   {
      pVtx = (CigiVertexSymbolTextureDataV4 *)*iVtx;
      if(pVtx != NULL)
      {
         NewVertex = new CigiVertexSymbolTextureDataV4;
         *NewVertex = *pVtx;
         Vertices.push_back((CigiBaseVertexSymbolData *)NewVertex);
         VariableDataSize += CIGI_VERTEX_SYMBOL_TEXTURE_DATA_SIZE_V4;
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
int CigiSymbolTexturedPolygonDefV4::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   PackPointer CDta;

   CigiSymbolTexturedPolygonDefV4 * Data = ( CigiSymbolTexturedPolygonDefV4 *)Base;

   CDta.c = Buff;

   *CDta.s++ = (PacketSize + Data->VariableDataSize);
   *CDta.s++ = PacketID;

   *CDta.s++ = Data->SymbolID;
   *CDta.s++ = Data->TextureID;

	Cigi_uint8 HDta;
	HDta =  ( Data->TextureFilter & 0x01 );
    HDta |= ( ( Data->TextureWrap << 1 ) & 0x02 );
    HDta |= ( ( Data->Primitive << 4 ) & 0xf0);
    *CDta.c++ = HDta;

   *CDta.c++ = 0; // reserved
   *CDta.s++ = 0; // reserved
   *CDta.l++ = 0; // reserved


   int Cnt;
   CigiVertexSymbolTextureDataV4 *pVtx;
   vector<CigiBaseVertexSymbolData *>::iterator iVtx;
   for(iVtx=Data->Vertices.begin();iVtx!=Data->Vertices.end();iVtx++)
   {
      pVtx = (CigiVertexSymbolTextureDataV4 *)*iVtx;
      if(pVtx != NULL)
      {
         Cnt = pVtx->Pack((CigiBaseVertexSymbolData *)pVtx,CDta.c);
         CDta.c += Cnt;
      }
   }

   return(PacketSize + Data->VariableDataSize);

}

// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSymbolTexturedPolygonDefV4::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{
   PackPointer CDta;
   unsigned char HDta = 0;

   CDta.c = Buff;

   // Clear the current Vertex Vector
   CigiBaseVertexSymbolData *pbVtx;
   vector<CigiBaseVertexSymbolData *>::iterator ibVtx;
   for(ibVtx=Vertices.begin();ibVtx!=Vertices.end();ibVtx++)
   {
      pbVtx = *ibVtx;
      if(pbVtx != NULL)
         delete pbVtx;
   }
   Vertices.clear();
   VariableDataSize = 0;


   // Determine variable data size;
   unsigned int PcktRemain = *CDta.s;
   PcktRemain -= CIGI_SYMBOL_TEXTURED_POLYGON_DEFINITION_PACKET_SIZE_V4;
   VariableDataSize = PcktRemain;

   CDta.c += 4;  // Step over packet id and size

   if(!Swap)
   {
      SymbolID = *CDta.s++;
      TextureID = *CDta.s++;
      HDta = *CDta.c++;
      *CDta.c++; // reserved
      *CDta.s++; // reserved
      *CDta.l++; // reserved
   }
   else
   {
      CigiSwap2(&SymbolID, CDta.s++);
      CigiSwap2(&TextureID, CDta.s++);
      HDta = *CDta.c++;
      *CDta.c++;
      *CDta.s++;
      *CDta.l++; // reserved
   }

   TextureFilter = ( TextureFilterMode ) ( HDta & 0x01 );
   TextureWrap = ( TextureWrapMode ) ( ( HDta >> 1 ) & 0x01 );
   Primitive = (PrimitiveGrp)( ( HDta >> 4 ) & 0x0f);

   // Unpack Vertices
   int cnt = 0;
   CigiVertexSymbolTextureDataV4 *pVtx;
   while(PcktRemain >= CIGI_VERTEX_SYMBOL_TEXTURE_DATA_SIZE_V4)
   {
      pVtx = new CigiVertexSymbolTextureDataV4;
      Vertices.push_back((CigiBaseVertexSymbolData *)pVtx);
      cnt = pVtx->Unpack(CDta.c,Swap);
      PcktRemain -= cnt;
      CDta.c += cnt;
   }

   return(PacketSize + VariableDataSize);

}



// ====================================================================
// Vertex Operation
// ====================================================================

// ================================================
// AddVertex
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiVertexSymbolTextureDataV4 * CigiSymbolTexturedPolygonDefV4::AddVertex(void)
{
   CigiVertexSymbolTextureDataV4 *NewVertex = NULL;
   int Cnt = (int)Vertices.size();

   if(Cnt < 29)
   {
      NewVertex = new CigiVertexSymbolTextureDataV4;
      Vertices.push_back((CigiBaseVertexSymbolData *)NewVertex);
      VariableDataSize += CIGI_VERTEX_SYMBOL_TEXTURE_DATA_SIZE_V4;
   }

   return(NewVertex);
}

// ================================================
// RemoveVertex
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSymbolTexturedPolygonDefV4::RemoveVertex(int VertexIndex, bool bndchk)
{
   int stat = CIGI_SUCCESS;

   int Cnt = (int)Vertices.size();

   if((VertexIndex >= 0) && (VertexIndex < Cnt))
   {
      vector<CigiBaseVertexSymbolData *>::iterator iVtx = Vertices.begin();

      iVtx += VertexIndex;

      CigiVertexSymbolTextureDataV4 *pVtx =
         (CigiVertexSymbolTextureDataV4 *)*iVtx;
      if(pVtx != NULL)
         delete pVtx;

      Vertices.erase(iVtx);

      VariableDataSize -= CIGI_VERTEX_SYMBOL_TEXTURE_DATA_SIZE_V4;
      if(VariableDataSize < 0)
         VariableDataSize = 0;

   }
   else
   {
#ifndef CIGI_NO_BND_CHK
      if(bndchk)
      {
#ifndef CIGI_NO_EXCEPT
         throw CigiValueOutOfRangeException("VertexIndex", (int)VertexIndex,0,Cnt);
#endif
         stat = CIGI_ERROR_VALUE_OUT_OF_RANGE;
      }
#endif
   }

   return(stat);
}



