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
 *  FILENAME:   CigiSensorRespV3.h
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
 *  Moved Packet information to base packet.
 *  
 * </pre>
 *  Author: The Boeing Company
 *
 */


#if !defined(_CIGI_SENSOR_RESP_V3_INCLUDED_)
#define _CIGI_SENSOR_RESP_V3_INCLUDED_

#include "CigiBaseSensorResp.h"



class CIGI_SPEC CigiSensorRespV3 : public CigiBaseSensorResp
{

public:

   //==> Management

   //=========================================================
   //! General Constructor
   //!
   CigiSensorRespV3();

   //=========================================================
   //! General Destructor
   //!
   virtual ~CigiSensorRespV3();


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

   //+> ViewID

   //=========================================================
   //! Sets the ViewID with bound checking control
   //! \param ViewIDIn - View ID
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetViewID(const Cigi_uint16 ViewIDIn, bool bndchk=true)
   {
      ViewID = ViewIDIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the ViewID value.
   //! \return the current ViewID.
   Cigi_uint16 GetViewID(void) const { return(ViewID); }


   //+> FrameCntr

   //=========================================================
   //! Sets the FrameCntr with bound checking control
   //! \param FrameCntrIn - Frame counter value
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetFrameCntr(const Cigi_uint32 FrameCntrIn, bool bndchk=true)
   {
      FrameCntr = FrameCntrIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the FrameCntr value.
   //! \return the current FrameCntr.
   Cigi_uint32 GetFrameCntr(void) const { return(FrameCntr); }





};

#endif // #if !defined(_CIGI_SENSOR_RESP_V3_INCLUDED_)
