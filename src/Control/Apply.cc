///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Apply.cc
// Copyright   :  (c) Andy Arvanitis 2015
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Apply FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#include "Apply.hh"

namespace Control_Apply {
  using namespace PureScript;

  auto arrayApply(const any::array& fs, const any::array& xs) -> any::array {
    any::array result;
    for (auto f = fs.cbegin(), fend = fs.cend(); f != fend; f++) {
      for (auto x = xs.cbegin(), xend = xs.cend(); x != xend; x++) {
        result.emplace_back((*f)(*x));
      }
    }
    return result;
  }

}
