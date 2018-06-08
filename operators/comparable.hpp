#ifndef COMPARABLE_HPP_INCLUDED_1841024632722627567
#define COMPARABLE_HPP_INCLUDED_1841024632722627567 1

//
// ... Operators header files
//
#include <operators/import.hpp>



namespace Operators
{
  namespace Core
  {

    /**
     * @brief Derive binary comparison operators
     * 
     * @details This class is intended for derivation from the less-than operator, 
     * the remaining binary comparison operators.
     */
    template< typename T >
    class Comparable : public Inequality<T>
    {
      template< typename U>
      friend constexpr bool
      operator >( const Comparable& x, const U& y ){
	return y < x;
      }

      template< typename U >
      friend constexpr bool
      operator >=( const Comparable& x,  const U& y ){
	return !( x < y);
      }

      template< typename U >
      friend constexpr bool
      operator <=( const Comparable& x, const U& y ){
	return !( y < x );
      }

      template< typename U >
      friend constexpr bool
      operator ==( const Comparable& x, const U& y ){
	return !(( x < y) || (y < x));
      }
      
    };
    
  } // end of namespace Core
} // end of namespace Operators

#endif // !defined COMPARABLE_HPP_INCLUDED_1841024632722627567
