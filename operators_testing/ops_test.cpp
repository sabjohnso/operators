//
// ... Operators header files
//
#include <operators/ops.hpp>

//
// ... Testing header files
//
#include <operators_testing/test_macros.hpp>

using namespace Operators::Core;

/**
 * @brief Test the assignment and compound
 * assignment operators.
*/
struct Assignment_test
{
  Assignment_test() : accum( 0 ) {
    assign_test();
  }

  void
  assign_test(){
    auto x = 3;
    auto y = 4;
    auto z =  assign( x, y );t
    OPERATORS_TEST( accum, x == 4);
    OPERATORS_TEST( accum, y == 4);
    OPERATORS_TEST( accum, z == 4);
  }
  void increment_test(){
    auto x = 3;
    auto y = increment( x );
    auto z = post_increment( x );
    OPERATORS_TEST( accum, x == 5 );
    OPERATORS_TEST( accum, y == 4 );
    OPERATORS_TEST( accum, z == 4 );
  }
  void decrement_test(){
    auto x = 3;
    auto y = decrement( x );
    auto z = post_decrement( x );
    OPERATORS_TEST( accum, x == 1 );
    OPERATORS_TEST( accum, y == 2 );
    OPERATORS_TEST( accum, z == 2 );
  }

  void add_to_test(){
    auto x = 3;
    auto y = 4;
    auto& z = add_assign( x, y );
    OPERATORS_TEST( accum, x == 7 );
    OPERATORS_TEST( accum, y == 4 );
    OPERATORS_TEST( accum, z == 7 );
  }
  void subtract_from_test(){}
  void multiply_by_test(){}
  void divide_by_test(){}
  void modulo_by_test(){}


  operator int() const { return accum; }
  int accum;
}; // end of struct Assignment_test



int
main( int, char** )
{
  int accum = 0;
  accum += Assignment_test();
  return accum;
}
