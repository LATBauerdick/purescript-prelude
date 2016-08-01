///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Semigroup.hh
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
#ifndef Data_Semigroup_FFI_HH
#define Data_Semigroup_FFI_HH

#include "PureScript/PureScript.hh"

namespace Data_Semigroup {
  using namespace PureScript;	

  // foreign import concatString :: String -> String -> String
  //
  inline auto concatString(const any& s1, const any& s2) -> any {
    return s1 + s2;
  }

  // foreign import concatArray :: forall a. Array a -> Array a -> Array a
  //
  inline auto concatArray(const any::array& xs, const any::array& ys) -> any::array {
    any::array result(xs); // makes a copy
    result.insert(result.end(), ys.cbegin(), ys.cend());
    return result;
  }

}

#endif // Data_Semigroup_FFI_HH
