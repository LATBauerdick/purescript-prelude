///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Prelude.cc
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
#include <climits>
#include "Prelude.hh"

namespace Prelude {
  using namespace PureScript;

  //- Functor --------------------------------------------------------------------

  auto arrayMap(const any& f, const any::array& as) -> any::array {
    any::array bs;
    for (auto it = as.cbegin(), end = as.cend(); it != end; it++) {
        bs.emplace_back(f(*it));
    }
    return bs;
  }

  //- Bind -----------------------------------------------------------------------

  auto arrayBind(const any::array& as, const any& f) -> any::array {
    any::array result;
    for (auto it = as.cbegin(), end = as.cend(); it != end; it++) {
      auto xs_ = f(*it);
      const any::array& xs = xs_;
      for (auto iit = xs.begin(), iend = xs.end(); iit != iend; iit++) {
        result.emplace_back(std::move(*iit));
      }
    }
    return result;
  }

  //- Monoid ---------------------------------------------------------------------

  auto concatArray(const any::array& as, const any::array& bs) -> any::array {
    any::array result(as); // makes a copy
    result.insert(result.end(), bs.cbegin(), bs.cend());
    return result;
  }

  //- Eq -------------------------------------------------------------------------

  auto eqArrayImpl(const any& f, const any::array& xs, const any::array& ys) -> bool {
    const auto xs_size = xs.size();
    if (xs_size != ys.size()) {
      return false;
    }
    auto itx = xs.cbegin();
    auto ity = ys.cbegin();
    for (auto i = 0; i < xs_size; i++) {
      auto res = f(*itx++)(*ity++);
      if (not cast<bool>(res)) {
        return false;
      }
    }
    return true;
  }

  auto ordArrayImpl(const any& f, const any::array& xs, const any::array& ys) -> integer {
    const auto xlen = xs.size();
    const auto ylen = ys.size();
    auto itx = xs.cbegin();
    auto ity = ys.cbegin();
    for (auto i = 0; i < xlen and i < ylen; i++) {
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

  //- Ord ------------------------------------------------------------------------

  auto unsafeCompareImpl(const any& lt,
                          const any& eq,
                          const any& gt,
                          const any& x,
                          const any& y) -> any {
    return x < y ? lt : x > y ? gt : eq;
  }

  //- Bounded --------------------------------------------------------------------

  const integer topInt    = INTEGER_MAX;
  const integer bottomInt = INTEGER_MIN;

  //- Show -----------------------------------------------------------------------

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
