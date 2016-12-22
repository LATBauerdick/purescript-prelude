///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Ord.cc
// Copyright   :  (c) Andy Arvanitis 2015
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Ord FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#include "Ord.hh"

namespace Data_Ord {
  using namespace PureScript;

  auto ordArrayImpl(const any& f, const any::array& xs, const any::array& ys) -> int {
    const auto xlen = xs.size();
    const auto ylen = ys.size();
    auto itx = xs.cbegin();
    auto ity = ys.cbegin();
    for (any::array::size_type i = 0; i < xlen and i < ylen; i++) {
      auto x = *itx++;
      auto y = *ity++;
      auto o = f(x)(y);
      if (o != 0) {
        return o;
      }
    }
    if (xlen == ylen) {
      return 0;
    } else if (xlen > ylen) {
      return -1;
    } else {
      return 1;
    }
  }

}
