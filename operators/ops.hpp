#ifndef OPS_HPP_INCLUDED_1958426945611988765
#define OPS_HPP_INCLUDED_1958426945611988765 1

//
// ... Operators header files
//
#include <operators/import.hpp>




#include <operators/macros.hpp>


namespace Operators
{
  namespace Core
  {

#define X( op, name, t, ... )						\
    constexpr struct t : Static_callable<t>{                            \
      template<typename T, typename U>                                  \
      static constexpr auto                                             \
      call(T&& x, U&& y){                                               \
        return forward<T>(x) op forward<U>(y);                          \
      }                                                                 \
    }name{};                                                            \
                                                                        \
    ostream&								\
    operator <<( ostream& os, t const& ){                               \
      os << OPERATORS_QUOTE( op );					\
      return os;							\
    }									\
                                                                        \
    ostream&								\
    operator <<( ostream& os, Type<t> ){                                \
      os << "Operators::Core::" << OPERATORS_QUOTE( t );		\
      return os;							\
    }									\
    OPERATORS_FORCE_SEMICOLON()
#include "binary_operator_list.def"
#undef X




#define X( op, name, t, ... )						\
    constexpr struct t                                                  \
    {                                                                   \
      template<typename T, typename U>                                  \
      T&                                                                \
      operator()(T& x, U&& y) const                                     \
      {                                                                 \
        return x op forward<U>(y);                                      \
      }                                                                 \
    } name{};                                                           \
                                                                        \
    template< typename Stream >						\
    Stream&								\
    operator <<( Stream& os, t ){					\
      os << OPERATORS_QUOTE( op );					\
      return os;							\
    }									\
    template< typename Stream >						\
    Stream&								\
    operator <<( Stream& os, Type<t> ){					\
      os << "Operators::Core::" << OPERATORS_QUOTE( t );		\
      return os;							\
    }									\
    OPERATORS_FORCE_SEMICOLON()

#include "compound_assignment_operator_list.def"
#undef X

    constexpr
    struct Comma :  Static_callable<Comma>
    {
      template<typename T, typename U>
      static constexpr auto
      call(T&& x, U&& y){
        return (forward<T>(x), forward<U>(y));
      }
    } comma{};

    template<typename Stream>
    Stream&
    operator<<(Stream& os, Comma const&){
      os << ",";
      return os;
    }

    template<typename Stream>
    Stream&
    operator<<(Stream& os, Type<Comma> const&){
      os << "Operators::Core::Comma";
      return os;
    }

    ostream&
    operator<<(ostream& os, Comma const&){
      os << ",";
      return os;
    }

    ostream&
    operator<<(ostream& os, Type<Comma> const&){
      os << "Operators::Core::Comma";
      return os;
    }

#define X( op, name, t, ... )						\
    constexpr                                                           \
    struct t : Static_callable<t>                                       \
    {                                                                   \
      template<typename U>                                              \
      constexpr auto                                                    \
      call(U&& x)                                                       \
      {                                                                 \
        return op forward<U>(x);                                        \
      }                                                                 \
    } name{};                                                           \
                                                                        \
    template<typename Stream>                                           \
    Stream&								\
    operator <<( Stream& os, t ){					\
      os << OPERATORS_QUOTE( op );					\
      return os;							\
    }                                                                   \
                                                                        \
    template< typename Stream >                                         \
    Stream&								\
    operator <<( Stream& os, Type<t> ){                                 \
      os << "Operators::Core::" << OPERATORS_QUOTE( t );                \
      return os;							\
    }									\
    OPERATORS_FORCE_SEMICOLON()
#include "unary_operator_list.def"
#undef X




    constexpr auto increment = []( auto&& x ) -> decltype( ++x ){ return ++x; };
    using Increment = decay_t<decltype(increment)>;

    template< typename Stream >
    Stream&
    operator <<( Stream& os, Increment ){
      os << "++";
      return os;
    }

    template< typename Stream >
    Stream&
    operator <<( Stream& os, Type<Increment> ){
      os << "Operators::Core::Increment";
      return os;
    }

    constexpr auto decrement = []( auto&& x ) -> decltype( --x ){ return --x; };
    using Decrement = decay_t<decltype(decrement)>;

    template< typename Stream >
    Stream&
    operator <<( Stream& os, Decrement ){
      os << "--";
      return os;
    }

    template< typename Stream >
    Stream&
    operator <<( Stream& os, Type<Decrement> ){
      os << "Operators::Coree::Decrement";
      return os;
    }






    constexpr auto post_increment = []( auto&& x ){ return x++; };
    using PostIncrement = decay_t<decltype(post_increment)>;

    template< typename Stream >
    Stream&
    operator <<( Stream& os, PostIncrement ){
      os << "<>++";
      return os;
    }

    template< typename Stream >
    Stream&
    operator <<( Stream& os, Type<PostIncrement> ){
      os << "Operators::Core::PostIncrement";
      return os;
    }





    constexpr auto post_decrement = []( auto&& x ){ return x--; };
    using PostDecrement = decay_t<decltype(post_decrement)>;

    template< typename Stream >
    Stream&
    operator <<( Stream& os, PostDecrement ){
      os << "<>--";
      return os;
    }

    template< typename Stream >
    Stream&
    operator <<( Stream& os, Type<PostDecrement> ){
      os << "Operators::Core::PostDecrement";
      return os;
    }




    constexpr auto dereference = []( auto&& x ) -> decltype( *x ){ return *x; };
    using Dereference = decay_t<decltype(dereference)>;
    template< typename Stream >
    Stream&
    operator<<( Stream& os, Dereference ){
      os << "*<>";
      return os;
    }

    template< typename Stream >
    Stream&
    operator <<( Stream& os, Type<Dereference> ){
      os <<  "Operators::Core::Dereference";
      return os;
    }


    constexpr auto address = []( auto&& x ){ return &x; };


    using Address = decay_t<decltype(address)>;


    template< typename Stream >
    Stream&
    operator <<( Stream& os, Address ){
      os << "*_";
      return os;
    }

    template< typename Stream >
    Stream&
    operator <<( Stream& os, Type<Address> ){
      os << "Operators::Core::Address";
    }




  } // end of namespace Core
} // end of namespace Operators



#endif // !defined OPS_HPP_INCLUDED_1958426945611988765
