#ifndef OPS_HPP_INCLUDED_1958426945611988765
#define OPS_HPP_INCLUDED_1958426945611988765 1

namespace Operators
{
  namespace Core
  {

    constexpr auto add = []( auto&& x, auto&& y ){ return x+y; };
    constexpr auto subtract = []( auto&& x, auto&& y ){ return x-y; };
    constexpr auto multiply = []( auto&& x, auto&& y ){ return x*y; };
    constexpr auto divide = []( auto&& x, auto&& y ){ return x/y; };
    constexpr auto modulus = []( auto&& x, auto&& y ){ return x%y; };
    
    constexpr auto plus = []( auto&& x ){ return +x; };
    constexpr auto minus = []( auto&& x ){ return -x; };
    
    constexpr auto bitwise_not = []( auto&& x ){ return ~x; };
    constexpr auto left_shift  = []( auto&& x, auto&& y ){ return x << y; };
    constexpr auto right_shift = []( auto&& x, auto&& y ){ return x >> y; };
    constexpr auto bitwise_and = []( auto&& x, auto&& y ){ return x & y; };
    constexpr auto bitwise_or  = []( auto&& x, auto&& y ){ return x | y; };
    constexpr auto bitwise_xor = []( auto&& x, auto&& y ){ return x ^ y; };

    constexpr auto comma = []( auto&& x, auto&& y ){ return (x,y); };

    constexpr auto less_than = []( auto&& x, auto&& y ){ return x < y; };
    constexpr auto less_or_equal = []( auto&& x, auto&& y ){ return x <= y; };
    constexpr auto equal = []( auto&& x, auto&& y ){ return x == y; };
    constexpr auto not_equal = []( auto&& x, auto&& y ){ return x != y; };
    constexpr auto greater_or_equal = []( auto&& x, auto&& y ){ return x >= y; };
    constexpr auto greater_than = []( auto&& x, auto&& y ){ return x > y; };

    constexpr auto logical_not = []( auto&& x ){ return ! x; };
    constexpr auto logical_and = []( auto&& x, auto&& y ){ return x && y; };
    constexpr auto logical_or = []( auto&& x, auto&& y ){ return x || y; };

    constexpr auto increment = []( auto&& x ) -> decltype( ++x ){ return ++x; };
    constexpr auto post_increment = []( auto&& x ){ return x++; };
    constexpr auto decrement = []( auto&& x ) -> decltype( --x ){ return --x; };
    constexpr auto post_decrement = []( auto&& x ){ return x--; };

    constexpr auto assign = []( auto&& x, auto&& y ) -> decltype( x  = y ){ return x = y; };
    constexpr auto add_to = []( auto&& x, auto&& y ) -> decltype( x += y ){ return x += y; };
    constexpr auto subtract_from = []( auto&& x, auto&& y ) -> decltype( x -= y){ return x -= y; };
    constexpr auto multiply_by = []( auto&& x, auto&& y ) -> decltype( x *= y ){ return x *= y; };
    constexpr auto divide_by = []( auto&& x, auto&& y ) -> decltype( x /= y ){ return x /= y; };
    constexpr auto modulo_by = []( auto&& x, auto&& y ) -> decltype( x %= y ){ return x %= y; };

    
    constexpr auto dereference = []( auto&& x ) -> decltype( *x ){ return *x; };
    constexpr auto address = []( auto&& x ){ return &x; };

    

  } // end of namespace Core
} // end of namespace Operators


#endif // !defined OPS_HPP_INCLUDED_1958426945611988765
