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
 *  FILENAME:   CigiBaseSymbolTexturedCircleDef.cpp
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
 *  
 * </pre>
 *  Author: The Boeing Company
 *
 */


#define _EXPORT_CCL_


#include "CigiBaseSymbolTexturedCircleDef.h"
#include "CigiExceptions.h"

using namespace std;

// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiBaseSymbolCircleDef
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseSymbolTexturedCircleDef::CigiBaseSymbolTexturedCircleDef(void)
{
}

// ================================================
// ~CigiBaseSymbolCircleDef
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseSymbolTexturedCircleDef::~CigiBaseSymbolTexturedCircleDef(void)
{
   CigiBaseCircleSymbolTextureData *pCircle;
   vector<CigiBaseCircleSymbolTextureData *>::iterator iCircle;
   for(iCircle=Circles.begin();iCircle!=Circles.end();iCircle++)
   {
      pCircle = *iCircle;
      if(pCircle != NULL)
         delete pCircle;
   }
   Circles.clear();
}


// ================================================
// CigiBaseSymbolCircleDef - Copy constructor
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseSymbolTexturedCircleDef::CigiBaseSymbolTexturedCircleDef(const CigiBaseSymbolTexturedCircleDef &BaseIn)
{
   SymbolID = BaseIn.SymbolID;
   TextureID = BaseIn.TextureID;
   TextureFilter = BaseIn.TextureFilter;
   TextureWrap = BaseIn.TextureWrap;

   // The Circle Vector should be copied in the specific version class
}

// ================================================
// Copy operator
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseSymbolTexturedCircleDef & CigiBaseSymbolTexturedCircleDef::operator=(const CigiBaseSymbolTexturedCircleDef &BaseIn)
{
   SymbolID = BaseIn.SymbolID;
   TextureID = BaseIn.TextureID;
   TextureFilter = BaseIn.TextureFilter;
   TextureWrap = BaseIn.TextureWrap;

   // The Circle Vector should be copied in the specific version class

   return(*this);
}


// ====================================================================
// Conversion Control
// ====================================================================
int CigiBaseSymbolTexturedCircleDef::GetCnvt(CigiVersionID &CnvtVersion,
                                CigiCnvtInfoType::Type &CnvtInfo)
{
    if (CnvtVersion.CigiMajorVersion < 4)
    {
	CnvtInfo.ProcID = CigiProcessType::ProcNone;
	CnvtInfo.CnvtPacketID = 0;
    }
    else {
	CnvtInfo.ProcID = CigiProcessType::ProcStd;
	CnvtInfo.CnvtPacketID = CIGI_SYMBOL_TEXTURED_CIRCLE_DEFINITION_PACKET_ID_V4;
    }

   return(CIGI_SUCCESS);
}


// ====================================================================
// Accessors
// ====================================================================


// ================================================
// SetTextureFilter
// ================================================
int CigiBaseSymbolTexturedCircleDef::SetTextureFilter(const TextureFilterMode TextureFilterIn, bool bndchk)
{
#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((TextureFilterIn < 0)||(TextureFilterIn > 1)))
	{
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("TextureFilterIn",(double)TextureFilterIn,0.0,1.0);
#endif
	  return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
	}
#endif

	TextureFilter = TextureFilterIn;
	return(CIGI_SUCCESS);
}

// ================================================
// SetTextureWrap
// ================================================
int CigiBaseSymbolTexturedCircleDef::SetTextureWrap(const TextureWrapMode TextureWrapIn, bool bndchk)
{
#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((TextureWrapIn < 0)||(TextureWrapIn > 1)))
	{
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("TextureFilterIn",(float)TextureWrapIn,0.0,1.0);
#endif
	  return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
	}
#endif

	TextureWrap = TextureWrapIn;
	return(CIGI_SUCCESS);
}

// ================================================
// GetCircleCount
// ================================================
int CigiBaseSymbolTexturedCircleDef::GetCircleCount(void)
{
   return((int)Circles.size());
}

// ================================================
// GetCircle
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseCircleSymbolTextureData * CigiBaseSymbolTexturedCircleDef::GetCircle(int CircleIndex, bool bndchk)
{
   CigiBaseCircleSymbolTextureData * pCircle = NULL;

   if((CircleIndex >= 0) && ((Cigi_uint8)CircleIndex < Circles.size()))
   {
      pCircle = Circles[CircleIndex];
   }
   else
   {
#ifndef CIGI_NO_BND_CHK
      if(bndchk)
      {
#ifndef CIGI_NO_EXCEPT
         throw CigiValueOutOfRangeException("CircleIndex", (int)CircleIndex,0,(int)Circles.size());
#endif
      }
#endif
   }

   return(pCircle);
}

// ================================================
// ClearCircles
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiBaseSymbolTexturedCircleDef::ClearCircles(void)
{
   CigiBaseCircleSymbolTextureData *pCircle;
   vector<CigiBaseCircleSymbolTextureData *>::iterator iCircle;
   for(iCircle=Circles.begin();iCircle!=Circles.end();iCircle++)
   {
      pCircle = *iCircle;
      if(pCircle != NULL)
         delete pCircle;
   }
   Circles.clear();
   VariableDataSize = 0;
}


