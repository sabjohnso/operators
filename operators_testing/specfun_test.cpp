//
// ... Standard header files
//
#include <cmath>

//
// ... Operators header files
//
#include <operators/operators.hpp>


//
// ... Testing header files
//
#include <operators_testing/test_macros.hpp>

using namespace Operators;


class Value
  : public Operators::Comparable<Value>
  , public Operators::Arithmetic<Value>
  , public Operators::Specfun<Value>
{
  double value;
public:
  constexpr
  Value( double input ) : value( input ){}

  friend constexpr bool
  operator <( Value x, Value y ){ return x.value < y.value; }

  template< typename F >
  friend constexpr Value
  apply_unary( F&& f, Value x ){ return Value( f( x.value )); }

  template< typename F >
  friend constexpr Value
  apply_binary( F&& f, Value x, Value y ){ return Value( f( x.value, y.value )); }

}; // end of class Value

/** 
 * @brief Test the derivation of special functions
 */
struct Specfun_test
{
  Specfun_test() : accum( 0 ) {
    using namespace Operators::Core;
    OPERATORS_STATIC_TEST( cos( Value( 0.0 )) == Value( cos( 0.0 )));
    OPERATORS_STATIC_TEST( sin( Value( 0.0 )) == Value( sin( 0.0 )));
    OPERATORS_STATIC_TEST( sqrt( Value( 4.0 )) == Value( sqrt( 4 )));

    OPERATORS_TEST( accum, cos( Value( 0.0 )) == Value( cos( 0.0 )));
    OPERATORS_TEST( accum, sin( Value( 0.0 )) == Value( sin( 0.0 )));
    OPERATORS_TEST( accum, sqrt( Value( 4.0 )) == Value( sqrt( 4 )));
    
  }
  operator int() const { return accum; }
  int accum;
}; // end of struct Specfun_test


int
main( int, char** )
{
  int accum = 0;
  accum += Specfun_test();
  return accum;
}
