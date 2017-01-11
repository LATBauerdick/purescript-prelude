///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Bounded.cc
// Copyright   :  (c) Andy Arvanitis 2015
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Bounded FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#include <limits>
#include "Bounded.hh"

namespace Data_Bounded {
  using namespace PureScript;

  const int topInt    = std::numeric_limits<decltype(topInt)>::max();
  const int bottomInt = std::numeric_limits<decltype(bottomInt)>::min();

  const char32_t topChar    = 0x10FFFF; // unicode limit
  const char32_t bottomChar = 0;

}
