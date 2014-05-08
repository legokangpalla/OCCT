// Created on: 2002-04-29
// Created by: Alexander KARTOMIN (akm)
// Copyright (c) 2002-2014 OPEN CASCADE SAS
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

//            Automatically created from NCollection_HArray1.hxx by GAWK

#ifndef NCollection_DefineHArray1_HeaderFile
#define NCollection_DefineHArray1_HeaderFile

#include <Standard_DefineHandle.hxx>
#include <NCollection_DefineArray1.hxx>
#include <MMgt_TShared.hxx>

//      Declaration of Array1 class managed by Handle

#define DEFINE_HARRAY1(HClassName, _Array1Type_)                               \
\
class HClassName : public _Array1Type_,                                        \
                   public MMgt_TShared {                                       \
 public:                                                                       \
   DEFINE_STANDARD_ALLOC                                                       \
   DEFINE_NCOLLECTION_ALLOC                                                    \
   inline                     HClassName    (const Standard_Integer theLower,  \
                                             const Standard_Integer theUpper); \
   inline                     HClassName    (const _Array1Type_&);             \
   inline const _Array1Type_& Array1        () const;                          \
   inline _Array1Type_&       ChangeArray1  ();                                \
   DEFINE_STANDARD_RTTI (HClassName)                                           \
};                                                                             \
                                                                               \
DEFINE_STANDARD_HANDLE (HClassName, MMgt_TShared)                              \
                                                                               \
inline HClassName::HClassName (const Standard_Integer theLower,                \
                               const Standard_Integer theUpper) :              \
       _Array1Type_ (theLower,theUpper),                                       \
       MMgt_TShared() {}                                                       \
                                                                               \
inline HClassName::HClassName (const _Array1Type_& theOther) :                 \
       _Array1Type_(theOther),                                                 \
       MMgt_TShared() {}                                                       \
                                                                               \
inline const _Array1Type_& HClassName::Array1 () const                         \
{ return * (const _Array1Type_ *) this; }                                      \
                                                                               \
inline _Array1Type_& HClassName::ChangeArray1 ()                               \
{ return * (_Array1Type_ *) this; }                                            \

#define IMPLEMENT_HARRAY1(HClassName)                                          \
IMPLEMENT_STANDARD_HANDLE  (HClassName, MMgt_TShared)                          \
IMPLEMENT_STANDARD_RTTIEXT (HClassName, MMgt_TShared)

#endif
