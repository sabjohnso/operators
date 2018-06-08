/**
 * @brief Define a handful of macros
 * 
 * @details The macros defined in this file are
 * intended to be undefined by inclusion of the
 * clear_macros.hpp file.  If the header guard defined
 * in clear_macros.hpp is defined here, it indicates that
 * the macros were previously cleared. To allow them to
 * be cleared again, The header gaurd for clear_macros.hpp
 * is undefined here.
 */
#ifndef MACROS_HPP_INCLUDED_58610792695753561
#define MACROS_HPP_INCLUDED_58610792695753561 1


#ifdef OPERATORS_FORCE_SEMICOLON
#  error OPERATORS_FORCE_SEMICOLON is already defined
#endif

#ifdef OPERATORS_QUOTE_AUX
#  error OPERATORS_QUOTE_AUX is aready defined
#endif

#ifdef OPERATORS_QUOTE
# error OPERATORS_QUOTE is already defined
#endif


#define OPERATORS_FORCE_SEMICOLON() static_assert(true)
#define OPERATORS_QUOTE_AUX( ... ) #__VA_ARGS__
#define OPERATORS_QUOTE( ... ) OPERATORS_QUOTE_AUX( __VA_ARGS__ )

#ifdef CLEAR_MACROS_HPP_INCLUDED_515014686904941410
# undef CLEAR_MACROS_HPP_INCLUDED_515014686904941410
#endif

#endif // !defined MACROS_HPP_INCLUDED_58610792695753561





