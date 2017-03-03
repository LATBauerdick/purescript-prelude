///////////////////////////////////////////////////////////////////////////////
//
// Module      :  HeytingAlgebra.hh
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
#ifndef Data_HeytingAlgebra_FFI_HH
#define Data_HeytingAlgebra_FFI_HH

#include "PureScript/PureScript.hh"

namespace Data_HeytingAlgebra {
  using namespace PureScript;	

  // foreign import boolConj :: Boolean -> Boolean -> Boolean
  //
  inline auto boolConj(const bool b1, const bool b2) -> bool {
    return b1 && b2;
  }

  // foreign import boolDisj :: Boolean -> Boolean -> Boolean
  //
  inline auto boolDisj(const bool b1, const bool b2) -> bool {
    return b1 || b2;
  }

  // foreign import boolNot :: Boolean -> Boolean
  //
  inline auto boolNot(const any& b) -> any {
    return not static_cast<bool>(b);
  }

}

#endif // Data_HeytingAlgebra_FFI_HH
