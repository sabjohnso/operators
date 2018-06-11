#ifndef SPECFUN_HPP_INCLUDED_45684590574513840
#define SPECFUN_HPP_INCLUDED_45684590574513840 1

//
// ... Standard header files
//
#include <cmath>

//
// ... Operators header files
//
#include <operators/import.hpp>



#define OPERATORS_FORCE_SEMICOLON() static_assert(true)
    
#define OPERATORS_QUOTE_AUX( ... ) #__VA_ARGS__
#define OPERATORS_QUOTE( ... ) OPERATORS_QUOTE_AUX( __VA_ARGS__ )


namespace Operators
{
  namespace Core
  {

    constexpr auto fused_multiply_add =
      []( auto && x, auto && y, auto && z ){
	using std::fma;
	return fma( x, y, z );
      };
    using FusedMultiplyAdd =
      decay_t<decltype( fused_multiply_add )>;

    template< typename Stream >
    Stream&
    operator <<( Stream& os, FusedMultiplyAdd ){
      os << "fma";
      return os;
    }

    
      

#define X( fun, proxy, type, ... )				\
    constexpr auto proxy =					\
      []( auto&& x ){ using std::fun; return fun( x ); };	\
    using type = decay_t<decltype(proxy)>;			\
    template< typename Stream >					\
    Stream&							\
    operator <<( Stream& os, type ){				\
      os << OPERATORS_QUOTE( fun );				\
      return os;						\
    }								\
    OPERATORS_FORCE_SEMICOLON()

    
#include "unary_specfun_list.def"
#undef X

    

#define X( fun, proxy, type, ... )		\
    constexpr auto proxy =			\
	    []( auto&& x, auto&& y ){		\
	      using std::fun;			\
	      return fun( x  ); };		\
    using type = decay_t<decltype(proxy)>;	\
    template< typename Stream >			\
    Stream&					\
    operator <<( Stream& os, type ){		\
      os << OPERATORS_QUOTE( fun );		\
      return os;				\
    }						\
    OPERATORS_FORCE_SEMICOLON()

#include "binary_specfun_list.def"
#undef X
    
    
    /** 
     * @brief Derive secial functions
     */
    template< typename T >
    class Specfun : public CRTP<Specfun,T>
    {


#define X( fun, proxy, ... )						\
      friend constexpr auto						\
      fun( const Specfun& x ){						\
	return apply_unary( proxy, x );					\
      }									\
      OPERATORS_FORCE_SEMICOLON()
#include "unary_specfun_list.def"
#undef X


      
#define X( fun, proxy, ... )			\
      template< typename U >			\
      friend constexpr auto			\
      fun( const Specfun& x, U&& y ){		\
	return apply_binary( proxy, x );	\
      }						\
      OPERATORS_FORCE_SEMICOLON()
#include "binary_specfun_list.def"
#undef X

      template< typename U, typename V >
      friend constexpr auto
      fma( const Specfun& x, U&& y, V&& z ){
	return apply_ternary( fused_multiply_add, x, forward<U>( y ), forward<V>( z ));
      }
     
		
      
    }; // end of class Specfun




    
     
  } // end of namespace Core
} // end of namespace Operators

#undef OPERATORS_QUOTE
#undef OPERATORS_QUOTE_AUX
#undef OPERATORS_FORCE_SEMICOLON

#endif // !defined SPECFUN_HPP_INCLUDED_45684590574513840
