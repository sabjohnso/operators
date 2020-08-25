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

    template<typename T>
    class Arithmetic : public CRTP<Arithmetic, T>
    {}; // end of class Arithmetic

    //
    // ... Addition
    //

    template<typename T>
    constexpr auto
    operator+(const Arithmetic<T>& x, const Arithmetic<T>& y)
    {
      return apply_binary(add, x, y);
    }

    template<typename T>
    constexpr auto
    operator+(Arithmetic<T>&& x, const Arithmetic<T>& y)
    {
      return apply_binary(add, move(x), y);
    }

    template<typename T>
    constexpr auto
    operator+(const Arithmetic<T>& x, Arithmetic<T>&& y)
    {
      return apply_binary(add, x, move(y));
    }

    template<typename T>
    constexpr auto
    operator+(Arithmetic<T>&& x, Arithmetic<T>&& y)
    {
      return apply_binary(add, move(x), move(y));
    }

    template<
      typename T,
      typename U,
      typename Test = typename enable_if<
        !is_convertible<U, Arithmetic<T>>::value>::type>
    constexpr auto
    operator+(const Arithmetic<T>& x, U&& y)
    {
      return apply_binary(add, x, forward<U>(y));
    }

    template<
      typename T,
      typename U,
      typename Test = typename enable_if<
        !is_convertible<U, Arithmetic<T>>::value>::type>
    constexpr auto
    operator+(Arithmetic<T>&& x, U&& y)
    {
      return apply_binary(add, move(x), forward<U>(y));
    }

    template<
      typename T,
      typename U,
      typename Test = typename enable_if<
        !is_convertible<U, Arithmetic<T>>::value>::type>
    constexpr auto
    operator+(U&& x, const Arithmetic<T>& y)
    {
      return apply_binary(add, forward<U>(x), y);
    }

    template<
      typename T,
      typename U,
      typename Test = typename enable_if<
        !is_convertible<U, Arithmetic<T>>::value>::type>
    constexpr auto
    operator+(U&& x, Arithmetic<T>&& y)
    {
      return apply_binary(add, forward<U>(x), move(y));
    }

    //
    // ... Subtraction
    //

    template<typename T>
    constexpr auto
    operator-(const Arithmetic<T>& x, const Arithmetic<T>& y)
    {
      return apply_binary(subtract, x, y);
    }

    template<typename T>
    constexpr auto
    operator-(Arithmetic<T>&& x, const Arithmetic<T>& y)
    {
      return apply_binary(subtract, move(x), y);
    }

    template<typename T>
    constexpr auto
    operator-(const Arithmetic<T>& x, Arithmetic<T>&& y)
    {
      return apply_binary(subtract, x, move(y));
    }

    template<typename T>
    constexpr auto
    operator-(Arithmetic<T>&& x, Arithmetic<T>&& y)
    {
      return apply_binary(subtract, move(x), move(y));
    }

    template<
      typename T,
      typename U,
      typename Test = typename enable_if<
        !is_convertible<U, Arithmetic<T>>::value>::type>
    constexpr auto
    operator-(const Arithmetic<T>& x, U&& y)
    {
      return apply_binary(subtract, x, forward<U>(y));
    }

    template<
      typename T,
      typename U,
      typename Test = typename enable_if<
        !is_convertible<U, Arithmetic<T>>::value>::type>
    constexpr auto
    operator-(Arithmetic<T>&& x, U&& y)
    {
      return apply_binary(subtract, move(x), forward<U>(y));
    }

    template<
      typename T,
      typename U,
      typename Test = typename enable_if<
        !is_convertible<U, Arithmetic<T>>::value>::type>
    constexpr auto
    operator-(U&& x, const Arithmetic<T>& y)
    {
      return apply_binary(subtract, forward<U>(x), y);
    }

    template<
      typename T,
      typename U,
      typename Test = typename enable_if<
        !is_convertible<U, Arithmetic<T>>::value>::type>
    constexpr auto
    operator-(U&& x, Arithmetic<T>&& y)
    {
      return apply_binary(subtract, forward<U>(x), move(y));
    }

    //
    // ... Multiplication
    //

    template<typename T>
    constexpr auto
    operator*(const Arithmetic<T>& x, const Arithmetic<T>& y)
    {
      return apply_binary(multiply, x, y);
    }

    template<typename T>
    constexpr auto
    operator*(Arithmetic<T>&& x, const Arithmetic<T>& y)
    {
      return apply_binary(multiply, move(x), y);
    }

    template<typename T>
    constexpr auto
    operator*(const Arithmetic<T>& x, Arithmetic<T>&& y)
    {
      return apply_binary(multiply, x, move(y));
    }

    template<typename T>
    constexpr auto
    operator*(Arithmetic<T>&& x, Arithmetic<T>&& y)
    {
      return apply_binary(multiply, move(x), move(y));
    }

    template<
      typename T,
      typename U,
      typename Test = typename enable_if<
        !is_convertible<U, Arithmetic<T>>::value>::type>
    constexpr auto
    operator*(const Arithmetic<T>& x, U&& y)
    {
      return apply_binary(multiply, x, forward<U>(y));
    }

    template<
      typename T,
      typename U,
      typename Test = typename enable_if<
        !is_convertible<U, Arithmetic<T>>::value>::type>
    constexpr auto
    operator*(Arithmetic<T>&& x, U&& y)
    {
      return apply_binary(multiply, move(x), forward<U>(y));
    }

    template<
      typename T,
      typename U,
      typename Test = typename enable_if<
        !is_convertible<U, Arithmetic<T>>::value>::type>
    constexpr auto
    operator*(U&& x, const Arithmetic<T>& y)
    {
      return apply_binary(multiply, forward<U>(x), y);
    }

    template<
      typename T,
      typename U,
      typename Test = typename enable_if<
        !is_convertible<U, Arithmetic<T>>::value>::type>
    constexpr auto
    operator*(U&& x, Arithmetic<T>&& y)
    {
      return apply_binary(multiply, forward<U>(x), move(y));
    }

    //
    // ... Division
    //

    template<typename T>
    constexpr auto
    operator/(const Arithmetic<T>& x, const Arithmetic<T>& y)
    {
      return apply_binary(divide, x, y);
    }

    template<typename T>
    constexpr auto
    operator/(Arithmetic<T>&& x, const Arithmetic<T>& y)
    {
      return apply_binary(divide, move(x), y);
    }

    template<typename T>
    constexpr auto
    operator/(const Arithmetic<T>& x, Arithmetic<T>&& y)
    {
      return apply_binary(divide, x, move(y));
    }

    template<typename T>
    constexpr auto
    operator/(Arithmetic<T>&& x, Arithmetic<T>&& y)
    {
      return apply_binary(divide, move(x), move(y));
    }

    template<
      typename T,
      typename U,
      typename Test = typename enable_if<
        !is_convertible<U, Arithmetic<T>>::value>::type>
    constexpr auto
    operator/(const Arithmetic<T>& x, U&& y)
    {
      return apply_binary(divide, x, forward<U>(y));
    }

    template<
      typename T,
      typename U,
      typename Test = typename enable_if<
        !is_convertible<U, Arithmetic<T>>::value>::type>
    constexpr auto
    operator/(Arithmetic<T>&& x, U&& y)
    {
      return apply_binary(divide, move(x), forward<U>(y));
    }

    template<
      typename T,
      typename U,
      typename Test = typename enable_if<
        !is_convertible<U, Arithmetic<T>>::value>::type>
    constexpr auto
    operator/(U&& x, const Arithmetic<T>& y)
    {
      return apply_binary(divide, forward<U>(x), y);
    }

    template<
      typename T,
      typename U,
      typename Test = typename enable_if<
        !is_convertible<U, Arithmetic<T>>::value>::type>
    constexpr auto
    operator/(U&& x, Arithmetic<T>&& y)
    {
      return apply_binary(divide, forward<U>(x), move(y));
    }

    //
    // ... Modulo
    //

    template<typename T>
    constexpr auto
    operator%(const Arithmetic<T>& x, const Arithmetic<T>& y)
    {
      return apply_binary(modulo, x, y);
    }

    template<typename T>
    constexpr auto
    operator%(Arithmetic<T>&& x, const Arithmetic<T>& y)
    {
      return apply_binary(modulo, move(x), y);
    }

    template<typename T>
    constexpr auto
    operator%(const Arithmetic<T>& x, Arithmetic<T>&& y)
    {
      return apply_binary(modulo, x, move(y));
    }

    template<typename T>
    constexpr auto
    operator%(Arithmetic<T>&& x, Arithmetic<T>&& y)
    {
      return apply_binary(modulo, move(x), move(y));
    }

    template<
      typename T,
      typename U,
      typename Test = typename enable_if<
        !is_convertible<U, Arithmetic<T>>::value>::type>
    constexpr auto
    operator%(const Arithmetic<T>& x, U&& y)
    {
      return apply_binary(modulo, x, forward<U>(y));
    }

    template<
      typename T,
      typename U,
      typename Test = typename enable_if<
        !is_convertible<U, Arithmetic<T>>::value>::type>
    constexpr auto
    operator%(Arithmetic<T>&& x, U&& y)
    {
      return apply_binary(modulo, move(x), forward<U>(y));
    }

    template<
      typename T,
      typename U,
      typename Test = typename enable_if<
        !is_convertible<U, Arithmetic<T>>::value>::type>
    constexpr auto
    operator%(U&& x, const Arithmetic<T>& y)
    {
      return apply_binary(modulo, forward<U>(x), y);
    }

    template<
      typename T,
      typename U,
      typename Test = typename enable_if<
        !is_convertible<U, Arithmetic<T>>::value>::type>
    constexpr auto
    operator%(U&& x, Arithmetic<T>&& y)
    {
      return apply_binary(modulo, forward<U>(x), move(y));
    }

  } // end of namespace Core
} // end of namespace Operators

#endif // !defined ARITHMETIC_HPP_INCLUDED_324502797521039265
