///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Bounded.hh
// Copyright   :  (c) Andy Arvanitis 2015, 2016
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
#ifndef Data_Bounded_FFI_HH
#define Data_Bounded_FFI_HH

#include "PureScript/PureScript.hh"

namespace Data_Bounded {
  using namespace PureScript;	

  extern const int topInt;
  extern const int bottomInt;

  extern const char32_t topChar;
  extern const char32_t bottomChar;
}

#endif // Data_Bounded_FFI_HH
