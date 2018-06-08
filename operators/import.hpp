#ifndef IMPORT_HPP_INCLUDED_70548141335921044
#define IMPORT_HPP_INCLUDED_70548141335921044 1

//
// ... Standard header files
//
#include <utility>
#include <type_traits>


//
// ... Type Utility header files
//
#include <type_utility/type_utility.hpp>


namespace Operators
{
  namespace Core
  {
    
    using std::forward;

    using std::decay_t;

    using TypeUtility::CRTP;
    
  } // end of namespace Core
} // end of namespace Operators

#endif // !defined IMPORT_HPP_INCLUDED_70548141335921044
