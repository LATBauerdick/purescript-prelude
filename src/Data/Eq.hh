///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Eq.hh
// Copyright   :  (c) Andy Arvanitis 2015, 2016
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Prelude FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#ifndef Data_Eq_FFI_HH
#define Data_Eq_FFI_HH

#include "PureScript/PureScript.hh"

namespace Data_Eq {
  using namespace PureScript;

  // foreign import refEq :: forall a. a -> a -> Boolean
  //
  inline auto refEq(const any& ref1, const any& ref2) -> bool {
    return ref1 == ref2;
  }

  // foreign import refIneq :: forall a. a -> a -> Boolean
  //
  inline auto refIneq(const any& ref1, const any& ref2) -> bool {
    return ref1 != ref2;
  }

  // foreign import eqArrayImpl :: forall a. (a -> a -> Boolean) -> Array a -> Array a -> Boolean
  //
  auto eqArrayImpl(const any& f, const any::array& xs, const any::array& ys) -> bool;

}

#endif // Data_Eq_FFI_HH
