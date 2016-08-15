///////////////////////////////////////////////////////////////////////////////
//
// Module      :  EuclideanRing.hh
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
#ifndef Data_EuclideanRing_FFI_HH
#define Data_EuclideanRing_FFI_HH

#include "PureScript/PureScript.hh"

namespace Data_EuclideanRing {
  using namespace PureScript;	

  // foreign import intDegree :: Int -> Int
  //
  inline auto intDegree(const any& x) -> any {
	  return x >= 0 ? x : -x;
  }

  // foreign import intDiv :: Int -> Int -> Int
  //
  inline auto intDiv(const int x, const int y) -> int {
    return x / y;
  }

  // foreign import intMod :: Int -> Int -> Int
  //
  inline auto intMod(const int x, const int y) -> int {
    return x % y;
  }

  // foreign import numDiv :: Number -> Number -> Number
  //
  inline auto numDiv(const double x, const double y) -> double {
    return x / y;
  }

}

#endif // Data_EuclideanRing_FFI_HH
