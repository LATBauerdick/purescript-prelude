///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Show.hh
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
#ifndef Data_Show_FFI_HH
#define Data_Show_FFI_HH

#include "PureScript/PureScript.hh"

namespace Data_Show {
  using namespace PureScript;	

  // foreign import showIntImpl :: Int -> String
  //
  inline auto showIntImpl(const any& x) -> any {
    return std::to_string((integer)x);
  }

  // foreign import showNumberImpl :: Number -> String
  //
  inline auto showNumberImpl(const any& x) -> any {
    return std::to_string((double)x);
  }

  // foreign import showCharImpl :: Char -> String
  //
  auto showCharImpl(const any& c) -> any;

  // foreign import showStringImpl :: String -> String
  //
  auto showStringImpl(const any& s) -> any;

  // foreign import showArrayImpl :: forall a. (a -> String) -> Array a -> String
  //
  auto showArrayImpl(const any& f, const any::array& xs) -> any;
}

#endif // Data_Show_FFI_HH
