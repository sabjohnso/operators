#ifndef ARITHMETIC_HPP_INCLUDED_324502797521039265
#define ARITHMETIC_HPP_INCLUDED_324502797521039265 1

//
// ... Operators header files
//
#include <operators/import.hpp>
#include <operators/ops.hpp>

namespace Operators
{
  namespace Core
  {

    template< typename T >
    class Arithmetic : public CRTP<Arithmetic,T>
    {
    public:
      
      template< typename U >
      constexpr auto
      operator +( U&& y ) const & {
	return apply_binary( add, static_cast<const T&>( *this ), forward<U>( y ));
      }

      template< typename U >
      constexpr auto
      operator -( U&& y ) const & {
	return apply_binary( subtract, static_cast<const T&>( *this ), forward<U>( y ));
      }

      template< typename U >
      constexpr auto
      operator *( U&& y ) const & {
	return apply_binary( multiply, static_cast<const T&>( *this ), forward<U>( y ));
      }

      template< typename U >
      constexpr auto
      operator /( U&& y ) const & {
	return apply_binary( divide, static_cast<const T&>( *this ), forward<U>( y ));
      }

    }; // end of class Arithmetic



    

  } // end of namespace Core
} // end of namespace Operators


#endif // !defined ARITHMETIC_HPP_INCLUDED_324502797521039265
