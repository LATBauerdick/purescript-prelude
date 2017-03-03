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
#include <locale>
#include <codecvt>
#include "Show.hh"

namespace Data_Show {
  using namespace PureScript;

  auto showCharImpl(const char32_t c) -> any {
    std::string s("'");
    if (c < 128) {
      s.push_back(c);
    } else {
      static std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> utf32conv;
      s += utf32conv.to_bytes(c);
    }
    s.push_back('\'');
    return s;
  }

  auto showStringImpl(const any& s) -> any {
    return std::string("\"") + s + '"';
  }

  auto showArrayImpl(const any& f, const any::array& xs) -> any {
    std::string s("[");
    auto count = xs.size();
    for (auto it = xs.cbegin(), end = xs.cend(); it != end; it++) {
      s.append(static_cast<const string&>(f(*it)));
      if (--count > 0) {
        s.push_back(',');
      }
    }
    s.push_back(']');
    return s;
  }

}
