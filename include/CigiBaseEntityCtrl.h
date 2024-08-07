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
 *  FILENAME:   CigiBaseEntityCtrl.h
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
 *  Changed native C++ types in function declarations to CCL-defined types.
 *  
 *  06/23/2006 Greg Basler                       Version 1.7.1
 *  Changed native char and unsigned char types to CIGI types Cigi_int8 and 
 *  Cigi_uint8.
 *  
 *  11/20/2007 Greg Basler                       Version 2.0.0
 *  Added new version conversion method.
 *  Moved Packet information to base packet.
 *  
 *  05/09/2008 Greg Basler                       Version 2.2.0
 *  Added Extrapolation or Interpolation Smoothing flag.
 *  Added the defines and declarations for V3_3.
 *  
 *  07/29/2015 Chas Whitley                       Version 4.0.0
 *  Initial Release for CIGI 4.0 compatibility.
 *
 *  12/13/2018 Paul Slade                       Version 4.0.2
 *  Fixes required to allow correct version conversion
 *
 * </pre>
 *  Author: The Boeing Company
 *
 */

#if !defined(_CIGI_BASE_ENTITY_CTRL_INCLUDED_)
#define _CIGI_BASE_ENTITY_CTRL_INCLUDED_

#include "CigiBasePacket.h"

#include "CigiAnimationTable.h"

// ====================================================================
// preprocessor definitions
// ====================================================================

#define CIGI_ENTITY_CTRL_PACKET_ID_V1 2
#define CIGI_ENTITY_CTRL_PACKET_SIZE_V1 48

#define CIGI_ENTITY_CTRL_PACKET_ID_V2 2
#define CIGI_ENTITY_CTRL_PACKET_SIZE_V2 56

#define CIGI_ENTITY_CTRL_PACKET_ID_V3 2
#define CIGI_ENTITY_CTRL_PACKET_SIZE_V3 48

#define CIGI_ENTITY_CTRL_PACKET_ID_V3_3 2
#define CIGI_ENTITY_CTRL_PACKET_SIZE_V3_3 48

#define CIGI_ENTITY_CTRL_PACKET_ID_V4 0x25
#define CIGI_ENTITY_CTRL_PACKET_SIZE_V4 16


class CigiEntityCtrlV1;
class CigiEntityCtrlV2;
class CigiEntityCtrlV3;
class CigiEntityCtrlV3_3;
class CigiEntityCtrlV4;


//=========================================================
//! The base class for the Entity Control packet
//!
class CIGI_SPEC CigiBaseEntityCtrl : public CigiBasePacket  
{

friend class CigiEntityCtrlV1;
friend class CigiEntityCtrlV2;
friend class CigiEntityCtrlV3;
friend class CigiEntityCtrlV3_3;
friend class CigiEntityCtrlV4;

public:

   //=========================================================
   //! The enumeration for the Entity State flag
   //!
   enum EntityStateGrp
   {
      Standby=0,
      Active=1,
      Remove=2,
      Destroyed=2
   };

   //=========================================================
   //! The enumeration for the Attached/Not Attached flag
   //!
   enum AttachStateGrp
   {
      Detach=0,
      Attach=1
   };

   //=========================================================
   //! The enumeration for the Collision Detection Enable flag
   //!
   enum CollisionDetectGrp
   {
      Disable=0,
      Enable=1
   };

   //=========================================================
   //! The enumeration for the Inherit Alpha flag
   //!
   enum InheritAlphaGrp
   {
      NoInherit=0,
      Inherit=1
   };

   //=========================================================
   //! The enumeration for the Ground/Ocean Clamp flag
   //!
   enum GrndClampGrp
   {
      NoClamp=0,
      AltClamp=1,
      AltAttClamp=2
   };

   //=========================================================
   //! The enumeration for the Animation Direction flag
   //!
   enum AnimationDirGrp
   {
      Forward=0,
      Backward=1
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
   //! The enumeration for the Animation State flag<br>
   //! This uses both V1 & V3 states to allow conversion.
   //!
   enum AnimationStateGrp
   {
      Stop=0,
      Pause=1,
      Play=2,
      Continue=3,
      NoAction=4,
      Load=5,
      LoadActivate=6,
      Activate=7,
      Deactivate=8,
      DeactivateUnload=9
   };


   //=========================================================
   //! The enumeration for the Entity State flag
   //!
   enum ExtendedEntityTypeGrp
   {
       Short = 0,
       Extended = 1
   };


   //==> Management

   //=========================================================
   //! General Constructor
   //!
	CigiBaseEntityCtrl();

   //=========================================================
   //! General Destructor
   //!
	virtual ~CigiBaseEntityCtrl();



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


   //+> Entity Type

   //=========================================================
   //! Sets the Entity Type with bound checking control
   //! \param EntityTypeIn - Specifies the type of entity this is.
   //!   The entity types are specified by the using systems
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetEntityType(const Cigi_uint16 EntityTypeIn, bool bndchk=true)
   {
      EntityType = EntityTypeIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Entity Type value
   //! \return EntityType specifies the type of entity this is
   //!   The entity types are specified by the using systems
   //!
   Cigi_uint16 GetEntityType(void) const { return(EntityType); }


   //+> Collision Detection Enable Flag

   //=========================================================
   //! Sets the Collision Detection Enable Flag
   //!   with bound checking control
   //! \param CollisionDetectEnIn - Specifies whether Collision
   //!   Detection is enabled or not.
   //!   0 Disable
   //!   1 Enable
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetCollisionDetectEn(const CollisionDetectGrp CollisionDetectEnIn,
                            bool bndchk=true);

   //=========================================================
   //! Getting the Collision Detection Enable Flag value
   //! \return CollisionDetectEn specifies whether Collision Detection is enabled or not.
   //!   0 Disable
   //!   1 Enable
   //!
   CollisionDetectGrp GetCollisionDetectEn(void) const { return(CollisionDetectEn); }


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
   //! Entity Type<br>
   //! Specifies the type of entity this is<br>
   //!   The entity types are specified by the using systems
   //!  For Cigi4 instead stores the EntityCountry when
   //!  extended types are used
   //!
	Cigi_uint16 EntityType;

   //=========================================================
   //! Parent ID<br>
   //! If this is an attached entity,
   //!   this specifies to which entity this entity is attached.
   //!
	Cigi_uint16 ParentID;

   //=========================================================
   //! Alpha<br>
   //! Specifies the visibility/transparency of the entity.<br>
   //! 0 - transparent : 255 - Fully visible
   Cigi_uint8 Alpha;

   //=========================================================
   //! Opacity<br>
   //! Specifies the visibility/transparency of the entity.<br>
   //! Percent visible: 0 - transparent : 100.0 - Fully visible
	float Opacity;


   //==> Member flags

   //=========================================================
   //! Entity State<br>
   //! 0 Inactive/Standby<br>
   //! 1 Active<br>
   //! 2 Destroy<br>
   //!
	EntityStateGrp EntityState;

   //=========================================================
   //! Collision Detection Enable<br>
   //! 0 Disable<br>
   //! 1 Enable<br>
   //!
   CollisionDetectGrp CollisionDetectEn;

   //=========================================================
   //! Inherit Alpha<br>
   //! 0 No Inheritance<br>
   //! 1 Inherit
   //!
	InheritAlphaGrp InheritAlpha;

   //=========================================================
   //! Smoothing Enabled<br>
   //!  Enable or Disable Extrapolation or Interpolation
   //!    motion smoothing.
   //!  true - Smoothing is Enabled<br>
   //!  false - Smoothing is Disabled.
   //!
   bool SmoothingEn;

   //=========================================================
   //! Animation Direction<br>
   //! 0 Forward<br>
   //! 1 Backward<br>
   //!
   AnimationDirGrp AnimationDir;

   //=========================================================
   //! Animation Loop Mode<br>
   //! 0 One-Shot<br>
   //! 1 Continuous<br>
   //!
   AnimationLoopModeGrp AnimationLoopMode;

   //=========================================================
   //! Animation State<br>
   //! 0 Stop<br>
   //! 1 Pause<br>
   //! 2 Play<br>
   //! 3 Continue
   //! 4 NoAction<br>
   //! 5 Load<br>
   //! 6 LoadActivate<br>
   //! 7 Activate<br>
   //! 8 Deactivate<br>
   //! 9 DeactivateUnload<br>
   //!
   AnimationStateGrp AnimationState;

   //=========================================================
   //! Past Animation State<br>
   //! This is for V1 compatibility<br>
   //! 0 Stop<br>
   //! 1 Pause<br>
   //! 2 Play<br>
   //! 3 Continue<br>
   //! 4 NoAction<br>
   //! 5 Load<br>
   //! 6 LoadActivate<br>
   //! 7 Activate<br>
   //! 8 Deactivate<br>
   //! 9 DeactivateUnload<br>
   //!
   AnimationStateGrp PastAnimationState;

   //=========================================================
   //! Ground/Ocean Clamp<br>
   //! 0 Clamp<br>
   //! 1 Altitude clamp<br>
   //! 2 Altitude and Orientation clamp
   //!
   GrndClampGrp GrndClamp;

   //=========================================================
   //! Attach State<br>
   //! 0 Detach<br>
   //! 1 Attach<br>
   //!
   AttachStateGrp AttachState;

   //=========================================================
   //! Temperature<br>
   //! Specifies the internal temperature of the entity
   //!   in degrees Celsius.
   //!
   float Temperature;

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


   //=========================================================
   //! ExtenedEntityType<br>
   //! Specifies the extended type of this entity<br>
   //!   0 Short
   //!   1 Extended
   //!
   ExtendedEntityTypeGrp ExtendedEntityType;


   //=========================================================
   //! EntityKind<br>
   //! Identifies the kind of entity<br>
   //!
   Cigi_uint8 EntityKind;

   //=========================================================
   //! EntityDomain<br>
   //! Identifies the domain of entity<br>
   //!
   Cigi_uint8 EntityDomain;


   //=========================================================
   //! EntityCategory<br>
   //! Identifies the cayegory of entity<br>
   //!
   Cigi_uint8 EntityCategory;

   //=========================================================
   //! EntitySubcategory<br>
   //! Identifies the subcategory of entity<br>
   //!
   Cigi_uint8 EntitySubcategory;

   //=========================================================
   //! EntitySpecific<br>
   //! Identifies the entiyu specifics of entity<br>
   //!
   Cigi_uint8 EntitySpecific;

   //=========================================================
   //! EntityExtra<br>
   //! Identifies the entity extras of entity<br>
   //!
   Cigi_uint8 EntityExtra;

   //==> Conversion Tables

   static const AnimationStateGrp ToV1[10];
   static const AnimationStateGrp ToV3[10];

};

#endif  //#if !defined(_CIGI_BASE_ENTITY_CTRL_INCLUDED_)
