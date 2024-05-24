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
 *  FILENAME:   CigiBaseCircleSymbolTextureData.h
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
 *  Based on CigiBaseCircleSymbolData.h
 *  
 * </pre>
 *  Author: TJ Inc.
 *
 */

#if !defined(_CIGI_BASE_CIRCLE_SYMBOL_DATA_TEXTURE_INCLUDED_)
#define _CIGI_BASE_CIRCLE_SYMBOL_DATA_TEXTURE_INCLUDED_


#include "CigiTypes.h"
#include "CigiErrorCodes.h"

// ====================================================================
// preprocessor definitions
// ====================================================================

#define CIGI_CIRCLE_SYMBOL_TEXTURE_DATA_SIZE_V4 40


class CigiCircleSymbolTextureData;

//=========================================================
//! The base class for all packets.
//!
class CIGI_SPEC CigiBaseCircleSymbolTextureData
{

   friend class CigiCircleSymbolTextureData;

public:


   //==> Management

   //=========================================================
   //! General Constructor
   //!
   CigiBaseCircleSymbolTextureData(void);

   //=========================================================
   //! General Destructor
   //!
   virtual ~CigiBaseCircleSymbolTextureData(void);


   //==> Buffer Packing/Unpacking

   //=========================================================
   //! A pure virtual Pack function.  
   //! This function is not implemented in this class.
   //! \param Base - A pointer to the instance of the Circle 
   //!          Data to be packed. (Downcast to CigiBaseCircleSymbolData)
   //! \param Buff - A pointer to the current pack point.
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Pack(CigiBaseCircleSymbolTextureData * Base, Cigi_uint8 * Buff) const=0;

   //=========================================================
   //! A pure virtual Unpack function.
   //! This function is not implemented in this class.
   //! \param Buff - A pointer to the current pack point.
   //! \param Swap - N/A for V1 & V2
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Unpack(Cigi_uint8 * Buff, bool Swap) =0;


   //==> Accessing Member Variable Values functions


   //+> CenterUPosition

   //=========================================================
   //! Sets the CenterUPosition with bound checking control
   //! \param CenterUPositionIn - Specifies the position of
   //!   the center of the circle along the current U Axis.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetCenterUPosition(const float CenterUPositionIn, bool bndchk=true)
   {
      CenterUPosition = CenterUPositionIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the CenterUPosition with bound checking control
   //! \return CenterUPosition
   //!
   float GetCenterUPosition(void) const { return(CenterUPosition); }


   //+> CenterVPosition

   //=========================================================
   //! Sets the CenterVPosition with bound checking control
   //! \param CenterVPositionIn - Specifies the position of
   //!   the center of the circle along the current V Axis.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetCenterVPosition(const float CenterVPositionIn, bool bndchk=true)
   {
      CenterVPosition = CenterVPositionIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the CenterVPosition with bound checking control
   //! \return CenterVPosition
   //!
   float GetCenterVPosition(void) const { return(CenterVPosition); }


   //+> Radius

   //=========================================================
   //! Sets the Radius with bound checking control
   //! \param RadiusIn - Specifies the radius of the circle
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetRadius(const float RadiusIn, bool bndchk=true);

   //=========================================================
   //! Gets the Radius with bound checking control
   //! \return Radius
   //!
   float GetRadius(void) const { return(Radius); }


   //+> InnerRadius

   //=========================================================
   //! Sets the InnerRadius with bound checking control
   //! \param InnerRadiusIn - Specifies the inner radius of
   //!   a filled or partially filled circle.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetInnerRadius(const float InnerRadiusIn, bool bndchk=true);

   //=========================================================
   //! Gets the InnerRadius with bound checking control
   //! \return InnerRadius
   //!
   float GetInnerRadius(void) const { return(InnerRadius); }


   //+> StartAngle

   //=========================================================
   //! Sets the StartAngle with bound checking control
   //! \param StartAngleIn - Specifies the angle from the
   //!   current X Axis that the circle starts.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetStartAngle(const float StartAngleIn, bool bndchk=true);

   //=========================================================
   //! Gets the StartAngle with bound checking control
   //! \return StartAngle
   //!
   float GetStartAngle(void) const { return(StartAngle); }


   //+> EndAngle

   //=========================================================
   //! Sets the EndAngle with bound checking control
   //! \param EndAngleIn - Specifies the angle from the
   //!   current X Axis that the circle ends.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetEndAngle(const float EndAngleIn, bool bndchk=true);

   //=========================================================
   //! Gets the EndAngle with bound checking control
   //! \return EndAngle
   //!
   float GetEndAngle(void) const { return(EndAngle); }

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

   //+> TextureRadius

   //=========================================================
   //! Sets the TextureRadius with bound checking control
   //! \param TextureRadiusIn - Specifies the extents of the texture
   //!  that is streched to cover the circle.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetTextureRadius(const float TextureRadiusIn, bool bndchk=true);

   //=========================================================
   //! Gets the TextureRadius
   //! \return TextureRadius
   //!
   float GetTextureRadius(void) const { return(TextureRadius); }

   //+> TextureRotation

   //=========================================================
   //! Sets the TextureRotation with bound checking control
   //! \param TextureRotationIn - Specifies the rotation of the
   //!   the texture relative to the cirlcle's center.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetTextureRotation(const float TextureRotationIn, bool bndchk=true);

   //=========================================================
   //! Gets the TextureRotation
   //! \return TextureRotation
   //!
   float GetTextureRotation(void) const { return(TextureRotation); }



protected:

   //==> Member variables

   //=========================================================
   //! CenterUPosition<br>
   //! The position of the center of the circle along
   //!   the current U Axis.
   //!
   float CenterUPosition;

   //=========================================================
   //! CenterVPosition<br>
   //! The position of the center of the circle along
   //!   the current V Axis.
   //!
   float CenterVPosition;

   //=========================================================
   //! Radius<br>
   //! The radius of this circle
   //!
   float Radius;

   //=========================================================
   //! InnerRadius<br>
   //! The inner radius of a filled or partially filled circle
   //!
   float InnerRadius;

   //=========================================================
   //! StartAngle<br>
   //! The angle from the current X Axis where the circle
   //!  or arc starts.
   //!
   float StartAngle;

   //=========================================================
   //! StartAngle<br>
   //! The angle from the current X Axis where the circle
   //!  or arc ends.
   //!
   float EndAngle;


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

   //=========================================================
   //! TextureRadius<br>
   //! The texture radius
   //!
   float TextureRadius;

   //=========================================================
   //! TextureRotation<br>
   //! The ttexture rotation
   //!
   float TextureRotation;

};



#endif   //  #if !defined(_CIGI_BASE_CIRCLE_SYMBOL_DATA_TEXTURE_INCLUDED_)

