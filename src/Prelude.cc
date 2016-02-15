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

  auto arrayMap(const any& f) -> any {
    return [=](const any& a) -> any {
      const auto& as = a.cast<any::array>();
      any::array bs;
      for (auto it = as.cbegin(), end = as.cend(); it != end; it++) {
          bs.emplace_back(f(*it));
      }
      return bs;
    };
  }

  //- Bind -----------------------------------------------------------------------

  auto arrayBind(const any& a) -> any {
    return [=](const any& f) -> any {
      const auto& as = a.cast<any::array>();
      any::array result;
      for (auto it = as.cbegin(), end = as.cend(); it != end; it++) {
        auto xs_ = f(*it);
        const auto& xs = xs_.cast<any::array>();
        for (auto iit = xs.begin(), iend = xs.end(); iit != iend; iit++) {
          result.emplace_back(std::move(*iit));
        }
      }
      return result;
    };
  }

  //- Monoid ---------------------------------------------------------------------

  auto concatArray(const any& a) -> any {
    return [=](const any& b) -> any {
      any::array result(a.cast<any::array>()); // makes a copy
      const auto& bs = b.cast<any::array>();
      result.insert(result.end(), bs.cbegin(), bs.cend());
      return result;
    };
  }

  //- Eq -------------------------------------------------------------------------

  auto eqArrayImpl(const any& f) -> any {
    return [=](const any& xs_) -> any {
      return [=](const any& ys_) -> any {
        const auto& xs = xs_.cast<any::array>();
        const auto& ys = ys_.cast<any::array>();
        const auto xs_size = xs.size();
        if (xs_size != ys.size()) {
          return false;
        }
        auto itx = xs.cbegin();
        auto ity = ys.cbegin();
        for (auto i = 0; i < xs_size; i++) {
          auto res = f(*itx++)(*ity++);
          if (not res.cast<bool>()) {
            return false;
          }
        }
        return true;
      };
    };
  }

  auto ordArrayImpl(const any& f) -> any {
    return [=](const any& xs_) -> any {
      return [=](const any& ys_) -> any {
        const auto& xs = xs_.cast<any::array>();
        const auto& ys = ys_.cast<any::array>();
        const auto xlen = xs.size();
        const auto ylen = ys.size();
        auto itx = xs.cbegin();
        auto ity = ys.cbegin();
        for (auto i = 0; i < xlen and i < ylen; i++) {
          auto x = *itx++;
          auto y = *ity++;
          auto o = f(x)(y);
          if (o != 0L) {
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
      };
    };
  }

  //- Ord ------------------------------------------------------------------------

  auto unsafeCompareImpl(const any& lt) -> any {
    return [=](const any& eq) -> any {
      return [=](const any& gt) -> any {
        return [=](const any& x) -> any {
          return [=](const any& y) -> any {
            return x < y ? lt : x > y ? gt : eq;
          };
        };
      };
    };
  }

  //- Bounded --------------------------------------------------------------------

  const long topInt    = LONG_MAX;
  const long bottomInt = LONG_MIN;

  //- Show -----------------------------------------------------------------------

  auto showCharImpl(const any& c) -> any {
    std::string s("'");
    s.push_back(c.cast<char>());
    s.push_back('\'');
    return s;
  }

  auto showStringImpl(const any& s) -> any {
    return std::string("\"") + s.cast<string>() + '"';
  }

  auto showArrayImpl(const any& f) -> any {
    return [=](const any& xs_) -> any {
      const auto& xs = xs_.cast<any::array>();
      std::string s("[");
      auto count = xs.size();
      for (auto it = xs.cbegin(), end = xs.cend(); it != end; it++) {
        s.append(f(*it).cast<string>());
        if (--count > 0) {
          s.push_back(',');
        }
      }
      s.push_back(']');
      return s;
    };
  }

}
