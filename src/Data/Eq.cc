///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Eq.cc
// Copyright   :  (c) Andy Arvanitis 2015
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Eq FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#include "Eq.hh"

namespace Data_Eq {
  using namespace PureScript;

  auto eqArrayImpl(const any& f, const any::array& xs, const any::array& ys) -> bool {
    const auto xs_size = xs.size();
    if (xs_size != ys.size()) {
      return false;
    }
    auto itx = xs.cbegin();
    auto ity = ys.cbegin();
    for (any::array::size_type i = 0; i < xs_size; i++) {
      auto res = f(*itx++)(*ity++);
      if (not static_cast<bool>(res)) {
        return false;
      }
    }
    return true;
  }

}
