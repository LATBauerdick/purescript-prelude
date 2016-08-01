///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Show.cc
// Copyright   :  (c) Andy Arvanitis 2015
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Show FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#include "Show.hh"

namespace Data_Show {
  using namespace PureScript;

  auto showCharImpl(const any& c) -> any {
    std::string s("'");
    s.push_back(c);
    s.push_back('\'');
    return s;
  }

  auto showStringImpl(const any& s) -> any {
    return std::string("\"") + cast<cstring>(s) + '"';
  }

  auto showArrayImpl(const any& f, const any::array& xs) -> any {
    std::string s("[");
    auto count = xs.size();
    for (auto it = xs.cbegin(), end = xs.cend(); it != end; it++) {
      s.append(cast<cstring>(f(*it)));
      if (--count > 0) {
        s.push_back(',');
      }
    }
    s.push_back(']');
    return s;
  }

}
