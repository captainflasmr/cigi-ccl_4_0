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
 *  FILENAME:   CigiEntityCtrlV3.h
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
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Added the CIGI_SPEC modifier to the class declaration for exporting the 
 *  class in a Windows DLL.
 *  
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Changed the Zoff parameter type from float to double in the SsetZoff 
 *  function.
 *  
 *  06/23/2006 Greg Basler                       Version 1.7.1
 *  Changed native char and unsigned char types to CIGI types Cigi_int8 and 
 *  Cigi_uint8.
 *  
 *  11/20/2007 Greg Basler                       Version 2.0.0
 *  Moved Packet information to base packet.
 *
 *  12/13/2018 Paul Slade                       Version 4.0.2
 *  Fixes required to allow correct version conversion
 *  Moved accessors that are not supported in V4 packet out of base class *
 *
 * </pre>
 *  Author: The Boeing Company
 *
 */


#if !defined(_CIGI_ENTITY_CONTROL_V3_INCLUDED_)
#define _CIGI_ENTITY_CONTROL_V3_INCLUDED_



#include "CigiBaseEntityCtrl.h"





//=========================================================
//! The class for the Entity Control packet for CIGI version 3
//!
class CIGI_SPEC CigiEntityCtrlV3 : public CigiBaseEntityCtrl  
{

public:

   //==> Management

   //=========================================================
   //! General Constructor
   //!
	CigiEntityCtrlV3();

   //=========================================================
   //! General Destructor
   //!
	virtual ~CigiEntityCtrlV3();



   //==> Buffer Packing/Unpacking

   //=========================================================
   //! The virtual Pack function for CIGI 1
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
   //! The virtual Unpack function for CIGI 1
   //! \param Buff - A pointer to the current pack point.
   //! \param Swap - Byte swapping required.
   //! \param Spec - A pointer to special data -
   //!          This is not used in this class.
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	virtual int Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec);


   //==> Accessing Member Variable Values functions


   //+> Internal Temperature

   //=========================================================
   //! Sets the Alpha with bound checking control
   //! \param AlphaIn - The alpha of the entity<br>
   //!   0 - transparent.<br>
   //!   255 - fully visible
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetAlpha(const Cigi_uint8 AlphaIn, bool bndchk=true)
   {
      Alpha = AlphaIn;
      Opacity = ((float)Alpha)/2.55f;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Alpha value.
   //! \return The alpha of the entity<br>
   //!   0 - transparent.<br>
   //!   255 - fully visible
   //!
   Cigi_uint8 GetAlpha(void) const { return(Alpha); }


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
   int SetParentID(const Cigi_uint16 ParentIDIn, bool bndchk = true)
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
   int SetPitch(const float PitchIn, bool bndchk = true);

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
   int SetRoll(const float RollIn, bool bndchk = true);

   //=========================================================
   //! Gets the Roll value
   //! \return Roll specifies the roll of the entity
   //!   (-180.0 to +180.0)
   //!
   float GetRoll(void) const { return(Roll); }


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
   int SetLat(const double Lat, bool bndchk = true);

   //=========================================================
   //! Gets the Latitude value
   //! \return LatOrXoff specifies the Latitude of the entity
   //!   (-90.0 to +90.0)
   //!
   double GetLat(void) const { return(LatOrXoff); }


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
   int SetXoff(const double Xoff, bool bndchk = true)
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
   int SetLon(const double Lon, bool bndchk = true);

   //=========================================================
   //! Getting the Longitude value
   //! \return LonOrYoff specifies the Longitude of the entity
   //!   (-180.0 to +180.0)
   //!
   double GetLon(void) const { return(LonOrYoff); }


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
   int SetYoff(const double Yoff, bool bndchk = true)
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


   //+> Attach State Flag

   //=========================================================
   //! Sets the Attach State Flag with bound checking control
   //! \param AttachStateIn - Specifies whether this entity is independant
   //!   or attached to a parent entity.
   //!   0 Detach   (independent)
   //!   1 Attach
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetAttachState(const AttachStateGrp AttachStateIn, bool bndchk = true);

   //=========================================================
   //! Gets the Attach State Flag value
   //! \return AttachState specifies whether this entity is independant
   //!   or attached to a parent entity.
   //!   0 Detach
   //!   1 Attach
   //!
   AttachStateGrp GetAttachState(void) const { return(AttachState); }

   //+> Altitude

   //=========================================================
   //! Sets the altitude with bound checking control
   //! \param Alt - The altitude above MSL of the entity in meters.
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
   //! Gets the altitude value
   //! \return The altitude above MSL of the entity in meters.
   //!
   double GetAlt(void) const { return(AltOrZoff); }


   //+> Z Offset

   //=========================================================
   //! Sets the Z Offset with bound checking control
   //! \param Zoff - The Z offset from the origin of the parent 
   //!   entity in meters.
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetZoff(const double Zoff, bool bndchk=true)
   {
      AltOrZoff = (double)Zoff;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Z Offset value
   //! \return The Z offset from the origin of the parent 
   //!   entity in meters.
   //!
	double GetZoff(void) const { return(AltOrZoff); }


   //+> Entity State

   //=========================================================
   //! Sets the Entity State with bound checking control
   //! \param EntityStateIn - The current state of this entity.<br>
   //!   0 Inactive/Standby<br>
   //!   1 Active<br>
   //!   2 Destroy
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetEntityState(const EntityStateGrp EntityStateIn, bool bndchk=true);

   //=========================================================
   //! Gets the Entity State value
   //! \return The current state of this entity.<br>
   //!   0 Inactive/Standby<br>
   //!   1 Active<br>
   //!   2 Destroy
   //!
   EntityStateGrp GetEntityState(void) const { return(EntityState); }


   //+> Ground/Ocean Clamp

   //=========================================================
   //! Sets the Ground/Ocean Clamp with bound checking control
   //! \param GrndClampIn - Ground/Ocean Clamp enable.<br>
   //!   0 Clamp<br>
   //!   1 Altitude clamp<br>
   //!   2 Altitude and Orientation clamp
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetGrndClamp(const GrndClampGrp GrndClampIn, bool bndchk=true);

   //=========================================================
   //! Gets the Ground/Ocean Clamp value
   //! \return The Ground/Ocean Clamp enable.<br>
   //!   0 Clamp<br>
   //!   1 Altitude clamp<br>
   //!   2 Altitude and Orientation clamp
   //!
   GrndClampGrp GetGrndClamp(void) const { return(GrndClamp); }


   //+> Inherit Alpha

   //=========================================================
   //! Sets the Inherit Alpha with bound checking control
   //! \param InheritAlphaIn - Flag for this entity inheriting alpha 
   //!   from the parent entity.<br>
   //!   0 No Inheritance<br>
   //!   1 Inherit
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetInheritAlpha(const InheritAlphaGrp InheritAlphaIn, bool bndchk=true);

   //=========================================================
   //! Gets the Inherit Alpha value
   //! \return The flag for this entity inheriting alpha 
   //!   from the parent entity.<br>
   //!   0 No Inheritance<br>
   //!   1 Inherit
   //!
   InheritAlphaGrp GetInheritAlpha(void) const { return(InheritAlpha); }


   //+> Animation Direction

   //=========================================================
   //! Sets the Animation Direction with bound checking control
   //! \param AnimationDirIn - Specifies the animation sequence direction.<br>
   //!   0 Forward<br>
   //!   1 Backward
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetAnimationDir(const AnimationDirGrp AnimationDirIn, bool bndchk=true);

   //=========================================================
   //! Gets the Animation Direction value
   //! \return The animation sequence direction.<br>
   //!   0 Forward<br>
   //!   1 Backward
   //!
   AnimationDirGrp GetAnimationDir(void) const { return(AnimationDir); }


   //+> Animation Loop Mode

   //=========================================================
   //! Sets the Animation Loop Mode with bound checking control
   //! \param AnimationLoopModeIn - The mode in which to run the animation.<br>
   //!   0 One-Shot<br>
   //!   1 Continuous
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetAnimationLoopMode(const AnimationLoopModeGrp AnimationLoopModeIn, bool bndchk=true);

   //=========================================================
   //! Gets the Animation Loop Mode value
   //! \return The mode in which to run the animation.<br>
   //!   0 One-Shot<br>
   //!   1 Continuous
   //!
   AnimationLoopModeGrp GetAnimationLoopMode(void) const { return(AnimationLoopMode); }


   //+> Animation State

   //=========================================================
   //! Sets the Animation State with bound checking control
   //! \param AnimationStateIn - The play state of the animation.<br>
   //!   0 Stop<br>
   //!   1 Pause<br>
   //!   2 Play<br>
   //!   3 Continue
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetAnimationState(const AnimationStateGrp AnimationStateIn, bool bndchk=true);

   //=========================================================
   //! Gets the Animation State value
   //! \return The play state of the animation.<br>
   //!   0 Stop<br>
   //!   1 Pause<br>
   //!   2 Play<br>
   //!   3 Continue
   //!
   AnimationStateGrp GetAnimationState(void) const;


};

#endif // #if !defined(_CIGI_ENTITY_CONTROL_V3_INCLUDED_)
