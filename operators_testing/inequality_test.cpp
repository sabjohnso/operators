//
// ... Operators header files
//
#include <operators/inequality.hpp>
#include <operators/operators.hpp>

//
// ... Testing header files
//
#include <operators_testing/test_macros.hpp>

//
// ... Other header files
//
#include <type_utility/type_utility.hpp> // -> Type1


/** 
 * @brief Test derivation of the inequality operator 
 */
struct Inequality_test
{

  class Value : public Operators::Core::Inequality<Value> {
  public:
    
    constexpr
    Value( char input ) : value( input ){};
    
    friend constexpr bool
    operator ==( const Value& x, const Value& y ){ return x.value == y.value; }
    
  private:
    char value;
  };// end of class Value
  
  Inequality_test() : accum( 0 ) {

    OPERATORS_STATIC_TEST( Value( 'x' ) == Value( 'x' ));
    OPERATORS_STATIC_TEST( Value( 'x' ) != Value( 'y' ));
    OPERATORS_STATIC_TEST( !( Value( 'x' ) != Value( 'x' )));

    OPERATORS_TEST( accum, Value( 'x' ) == Value( 'x' ));
    OPERATORS_TEST( accum, Value( 'x' ) != Value( 'y' ));
    OPERATORS_TEST( accum, !( Value( 'x' ) != Value( 'x' )));
    
  }
  operator int() const { return accum; }
  int accum;

}; // end of struct Inequality_test


int
main( int, char** )
{
  int accum = 0;
  accum += Inequality_test();
  return accum;
}
