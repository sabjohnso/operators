#ifndef SPECFUNABLE_HPP_INCLUDED_1330912561370692046
#define SPECFUNABLE_HPP_INCLUDED_1330912561370692046 1

//
// ... Operators header files
//
#include <operators/specfun.hpp>


#include <operators/macros.hpp>
namespace Operators
{
  namespace Core
  {

    /** 
     * @brief Derivation of special functions
     *
     * @details This CRTP base class provides derivation
     * of the special functions to its subtypes through the
     * overloads to the functions apply_unary, and apply_binary.
     */
    template< typename T >
    class Specfunable : public CRTP<Specfunable,T>
    {
      //
      // ... Unary special functions 
      //
#define X( fun, proxy, ... )			\
      friend constexpr auto			\
      fun( const Specfunable& x ){		\
	return apply_unary( proxy, x );		\
      }						\
      friend constexpr auto			\
      fun( Specfunable&& x ){			\
	return apply_unary( proxy, move( x ));	\
      }						\
      OPERATORS_FORCE_SEMICOLON()
#include "unary_specfun_list.def"
#undef X

      //
      // ... Binary special functions 
      //


#define X( fun, proxy, ... )						\
      friend constexpr auto						\
      fun( const Specfunable& x, const Specfunable& y ){		\
	return apply_binary( proxy, x, y );				\
      }									\
									\
      friend constexpr auto						\
      fun( Specfunable&& x, const Specfunable& y ){			\
	return apply_binary( proxy, move( x ), y );			\
      }									\
									\
      friend constexpr auto						\
      fun( const Specfunable& x, Specfunable&& y ){			\
	return apply_binary( proxy, x, move( y ));			\
      }									\
									\
      friend constexpr auto						\
      fun( Specfunable&& x, Specfunable&& y ){				\
	return apply_binary( proxy, move( x ), move( y ));		\
      }									\
									\
      template< typename U,						\
		typename Test = typename enable_if<! is_convertible<U,Arithmetic<T>>::value >::type > \
      friend constexpr auto						\
      fun( const Specfunable& x, U&& y ){				\
	return apply_binary( proxy, x, forward<U>( y ));		\
      }									\
									\
      template< typename U,						\
		typename Test =						\
		typename enable_if<! is_convertible<U,Arithmetic<T>>::value >::type > \
      friend constexpr auto						\
      fun( Specfunable&& x, U&& y ){					\
	return apply_binary( proxy, move( x ), forward<U>( y ));	\
      }									\
									\
      template< typename U,						\
		typename Test =						\
		typename enable_if<! is_convertible<U,Arithmetic<T>>::value >::type > \
      friend constexpr auto						\
      fun( U&& x, const Specfunable& y ){				\
	return apply_binary( proxy, forward<U>( x ), y );		\
      }									\
									\
      template< typename U,						\
		typename Test =						\
		typename enable_if<! is_convertible<U,Arithmetic<T>>::value >::type > \
      friend constexpr auto						\
      fun( U&& x, Specfunable&& y){					\
	return apply_binary( proxy, forward<U>( x ), move( y ));	\
      }									\
      OPERATORS_FORCE_SEMICOLON()
      
#include "binary_specfun_list.def"
#undef X



    }; // end of class Specfunable
    
    
  } // end of namespace Coree
} // end of namespace Operators


#include <operators/clear_macros.hpp>
#endif // !defined SPECFUNABLE_HPP_INCLUDED_1330912561370692046
