#ifndef INEQUALITY_HPP_INCLUDED_1500701587200122063
#define INEQUALITY_HPP_INCLUDED_1500701587200122063 1

//
// ... Operators header files
//
#include <operators/import.hpp>

namespace Operators
{
  namespace Core
  {

    /**
     * @details Derive the inequality operator from the equality
     * operator.
     */
    template<typename T>
    class Inequality : public CRTP<Inequality, T>
    {
    public:
      template<typename U>
      friend constexpr bool
      operator!=(const Inequality<T>& x, const U& y)
      {
        return !(x == y);
      }
    }; // end of class Inequality

  } // end of namespace Core
} // end of namespace Operators

#endif // !defined INEQUALITY_HPP_INCLUDED_1500701587200122063
