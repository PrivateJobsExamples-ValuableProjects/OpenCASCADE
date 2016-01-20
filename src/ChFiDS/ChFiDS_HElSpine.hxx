// Created on: 1993-11-17
// Created by: Isabelle GRIGNON
// Copyright (c) 1993-1999 Matra Datavision
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

#ifndef _ChFiDS_HElSpine_HeaderFile
#define _ChFiDS_HElSpine_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <ChFiDS_ElSpine.hxx>
#include <Adaptor3d_HCurve.hxx>
class Standard_OutOfRange;
class Standard_NoSuchObject;
class Standard_DomainError;
class ChFiDS_ElSpine;
class Adaptor3d_Curve;


class ChFiDS_HElSpine;
DEFINE_STANDARD_HANDLE(ChFiDS_HElSpine, Adaptor3d_HCurve)


class ChFiDS_HElSpine : public Adaptor3d_HCurve
{

public:

  
  Standard_EXPORT ChFiDS_HElSpine();
  
  Standard_EXPORT ChFiDS_HElSpine(const ChFiDS_ElSpine& C);
  
  Standard_EXPORT void Set (const ChFiDS_ElSpine& C);
  
  Standard_EXPORT const Adaptor3d_Curve& Curve() const;
  
  Standard_EXPORT Adaptor3d_Curve& GetCurve();
  
    ChFiDS_ElSpine& ChangeCurve();




  DEFINE_STANDARD_RTTI(ChFiDS_HElSpine,Adaptor3d_HCurve)

protected:


  ChFiDS_ElSpine myCurve;


private:




};

#define TheCurve ChFiDS_ElSpine
#define TheCurve_hxx <ChFiDS_ElSpine.hxx>
#define Adaptor3d_GenHCurve ChFiDS_HElSpine
#define Adaptor3d_GenHCurve_hxx <ChFiDS_HElSpine.hxx>
#define Handle_Adaptor3d_GenHCurve Handle(ChFiDS_HElSpine)

#include <Adaptor3d_GenHCurve.lxx>

#undef TheCurve
#undef TheCurve_hxx
#undef Adaptor3d_GenHCurve
#undef Adaptor3d_GenHCurve_hxx
#undef Handle_Adaptor3d_GenHCurve




#endif // _ChFiDS_HElSpine_HeaderFile
