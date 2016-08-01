///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Semiring.hh
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
#ifndef Data_Semiring_FFI_HH
#define Data_Semiring_FFI_HH

#include "PureScript/PureScript.hh"

namespace Data_Semiring {
  using namespace PureScript;	

  // foreign import intAdd :: Int -> Int -> Int
  //
  inline auto intAdd(const integer x, const integer y) -> integer {
    return x + y;
  }

  // foreign import intMul :: Int -> Int -> Int
  //
  inline auto intMul(const integer x, const integer y) -> integer {
    return x * y;
  }

  // foreign import numAdd :: Number -> Number -> Number
  //
  inline auto numAdd(const double x, const double y) -> double {
    return x + y;
  }

  // foreign import numMul :: Number -> Number -> Number
  //
  inline auto numMul(const double x, const double y) -> double {
    return x * y;
  }
}

#endif // Data_Semiring_FFI_HH
