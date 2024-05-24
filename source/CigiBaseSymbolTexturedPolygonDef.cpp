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
 *  FILENAME:   CigiBaseSymbolTexturedPolygonDef.cpp
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
 *  Based on CigiBaseSymbolLineDef.cpp
 *
 *	05/14/2019 Elliot Catalano                   Version 4.0.3
 *  Modified copy constructor and operator to correctly copy TextureID.
 *  Added implementation for SetTextureWrap and SetTextureFilter, defined in header.
 *
 * </pre>
 *  Author: The Boeing Company
 *
 */


#define _EXPORT_CCL_


#include "CigiBaseSymbolTexturedPolygonDef.h"
#include "CigiExceptions.h"

using namespace std;

// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiBaseSymbolTexturedPolygonDef
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseSymbolTexturedPolygonDef::CigiBaseSymbolTexturedPolygonDef(void)
{
}

// ================================================
// ~CigiBaseSymbolTexturedPolygonDef
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseSymbolTexturedPolygonDef::~CigiBaseSymbolTexturedPolygonDef(void)
{
   CigiBaseVertexSymbolData *pVtx;
   vector<CigiBaseVertexSymbolData *>::iterator iVtx;
   for(iVtx=Vertices.begin();iVtx!=Vertices.end();iVtx++)
   {
      pVtx = *iVtx;
      if(pVtx != NULL)
         delete pVtx;
   }
   Vertices.clear();
}


// ================================================
// CigiBaseSymbolLineDef - Copy constructor
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseSymbolTexturedPolygonDef::CigiBaseSymbolTexturedPolygonDef(const CigiBaseSymbolTexturedPolygonDef &BaseIn)
{
   SymbolID = BaseIn.SymbolID;
   TextureID = BaseIn.TextureID;
   Primitive = BaseIn.Primitive;
   TextureFilter = BaseIn.TextureFilter;
   TextureWrap = BaseIn.TextureWrap;
   // The Vertex Vector should be copied in the specific version class
}

// ================================================
// Copy operator
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseSymbolTexturedPolygonDef & CigiBaseSymbolTexturedPolygonDef::operator=(const CigiBaseSymbolTexturedPolygonDef &BaseIn)
{
   SymbolID = BaseIn.SymbolID;
   TextureID = BaseIn.TextureID;
   Primitive = BaseIn.Primitive;
   TextureFilter = BaseIn.TextureFilter;
   TextureWrap = BaseIn.TextureWrap;

   // The Vertex Vector should be copied in the specific version class

   return(*this);
}


// ====================================================================
// Conversion Control
// ====================================================================
int CigiBaseSymbolTexturedPolygonDef::GetCnvt(CigiVersionID &CnvtVersion,
                                CigiCnvtInfoType::Type &CnvtInfo)
{
    if (CnvtVersion.CigiMajorVersion < 4)
    {
	CnvtInfo.ProcID = CigiProcessType::ProcNone;
	CnvtInfo.CnvtPacketID = 0;
    }
    else {
	CnvtInfo.ProcID = CigiProcessType::ProcStd;
	CnvtInfo.CnvtPacketID = CIGI_SYMBOL_TEXTURED_POLYGON_DEFINITION_PACKET_ID_V4;
    }

   return(CIGI_SUCCESS);
}


// ====================================================================
// Accessors
// ====================================================================

// ================================================
// SetTextureFilter
// ================================================
int CigiBaseSymbolTexturedPolygonDef::SetTextureFilter(const TextureFilterMode TextureFilterIn, bool bndchk)
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
int CigiBaseSymbolTexturedPolygonDef::SetTextureWrap(const TextureWrapMode TextureWrapIn, bool bndchk)
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
// SetPrimitive
// ================================================
int CigiBaseSymbolTexturedPolygonDef::SetPrimitive(const PrimitiveGrp PrimitiveIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((PrimitiveIn < 0)||(PrimitiveIn > 6)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Primitive", (int)PrimitiveIn,0,6);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   Primitive = PrimitiveIn;

   return(CIGI_SUCCESS);

}

// ================================================
// GetVertexCount
// ================================================
int CigiBaseSymbolTexturedPolygonDef::GetVertexCount(void)
{
   return((int)Vertices.size());
}

// ================================================
// GetVertex
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseVertexSymbolData * CigiBaseSymbolTexturedPolygonDef::GetVertex(int VertexIndex, bool bndchk)
{
   CigiBaseVertexSymbolData * pVtx = NULL;

   if((VertexIndex >= 0) && ((Cigi_uint8)VertexIndex < Vertices.size()))
   {
      pVtx = Vertices[VertexIndex];
   }
   else
   {
#ifndef CIGI_NO_BND_CHK
      if(bndchk)
      {
#ifndef CIGI_NO_EXCEPT
         throw CigiValueOutOfRangeException("VertexIndex", VertexIndex,0,(int)Vertices.size());
#endif
      }
#endif
   }

   return(pVtx);
}

// ================================================
// ClearVertices
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiBaseSymbolTexturedPolygonDef::ClearVertices(void)
{
   CigiBaseVertexSymbolData *pVtx;
   vector<CigiBaseVertexSymbolData *>::iterator iVtx;
   for(iVtx=Vertices.begin();iVtx!=Vertices.end();iVtx++)
   {
      pVtx = *iVtx;
      if(pVtx != NULL)
         delete pVtx;
   }
   Vertices.clear();
   VariableDataSize = 0;
}


