// Created on: 2015-07-13
// Created by: Irina KRYLOVA
// Copyright (c) 2015 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#ifndef _StepDimTol_ToleranceZoneDefinition_HeaderFile
#define _StepDimTol_ToleranceZoneDefinition_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <MMgt_TShared.hxx>
#include <Standard_Integer.hxx>
#include <StepRepr_HArray1OfShapeAspect.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepDimTol_ToleranceZone.hxx>

class StepRepr_HArray1OfShapeAspect;

class StepDimTol_ToleranceZoneDefinition;
DEFINE_STANDARD_HANDLE(StepDimTol_ToleranceZoneDefinition, MMgt_TShared)
//! Representation of STEP entity ToleranceZoneDefinition
class StepDimTol_ToleranceZoneDefinition : public MMgt_TShared
{

public:
  
  //! Empty constructor
  Standard_EXPORT StepDimTol_ToleranceZoneDefinition();
  
  //! Initialize all fields (own and inherited)
  Standard_EXPORT   void Init (const Handle(StepDimTol_ToleranceZone)& theZone,
                               const Handle(StepRepr_HArray1OfShapeAspect)& theBoundaries);
  
  //! Returns field Boundaries
  inline Handle(StepRepr_HArray1OfShapeAspect) Boundaries () const
  {
    return boundaries;
  }
  
  //! Set field Boundaries
  inline void SetBoundaries (const Handle(StepRepr_HArray1OfShapeAspect) &theBoundaries)
  {
    boundaries = theBoundaries;
  }
  
  //! Returns number of Boundaries
  inline Standard_Integer NbBoundaries () const
  {  
    return (boundaries.IsNull() ? 0 : boundaries->Length());
  }
  
  //! Returns Boundaries with the given number
  inline Handle(StepRepr_ShapeAspect) BoundariesValue(const Standard_Integer num) const
  {  
    return boundaries->Value(num);
  }
  
  //! Sets Boundaries with given number
  inline void SetBoundariesValue(const Standard_Integer num, const Handle(StepRepr_ShapeAspect)& theItem)
  {  
    boundaries->SetValue (num, theItem);
  }
  
  //! Returns field Zone
  inline Handle(StepDimTol_ToleranceZone) Zone()
  {
    return zone;
  }
  
  //! Set field Zone
  inline void SetZone(const Handle(StepDimTol_ToleranceZone)& theZone)
  {
    zone = theZone;
  }
  
  DEFINE_STANDARD_RTTI(StepDimTol_ToleranceZoneDefinition, MMgt_TShared)

private: 
  Handle(StepRepr_HArray1OfShapeAspect) boundaries;
  Handle(StepDimTol_ToleranceZone) zone;
};
#endif // _StepDimTol_ToleranceZoneDefinition_HeaderFile
