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
 *  FILENAME:   CigiBaseCollDetSegResp.cpp
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
 *  Defined _EXPORT_CCL_ for exporting the class in a Windows DLL.
 *  
 *  11/20/2007 Greg Basler                       Version 2.0.0
 *  Added new version conversion method.
 *  
 * </pre>
 *  Author: The Boeing Company
 *
 */

#define _EXPORT_CCL_

#include "CigiBaseCollDetSegResp.h"
#include "CigiSwapping.h"
#include "CigiExceptions.h"


// ====================================================================
// Construction/Destruction
// ====================================================================


// ================================================
// CigiBaseCollDetSegResp
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseCollDetSegResp::CigiBaseCollDetSegResp()
{

}



// ================================================
// ~CigiBaseCollDetSegResp
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseCollDetSegResp::~CigiBaseCollDetSegResp()
{

}

// ====================================================================
// Conversion Control
// ====================================================================


// ================================================
// GetCnvt
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseCollDetSegResp::GetCnvt(CigiVersionID &CnvtVersion,
                                    CigiCnvtInfoType::Type &CnvtInfo)
{
   CnvtInfo.ProcID = CigiProcessType::ProcStd;

   // Note: V1 & V2 are the same
   if(CnvtVersion.CigiMajorVersion < 3)
      CnvtInfo.CnvtPacketID = CIGI_COLL_DET_SEG_RESP_PACKET_ID_V2;
   else if(CnvtVersion.CigiMajorVersion < 4)
      CnvtInfo.CnvtPacketID = CIGI_COLL_DET_SEG_RESP_PACKET_ID_V3;
   else
      CnvtInfo.CnvtPacketID = CIGI_COLL_DET_SEG_RESP_PACKET_ID_V4;

   return(CIGI_SUCCESS);
}


// ====================================================================
// Accessors
// ====================================================================


