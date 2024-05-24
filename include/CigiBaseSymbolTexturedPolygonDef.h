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
 *  FILENAME:   CigiBaseSymbolTexturedPolygonDef.h
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
 *  Based on CigiBaseSymbolTexturedDef.cpp
 *  
 * </pre>
 *  Author: The Boeing Company
 *
 */

#if !defined(_CIGI_BASE_SYMBOL_TEXTURED_POLYGON_DEF_INCLUDED_)
#define _CIGI_BASE_SYMBOL_TEXTURED_POLYGON_DEF_INCLUDED_


#include "CigiBaseVariableSizePckt.h"
#include "CigiVertexSymbolTextureDataV4.h"
#include <vector>


// ====================================================================
// preprocessor definitions
// ====================================================================

#define CIGI_SYMBOL_TEXTURED_POLYGON_DEFINITION_PACKET_ID_V4 0x24
#define CIGI_SYMBOL_TEXTURED_POLYGON_DEFINITION_PACKET_SIZE_V4 16 // + ( 16 * n )


class CigiSymbolTexturedPolygonDefV4;


//=========================================================
//! The base class for all packets.
//!
class CIGI_SPEC CigiBaseSymbolTexturedPolygonDef :
   public CigiBaseVariableSizePckt
{

   friend class CigiSymbolTexturedPolygonDefV4;

public:


   //=========================================================
   //! The enumeration for the CigiBaseSymbolLineDef
   //!   Datum type Group
   //!
   enum PrimitiveGrp
   {
// not valid      Points=0,
// not valid      Lines=1,
// not valid      LineStrip=2,
// not valid      LineLoop=3,
      Triangles=4,
      TriangleStrip=5,
      TriangleFan=6
   };

   //=========================================================
   //! The enumeration for the CigiBaseSymbolTexturedCircleDef
   //!   Texture Filter type Group
   //!
   enum TextureFilterMode
   {
      Nearest=0,
      Linear=1
   };

   //=========================================================
   //! The enumeration for the CigiBaseSymbolTexturedCircleDef
   //!   Texture Wrap type Group
   //!
   enum TextureWrapMode
   {
      Repeat=0,
      Clamp=1
   };



   //==> Management

   //=========================================================
   //! General Constructor
   //!
   CigiBaseSymbolTexturedPolygonDef(void);

   //=========================================================
   //! General Destructor
   //!
   virtual ~CigiBaseSymbolTexturedPolygonDef(void);

   //=========================================================
   //! Copy Constructor
   //!
   CigiBaseSymbolTexturedPolygonDef(const CigiBaseSymbolTexturedPolygonDef &BaseIn);

   //=========================================================
   //! Assignment operator
   //!
   CigiBaseSymbolTexturedPolygonDef & operator=(const CigiBaseSymbolTexturedPolygonDef &BaseIn);


   //==> Buffer Packing/Unpacking

   //=========================================================
   //! A pure virtual Pack function.  
   //! This function is not implemented in this class.
   //! \param Base - A pointer to the instance of the packet 
   //!          to be packed. (Downcast to CigiBasePacket)
   //! \param Buff - A pointer to the current pack point.
   //! \param Spec - A pointer to special data.
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const=0;

   //=========================================================
   //! A pure virtual Unpack function.
   //! This function is not implemented in this class.
   //! \param Buff - A pointer to the current pack point.
   //! \param Swap - N/A for V1 & V2
   //! \param Spec - A pointer to special data.
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec) =0;

   //=========================================================
   //! A pure virtual function to determine the size that the
   //!  packet will take up when packed.
   //! This function is not implemented in this class.
   //! \param refPacket - A pointer to the current pack point.
   //!
   //! \return The size that the packet will take up when packed
   //!
	virtual int GetTruePacketSize(CigiBaseVariableSizePckt &refPacket)
   { return(PacketSize + refPacket.GetVariableDataSize()); }

   //=========================================================
   //! A virtual Conversion Information function.
   //! This function provides conversion information for this
   //!  packet.
   //! \param CnvtVersion - The CIGI version to which this packet
   //!    is being converted.
   //! \param CnvtInfo - The information needed for conversion
   //!    
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	virtual int GetCnvt(CigiVersionID &CnvtVersion,
                       CigiCnvtInfoType::Type &CnvtInfo);



   //==> Accessing Member Variable Values functions

   //+> SymbolID

   //=========================================================
   //! Sets the SymbolID with bound checking control
   //! \param SymbolIDIn - The ID number of this symbol.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetSymbolID(const Cigi_uint16 SymbolIDIn, bool bndchk=true)
   {
      SymbolID = SymbolIDIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the SymbolID with bound checking control
   //! \return The ID number of this Symbol.
   //!
   Cigi_uint16 GetSymbolID(void) const { return(SymbolID); }
   

   //+> Primitive

   //=========================================================
   //! Sets the Primitive with bound checking control
   //! \param PrimitiveIn - Specifies the primatives used in this symbol.
   //!   (Points, Lines, LineStrip, LineLoop, Triangles,
   //!   TriangleStrip, TriangleFan)
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetPrimitive(const PrimitiveGrp PrimitiveIn, bool bndchk=true);

   //=========================================================
   //! Gets the Primitive with bound checking control
   //! \return The Primitive used in this symbol
   //!   (Points, Lines, LineStrip, LineLoop, Triangles,
   //!   TriangleStrip, TriangleFan)
   //!
   PrimitiveGrp GetPrimitive(void) const { return(Primitive); }


   //+> TextureID

   //=========================================================
   //! Sets the TextureID with bound checking control
   //! \param TextureIDIn - Specifies the ID number for this symbol's
   //! texture
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetTextureID(const Cigi_uint16 TextureIDIn, bool bndchk=true)
   {
      TextureID = TextureIDIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the TextureID with bound checking control
   //! \return TextureID
   //!
   Cigi_uint16 GetTextureID(void) const { return(TextureID); }
   
   //+> TextureFilter

   //=========================================================
   //! Sets the TextureFilter with bound checking control
   //! \param TextureFilterIn - Specifies this symbol's
   //! texture filtering mode
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetTextureFilter(const TextureFilterMode TextureFilterIn, bool bndchk=true);

   //=========================================================
   //! Gets the TextureFilter with bound checking control
   //! \return TextureFilter
   //!
   TextureFilterMode GetTextureFilter(void) const { return(TextureFilter); }
   

   //+> TextureWrap

   //=========================================================
   //! Sets the TextureWrap with bound checking control
   //! \param TextureWrapIn - Specifies this symbol's
   //! texture wrap mode
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetTextureWrap(const TextureWrapMode TextureWrapIn, bool bndchk=true);

   //=========================================================
   //! Gets the TextureWrap with bound checking control
   //! \return TextureWrap
   //!
   TextureWrapMode GetTextureWrap(void) const { return(TextureWrap); }
    

   //+> Vertices

   //=========================================================
   //! Gets the number of vertices contained in this symbol
   //!   with bound checking control.
   //! \return The vertex count.
   //!
   int GetVertexCount(void);

   //=========================================================
   //! A pure virtual Create Vertex function.  
   //! This function is not implemented in this class.
   //! The implemented function will create a Vertex object and
   //!   insert a pointer into the Vertex Vector.
   //!
   //! \return The pointer to the new Vertex object.
   //!   If the Vertex exceeds the maximum number of Vertices
   //!   or the Vertex object cannot be created, this will
   //!   return a NULL pointer.
   virtual CigiBaseVertexSymbolData * AddVertex(void) =0;

   //=========================================================
   //! A pure virtual Remove Vertex function.  
   //! This function is not implemented in this class.
   //! The implemented function will remove a Vertex object
   //!   from the Vertex Vector.
   //! \param VertexIndex - The index of the vertex to be removed.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   virtual int RemoveVertex(int VertexIndex, bool bndchk=true) =0;

   //=========================================================
   //! Gets a pointer to a Vertex object.
   //! \param VertexIndex - The index of the desired vertex.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return The pointer to the desired Vertex object.
   //!   If the Vertex does not exist, the return is a NULL pointer.
   CigiBaseVertexSymbolData * GetVertex(int VertexIndex, bool bndchk=true);

   //=========================================================
   //! Removes all vertices from the symbol.
   //!
   void ClearVertices(void);



protected:

   //==> Member variables

   //=========================================================
   //! SymbolID<br>
   //! The ID number of the symbol.
   //!
   Cigi_uint16 SymbolID;

   //=========================================================
   //! Primitive<br>
   //! The drawing primitive used in this symbol.<br>
   //!   Triangles<br>
   //!   TriangleStrip<br>
   //!   TriangleFan
   //!
   PrimitiveGrp Primitive;

   //=========================================================
   //! TextureID<br>
   //! The ID number of this symbol's texture.
   //!
   Cigi_uint16 TextureID;

   //=========================================================
   //! TextureFilter<br>
   //! This symbol's texture filtering mode.
   //!
	TextureFilterMode TextureFilter;

   //=========================================================
   //! TextureWrap<br>
   //! This symbol's texture wrap mode.
   //!
	TextureWrapMode TextureWrap;

   //=========================================================
   //! Vertices<br>
   //! A dynamic array of vertices.
   //!
   std::vector<CigiBaseVertexSymbolData *> Vertices;


};



#endif   //  #if !defined(_CIGI_BASE_SYMBOL_TEXTURED_POLYGON_DEF_INCLUDED_)

