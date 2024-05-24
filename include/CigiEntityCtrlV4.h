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
 *  FILENAME:   CigiEntityCtrlV4.h
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
 *  05/09/2008 Greg Basler                       Version 2.2.0
 *  Initial Release for CIGI 3.3 compatibility.
 *  Based on CigiEntityCtrlV3.h"
 *  
 *  07/29/2015 Chas Whitley                       Version 4.0.0
 *  Initial Release for CIGI 4.0 compatibility.
 *  Based on CigiEntityCtrlV4.h"
 *
 * </pre>
 *  Author: The Boeing Company
 *
 */


#if !defined(_CIGI_ENTITY_CONTROL_V4)
#define _CIGI_ENTITY_CONTROL_V4



#include "CigiBaseEntityCtrl.h"





//=========================================================
//! The class for the Entity Control packet for CIGI version 4
//!
class CIGI_SPEC CigiEntityCtrlV4 : public CigiBaseEntityCtrl  
{

public:

   //==> Management

   //=========================================================
   //! General Constructor
   //!
	CigiEntityCtrlV4();

   //=========================================================
   //! General Destructor
   //!
	virtual ~CigiEntityCtrlV4();



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

   //+> Smoothing Enabled

   //=========================================================
   //! Gets the Smoothing Enabled flag for V3.3
   //! \return Smoothing Enabled flag
   //!
   bool GetSmoothingEn(void) const { return(SmoothingEn); }

   //=========================================================
   //! Enables or Disables motion smoothing of this entity.<br>
   //!  Motion smoothing for an entity can only be enabled if
   //!  global motion smoothing is enabled in the IG Ctrl packet
   //!  and the motion smoothing for the entity is enabled.
   //! \param SmoothingEnabled - Enables (true) or disables (false)
   //!    Extrapolation or Interpolation motion smoothing
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetSmoothingEn(const bool SmoothingEnabled, bool bndchk=true)
   {
      SmoothingEn = SmoothingEnabled;

      return(CIGI_SUCCESS);
   }

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

   //+> Extended Entity Type

   //=========================================================
   //! Sets the ExtenedEntityType value with bound checking control
   //! \param ExtenedEntityTypeIn - Specifies the extended type
   //!   0 Short
   //!   1 Extended
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetExtendedEntityType(const ExtendedEntityTypeGrp ExtenedEntityTypeIn, bool bndchk=true);

   //=========================================================
   //! Gets the ExtenedEntityType value
   //! \return ExtenedEntityType Specifies the extended type of this entity.
   //!
   ExtendedEntityTypeGrp GetExtendedEntityType(void) const { return(ExtendedEntityType); }

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

   //+> Extended Kind

   //=========================================================
   //! Sets the EntityKindIn value with bound checking control
   //! \param EntityKindIn - Identifies the kind of entity
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetEntityKind(const Cigi_uint8 EntityKindIn, bool bndchk=true)
   {
      EntityKind = EntityKindIn;
      return(CIGI_SUCCESS);
   } 

   //=========================================================
   //! Gets the EntityKind value
   //! \return EntityKind Specifies the extended type of this entity.
   //!
   Cigi_uint8 GetEntityKind(void) const { return(EntityKind); }


   //+> Entity Domain

   //=========================================================
   //! Sets the EntityDomainIn value with bound checking control
   //! \param EntityDomainIn - Identifies the domain of entity
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetEntityDomain(const Cigi_uint8 EntityDomainIn, bool bndchk=true)
   {
      EntityDomain = EntityDomainIn;
      return(CIGI_SUCCESS);
   } 

   //=========================================================
   //! Gets the EntityDomain value
   //! \return EntityDomain Specifies the extended type of this entity.
   //!
   Cigi_uint8 GetEntityDomain(void) const { return(EntityDomain); }


   //+> Short Entity Type

   //=========================================================
   //! Sets the ShortEntityTypeIn value with bound checking control
   //! \param ShortEntityTypeIn - Specifies the entity type
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetShortEntityType(const Cigi_uint16 ShortEntityTypeIn, bool bndchk=true)
   {
      EntityType = ShortEntityTypeIn;
      return(CIGI_SUCCESS);
   } 

   //=========================================================
   //! Gets the ShortEntityType value
   //! \return ShortEntityType Specifies the short type of this entity.
   //!
   Cigi_uint16 GetShortEntityType(void) const { return(EntityType); }


   //+> Entity country

   //=========================================================
   //! Sets the EntityCountryIn value with bound checking control
   //! \param EntityCountryIn - Specifies the entity country
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetEntityCountry(const Cigi_uint16 EntityCountryIn, bool bndchk=true)
   {
       EntityType = EntityCountryIn;
      return(CIGI_SUCCESS);
   } 

   //=========================================================
   //! Gets the EntityCountry value
   //! \return EntityCountry Specifies the country of origin of this entity.
   //!
   Cigi_uint16 GetEntityCountry(void) const { return(EntityType); }


   //+> Entity Category

   //=========================================================
   //! Sets the EntityCategoryIn value with bound checking control
   //! \param EntityCategoryIn - Specifies the entity category
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetEntityCategory(const Cigi_uint8 EntityCategoryIn, bool bndchk=true)
   {
      EntityCategory = EntityCategoryIn;
      return(CIGI_SUCCESS);
   } 

   //=========================================================
   //! Gets the EntityCategory value
   //! \return EntityCategory Specifies the entity category
   //!
   Cigi_uint8 GetEntityCategory(void) const { return(EntityCategory); }


   //+> Entity Subcategory

   //=========================================================
   //! Sets the EntitySubcategoryIn value with bound checking control
   //! \param EntitySubcategoryIn - Specifies the entity category
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetEntitySubcategory(const Cigi_uint8 EntitySubcategoryIn, bool bndchk=true)
   {
      EntitySubcategory = EntitySubcategoryIn;
      return(CIGI_SUCCESS);
   } 

   //=========================================================
   //! Gets the EntitySubcategory value
   //! \return EntitySubcategory Specifies the entity category
   //!
   Cigi_uint8 GetEntitySubcategory(void) const { return(EntitySubcategory); }


   //+> Entity Specific

   //=========================================================
   //! Sets the EntitySpecificIn value with bound checking control
   //! \param EntitySpecificIn - Specifies the entity specific data
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetEntitySpecific(const Cigi_uint8 EntitySpecificIn, bool bndchk=true)
   {
      EntitySpecific = EntitySpecificIn;
      return(CIGI_SUCCESS);
   } 

   //=========================================================
   //! Gets the EntitySpecific value
   //! \return EntitySpecific Specifies the entity specific data
   //!
   Cigi_uint8 GetEntitySpecific(void) const { return(EntitySpecific); }


   //+> Entity Extra

   //=========================================================
   //! Sets the EntityExtraIn value with bound checking control
   //! \param EntityExtraIn - Specifies the entity extra data
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetEntityExtra(const Cigi_uint8 EntityExtraIn, bool bndchk=true)
   {
      EntityExtra = EntityExtraIn;
      return(CIGI_SUCCESS);
   } 

   //=========================================================
   //! Gets the EntityExtra value
   //! \return EntityExtra Specifies the entity extra data
   //!
   Cigi_uint8 GetEntityExtra(void) const { return(EntityExtra); }


};

#endif // #if !defined(_CIGI_ENTITY_CONTROL_V4)
