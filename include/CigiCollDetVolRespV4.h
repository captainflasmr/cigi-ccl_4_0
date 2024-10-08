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
 *  FILENAME:   CigiCollDetVolRespV4.h
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
 *  06/23/2006 Greg Basler                       Version 1.7.1
 *  Changed native char and unsigned char types to CIGI types Cigi_int8 and 
 *  Cigi_uint8.
 *  
 *  11/20/2007 Greg Basler                       Version 2.0.0
 *  Moved Packet information to base packet.
 *  
 *  07/29/2015 Chas Whitley                      Version 4.0.0
 *  Initial Release for CIGI 4.0 compatibility.
 *  Based on CigiCollDetVolRespV3.h
 *  
 * </pre>
 *  Author: The Boeing Company
 *
 */


#if !defined(_CIGI_COLL_DET_VOL_RESP_V4_INCLUDED_)
#define _CIGI_COLL_DET_VOL_RESP_V4_INCLUDED_

#include "CigiBaseCollDetVolResp.h"



class CIGI_SPEC CigiCollDetVolRespV4 : public CigiBaseCollDetVolResp
{

public:

   //==> Management

   //=========================================================
   //! General Constructor
   //!
   CigiCollDetVolRespV4();

   //=========================================================
   //! General Destructor
   //!
   virtual ~CigiCollDetVolRespV4();


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

   //+> VolID

   //=========================================================
   //! Sets the VolID with bound checking control
   //! \param VolIDIn - 
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetVolID(const Cigi_uint8 VolIDIn, bool bndchk=true)
   {
      VolID = VolIDIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the VolID value.
   //! \return the current VolID.
   Cigi_uint8 GetVolID(void) const { return(VolID); }


   //+> CollVolID

   //=========================================================
   //! Sets the CollVolID with bound checking control
   //! \param CollVolIDIn - 
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetCollVolID(const Cigi_uint8 CollVolIDIn, bool bndchk=true)
   {
      CollVolID = CollVolIDIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the CollVolID value.
   //! \return the current CollVolID.
   Cigi_uint8 GetCollVolID(void) const { return(CollVolID); }



};

#endif // #if !defined(_CIGI_COLL_DET_VOL_RESP_V4_INCLUDED_)
