///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Functor.hh
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
#ifndef Data_Functor_FFI_HH
#define Data_Functor_FFI_HH

#include "PureScript/PureScript.hh"

namespace Data_Functor {
  using namespace PureScript;	

  // foreign import arrayMap :: forall a b. (a -> b) -> Array a -> Array b
  //
  auto arrayMap(const any& f, const any::array& xs) -> any::array;
  
}

#endif // Data_Functor_FFI_HH
