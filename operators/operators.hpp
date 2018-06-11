/**
 * @file operators/operators.hpp
 *
 * @brief A header file providing the API for the operators libarary
 * 
 * @details 
 */
#ifndef OPERATORS_HPP_INCLUDED_2011373981609832720
#define OPERATORS_HPP_INCLUDED_2011373981609832720 1

//
// ... Operators header files
//
#include <operators/inequality.hpp>
#include <operators/comparable.hpp>
#include <operators/ops.hpp>
#include <operators/arithmetic.hpp>
#include <operators/specfun.hpp>
#include <operators/specfunable.hpp>
#include <operators/compound_assignable.hpp>



namespace Operators
{

  //
  // ... Operator Derivation
  // 
  using Core::Inequality;
  using Core::Comparable;
  using Core::Arithmetic;
  using Core::Specfun;
  using Core::Specfunable;
  using Core::Compound_assignable;


  //
  // ... Operator proxies
  //

  using Core::Addition;
  using Core::Subtraction;
  using Core::Multiplication;
  using Core::Division;

  using Core::Plus;
  using Core::Minus;


  /** A proxy for the binary `+` operator */
  using Core::add;

  /** A proxy for the binary `-` operator */
  using Core::subtract;

  /** A proxy for the binary `*` operator */
  using Core::multiply;

  /** A proxy for the `/` operator */
  using Core::divide;

  /** A proxy for the `%` operator */
  using Core::modulo;

  /** A proxy for the unary `+` operator */
  using Core::plus;

  /** A proxy for the unary `-` operator */
  using Core::minus;

  /** A proxy for the `~` operator */
  using Core::bitwise_not;
  
  /** A proxy for the `<<` operator */
  using Core::left_shift ;

  /** A proxy for the `>>` operator */
  using Core::right_shift;
  
  /** A proxy for the `&` operator */
  using Core::bitwise_and;

  /** A proxy for the `|` operator */
  using Core::bitwise_or ;

  /** A proxy for the `^` operator */
  using Core::bitwise_xor;

  /** A proxy for the `,` operator */
  using Core::comma;

  /** A proxy for the `<` operator */
  using Core::less_than;

  /** A proxy for the `<=` operator */
  using Core::less_or_equal;

  /** A proxy for the `==` operator */
  using Core::equal;

  /** A proxy for the `!=` operator */
  using Core::not_equal;

  /** A proxy for the `>=` operator */
  using Core::greater_or_equal;

  /** A proxy for the `>` operator */
  using Core::greater_than;

  /** A proxy for the `!` operator */
  using Core::logical_not;

  /** A proxy for the `&&` operator */
  using Core::logical_and;

  /** A proxy for the `||` operator */
  using Core::logical_or;

  /** A proxy for the `++` prefix operator */
  using Core::increment;

  /** A proxy for the `++` suffix operator */
  using Core::post_increment;

  /** A proxy for the `--` pr
      efix operator */
  using Core::decrement;

  /** A proxy for the `--` suffix operator */
  using Core::post_decrement;

  /** A proxy for the `=` operator */
  using Core::assign;

  /** A proxy for the `+=` operator */
  using Core::add_assign;

  /** A proxy for the `-=` operator */
  using Core::subtract_assign;

  /** A proxy for the `*=` operator */
  using Core::multiply_assign;

  /** A proxy for the `/=` operator */
  using Core::divide_assign;

  /** A proxy for the `%=` operator */
  using Core::modulo_assign;

  /** A proxy for the `<<=` operator */
  using Core::left_shift_assign;

  /** A proxy for the `>>=` operator */
  using Core::right_shift_assign;

  /** A proxy for the `&=` operator */
  using Core::bitwise_and_assign;

  /** A proxy for the `|=` operator */
  using Core::bitwise_or_assign;

  /** A proxy for the `^=` operator */
  using Core::bitwise_xor_assign;

  /** A proxy for the `*` prefix operator */
  using Core::dereference;

  /** A proxy for the `&` prefix operator */
  using Core::address;



  //
  // ... Unary special function proxies
  //
  using Core::Cosine;
  using Core::Sine;
  using Core::Tangent;
  using Core::ArcCosine;
  using Core::ArcSine;
  using Core::ArcTangent;
  using Core::HyperbolicCosine;
  using Core::HyperbolicSine;
  using Core::HyperbolicTangent;
  using Core::AreaHyperbolicCosine;
  using Core::AreaHyperbolicSine;
  using Core::AreaHyperbolicTangent;
  using Core::ErrorFunction;
  using Core::ComplementaryErrorFunction;
  using Core::GammaFunction;
  using Core::LogGamma;
  using Core::Exponent;
  using Core::Logarithm;
  using Core::Logarithm10;
  using Core::SquareRoot;
  using Core::CubeRoot;
  using Core::Floor;
  using Core::Ceil;
  
  /** A proxy for the `cos` special function */
  using Core::cosine;

  /** A proxy for the `sin` special function */
  using Core::sine;

  /** A proxy for the `tan` special function */
  using Core::tangent;

  /** A proxy for the `acos` special function */
  using Core::arccosine;

  /** A proxy for the `asin` special function */
  using Core::arcsine;

  /** A proxy for the `atan` special function */
  using Core::arctangent;

  /** A proxy for the `cosh` special function */
  using Core::hyperbolic_cosine;

  /** A proxy for the `sinh` special function */
  using Core::hyperbolic_sine;

  /** A proxy for the `tanh` special function */
  using Core::hyperbolic_tangent;

  /** A proxy for the `acosh` special function */
  using Core::area_hyperbolic_cosine;

  /** A proxy for the `asinh` special function */
  using Core::area_hyperbolic_sine;

  /** A proxy for the `atanh` special function */
  using Core::area_hyperbolic_tangent;

  /** A proxy for the `erf` special function */
  using Core::error_function;

  /** A proxy for the `erfc` special function */
  using Core::complementary_error_function;

  /** A proxy for the `tgamma` special function */
  using Core::gamma_function;

  /** A proxy for the `lgamma` special function */
  using Core::log_gamma;

  /** A proxy for the `exp` special function */
  using Core::exponent;

  /** A proxy for the `log` special function */
  using Core::logarithm;

  /** A proxy for the `log10` special function */
  using Core::logarithm10;

  /** A proxy for the `sqrt` special function */
  using Core::square_root;

  /** A proxy for the `cbrt` special function */
  using Core::cube_root;

  /** A proxy for the `floor` special function */
  using Core::floor_function;

  /** A proxy for the `ceil` special function */
  using Core::ceil_function;
  


  
  //
  // ... Binary special functio proxies
  //

  using Core::Power;
  using Core::ArcTangent2;
  using Core::Hypotenuse;
  using Core::PositiveDifference;
  using Core::Minimum;
  using Core::Maximum;

  /** A proxy for the `pow` special function */
  using Core::power;

  /** A proxy for the `atan2` special function */
  using Core::arctangent2;

  /** A proxy for the `hypot` special function */
  using Core::hypotenuse;

  /** A proxy for the `fdim` special function */
  using Core::positive_difference;

  /** A proxy for the `fmin` special function */
  using Core::minimum;

  /** A proxy for the `fmax` special function */
  using Core::maximum;



  //
  // ... Ternary special functions
  //

  using Core::FusedMultiplyAdd;
  using Core::fused_multiply_add;







  
  

  
  
} // end of namespace Operators

#endif // !defined OPERATORS_HPP_INCLUDED_2011373981609832720
