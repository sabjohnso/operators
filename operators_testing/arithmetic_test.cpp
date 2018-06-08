
//
// ... Operators header files
//
#include <operators/operators.hpp>

//
// ... Testing header files
//
#include <operators_testing/test_macros.hpp>

class Value : public Operators::Arithmetic<Value> {

  int value;
  
public:
  
  constexpr
  Value( int input ) : value( input ){}

  template< typename F >
  friend constexpr auto
  apply_binary( F&& f, Value x, Value y ){
    return Value( f( x.value, y.value ));
  }

  template< typename F >
  friend constexpr auto
  apply_unary( F&& f, Value x ){
    return Value( f( x.value ));
  }

  friend constexpr bool
  operator ==( Value x, Value y ){
    return x.value == y.value;
  }
  
  
}; // end of class Value


/**  
 * @brief test derivation of arithmetic operators
 */
struct Arithmetic_test
{

  Arithmetic_test() : accum( 0 ) {
    OPERATORS_STATIC_TEST( Value( 3 ) + Value( 4 ) == Value( 7 ));
  }
  operator int() const { return accum; }
  int accum;
}; // end of struct Arithmetic_test




int
main( int, char** )
{
  int accum = 0;
  accum += Arithmetic_test();
  return accum;
}
