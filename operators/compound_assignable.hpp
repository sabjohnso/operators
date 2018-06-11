#ifndef COMPOUND_ASSIGNABLE_HPP_INCLUDED_979834572872301386
#define COMPOUND_ASSIGNABLE_HPP_INCLUDED_979834572872301386 1

//
// ... Operators header files
//
#include <operators/import.hpp>


namespace Operators
{
  namespace Core
  {


    template< typename T >
    class Compound_assignable : public CRTP<Compound_assignable,T>
    {

      template< typename U >
      decltype(auto)
      operator +=( U&& y ){
	return static_cast<T&>( *this ) = *this + forward<U>( y );
      }

      template< typename U >
      decltype(auto)
      operator -=( U&& y ){
	return static_cast<T&>( *this ) = *this - forward<U>( y );
      }

      template< typename U >
      decltype(auto)
      operator *=( U&& y ){
	return static_cast<T&>( *this ) = *this * forward<U>( y );
      }


      template< typename U >
      decltype(auto)
      operator /=( U&& y ){
	return static_cast<T&>( *this ) = *this / forward<U>( y );
      }

      template< typename U >
      decltype(auto)
      operator %=( U&& y ){
	return static_cast<T&>( *this ) = *this % forward<U>( y );
      }


      template< typename U >
      decltype(auto)
      operator &=( U&& y ){
	return static_cast<T&>( *this ) = *this & forward<U>( y );
      }


      template< typename U >
      decltype(auto)
      operator |=( U&& y ){
	return static_cast<T&>( *this ) = *this | forward<U>( y );
      }

      template< typename U >
      decltype(auto)
      operator <<=( U&& y ){
	return static_cast<T&>( *this ) = *this << forward<U>( y );
      }

      template< typename U >
      decltype(auto)
      operator >>=( U&& y ){
	return static_cast<T&>( *this ) = *this >> forward<U>( y );
      }

    }; // end of class Compound_assignable


    
  } // end of namespace Core
} // end of namespace Operators

#endif // !defined COMPOUND_ASSIGNABLE_HPP_INCLUDED_979834572872301386
