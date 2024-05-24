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
 *  FILENAME:   CigiVelocityCtrlV4.h
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
 *  07/29/2015 Chas Whitley                      Version 4.0.0
 *  Initial Release for CIGI 4.0 compatibility.
 *
 *  12/12/2018 Paul Slade                      Version 4.0.2
 *  Removed ArtPartIDV4 (must now use ArtPartIDV3 instead) to allow correct version conversion
 *
 *  12/10/2018 Paul Slade                      Version 4.0.2
 *  Switched base class to CigiBaseRateCtrl (was CigiBaseVelocityCtrl which is now removed).
 *  This is required to allow correct translation of Cigi 3.x incomming data to a Cigi 4.0 reader.
 *
 * </pre>
 *  Author: TJ Inc.
 *
 */


#if !defined(_CIGI_VELOCITY_CTRL_V4_INCLUDED_)
#define _CIGI_VELOCITY_CTRL_V4_INCLUDED_

#include "CigiBaseRateCtrl.h"



class CIGI_SPEC CigiVelocityCtrlV4 : public CigiBaseRateCtrl
{

public:

   //==> Management

   //=========================================================
   //! General Constructor
   //!
   CigiVelocityCtrlV4();

   //=========================================================
   //! General Destructor
   //!
   virtual ~CigiVelocityCtrlV4();


   //==> Buffer Packing/Unpacking

   //=========================================================
   //! The virtual Pack function for CIGI 4
   //! \param Base - A pointer to the instance of the packet
   //!          to be packed. (Downcast to CigiBasePacket)
   //! \param Buff - A pointer to the current pack point.
   //! \param Spec - A pointer to special data -
   //!          This is not used in this class.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const;

   //=========================================================
   //! The virtual Unpack function for CIGI 4
   //! \param Buff - A pointer to the current pack point.
   //! \param Swap - N/A for V1 & V2
   //! \param Spec - A pointer to special data -
   //!          This is not used in this class.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec);



   //==> Accessing Member Variable Values functions

   //+> ArtPartIDV3

   //=========================================================
   //! Sets the ArtPartIDV3 with bound checking control
   //! \param ArtPartIDIn - Specifies the art part to which
   //!   this packet's data is applied.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetArtPartID(const Cigi_uint8 ArtPartIDIn, bool bndchk=true);

   //=========================================================
   //! Gets the ArtPartIDV3 value.
   //! \return the current ArtPartIDV3.
   Cigi_uint8 GetArtPartID(void) const { return(ArtPartIDV3); }


   //+> ApplyToArtPart

   //=========================================================
   //! Sets the ApplyToArtPart with bound checking control
   //! \param ApplyToArtPartIn - Specifies whether this data is to be
   //!   applied to an articulated part or an entity.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetApplyToArtPart(const bool ApplyToArtPartIn, bool bndchk=true);

   //=========================================================
   //! Gets the ApplyToArtPart value.
   //! \return the current ApplyToArtPart.
   bool GetApplyToArtPart(void) const { return(ApplyToArtPart); }


   //+> Coordinate System

   //=========================================================
   //! Sets the Coordinate System with bound checking control
   //! \param CoordSysIn - Specifies the coordinate system in which
   //!   the rates are applied.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetCoordSys(const CoordSysGrp CoordSysIn, bool bndchk=true);

   //=========================================================
   //! Gets the Coordinate System value.
   //! \return the current Coordinate System being used for rates.
   CoordSysGrp GetCoordSys(void) const { return(CoordSys); }

};

#endif // #if !defined(_CIGI_VELOCITY_CTRL_V4_INCLUDED_)
