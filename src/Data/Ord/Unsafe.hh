///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Unsafe.hh
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
#ifndef Data_Ord_Unsafe_FFI_HH
#define Data_Ord_Unsafe_FFI_HH

#include "PureScript/PureScript.hh"

namespace Data_Ord_Unsafe {
  using namespace PureScript;	

  // foreign import unsafeCompareImpl
  //   :: forall a
  //    . Ordering
  //   -> Ordering
  //   -> Ordering
  //   -> a
  //   -> a
  //   -> Ordering
  //
  inline auto unsafeCompareImpl(const any& lt,
                                const any& eq,
                                const any& gt,
                                const any& x,
                                const any& y) -> any {                           
    return x < y ? lt : x > y ? gt : eq;
  }
}

#endif // Data_Ord_Unsafe_FFI_HH
