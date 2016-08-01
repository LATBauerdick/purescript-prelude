///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Apply.hh
// Copyright   :  (c) Andy Arvanitis 2015
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
#ifndef Control_Apply_FFI_HH
#define Control_Apply_FFI_HH

#include "PureScript/PureScript.hh"

namespace Control_Apply {
  using namespace PureScript;	

  // foreign import arrayApply :: forall a b. Array (a -> b) -> Array a -> Array b
  //
  auto arrayApply(const any::array& fs, const any::array& xs) -> any::array;

}

#endif // Control_Apply_FFI_HH
