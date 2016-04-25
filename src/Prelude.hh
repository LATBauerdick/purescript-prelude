///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Prelude.hh
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
#ifndef Prelude_FFI_HH
#define Prelude_FFI_HH

#include "PureScript/PureScript.hh"

namespace Prelude {
  using namespace PureScript;

  //- Functor --------------------------------------------------------------------

  auto arrayMap(const any& f, const any::array& as) -> any::array;

  //- Bind -----------------------------------------------------------------------

  auto arrayBind(const any::array& as, const any& f) -> any::array;

  //- Monoid ---------------------------------------------------------------------

  inline auto concatString(const any& s1, const any& s2) -> any {
    return s1 + s2;
  }

  auto concatArray(const any::array& as, const any::array& bs) -> any::array;

  //- Semiring -------------------------------------------------------------------

  inline auto intAdd(const long x, const long y) -> long {
    return x + y;
  }

  inline auto intMul(const long x, const long y) -> long {
    return x * y;
  }

  inline auto numAdd(const double x, const double y) -> double {
    return x + y;
  }

  inline auto numMul(const double x, const double y) -> double {
    return x * y;
  }

  //- ModuloSemiring -------------------------------------------------------------

  inline auto intDiv(const long x, const long y) -> long {
    return x / y;
  }

  inline auto intMod(const long x, const long y) -> long {
    return x % y;
  }

  inline auto numDiv(const double x, const double y) -> double {
    return x / y;
  }

  //- Ring -----------------------------------------------------------------------

  inline auto intSub(const long x, const long y) -> long {
    return x - y;
  }

  inline auto numSub(const double x, const double y) -> double {
    return x - y;
  }

  //- Eq -------------------------------------------------------------------------

  inline auto refEq(const any& ref1, const any& ref2) -> any {
    return ref1 == ref2;
  }

  inline auto refIneq(const any& ref1, const any& ref2) -> any {
    return ref1 != ref2;
  }

  auto eqArrayImpl(const any& f, const any::array& xs, const any::array& ys) -> bool;

  auto ordArrayImpl(const any& f, const any::array& xs, const any::array& ys) -> long;

  //- Ord ------------------------------------------------------------------------

  auto unsafeCompareImpl(const any& lt,
                          const any& eq,
                          const any& gt,
                          const any& x,
                          const any& y) -> any;

  //- Bounded --------------------------------------------------------------------

  extern const long topInt;
  extern const long bottomInt;

  const char topChar    = 0xFF; // TODO: unicode support
  const char bottomChar = 0x00;

  //- Lattice --------------------------------------------------------------------

  inline auto boolOr(const bool x, const bool y) -> bool {
    return x || y;
  }

  inline auto boolAnd(const bool x, const bool y) -> bool {
    return x && y;
  }

  //- ComplementedLattice --------------------------------------------------------

  inline auto boolNot(const any& x) -> any {
    return (not cast<bool>(x));
  }

  //- Show -----------------------------------------------------------------------

  inline auto showIntImpl(const any& x) -> any {
    return std::to_string((long)x);
  }

  inline auto showNumberImpl(const any& x) -> any {
    return std::to_string((double)x);
  }

  auto showCharImpl(const any&) -> any;

  auto showStringImpl(const any& s) -> any;

  auto showArrayImpl(const any& f, const any::array& xs) -> any;

}

#endif // Prelude_FFI_HH
