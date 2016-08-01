///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Functor.cc
// Copyright   :  (c) Andy Arvanitis 2015
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Functor FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#include "Functor.hh"

namespace Data_Functor {
  using namespace PureScript;

  auto arrayMap(const any& f, const any::array& xs) -> any::array {
    any::array bs;
    for (auto it = xs.cbegin(), end = xs.cend(); it != end; it++) {
        bs.emplace_back(f(*it));
    }
    return bs;
  }

}
