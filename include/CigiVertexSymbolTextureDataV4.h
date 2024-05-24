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
 *  FILENAME:   CigiVertexSymbolTextureDataV4.h
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
 *  11/20/2007 Greg Basler                       Version 2.0.0
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

#if !defined(_CIGI_VERTEX_SYMBOL_TEXTURE_DATA_V4_INCLUDED_)
#define _CIGI_VERTEX_SYMBOL_TEXTURE_DATA_V4_INCLUDED_


#include "CigiBaseVertexSymbolData.h"

// ====================================================================
// preprocessor definitions
// ====================================================================

#define CIGI_VERTEX_SYMBOL_TEXTURE_DATA_SIZE_V4 16



//=========================================================
//! The base class for all packets.
//!
class CIGI_SPEC CigiVertexSymbolTextureDataV4 : public CigiBaseVertexSymbolData
{

public:


   //==> Management

   //=========================================================
   //! General Constructor
   //!
   CigiVertexSymbolTextureDataV4(void);

   //=========================================================
   //! General Destructor
   //!
   virtual ~CigiVertexSymbolTextureDataV4(void);


   //==> Buffer Packing/Unpacking

   //=========================================================
   //! A virtual Pack function.  
   //! \param Base - A pointer to the instance of the Circle 
   //!          Data to be packed. (Downcast to CigiBaseVertexSymbolData)
   //! \param Buff - A pointer to the current pack point.
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Pack(CigiBaseVertexSymbolData * Base, Cigi_uint8 * Buff) const;

   //=========================================================
   //! A virtual Unpack function.
   //! \param Buff - A pointer to the current pack point.
   //! \param Swap - N/A for V1 & V2
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Unpack(Cigi_uint8 * Buff, bool Swap);

   //==> Accessing Member Variable Values functions

   //+> STexCoord

   //=========================================================
   //! Sets the STexCoord with bound checking control
   //! \param STexCoordIn - Specifies the normalized S texture
   //!   coordinate to position the texture relative to the
   //!   cirlcle's center.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetSTexCoord(const float STexCoordIn, bool bndchk=true);

   //=========================================================
   //! Gets the STexCoord
   //! \return STexCoord
   //!
   float GetSTexCoord(void) const { return(STexCoord); }

   //+> TTexCoord

   //=========================================================
   //! Sets the TTexCoord with bound checking control
   //! \param TTexCoordIn - Specifies the normalized T texture
   //!   coordinate to position the texture relative to the
   //!   cirlcle's center.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetTTexCoord(const float TTexCoordIn, bool bndchk=true);

   //=========================================================
   //! Gets the TTexCoord.
   //! \return TTexCoord
   //!
   float GetTTexCoord(void) const { return(TTexCoord); }

protected:

   //=========================================================
   //! STexCoord<br>
   //! The S texture coordinate
   //!
   float STexCoord;

   //=========================================================
   //! TTexCoord<br>
   //! The T texture coordinate
   //!
   float TTexCoord;

};



#endif   //  #if !defined(_CIGI_VERTEX_SYMBOL_TEXTURE_DATA_V4_INCLUDED_)

