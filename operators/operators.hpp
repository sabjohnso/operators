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



namespace Operators
{

  //
  // ... Operator Derivation
  // 
  using Core::Inequality;
  using Core::Comparable;
  using Core::Arithmetic;
  using Core::Specfun;


  //
  // ... Operator proxies
  //
  
  using Core::add;
  using Core::subtract;
  using Core::multiply;
  using Core::divide; 
  using Core::modulus;
  using Core::plus;
  using Core::minus;
  using Core::bitwise_not;
  using Core::left_shift ;
  using Core::right_shift;
  using Core::bitwise_and;
  using Core::bitwise_or ;
  using Core::bitwise_xor;
  using Core::comma;
  using Core::less_than;
  using Core::less_or_equal;
  using Core::equal;
  using Core::not_equal;
  using Core::greater_or_equal;
  using Core::greater_than;
  using Core::logical_not;
  using Core::logical_and;
  using Core::logical_or;
  using Core::increment;
  using Core::post_increment;
  using Core::decrement;
  using Core::post_decrement;
  using Core::assign;
  using Core::add_to;
  using Core::subtract_from;
  using Core::multiply_by;
  using Core::divide_by;
  using Core::modulo_by;
  using Core::dereference;
  using Core::address;






  




  //
  // ... Special function proxies
  //
  
} // end of namespace Operators

#endif // !defined OPERATORS_HPP_INCLUDED_2011373981609832720
