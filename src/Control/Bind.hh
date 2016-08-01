///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Bind.hh
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
#ifndef Control_Bind_FFI_HH
#define Control_Bind_FFI_HH

#include "PureScript/PureScript.hh"

namespace Control_Bind {
  using namespace PureScript;	

  // foreign import arrayBind :: forall a b. Array a -> (a -> Array b) -> Array b
  //
  auto arrayBind(const any::array& xs, const any& f) -> any::array;

}

#endif // Control_Bind_FFI_HH
