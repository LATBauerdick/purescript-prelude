///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Ring.hh
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
#ifndef Data_Ring_FFI_HH
#define Data_Ring_FFI_HH

#include "PureScript/PureScript.hh"

namespace Data_Ring {
  using namespace PureScript;	

  // foreign import intSub :: Int -> Int -> Int
  //
  inline auto intSub(const int x, const int y) -> int {
    return x - y;
  }

  // foreign import numSub :: Number -> Number -> Number
  //
  inline auto numSub(const double x, const double y) -> double {
    return x - y;
  }

}

#endif // Data_Ring_FFI_HH
