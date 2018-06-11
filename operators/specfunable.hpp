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
      // ... Unary special functions as friends
      //
#define X( fun, proxy, ... )			\
      friend constexpr auto			\
      fun( const Specfunable& x ){		\
	return apply_unary( proxy, x );		\
      }						\
      OPERATORS_FORCE_SEMICOLON()
#include "unary_specfun_list.def"
#undef X

      //
      // ... Binary special functions as friends
      //
      // Dispatched with the first argument
#define X( fun, proxy, ... )					\
      template< typename U >					\
      friend constexpr auto					\
      fun( const Specfunable& x, const U& y ){			\
	return apply_binary( proxy, x, y );			\
      }								\
      OPERATORS_FORCE_SEMICOLON()
#include "binary_specfun_list.def"
#undef X


    // Dispatched with the second argument
#define X( fun, proxy, ... )					\
      template< typename U >					\
      friend constexpr auto					\
      fun( const U& x, const Specfunable& y ){			\
	return apply_binary( proxy, x, y );			\
      }								\
      OPERATORS_FORCE_SEMICOLON()
#include "binary_specfun_list.def"
#undef X

    // Dispatched with both arguments to remove
    // ambiguity avover the previous overloads
#define X( fun, proxy, ... )					\
      friend constexpr auto					\
      fun( const Specfunable& x, const Specfunable& y ){	\
	return apply_binary( proxy, x, y );			\
      }								\
      OPERATORS_FORCE_SEMICOLON()
#include "binary_specfun_list.def"
#undef X

    }; // end of class Specfunable
    
    
  } // end of namespace Coree
} // end of namespace Operators


#include <operators/clear_macros.hpp>
#endif // !defined SPECFUNABLE_HPP_INCLUDED_1330912561370692046
