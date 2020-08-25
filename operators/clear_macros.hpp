/**
 * @brief Clear all macro definitions to prevent
 * pollution of the global namespace
 *
 * @details This file clears all of the macros define
 * in the macros.hpp header file to prevent namespace
 * conflicts.  It also clears the header gaurd to allow
 * The macros to be redefined.
 */
#ifndef CLEAR_MACROS_HPP_INCLUDED_515014686904941410
#define CLEAR_MACROS_HPP_INCLUDED_515014686904941410 1

//
// ... Clear the header gaurd if it is define otherwise give an error
//
#ifndef MACROS_HPP_INCLUDED_58610792695753561
#error "The header gaurd for macros definitions is not defined"
#endif


#undef MACROS_HPP_INCLUDED_58610792695753561

//
//  ... Clear the macros if they are defined. Otherwise provide an error
//
#ifndef OPERATORS_FORCE_SEMICOLON
// #error OPERATORS_FORCE_SEMICOLON is _NOT_  defined
#endif

#ifndef OPERATORS_QUOTE_AUX
// #error OPERATORS_QUOTE_AUX is _NOT_ defined
#endif

#ifndef OPERATORS_QUOTE
// #error OPERATORS_QUOTE is _NOT_ defined
#endif

#endif // !defined CLEAR_MACROS_HPP_INCLUDED_515014686904941410
