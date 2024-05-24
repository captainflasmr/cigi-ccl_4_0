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
 *  FILENAME:   CigiBasePositionCtrl.h
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
 *  07/29/2015 Chas Whitley                       Version 4.0.0
 *  Initial Release for CIGI 4.0 compatibility.
 *  Based on CigiBaseEntityCtrl.cpp
 *
 * </pre>
 *  Author: TJ Inc.
 *
 */

#if !defined(_CIGI_BASE_ENTITY_POSITION_CTRL_INCLUDED_)
#define _CIGI_BASE_ENTITY_POSITION_CTRL_INCLUDED_

#include "CigiBasePacket.h"

// ====================================================================
// preprocessor definitions
// ====================================================================

#define CIGI_ENTITY_POSITION_CTRL_PACKET_ID_V4 0x01
#define CIGI_ENTITY_POSITION_CTRL_PACKET_SIZE_V4 48


class CigiEntityPositionCtrlV4;


//=========================================================
//! The base class for the Entity Control packet
//!
class CIGI_SPEC CigiBaseEntityPositionCtrl : public CigiBasePacket  
{

friend class CigiEntityPositionCtrlV4;

public:

   //=========================================================
   //! The enumeration for the Attached/Not Attached flag
   //!
   enum AttachStateGrp
   {
      Detach=0,
      Attach=1
   };

   //=========================================================
   //! The enumeration for the Ground/Ocean Clamp flag
   //!
   enum ClampStateGrp
   {
      NoClamp=0,
      AltClamp=1,
      AltAttClamp=2
   };



   //==> Management

   //=========================================================
   //! General Constructor
   //!
	CigiBaseEntityPositionCtrl();

   //=========================================================
   //! General Destructor
   //!
	virtual ~CigiBaseEntityPositionCtrl();



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

   //+> Entity ID

   //=========================================================
   //! Sets the Entity ID with bound checking control
   //! \param EntityIDIn - Uniquely identifies the specific entity
   //!   0 - The ownship
   //!   All other values - An Application defined entity
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetEntityID(const Cigi_uint16 EntityIDIn, bool bndchk=true)
   {
      EntityID = EntityIDIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Entity ID value
   //! \return EntityID uniquely identifies the specific entity
   //!   0 - The ownship
   //!   All other values - An Application defined entity
   //!
   Cigi_uint16 GetEntityID(void) const { return(EntityID); }

   //+> Parent ID

   //=========================================================
   //! Sets the Parent ID with bound checking control
   //! \param ParentIDIn - If this is an attached entity,
   //!   this specifies to which entity this entity is attached.
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetParentID(const Cigi_uint16 ParentIDIn, bool bndchk=true)
   {
      ParentID = ParentIDIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Parent ID value
   //! \return ParentID specifies to which entity this entity is attached,
   //!   if this is an attached entity.
   //!
   Cigi_uint16 GetParentID(void) const { return(ParentID); }

   //+> Attach State

   //=========================================================
   //! Sets the Attach State with bound checking control
   //! \param AttachStateIn - Specifies whether this entity is independant
   //!   or attached to a parent entity.
   //!   0 Detach   (independent)
   //!   1 Attach
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetAttachState(const AttachStateGrp AttachStateIn, bool bndchk=true);

   //=========================================================
   //! Gets the Attach State value
   //! \return AttachState specifies whether this entity is independant
   //!   or attached to a parent entity.
   //!   0 Detach
   //!   1 Attach
   //!
   AttachStateGrp GetAttachState(void) const { return(AttachState); }


   //+> Clamp State

   //=========================================================
   //! Sets the Clamp State with bound checking control
   //! \param AttachStateIn - Specifies whether this entity may be clamped.
   //!   0 No Clamp
   //!   1 Non-Conformal
   //!   2 Conformal
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetClampState(const ClampStateGrp ClampStateIn, bool bndchk=true);

   //=========================================================
   //! Gets the Attach State Flag value
   //! \return AttachState specifies whether this entity is independant
   //!   or attached to a parent entity.
   //!   0 No Clamp
   //!   1 Non-Conformal
   //!   2 Conformal
   //!
   ClampStateGrp GetClampState(void) const { return(ClampState); }


   //+> Pitch

   //=========================================================
   //! Sets the Pitch with bound checking control
   //! \param PitchIn - Specifies the pitch of the entity
   //!   (-90.0 to +90.0)
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetPitch(const float PitchIn, bool bndchk=true);

   //=========================================================
   //! Gets the Pitch value
   //! \return Pitch specifies the pitch of the entity
   //!   (-90.0 to +90.0)
   //!
   float GetPitch(void) const { return(Pitch); }


   //+> Roll

   //=========================================================
   //! Sets the Roll with bound checking control
   //! \param RollIn - Specifies the roll of the entity
   //!   (-180.0 to +180.0)
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetRoll(const float RollIn, bool bndchk=true);

   //=========================================================
   //! Gets the Roll value
   //! \return Roll specifies the roll of the entity
   //!   (-180.0 to +180.0)
   //!
   float GetRoll(void) const { return(Roll); }

   //+> Yaw

   //=========================================================
   //! Sets the Yaw with bound checking control
   //! \param YawIn - The Yaw of the entity in degrees.<br>
   //!   (0 - 360.0)
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetYaw(const float YawIn, bool bndchk=true);

   //=========================================================
   //! Gets the Yaw value
   //! \return The Yaw of the entity in degrees.<br>
   //!   (0 to 360.0)
   //!
   float GetYaw(void) const { return(Yaw); }


   //+> X Offset

   //=========================================================
   //! Sets the X Offset with bound checking control
   //! \param Xoff - Specifies the X axis Offset from 
   //!   the Parent entity's origin.
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetXoff(const double Xoff,bool bndchk=true)
   {
      LatOrXoff = Xoff;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the X Offset value
   //! \return LatOrXoff specifies the X axis Offset from 
   //!   the Parent entity's origin.
   //!
	double GetXoff(void) const { return(LatOrXoff); }

   //+> Y Offset

   //=========================================================
   //! Sets the Y Offset with bound checking control
   //! \param Yoff - Specifies the Y axis Offset from 
   //!   the Parent entity's origin.
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetYoff(const double Yoff, bool bndchk=true)
   {
      LonOrYoff = Yoff;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Y Offset value
   //! \return LonOrYoff specifies the Y axis Offset from 
   //!   the Parent entity's origin.
   //!
	double GetYoff(void) const { return(LonOrYoff); }


   //+> Z Offset

   //=========================================================
   //! Sets the Z Offset with bound checking control
   //! \param Zoff - Specifies the Y axis Offset from 
   //!   the Parent entity's origin.
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetZoff(const double Zoff, bool bndchk=true)
   {
      AltOrZoff = Zoff;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Y Offset value
   //! \return LonOrYoff specifies the Y axis Offset from 
   //!   the Parent entity's origin.
   //!
	double GetZoff(void) const { return(AltOrZoff); }

   //+> Latitude

   //=========================================================
   //! Sets the Latitude with bound checking control
   //! \param Lat - Specifies the Latitude of the entity
   //!   (-90.0 to +90.0)
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetLat(const double Lat, bool bndchk=true);

   //=========================================================
   //! Gets the Latitude value
   //! \return LatOrXoff specifies the Latitude of the entity
   //!   (-90.0 to +90.0)
   //!
   double GetLat(void) const { return(LatOrXoff); }



   //+> Longitude

   //=========================================================
   //! Sets the Longitude with bound checking control
   //! \param Lon - Specifies the Longitude of the entity
   //!   (-180.0 to +180.0)
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetLon(const double Lon, bool bndchk=true);

   //=========================================================
   //! Getting the Longitude value
   //! \return LonOrYoff specifies the Longitude of the entity
   //!   (-180.0 to +180.0)
   //!
   double GetLon(void) const { return(LonOrYoff); }

   //+> Altitude

   //=========================================================
   //! Sets the Z Offset with bound checking control
   //! \param Zoff - Specifies the Y axis Offset from 
   //!   the Parent entity's origin.
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetAlt(const double Alt, bool bndchk=true)
   {
      AltOrZoff = Alt;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Y Offset value
   //! \return LonOrYoff specifies the Y axis Offset from 
   //!   the Parent entity's origin.
   //!
	double GetAlt(void) const { return(AltOrZoff); }




protected:

   //==> Member variables

   //=========================================================
   //! Entity ID<br>
   //! Uniquely identifies the specific entity<br>
   //!   0 - The ownship<br>
   //!   All other values - An Application defined entity
   //!
	Cigi_uint16 EntityID;

   //=========================================================
   //! Parent ID<br>
   //! If this is an attached entity,
   //!   this specifies to which entity this entity is attached.
   //!
	Cigi_uint16 ParentID;


   //=========================================================
   //! Roll
   //! Specifies the roll of the entity<br>
   //!   (-180.0 to +180.0)
   //!
	float Roll;

   //=========================================================
   //! Pitch
   //! Specifies the pitch of the entity<br>
   //!   (-90.0 to +90.0)
   //!
	float Pitch;

   //=========================================================
   //! Yaw
   //! Specifies the Yaw or Heading of the entity<br>
   //!   (0.0 to 360.0)
	float Yaw;

   //=========================================================
   //! Latitude or X Offset from parent entity origin<br>
   //! Specifies the latitude or X Offset from parent entity origin<br>
   //!   (-90.0 to +90.0 if latitude)<br>
   //!   no bounds if X Offset
   //!
	double LatOrXoff;

   //=========================================================
   //! Longitude or Y Offset from parent entity origin<br>
   //! Specifies the longitude or Y Offset from parent entity origin<br>
   //!   (-180.0 to +180.0 if longitude)<br>
   //!   no bounds if Y Offset
   //!
	double LonOrYoff;

   //=========================================================
   //! Altitude or Z Offset from parent entity origin.<br>
   //! Specifies the longitude or Z Offset from parent entity origin<br>
   //!   (no bounds)
   //!
	double AltOrZoff;


   //==> Member flags

   //=========================================================
   //! Attach State<br>
   //! 0 Detach<br>
   //! 1 Attach<br>
   //!
   AttachStateGrp AttachState;


   //=========================================================
   //! Ground/Ocean Clamp<br>
   //! 0 Clamp<br>
   //! 1 Altitude clamp<br>
   //! 2 Altitude and Orientation clamp
   //!
	ClampStateGrp ClampState;

};

#endif  //#if !defined(_CIGI_BASE_ENTITY_POSITION_CTRL_INCLUDED_)
