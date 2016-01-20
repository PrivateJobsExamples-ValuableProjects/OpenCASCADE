// Created on: 1993-02-05
// Created by: Jacques GOUSSARD
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

#ifndef _Contap_TheSearch_HeaderFile
#define _Contap_TheSearch_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Boolean.hxx>
#include <Contap_SequenceOfSegmentOfTheSearch.hxx>
#include <Contap_SequenceOfPathPointOfTheSearch.hxx>
#include <Standard_Real.hxx>
#include <Standard_Integer.hxx>
class StdFail_NotDone;
class Standard_OutOfRange;
class Standard_ConstructionError;
class Adaptor3d_HVertex;
class Adaptor2d_HCurve2d;
class Contap_HCurve2dTool;
class Contap_HContTool;
class Adaptor3d_TopolTool;
class Contap_ArcFunction;
class Contap_ThePathPointOfTheSearch;
class Contap_SequenceOfPathPointOfTheSearch;
class Contap_SequenceNodeOfSequenceOfPathPointOfTheSearch;
class Contap_TheSegmentOfTheSearch;
class Contap_SequenceOfSegmentOfTheSearch;
class Contap_SequenceNodeOfSequenceOfSegmentOfTheSearch;



class Contap_TheSearch 
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT Contap_TheSearch();
  
  Standard_EXPORT void Perform (Contap_ArcFunction& F, const Handle(Adaptor3d_TopolTool)& Domain, const Standard_Real TolBoundary, const Standard_Real TolTangency, const Standard_Boolean RecheckOnRegularity = Standard_False);
  
    Standard_Boolean IsDone() const;
  
    Standard_Boolean AllArcSolution() const;
  
    Standard_Integer NbPoints() const;
  
    const Contap_ThePathPointOfTheSearch& Point (const Standard_Integer Index) const;
  
    Standard_Integer NbSegments() const;
  
    const Contap_TheSegmentOfTheSearch& Segment (const Standard_Integer Index) const;




protected:





private:



  Standard_Boolean done;
  Standard_Boolean all;
  Contap_SequenceOfSegmentOfTheSearch sseg;
  Contap_SequenceOfPathPointOfTheSearch spnt;


};

#define TheVertex Handle(Adaptor3d_HVertex)
#define TheVertex_hxx <Adaptor3d_HVertex.hxx>
#define TheArc Handle(Adaptor2d_HCurve2d)
#define TheArc_hxx <Adaptor2d_HCurve2d.hxx>
#define TheArcTool Contap_HCurve2dTool
#define TheArcTool_hxx <Contap_HCurve2dTool.hxx>
#define TheSOBTool Contap_HContTool
#define TheSOBTool_hxx <Contap_HContTool.hxx>
#define Handle_TheTopolTool Handle(Adaptor3d_TopolTool)
#define TheTopolTool Adaptor3d_TopolTool
#define TheTopolTool_hxx <Adaptor3d_TopolTool.hxx>
#define TheFunction Contap_ArcFunction
#define TheFunction_hxx <Contap_ArcFunction.hxx>
#define IntStart_ThePathPoint Contap_ThePathPointOfTheSearch
#define IntStart_ThePathPoint_hxx <Contap_ThePathPointOfTheSearch.hxx>
#define IntStart_SequenceOfPathPoint Contap_SequenceOfPathPointOfTheSearch
#define IntStart_SequenceOfPathPoint_hxx <Contap_SequenceOfPathPointOfTheSearch.hxx>
#define IntStart_SequenceNodeOfSequenceOfPathPoint Contap_SequenceNodeOfSequenceOfPathPointOfTheSearch
#define IntStart_SequenceNodeOfSequenceOfPathPoint_hxx <Contap_SequenceNodeOfSequenceOfPathPointOfTheSearch.hxx>
#define IntStart_SequenceNodeOfSequenceOfPathPoint Contap_SequenceNodeOfSequenceOfPathPointOfTheSearch
#define IntStart_SequenceNodeOfSequenceOfPathPoint_hxx <Contap_SequenceNodeOfSequenceOfPathPointOfTheSearch.hxx>
#define IntStart_TheSegment Contap_TheSegmentOfTheSearch
#define IntStart_TheSegment_hxx <Contap_TheSegmentOfTheSearch.hxx>
#define IntStart_SequenceOfSegment Contap_SequenceOfSegmentOfTheSearch
#define IntStart_SequenceOfSegment_hxx <Contap_SequenceOfSegmentOfTheSearch.hxx>
#define IntStart_SequenceNodeOfSequenceOfSegment Contap_SequenceNodeOfSequenceOfSegmentOfTheSearch
#define IntStart_SequenceNodeOfSequenceOfSegment_hxx <Contap_SequenceNodeOfSequenceOfSegmentOfTheSearch.hxx>
#define IntStart_SequenceNodeOfSequenceOfSegment Contap_SequenceNodeOfSequenceOfSegmentOfTheSearch
#define IntStart_SequenceNodeOfSequenceOfSegment_hxx <Contap_SequenceNodeOfSequenceOfSegmentOfTheSearch.hxx>
#define Handle_IntStart_SequenceNodeOfSequenceOfPathPoint Handle(Contap_SequenceNodeOfSequenceOfPathPointOfTheSearch)
#define Handle_IntStart_SequenceNodeOfSequenceOfPathPoint Handle(Contap_SequenceNodeOfSequenceOfPathPointOfTheSearch)
#define Handle_IntStart_SequenceNodeOfSequenceOfSegment Handle(Contap_SequenceNodeOfSequenceOfSegmentOfTheSearch)
#define Handle_IntStart_SequenceNodeOfSequenceOfSegment Handle(Contap_SequenceNodeOfSequenceOfSegmentOfTheSearch)
#define IntStart_SearchOnBoundaries Contap_TheSearch
#define IntStart_SearchOnBoundaries_hxx <Contap_TheSearch.hxx>

#include <IntStart_SearchOnBoundaries.lxx>

#undef TheVertex
#undef TheVertex_hxx
#undef TheArc
#undef TheArc_hxx
#undef TheArcTool
#undef TheArcTool_hxx
#undef TheSOBTool
#undef TheSOBTool_hxx
#undef Handle_TheTopolTool
#undef TheTopolTool
#undef TheTopolTool_hxx
#undef TheFunction
#undef TheFunction_hxx
#undef IntStart_ThePathPoint
#undef IntStart_ThePathPoint_hxx
#undef IntStart_SequenceOfPathPoint
#undef IntStart_SequenceOfPathPoint_hxx
#undef IntStart_SequenceNodeOfSequenceOfPathPoint
#undef IntStart_SequenceNodeOfSequenceOfPathPoint_hxx
#undef IntStart_SequenceNodeOfSequenceOfPathPoint
#undef IntStart_SequenceNodeOfSequenceOfPathPoint_hxx
#undef IntStart_TheSegment
#undef IntStart_TheSegment_hxx
#undef IntStart_SequenceOfSegment
#undef IntStart_SequenceOfSegment_hxx
#undef IntStart_SequenceNodeOfSequenceOfSegment
#undef IntStart_SequenceNodeOfSequenceOfSegment_hxx
#undef IntStart_SequenceNodeOfSequenceOfSegment
#undef IntStart_SequenceNodeOfSequenceOfSegment_hxx
#undef Handle_IntStart_SequenceNodeOfSequenceOfPathPoint
#undef Handle_IntStart_SequenceNodeOfSequenceOfPathPoint
#undef Handle_IntStart_SequenceNodeOfSequenceOfSegment
#undef Handle_IntStart_SequenceNodeOfSequenceOfSegment
#undef IntStart_SearchOnBoundaries
#undef IntStart_SearchOnBoundaries_hxx




#endif // _Contap_TheSearch_HeaderFile
