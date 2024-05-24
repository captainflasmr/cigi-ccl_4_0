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
 *  FILENAME:   CigiSymbolCircleDefV4.cpp
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
 * </pre>
 *  Author: The Boeing Company
 *
 */


#define _EXPORT_CCL_


#include "CigiSymbolCircleDefV4.h"
#include "CigiSwapping.h"
#include "CigiExceptions.h"

using namespace std;

// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiBaseEntityCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSymbolCircleDefV4::CigiSymbolCircleDefV4(void)
{
   PacketID = CIGI_SYMBOL_CIRCLE_DEFINITION_PACKET_ID_V4;
   PacketSize = CIGI_SYMBOL_CIRCLE_DEFINITION_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;
   VariableDataSize = 0;

   SymbolID = 0;
   DrawingStyle = Line;
   StipplePattern = 0;
   LineWidth = 0.0f;
   StipplePatternLen = 0.0f;

}

// ================================================
// ~CigiBaseEntityCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSymbolCircleDefV4::~CigiSymbolCircleDefV4(void)
{
}

// ================================================
// CigiSymbolCircleDefV4 - Copy constructor
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSymbolCircleDefV4::CigiSymbolCircleDefV4(const CigiSymbolCircleDefV4 &BaseIn)
: CigiBaseSymbolCircleDef((CigiBaseSymbolCircleDef &)BaseIn)
{
   PacketID = CIGI_SYMBOL_CIRCLE_DEFINITION_PACKET_ID_V4;
   PacketSize = CIGI_SYMBOL_CIRCLE_DEFINITION_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;

   VariableDataSize = 0;

   SymbolID = BaseIn.SymbolID;
   DrawingStyle = BaseIn.DrawingStyle;
   StipplePattern = BaseIn.StipplePattern;
   LineWidth = BaseIn.LineWidth;
   StipplePatternLen = BaseIn.StipplePatternLen;

   CigiCircleSymbolDataV4 *NewCircle = NULL;
   CigiCircleSymbolDataV4 *pCircle;
   vector<CigiBaseCircleSymbolData *>::const_iterator iCircle;
   for(iCircle=BaseIn.Circles.begin();iCircle!=BaseIn.Circles.end();iCircle++)
   {
      pCircle = (CigiCircleSymbolDataV4 *)*iCircle;
      if(pCircle != NULL)
      {
         NewCircle = new CigiCircleSymbolDataV4;
         *NewCircle = *pCircle;
         Circles.push_back((CigiBaseCircleSymbolData *)NewCircle);
         VariableDataSize += CIGI_CIRCLE_SYMBOL_DATA_SIZE_V4;
      }
   }
}

// ================================================
// Copy Operator
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSymbolCircleDefV4 & CigiSymbolCircleDefV4::operator=(const CigiSymbolCircleDefV4 &BaseIn)
{
   PacketID = CIGI_SYMBOL_CIRCLE_DEFINITION_PACKET_ID_V4;
   PacketSize = CIGI_SYMBOL_CIRCLE_DEFINITION_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;

   CigiBaseCircleSymbolData *pbCircle;
   vector<CigiBaseCircleSymbolData *>::iterator ibCircle;
   for(ibCircle=Circles.begin();ibCircle!=Circles.end();ibCircle++)
   {
      pbCircle = *ibCircle;
      if(pbCircle != NULL)
         delete pbCircle;
   }
   Circles.clear();
   VariableDataSize = 0;

   SymbolID = BaseIn.SymbolID;
   DrawingStyle = BaseIn.DrawingStyle;
   StipplePattern = BaseIn.StipplePattern;
   LineWidth = BaseIn.LineWidth;
   StipplePatternLen = BaseIn.StipplePatternLen;

   CigiCircleSymbolDataV4 *NewCircle = NULL;
   CigiCircleSymbolDataV4 *pCircle;
   vector<CigiBaseCircleSymbolData *>::const_iterator iCircle;
   for(iCircle=BaseIn.Circles.begin();iCircle!=BaseIn.Circles.end();iCircle++)
   {
      pCircle = (CigiCircleSymbolDataV4 *)*iCircle;
      if(pCircle != NULL)
      {
         NewCircle = new CigiCircleSymbolDataV4;
         *NewCircle = *pCircle;
         Circles.push_back((CigiBaseCircleSymbolData *)NewCircle);
         VariableDataSize += CIGI_CIRCLE_SYMBOL_DATA_SIZE_V4;
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
int CigiSymbolCircleDefV4::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   PackPointer CDta;

   CigiSymbolCircleDefV4 * Data =
      ( CigiSymbolCircleDefV4 *)Base;

   CDta.c = Buff;


   *CDta.s++ = (PacketSize + Data->VariableDataSize);
   *CDta.s++ =  PacketID;

   *CDta.s++ = Data->SymbolID;
   *CDta.s++ = Data->StipplePattern;
   *CDta.c++ = (Data->DrawingStyle != 0) ? 1 : 0;

   *CDta.c++ = 0; // reserved
   *CDta.s++ = 0; // reserved

   *CDta.f++ = Data->LineWidth;
   *CDta.f++ = Data->StipplePatternLen;
   *CDta.l++ = 0; // reserved

   int Cnt;
   CigiCircleSymbolDataV4 *pCircle;
   vector<CigiBaseCircleSymbolData *>::iterator iCircle;
   for(iCircle=Data->Circles.begin();iCircle!=Data->Circles.end();iCircle++)
   {
      pCircle = (CigiCircleSymbolDataV4 *)*iCircle;
      if(pCircle != NULL)
      {
         Cnt = pCircle->Pack((CigiBaseCircleSymbolData *)pCircle,CDta.c);
         CDta.c += Cnt;
      }
   }

   return(PacketSize + Data->VariableDataSize);

}

// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSymbolCircleDefV4::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{
   PackPointer CDta;
   unsigned char HDta = 0;

   CDta.c = Buff;

   // Clear the current Circle Vector
   CigiBaseCircleSymbolData *pbCircle;
   vector<CigiBaseCircleSymbolData *>::iterator ibCircle;
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
   PcktRemain -= CIGI_SYMBOL_CIRCLE_DEFINITION_PACKET_SIZE_V4;
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
      CDta.c++; // reserved
      CDta.s++; // reserved
      CigiSwap4(&LineWidth, CDta.f++);
      CigiSwap4(&StipplePatternLen, CDta.f++);
      CDta.l++; // reserved
   }

   DrawingStyle = (HDta != 0) ? Fill : Line ;

   // Unpack Circles
   int cnt = 0;
   CigiCircleSymbolDataV4 *pCircle;
   while(PcktRemain >= CIGI_CIRCLE_SYMBOL_DATA_SIZE_V4)
   {
      pCircle = new CigiCircleSymbolDataV4;
      Circles.push_back((CigiBaseCircleSymbolData *)pCircle);
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
CigiBaseCircleSymbolData * CigiSymbolCircleDefV4::AddCircle(void)
{
   CigiCircleSymbolDataV4 *NewCircle = NULL;
   int Cnt = (int)Circles.size();

   if(Cnt < 10)
   {
      NewCircle = new CigiCircleSymbolDataV4;
      Circles.push_back((CigiBaseCircleSymbolData *)NewCircle);
      VariableDataSize += CIGI_CIRCLE_SYMBOL_DATA_SIZE_V4;
   }

   return((CigiBaseCircleSymbolData *)NewCircle);
}

// ================================================
// RemoveCircle
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSymbolCircleDefV4::RemoveCircle(int CircleIndex, bool bndchk)
{
   int stat = CIGI_SUCCESS;

   int Cnt = (int)Circles.size();

   if((CircleIndex >= 0) && (CircleIndex < Cnt))
   {
      vector<CigiBaseCircleSymbolData *>::iterator iCircle = Circles.begin();

      iCircle += CircleIndex;

      CigiCircleSymbolDataV4 *pCircle =
         (CigiCircleSymbolDataV4 *)*iCircle;
      if(pCircle != NULL)
         delete pCircle;

      Circles.erase(iCircle);

      VariableDataSize -= CIGI_CIRCLE_SYMBOL_DATA_SIZE_V4;
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



