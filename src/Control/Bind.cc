///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Bind.cc
// Copyright   :  (c) Andy Arvanitis 2015
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Bind FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#include "Bind.hh"

namespace Control_Bind {
  using namespace PureScript;

  auto arrayBind(const any::array& xs, const any& f) -> any::array {
    any::array result;
    for (auto it = xs.cbegin(), end = xs.cend(); it != end; it++) {
      auto ys_ = f(*it);
      const any::array& ys = ys_;
      for (auto iit = ys.begin(), iend = ys.end(); iit != iend; iit++) {
        result.emplace_back(std::move(*iit));
      }
    }
    return result;
  }

}
