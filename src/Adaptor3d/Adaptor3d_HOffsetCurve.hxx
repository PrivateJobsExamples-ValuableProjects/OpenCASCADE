// Created on: 1992-10-08
// Created by: Isabelle GRIGNON
// Copyright (c) 1992-1999 Matra Datavision
// Copyright (c) 1999-2014 OPEN CASCADE SAS
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

#ifndef _Adaptor3d_HOffsetCurve_HeaderFile
#define _Adaptor3d_HOffsetCurve_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Adaptor3d_OffsetCurve.hxx>
#include <Adaptor2d_HCurve2d.hxx>
class Standard_OutOfRange;
class Standard_NoSuchObject;
class Standard_DomainError;
class Adaptor3d_OffsetCurve;
class Adaptor2d_Curve2d;


class Adaptor3d_HOffsetCurve;
DEFINE_STANDARD_HANDLE(Adaptor3d_HOffsetCurve, Adaptor2d_HCurve2d)


class Adaptor3d_HOffsetCurve : public Adaptor2d_HCurve2d
{

public:

  
  Standard_EXPORT Adaptor3d_HOffsetCurve();
  
  Standard_EXPORT Adaptor3d_HOffsetCurve(const Adaptor3d_OffsetCurve& C);
  
  Standard_EXPORT void Set (const Adaptor3d_OffsetCurve& C);
  
  Standard_EXPORT const Adaptor2d_Curve2d& Curve2d() const;
  
    Adaptor3d_OffsetCurve& ChangeCurve2d();




  DEFINE_STANDARD_RTTI(Adaptor3d_HOffsetCurve,Adaptor2d_HCurve2d)

protected:


  Adaptor3d_OffsetCurve myCurve;


private:




};

#define TheCurve Adaptor3d_OffsetCurve
#define TheCurve_hxx <Adaptor3d_OffsetCurve.hxx>
#define Adaptor2d_GenHCurve2d Adaptor3d_HOffsetCurve
#define Adaptor2d_GenHCurve2d_hxx <Adaptor3d_HOffsetCurve.hxx>
#define Handle_Adaptor2d_GenHCurve2d Handle(Adaptor3d_HOffsetCurve)

#include <Adaptor2d_GenHCurve2d.lxx>

#undef TheCurve
#undef TheCurve_hxx
#undef Adaptor2d_GenHCurve2d
#undef Adaptor2d_GenHCurve2d_hxx
#undef Handle_Adaptor2d_GenHCurve2d




#endif // _Adaptor3d_HOffsetCurve_HeaderFile
