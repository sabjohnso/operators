//
// ... Operators header files
//
#include <operators/operators.hpp>

//
// ... Testing header files
//
#include <operators_testing/test_macros.hpp>


/** Test the comparable base class */
struct Comparable_test
{
  class Value : public Operators::Comparable<Value>{
  public:
    constexpr
    Value( int input ) : value( input ){}
  private:
    int value;

    friend constexpr bool
    operator <( const Value& x, const Value& y ){
      return x.value < y.value;
    }
  }; // end of class value


  Comparable_test() : accum( 0 ) {
    
    OPERATORS_STATIC_TEST( Value( 1 ) < Value( 2 ));
    OPERATORS_STATIC_TEST( Value( 1 ) <= Value( 2 ));
    OPERATORS_STATIC_TEST( !( Value( 1 ) == Value( 2 )));
    OPERATORS_STATIC_TEST( Value( 1 ) != Value( 2 ));
    OPERATORS_STATIC_TEST( !( Value( 1 ) >= Value( 2 )));
    OPERATORS_STATIC_TEST( !( Value( 1 ) > Value( 2 )));

    OPERATORS_STATIC_TEST( !( Value( 3 ) < Value( 3 )));
    OPERATORS_STATIC_TEST( Value( 3 ) <= Value( 3 ));
    OPERATORS_STATIC_TEST( Value( 3 ) == Value( 3 ));
    OPERATORS_STATIC_TEST( !( Value( 3 ) != Value( 3 )));
    OPERATORS_STATIC_TEST( Value( 3 ) >= Value( 3 ));
    OPERATORS_STATIC_TEST( !( Value( 3 ) > Value( 3 )));

    OPERATORS_STATIC_TEST( !( Value( 5 ) < Value( 4 )));
    OPERATORS_STATIC_TEST( !( Value( 5 ) <= Value( 4 )));
    OPERATORS_STATIC_TEST( !( Value( 5 ) == Value( 4 )));
    OPERATORS_STATIC_TEST( Value( 5 ) != Value( 4 ));
    OPERATORS_STATIC_TEST( Value( 5 ) >= Value( 4 ));
    OPERATORS_STATIC_TEST( Value( 5 ) > Value( 4 ));

    OPERATORS_TEST( accum, Value( 1 ) < Value( 2 ));
    OPERATORS_TEST( accum, Value( 1 ) <= Value( 2 ));
    OPERATORS_TEST( accum, !( Value( 1 ) == Value( 2 )));
    OPERATORS_TEST( accum, Value( 1 ) != Value( 2 ));
    OPERATORS_TEST( accum, !( Value( 1 ) >= Value( 2 )));
    OPERATORS_TEST( accum, !( Value( 1 ) > Value( 2 )));

    OPERATORS_TEST( accum, !( Value( 3 ) < Value( 3 )));
    OPERATORS_TEST( accum, Value( 3 ) <= Value( 3 ));
    OPERATORS_TEST( accum, Value( 3 ) == Value( 3 ));
    OPERATORS_TEST( accum, !( Value( 3 ) != Value( 3 )));
    OPERATORS_TEST( accum, Value( 3 ) >= Value( 3 ));
    OPERATORS_TEST( accum, !( Value( 3 ) > Value( 3 )));

    OPERATORS_TEST( accum, !( Value( 5 ) < Value( 4 )));
    OPERATORS_TEST( accum, !( Value( 5 ) <= Value( 4 )));
    OPERATORS_TEST( accum, !( Value( 5 ) == Value( 4 )));
    OPERATORS_TEST( accum, Value( 5 ) != Value( 4 ));
    OPERATORS_TEST( accum, Value( 5 ) >= Value( 4 ));
    OPERATORS_TEST( accum, Value( 5 ) > Value( 4 ));

  }
  operator int() const { return accum; }
  int accum;
}; // end of struct Comparable_test

int
main( int, char** )
{
  int accum = 0;
  accum += Comparable_test();
  return accum;
}
