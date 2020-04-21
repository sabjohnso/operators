#
# ... Build script for operators
#

cmake_minimum_required(VERSION 3.12)
project(operators VERSION 0.2.0 LANGUAGES CXX)

list(INSERT CMAKE_MODULE_PATH 0 ${PROJECT_SOURCE_DIR}/cmake)
  
#
# ... Build options
#
option( BUILD_OPERATORS_TESTING  "Build the operators tests if BUILD_TESTING is also ON" ON )
option( BUILD_OPERATORS_DOCUMENTATION "Build the operators documenation" ON )
option( operators_INSTALL_VERSIONED "Make a version specific installation" ON )

#
# ... Installation Setup
#
include(GNUInstallDirs)

if(operators_INSTALL_WITH_VERSION)
  set(operators_INSTALL_INCLUDEDIR ${CMAKE_INSTALL_INCLUDEDIR}/operators-${PROJECT_VERSION})
else()
  set(operators_INSTALL_INCLUDEDIR ${CMAKE_INSTALL_INCLUDEDIR})
endif()

set(operators_INSTALL_LIBDIR ${CMAKE_INSTALL_LIBDIR})
set(operators_INSTALL_BINDIR ${CMAKE_INSTALL_BINDIR})
set(operators_INSTALL_CONFDIR ${operators_INSTALL_LIBDIR}/cmake/operators-${PROJECT_VERSION})

#
# ... Dependencies
#

find_package(type_utility REQUIRED)
find_package(function_utility REQUIRED)

#
# ... Header library target
#
add_library(operators INTERFACE)
target_link_libraries(operators INTERFACE type_utility::type_utility)

target_include_directories(operators
  INTERFACE
    $<BUILD_INTERFACE:${operators_SOURCE_DIR}> 
    $<BUILD_INTERFACE:${operators_BINARY_DIR}>
    $<INSTALL_INTERFACE:${operators_INSTALL_INCLUDEDIR}>)

install(
  TARGETS operators
  EXPORT operators_targets
  DESTINATION ${operators_INSTALL_LIBDIR})

install(
  EXPORT operators_targets
  NAMESPACE operators::
  FILE operators-targets.cmake
  DESTINATION ${operators_INSTALL_CONFDIR})

configure_file(operators-config.cmake.in operators-config.cmake @ONLY) 
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/operators-config.cmake
  DESTINATION ${operators_INSTALL_CONFDIR})

#
# ... Walk the source tree
#
add_subdirectory(operators)

#
# ... Testing
#
if(BUILD_OPERATORS_TESTING)
  include(CTest)
  if(BUILD_TESTING)
    add_subdirectory(operators_testing)
  endif()
endif()

#
# ... Documentation
#
if(operators_BUILD_DOCUMENTATION)

  configure_file(Doxyfile.in Doxyfile)
  
  if(NOT operators_INSTALL_DOCDIR)    
    set(operators_INSTALL_DOCDIR share/operators-${PROJECT_VERSION}
      CACHE PATH "Path for installation of documentation")
  endif()

  if(NOT operators_INSTALL_MAN_DIR)
    set(operators_INSTALL_MANDIR share
      CACHE PATH "Path for installation of manual pages")
  endif()

  find_package(Doxygen REQUIRED)

  add_custom_command(
    OUTPUT ${operators_BINARY_DIR}/doxygen.log
    COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile > doxygen.log
    MAIN_DEPENDENCY Doxyfile
    DEPENDS ${operators_SOURCE_DIR}/operators
    WORKING_DIRECTORY ${operators_BINARY_DIR})

  add_custom_target(
    operators_documentation ALL
    DEPENDS ${operators_BINARY_DIR}/doxygen.log)

  install(DIRECTORY ${operators_BINARY_DIR}/doc/html DESTINATION ${operators_INSTALL_DOC_DIR})
  install(DIRECTORY ${operators_BINARY_DIR}/doc/man DESTINATION ${operators_INSTALL_MAN_DIR})
  
endif()


# end of build definition for operators
