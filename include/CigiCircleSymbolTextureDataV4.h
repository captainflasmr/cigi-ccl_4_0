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
 *  FILENAME:   CigiCircleSymbolTextureDataV4.h
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
 *  09/17/2003 Greg Basler                       CIGI_CR_DR_1
 *  Initial Release.
 *  
 *  07/29/2015 Chas Whitley                      Version 4.0.0
 *  Initial Release for CIGI 4.0 compatibility.
 *  Based on CigiCircleSymbolDataV3_3.h
 *  
 * </pre>
 *  Author: TJ Inc.
 *
 */

#if !defined(_CIGI_CIRCLE_SYMBOL_TEXTURE_DATA_V4_INCLUDED_)
#define _CIGI_CIRCLE_SYMBOL_TEXTURE_DATA_V4_INCLUDED_


#include "CigiBaseCircleSymbolTextureData.h"

// ====================================================================
// preprocessor definitions
// ====================================================================

#define CIGI_CIRCLE_SYMBOL_TEXTURE_DATA_SIZE_V4 40



//=========================================================
//! The base class for all packets.
//!
class CIGI_SPEC CigiCircleSymbolTextureDataV4 :
   public CigiBaseCircleSymbolTextureData
{

public:


   //==> Management

   //=========================================================
   //! General Constructor
   //!
   CigiCircleSymbolTextureDataV4(void);

   //=========================================================
   //! General Destructor
   //!
   virtual ~CigiCircleSymbolTextureDataV4(void);


   //==> Buffer Packing/Unpacking

   //=========================================================
   //! A virtual Pack function.  
   //! \param Base - A pointer to the instance of the Circle 
   //!          Data to be packed. (Downcast to CigiBaseCircleSymbolData)
   //! \param Buff - A pointer to the current pack point.
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Pack(CigiBaseCircleSymbolTextureData * Base, Cigi_uint8 * Buff) const;

   //=========================================================
   //! A virtual Unpack function.
   //! \param Buff - A pointer to the current pack point.
   //! \param Swap - N/A for V1 & V2
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Unpack(Cigi_uint8 * Buff, bool Swap);

};



#endif   //  #if !defined(_CIGI_CIRCLE_SYMBOL_TEXTURE_DATA_V4_INCLUDED_)

