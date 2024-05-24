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
 *  FILENAME:   CigiBaseAnimationCtrl.cpp
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
 *  Author: TJ Inc.
 *
 */


#define _EXPORT_CCL_

#include "CigiBaseAnimationCtrl.h"
#include "CigiExceptions.h"

// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiBaseAnimationCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseAnimationCtrl::CigiBaseAnimationCtrl()
{

}

// ================================================
// ~CigiBaseAnimationCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseAnimationCtrl::~CigiBaseAnimationCtrl()
{

}


// ====================================================================
// Conversion Control
// ====================================================================


// ================================================
// GetCnvt
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseAnimationCtrl::GetCnvt(CigiVersionID &CnvtVersion,
                                CigiCnvtInfoType::Type &CnvtInfo)
{
   if (CnvtVersion.CigiMajorVersion < 4)
   {
       CnvtInfo.ProcID = CigiProcessType::ProcNone;
       CnvtInfo.CnvtPacketID = 0;
   }
   else {
       CnvtInfo.ProcID = CigiProcessType::ProcEntity;
       CnvtInfo.CnvtPacketID = CIGI_ANIMATION_CTRL_PACKET_ID_V4;
   }
   return(CIGI_SUCCESS);
}


// ====================================================================
// Accessors
// ====================================================================

// ================================================
// InheritAlpha
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseAnimationCtrl::SetInheritAlpha(const InheritAlphaGrp InheritAlphaIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((InheritAlphaIn < 0)||(InheritAlphaIn > 1)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("InheritAlpha",InheritAlphaIn,0,1);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   InheritAlpha = InheritAlphaIn;
   return(CIGI_SUCCESS);

}


// ================================================
// AnimationState
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseAnimationCtrl::SetAnimationState(const AnimationStateGrp AnimationStateIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((AnimationStateIn < 0)||(AnimationStateIn > 1)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("AnimationState",AnimationStateIn,0,1);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   AnimationState = AnimationStateIn;
   return(CIGI_SUCCESS);

}

// ================================================
// AnimationFrameResetMode
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseAnimationCtrl::SetAnimationFrameResetMode(const AnimationFramePositionResetGrp AnimationFrameResetModeIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((AnimationFrameResetModeIn < 0)||(AnimationFrameResetModeIn > 1)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("AnimationFrameResetMode",AnimationFrameResetModeIn,0,1);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   AnimationFrameResetMode = AnimationFrameResetModeIn;
   return(CIGI_SUCCESS);

}

// ================================================
// AnimationLoopMode
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseAnimationCtrl::SetAnimationLoopMode(const AnimationLoopModeGrp AnimationLoopModeIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((AnimationLoopModeIn < 0)||(AnimationLoopModeIn > 1)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("AnimationFrameResetMode",AnimationLoopModeIn,0,1);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   AnimationLoopMode = AnimationLoopModeIn;
   return(CIGI_SUCCESS);

}


