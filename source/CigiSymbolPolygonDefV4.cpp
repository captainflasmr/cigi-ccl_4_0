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
 *  FILENAME:   CigiSymbolPolygonDefV4.cpp
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
 *  Based on CigiSymbolLineDefV3_3.cpp
 *  
 * </pre>
 *  Author: The Boeing Company
 *
 */


#define _EXPORT_CCL_


#include "CigiSymbolPolygonDefV4.h"
#include "CigiSwapping.h"
#include "CigiExceptions.h"

using namespace std;

// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiBaseEntityCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSymbolPolygonDefV4::CigiSymbolPolygonDefV4(void)
{
   PacketID = CIGI_SYMBOL_POLYGON_DEFINITION_PACKET_ID_V4;
   PacketSize = CIGI_SYMBOL_POLYGON_DEFINITION_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;
   VariableDataSize = 0;

   SymbolID = 0;
   Primitive = Points;
   StipplePattern = 0;
   LineWidth = 0.0f;
   StipplePatternLen = 0.0f;

}

// ================================================
// ~CigiBaseEntityCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSymbolPolygonDefV4::~CigiSymbolPolygonDefV4(void)
{
}

// ================================================
// CigiSymbolPolygonDefV4 - Copy constructor
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSymbolPolygonDefV4::CigiSymbolPolygonDefV4(const CigiSymbolPolygonDefV4 &BaseIn)
: CigiBaseSymbolLineDef((CigiBaseSymbolLineDef &)BaseIn)
{
   PacketID = CIGI_SYMBOL_POLYGON_DEFINITION_PACKET_ID_V4;
   PacketSize = CIGI_SYMBOL_POLYGON_DEFINITION_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;

   VariableDataSize = 0;

   SymbolID = BaseIn.SymbolID;
   Primitive = BaseIn.Primitive;
   StipplePattern = BaseIn.StipplePattern;
   LineWidth = BaseIn.LineWidth;
   StipplePatternLen = BaseIn.StipplePatternLen;

   CigiVertexSymbolDataV4 *NewVertex = NULL;
   CigiVertexSymbolDataV4 *pVtx;
   vector<CigiBaseVertexSymbolData *>::const_iterator iVtx;
   for(iVtx=BaseIn.Vertices.begin();iVtx!=BaseIn.Vertices.end();iVtx++)
   {
      pVtx = (CigiVertexSymbolDataV4 *)*iVtx;
      if(pVtx != NULL)
      {
         NewVertex = new CigiVertexSymbolDataV4;
         *NewVertex = *pVtx;
         Vertices.push_back((CigiBaseVertexSymbolData *)NewVertex);
         VariableDataSize += CIGI_VERTEX_SYMBOL_DATA_SIZE_V4;
      }
   }
}

// ================================================
// Copy operator
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSymbolPolygonDefV4 & CigiSymbolPolygonDefV4::operator=(const CigiSymbolPolygonDefV4 &BaseIn)
{
   PacketID = CIGI_SYMBOL_POLYGON_DEFINITION_PACKET_ID_V4;
   PacketSize = CIGI_SYMBOL_POLYGON_DEFINITION_PACKET_SIZE_V4;
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
   Primitive = BaseIn.Primitive;
   StipplePattern = BaseIn.StipplePattern;
   LineWidth = BaseIn.LineWidth;
   StipplePatternLen = BaseIn.StipplePatternLen;

   CigiVertexSymbolDataV4 *NewVertex = NULL;
   CigiVertexSymbolDataV4 *pVtx;
   vector<CigiBaseVertexSymbolData *>::const_iterator iVtx;
   for(iVtx=BaseIn.Vertices.begin();iVtx!=BaseIn.Vertices.end();iVtx++)
   {
      pVtx = (CigiVertexSymbolDataV4 *)*iVtx;
      if(pVtx != NULL)
      {
         NewVertex = new CigiVertexSymbolDataV4;
         *NewVertex = *pVtx;
         Vertices.push_back((CigiBaseVertexSymbolData *)NewVertex);
         VariableDataSize += CIGI_VERTEX_SYMBOL_DATA_SIZE_V4;
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
int CigiSymbolPolygonDefV4::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   PackPointer CDta;

   CigiBaseSymbolLineDef * Data = (CigiBaseSymbolLineDef *)Base;

   CDta.c = Buff;

   *CDta.s++ = (PacketSize + Data->VariableDataSize);
   *CDta.s++ = PacketID;

   *CDta.s++ = Data->SymbolID;
   *CDta.s++ = Data->StipplePattern;

   *CDta.c++ = (Cigi_uint8)(Data->Primitive & 0x0f);

   *CDta.c++ = 0; // reserved
   *CDta.s++ = 0; // reserved

   *CDta.f++ = Data->LineWidth;
   *CDta.f++ = Data->StipplePatternLen;

   *CDta.l++ = 0; // reserved

   int Cnt;
   CigiVertexSymbolDataV4 *pVtx;
   vector<CigiBaseVertexSymbolData *>::iterator iVtx;
   for(iVtx=Data->Vertices.begin();iVtx!=Data->Vertices.end();iVtx++)
   {
      pVtx = (CigiVertexSymbolDataV4 *)*iVtx;
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
int CigiSymbolPolygonDefV4::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
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
   PcktRemain -= CIGI_SYMBOL_POLYGON_DEFINITION_PACKET_SIZE_V4;
   VariableDataSize = PcktRemain;

   CDta.c += 4;  // Step over packet id and size

   if(!Swap)
   {
      SymbolID = *CDta.s++;
      StipplePattern = *CDta.s++;
      HDta = *CDta.c++;
      CDta.c++; // reserved
      CDta.s++; // reserved
      LineWidth = *CDta.f++;
      StipplePatternLen = *CDta.f++;
      CDta.l++; // reserved
   }
   else
   {
      CigiSwap2(&SymbolID, CDta.s++);
      CigiSwap2(&StipplePattern, CDta.s++);
      HDta = *CDta.c++;
      CDta.c++;
      CDta.s++;
      CigiSwap4(&LineWidth, CDta.f++);
      CigiSwap4(&StipplePatternLen, CDta.f++);
      CDta.l++; // reserved
   }

   Primitive = (PrimitiveGrp)(HDta & 0x0f);

   // Unpack Vertices
   int cnt = 0;
   CigiVertexSymbolDataV4 *pVtx;
   while(PcktRemain >= CIGI_VERTEX_SYMBOL_DATA_SIZE_V4)
   {
      pVtx = new CigiVertexSymbolDataV4;
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
CigiBaseVertexSymbolData * CigiSymbolPolygonDefV4::AddVertex(void)
{
   CigiVertexSymbolDataV4 *NewVertex = NULL;
   int Cnt = (int)Vertices.size();

   if(Cnt < 29)
   {
      NewVertex = new CigiVertexSymbolDataV4;
      Vertices.push_back((CigiBaseVertexSymbolData *)NewVertex);
      VariableDataSize += CIGI_VERTEX_SYMBOL_DATA_SIZE_V4;
   }

   return((CigiBaseVertexSymbolData *)NewVertex);
}

// ================================================
// RemoveVertex
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSymbolPolygonDefV4::RemoveVertex(int VertexIndex, bool bndchk)
{
   int stat = CIGI_SUCCESS;

   int Cnt = (int)Vertices.size();

   if((VertexIndex >= 0) && (VertexIndex < Cnt))
   {
      vector<CigiBaseVertexSymbolData *>::iterator iVtx = Vertices.begin();

      iVtx += VertexIndex;

      CigiVertexSymbolDataV4 *pVtx =
         (CigiVertexSymbolDataV4 *)*iVtx;
      if(pVtx != NULL)
         delete pVtx;

      Vertices.erase(iVtx);

      VariableDataSize -= CIGI_VERTEX_SYMBOL_DATA_SIZE_V4;
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



