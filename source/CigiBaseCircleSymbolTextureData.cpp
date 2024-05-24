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
 *  FILENAME:   CigiBaseCircleSymbolTextureData.cpp
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
 *  01/17/2008 Greg Basler                       CIGI_CR_DR_1
 *  Initial Release.
 *  
 *  07/29/2015 Chas Whitley                      Version 4.0.0
 *  Initial Release for CIGI 4.0 compatibility.
 *  Based on CigiBaseCircleSymbolData.cpp
 *  
 * </pre>
 *  Author: TJ Inc.
 *
 */


#define _EXPORT_CCL_


#include "CigiBaseCircleSymbolTextureData.h"
#include "CigiExceptions.h"



// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiBaseEntityCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseCircleSymbolTextureData::CigiBaseCircleSymbolTextureData(void)
{
}

// ================================================
// ~CigiBaseEntityCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseCircleSymbolTextureData::~CigiBaseCircleSymbolTextureData(void)
{
}


// ====================================================================
// Accessors
// ====================================================================

// ================================================
// SetRadius
// ================================================
int CigiBaseCircleSymbolTextureData::SetRadius(const float RadiusIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((RadiusIn < 0.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("RadiusIn", (int)RadiusIn,">=",0.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   Radius = RadiusIn;

   return(CIGI_SUCCESS);

}


// ================================================
// InnerRadius
// ================================================
int CigiBaseCircleSymbolTextureData::SetInnerRadius(const float InnerRadiusIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((InnerRadiusIn < 0.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("InnerRadiusIn", (int)InnerRadiusIn,">=",0.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   InnerRadius = InnerRadiusIn;

   return(CIGI_SUCCESS);

}


// ================================================
// StartAngle
// ================================================
int CigiBaseCircleSymbolTextureData::SetStartAngle(const float StartAngleIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((StartAngleIn < 0.0)||(StartAngleIn > 360.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("StartAngle", (double)StartAngleIn,0.0,360.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   StartAngle = StartAngleIn;

   return(CIGI_SUCCESS);

}


// ================================================
// EndAngle
// ================================================
int CigiBaseCircleSymbolTextureData::SetEndAngle(const float EndAngleIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((EndAngleIn < 0.0)||(EndAngleIn > 360.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("EndAngle", (double)EndAngleIn,0.0,360.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   EndAngle = EndAngleIn;

   return(CIGI_SUCCESS);

}


// ================================================
// STexCoord;
// ================================================
int CigiBaseCircleSymbolTextureData::SetSTexCoord(const float STexCoordIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((STexCoordIn < 0.0)||(STexCoordIn > 1.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("STexCoord", (double)STexCoordIn,0.0,1.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   STexCoord = STexCoordIn;

   return(CIGI_SUCCESS);

}

// ================================================
// TTexCoord;
// ================================================
int CigiBaseCircleSymbolTextureData::SetTTexCoord(const float TTexCoordIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((TTexCoordIn < 0.0)||(TTexCoordIn > 1.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("TTexCoord", (double)TTexCoordIn,0.0,1.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   TTexCoord = TTexCoordIn;

   return(CIGI_SUCCESS);

}

// ================================================
// TextureRadius;
// ================================================
int CigiBaseCircleSymbolTextureData::SetTextureRadius(const float TextureRadiusIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((TextureRadiusIn < 0.0)||(TextureRadiusIn > 1.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("TextureRadius", (double)TextureRadiusIn,0.0,1.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   TextureRadius = TextureRadiusIn;

   return(CIGI_SUCCESS);

}

// ================================================
// TextureRotation;
// ================================================
int CigiBaseCircleSymbolTextureData::SetTextureRotation(const float TextureRotationIn, bool bndchk)
{

   TextureRotation = TextureRotationIn;

   return(CIGI_SUCCESS);

}
