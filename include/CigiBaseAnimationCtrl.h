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
 *  FILENAME:   CigiBaseAnimationCtrl.h
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
 *
 * </pre>
 *  Author: TJ INc.
 *
 */

#if !defined(_CIGI_BASE_ANIMATION_CTRL_INCLUDED_)
#define _CIGI_BASE_ANIMATION_CTRL_INCLUDED_

#include "CigiBasePacket.h"

// ====================================================================
// preprocessor definitions
// ====================================================================

#define CIGI_ANIMATION_CTRL_PACKET_ID_V4 0x26
#define CIGI_ANIMATION_CTRL_PACKET_SIZE_V4 16

class CigiAnimationCtrlV4;


//=========================================================
//! The base class for the Entity Control packet
//!
class CIGI_SPEC CigiBaseAnimationCtrl : public CigiBasePacket  
{

friend class CigiAnimationCtrlV4;

public:

   //=========================================================
   //! The enumeration for the Animation State
   //!
   enum AnimationStateGrp
   {
      Stop=0,
      Play=1
   };

   //=========================================================
   //! The enumeration for the Attached/Not Attached flag
   //!
   enum AnimationFramePositionResetGrp
   {
      Continue=0,
      Reset=1
   };

   //=========================================================
   //! The enumeration for the Animation Loop Mode flag
   //!
   enum AnimationLoopModeGrp
   {
      OneShot=0,
      Continuous=1
   };

   //=========================================================
   //! The enumeration for the Inherit Alpha flag
   //!
   enum InheritAlphaGrp
   {
      NoInherit=0,
      Inherit=1
   };


   //==> Management

   //=========================================================
   //! General Constructor
   //!
	CigiBaseAnimationCtrl();

   //=========================================================
   //! General Destructor
   //!
	virtual ~CigiBaseAnimationCtrl();



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

   //+> Animation ID

   //=========================================================
   //! Sets the Animation ID with bound checking control
   //! \param AnimationIDIn - Uniquely identifies the specific animation ID
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetAnimationID(const Cigi_uint16 AnimationIDIn, bool bndchk=true)
   {
      AnimationID = AnimationIDIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Entity ID value
   //! \return EntityID uniquely identifies the specific entity
   //!   0 - The ownship
   //!   All other values - An Application defined entity
   //!
   Cigi_uint16 GetAnimationID(void) const { return(AnimationID); }

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
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Alpha value.
   //! \return The alpha of the entity<br>
   //!   0 - transparent.<br>
   //!   255 - fully visible
   //!
   Cigi_uint8 GetAlpha(void) const { return(Alpha); }


   //+> animation Speed


   //=========================================================
   //! Sets the animation Speed with bound checking control
   //! \param AnimationSpeedIn - The animation speed<br>
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetAnimationSpeed(const float AnimationSpeedIn, bool bndchk=true)
   {
      AnimationSpeed = AnimationSpeedIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets AnimationSpeed value.
   //! \return The AnimationSpeed<br>
   //!
   float GetAnimationSpeed(void) const { return(AnimationSpeed); }

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

   //+> Animation State

   //=========================================================
   //! Sets the animation state with bound checking control
   //! \param AnimationStateIn - The Animation State.<br>
   //!   0 Stop<br>
   //!   1 Play
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetAnimationState(const AnimationStateGrp AnimationStateIn, bool bndchk=true);

   //=========================================================
   //! Gets the Inherit Alpha value
   //! \return The Animaition State 
   //!   from the parent entity.<br>
   //!
   AnimationStateGrp GetAnimationState(void) const { return(AnimationState); }


   //+> Animation Frame Position Reset

   //=========================================================
   //! Sets the animation Frame Position Reset Mode with bound checking control
   //! \param AnimationFrameResetModeIn - The Animation State.<br>
   //!   0 Continue<br>
   //!   1 Reset
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetAnimationFrameResetMode(const AnimationFramePositionResetGrp AnimationFrameResetModeIn, bool bndchk=true);

   //=========================================================
   //! Gets the Animation Frame Position Reset mode
   //! \return AnimationFrameResetMode<br>
   //!
   AnimationFramePositionResetGrp GetAnimationFrameResetMode(void) const { return(AnimationFrameResetMode); }


   //+> Animation Loop Mode

   //=========================================================
   //! Sets the animation loop Mode with bound checking control
   //! \param AnimationLoopModeIn - The Animation Loop Mode.<br>
   //!   0 One-Shot<br>
   //!   1 Continuous
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetAnimationLoopMode(const AnimationLoopModeGrp AnimationLoopModeIn, bool bndchk=true);

   //=========================================================
   //! Gets the Animation loop mode
   //! \return AnimationLoopMode<br>
   //!
   AnimationLoopModeGrp GetAnimationLoopMode(void) const { return(AnimationLoopMode); }




protected:

   //==> Member variables

   //=========================================================
   //! Entity ID<br>
   //! specifies the entity to which this animation belongs the specific entity<br>
   //!
	Cigi_uint16 EntityID;

   //=========================================================
   //! Animation ID<br>
   //! Uniquely identifies the specific animation<br>
   //!
	Cigi_uint16 AnimationID;

   //=========================================================
   //! Alpha<br>
   //! Specifies the visibility/transparency of the entity.<br>
   //! 0 - transparent : 255 - Fully visible
   Cigi_uint8 Alpha;

   //=========================================================
   //! AnimationSpeed<br>
   //! Specifies the animation speed<br>
	float AnimationSpeed;


   //==> Member flags


   //=========================================================
   //! Inherit Alpha<br>
   //! 0 No Inheritance<br>
   //! 1 Inherit
   //!
	InheritAlphaGrp InheritAlpha;

   //=========================================================
   //! Inherit Alpha<br>
   //! 0 Continue<br>
   //! 1 Reset
   //!
	AnimationFramePositionResetGrp AnimationFrameResetMode;

   //=========================================================
   //! Animation Loop Mode<br>
   //! 0 One-Shot<br>
   //! 1 Continuous<br>
   //!
	AnimationLoopModeGrp AnimationLoopMode;

   //=========================================================
   //! Animation State<br>
   //! 0 Stop<br>
   //! 1 Play<br>
   //!
	AnimationStateGrp AnimationState;

};

#endif  //#if !defined(_CIGI_BASE_ANIMATION_CTRL_INCLUDED_)
