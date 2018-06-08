#ifndef TEST_MACROS_HPP_INCLUDED_401908780185186673
#define TEST_MACROS_HPP_INCLUDED_401908780185186673 1

//
// ... Standard header files
//
#include <iostream>



#define OPERATORS_TEST_PRINT_AUX( ... ) #__VA_ARGS__
#define OPERATORS_TEST_PRINT( ... ) OPERATORS_TEST_PRINT_AUX( __VA_ARGS__ )

#define OPERATORS_FAIL( accum, ... )				\
  {								\
    ++accum;							\
    std::cout << '\n' << __FILE__ << ':' << __LINE__ << ":0"	\
	      << "OPERATORS test failure\n"			\
	      << OPERATORS_TEST_PRINT( __VA_ARGS__ ) << '\n'	\
	      << "did not evaluate to true.\n\n";		\
  }
  

#define OPERATORS_PASS( ... )			\
  {						\
    std::cout << '.';				\
  }
  
/** The first argument to a test is a variable 
    that is accumulating the count of test failures,
    and the rest are an expression that evaluates 
    to true to pass or false to fail. Upon failure,
    a message is printed with the location of the
    failure.  Upon success, a '.' is printed to
    indicate the successfull execution. */
#define OPERATORS_TEST( accum , ... )		\
  if(!(  __VA_ARGS__ )){			\
    OPERATORS_FAIL( accum, __VA_ARGS__ );	\
  }						\
  else{						\
    OPERATORS_PASS( __VA_ARGS___ );		\
  }


/** Static tests use static_assert and are really only executed
    at compile time.  At runtime,  a '+' is printed to indicate
    the static test passed, but it was not actually executed at
    runtime. 
*/
#define OPERATORS_STATIC_TEST( ... )					\
  {									\
    static_assert( __VA_ARGS__, "OPERATORS static test failure" );	\
    std::cout << '+';							\
  }

/**  Don't run the test, just print a ? to idicated that
     the test is pending.
*/
#define OPERATORS_PENDING_TEST( ... )		\
  {						\
    std::cout << '?';				\
  }

#endif // !defined TEST_MACROS_HPP_INCLUDED_401908780185186673
