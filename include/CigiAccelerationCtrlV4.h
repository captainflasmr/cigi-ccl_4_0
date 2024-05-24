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
 *  FILENAME:   CigiAccelerationCtrlV4.h
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
 *  
 *  07/29/2015 Chas Whitley                      Version 4.0.0
 *  Initial Release for CIGI 4.0 compatibility.
 *
 *  12/10/2018 Paul Slade                      Version 4.0.2
 *  Switched base class to CigiBaseTrajectoryDef (was CigiBaseAccelerationCtrl which is now removed).
 *  This is required to allow correct translation of Cigi 3.x incomming data to a Cigi 4.0 reader.
 *
 * </pre>
 *  Author: TJ Inc.
 *
 */


#if !defined(_CIGI_ACCELERATION_CTRL_V4_INCLUDED_)
#define _CIGI_ACCELERATION_CTRL_V4_INCLUDED_

#include "CigiBaseTrajectoryDef.h"



class CIGI_SPEC CigiAccelerationCtrlV4 : public CigiBaseTrajectoryDef
{

public:

   //==> Management

   //=========================================================
   //! General Constructor
   //!
   CigiAccelerationCtrlV4();

   //=========================================================
   //! General Destructor
   //!
   virtual ~CigiAccelerationCtrlV4();


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

   //+> ArtPartID

   //=========================================================
   //! Sets the ArtPartID with bound checking control
   //! \param ArtPartIDIn - The Articulated Prt ID.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetArtPartID(const Cigi_uint8 ArtPartIDIn, bool bndchk = true)
   {
       ArtPartID = ArtPartIDIn;
       return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the ArtPartID value.
   //! \return the current ArtPartID.
   Cigi_uint8 GetArtPartID(void) const { return(ArtPartID); }


   //+> CoordSys

   //=========================================================
   //! Sets the CoordSys with bound checking control
   //! \param CoordSysIn - The Coordinate System.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetCoordSys(const CoordGrp CoordSysIn, bool bndchk = true)
   {
       CoordSys = CoordSysIn;
       return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the CoordSys value.
   //! \return the current CoordSys.
   CoordGrp GetCoordSys(void) const { return(CoordSys); }


   //+> ArtPartApplyEn

   //=========================================================
   //! Sets the ArtPartApplyEn with bound checking control
   //! \param ArtPartApplyEnIn - The Articulated Prt enable.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetArtPartApply(const bool ArtPartApplyEnIn, bool bndchk = true)
   {
       ArtPartApplyEn = ArtPartApplyEnIn;
       return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the ArtPartApplyEn value.
   //! \return the current ArtPartApplyEn.
   bool GetArtPartApply(void) const { return(ArtPartApplyEn); }

   //+> AccelX

   //=========================================================
   //! Sets the Accel with bound checking control
   //! \param AccelIn - Acceleration value.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetAccelX(const float AccelIn, bool bndchk=true);

   //=========================================================
   //! Gets the Accel value.
   //! \return the current Accel.
   float GetAccelX(void) const { return(AccelX); }

   //+> Accel

   //=========================================================
   //! Sets the Accel with bound checking control
   //! \param AccelIn - Acceleration value.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetAccelY(const float AccelIn, bool bndchk=true);

   //=========================================================
   //! Gets the Accel value.
   //! \return the current Accel.
   float GetAccelY(void) const { return(AccelY); }

   //+> Accel

   //=========================================================
   //! Sets the Accel with bound checking control
   //! \param AccelIn - Acceleration value.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetAccelZ(const float AccelIn, bool bndchk=true);

   //=========================================================
   //! Gets the Accel value.
   //! \return the current Accel.
   float GetAccelZ(void) const { return(AccelZ); }

   //+> AccelRoll

   //=========================================================
   //! Sets the AccelRoll with bound checking control
   //! \param AccelRollIn - The Roll angular acceleration.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetAccelRoll(const float AccelRollIn, bool bndchk);

   //=========================================================
   //! Gets the AccelRoll value.
   //! \return the current AccelRoll.
   float GetAccelRoll(void) const { return(AccelRoll); }


   //+> AccelPitch

   //=========================================================
   //! Sets the AccelPitch with bound checking control
   //! \param AccelPitchIn - The Pitch angular acceleration.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetAccelPitch(const float AccelPitchIn, bool bndchk);

   //=========================================================
   //! Gets the AccelPitch value.
   //! \return the current AccelPitch.
   float GetAccelPitch(void) const { return(AccelPitch); }


   //+> AccelYaw

   //=========================================================
   //! Sets the AccelYaw with bound checking control
   //! \param AccelYawIn - The Yaw angular acceleration.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetAccelYaw(const float AccelYawIn, bool bndchk);

   //=========================================================
   //! Gets the AccelYaw value.
   //! \return the current AccelYaw.
   float GetAccelYaw(void) const { return(AccelYaw); }



};

#endif // #if !defined(_CIGI_ACCELERATION_CTRL_V4_INCLUDED_)
