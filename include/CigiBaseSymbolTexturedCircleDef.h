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
 *  FILENAME:   CigiBaseSymbolTexturedCircleDef.h
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

#if !defined(_CIGI_BASE_SYMBOL_TEXTURED_CIRCLE_DEF_INCLUDED_)
#define _CIGI_BASE_SYMBOL_TEXTURED_CIRCLE_DEF_INCLUDED_


#include "CigiBaseVariableSizePckt.h"
#include "CigiBaseCircleSymbolTextureData.h"
#include <vector>


// ====================================================================
// preprocessor definitions
// ====================================================================

#define CIGI_SYMBOL_TEXTURED_CIRCLE_DEFINITION_PACKET_ID_V4 0x23
#define CIGI_SYMBOL_TEXTURED_CIRCLE_DEFINITION_PACKET_SIZE_V4 16 // + ( 40 * n ), n = number of textured circle definitions


class CigiSymbolTexturedCircleDefV4;


//=========================================================
//! The base class for all packets.
//!
class CIGI_SPEC CigiBaseSymbolTexturedCircleDef :
   public CigiBaseVariableSizePckt
{

   friend class CigiSymbolTexturedCircleDefV4;

public:


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
   CigiBaseSymbolTexturedCircleDef(void);

   //=========================================================
   //! General Destructor
   //!
   virtual ~CigiBaseSymbolTexturedCircleDef(void);

   //=========================================================
   //! Copy Constructor
   //!
   CigiBaseSymbolTexturedCircleDef(const CigiBaseSymbolTexturedCircleDef &BaseIn);

   //=========================================================
   //! Assignment operator
   //!
   CigiBaseSymbolTexturedCircleDef & operator=(const CigiBaseSymbolTexturedCircleDef &BaseIn);


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
   //! \param SymbolIDIn - Specifies the ID number for this symbol
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
   //! \return SymbolID
   //!
   Cigi_uint16 GetSymbolID(void) const { return(SymbolID); }
   
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
   

   //+> Circles

   //=========================================================
   //! Gets the number of circle symbols.
   //! \return Gets the number of circles contained in this symbol.
   //!
   int GetCircleCount(void);

   //=========================================================
   //! A pure virtual Create Circle function.  
   //! This function is not implemented in this class.
   //! The implemented function will create a circle object and
   //!   insert a pointer into the Circle Vector.
   //!
   //! \return The pointer to the new circle object.
   //!   If the circle exceeds the maximum number of circles
   //!   or the circle object cannot be created, this will
   //!   return a NULL pointer.
   virtual CigiBaseCircleSymbolTextureData * AddCircle(void) =0;

   //=========================================================
   //! A pure virtual Remove Circle function.  
   //! This function is not implemented in this class.
   //! The implemented function will remove a Circle object
   //!   from the Circle Vector.
   //! \param CircleIndex - The index of the circle to delete from this
   //!   symbol.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   virtual int RemoveCircle(int CircleIndex, bool bndchk=true) =0;

   //=========================================================
   //! Gets a pointer to a circle object.
   //! \param CircleIndex - The index of the desired circle.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return The pointer to the desired circle object.
   //!   If the circle does not exist, the return is a NULL pointer.
   CigiBaseCircleSymbolTextureData * GetCircle(int CircleIndex, bool bndchk=true);

   //=========================================================
   //! Removes all the circles in this symbol.
   //!
   void ClearCircles(void);



protected:

   //==> Member variables

   //=========================================================
   //! SymbolID<br>
   //! The ID number of this symbol.
   //!
   Cigi_uint16 SymbolID;

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
   //! Circles<br>
   //! A dynamic array of circles in this symbol
   //!
   std::vector<CigiBaseCircleSymbolTextureData *> Circles;


};



#endif   //  #if !defined(_CIGI_BASE_SYMBOL_TEXTURED_CIRCLE_DEF_INCLUDED_)

