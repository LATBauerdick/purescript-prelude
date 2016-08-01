///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Ord.hh
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
#ifndef Data_Ord_FFI_HH
#define Data_Ord_FFI_HH

#include "PureScript/PureScript.hh"

namespace Data_Ord {
  using namespace PureScript;

  // foreign import ordArrayImpl :: forall a. (a -> a -> Int) -> Array a -> Array a -> Int
  //
  auto ordArrayImpl(const any& f, const any::array& xs, const any::array& ys) -> integer;

}

#endif // Data_Ord_FFI_HH
