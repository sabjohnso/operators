#
# ... Build script for operators
#

cmake_minimum_required( VERSION 3.8 )

project( OPERATORS VERSION 0.1.0 LANGUAGES CXX )

include( GNUInstallDirs )

#
# ... Version information
#
set( OPERATORS_MAJOR  ${PROJECT_VERSION_MAJOR} )
set( OPERATORS_MINOR  ${PROJECT_VERSION_MINOR} )
set( OPERATORS_UPDATE ${PROJECT_VERSION_PATCH} )

set( OPERATORS_SUFFIX -${OPERATORS_MAJOR}.${OPERATORS_MINOR} )

set( OPERATORS_VERSION operators${OPERATORS_SUFFIX} )
set( OPERATORS_VERSION_UPDATE ${OPERATORS_VERSION}.{OPERATORS_UPDATE} )

#
# ... Build options
#
option( BUILD_OPERATORS_TESTING  "Build the operators tests" ON )
option( BUILD_OPERATORS_DOCUMENTATION "Build the operators documenation" ON )
option( OPERATORS_INSTALL_VERSIONED "Make a version specific installation" ON )


#
# ... Dependencies
#
find_package( type_utility REQUIRED )


#
# ... Installation path info
#
set( OPERATORS_INSTALL_INCLUDEDIR ${CMAKE_INSTALL_INCLUDEDIR}
  CACHE PATH "Path for installation of header files" )

set( OPERATORS_INSTALL_LIBRARY_DIR ${CMAKE_INSTALL_LIBDIR}/operators
  CACHE PATH "Path for installation of library files" )


if( OPERATORS_INSTALL_VERSIONED )
  string( APPEND OPERATORS_INSTALL_INCLUDE_DIR /operator${OPERATORS_SUFFIX})
  string( APPEND OPERATORS_INSTALL_LIBRARY_DIR ${OPERATORS_SUFFIX})
endif()

set( OPERATORS_INSTALL_CONFIGDIR ${OPERATORS_INSTALL_LIBRARY_DIR})


#
# ... Header library target
#
add_library( operators INTERFACE )
target_link_libraries( operators INTERFACE type_utility::type_utility )

target_include_directories( operators INTERFACE $<INSTALL_INTERFACE:${OPERATORS_INSTALL_INCLUDE_DIR}> )
target_include_directories( operators INTERFACE $<BUILD_INTERFACE:${OPERATORS_SOURCE_DIR}> )
target_include_directories( operators INTERFACE $<BUILD_INTERFACE:${OPERATORS_BINARY_DIR}> )


install(
  TARGETS operators
  EXPORT operators_targets
  DESTINATION ${OPERATORS_INSTALL_LIBRARY_DIR})

install(
  EXPORT operators_targets
  NAMESPACE operators::
  FILE operators-targets.cmake
  DESTINATION ${OPERATORS_INSTALL_LIBRARY_DIR} )

configure_file( operators-config.cmake.in operators-config.cmake @ONLY)
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/operators-config.cmake
  DESTINATION ${OPERATORS_INSTALL_CONFIGDIR})




#
# ... Walk the source tree
#
add_subdirectory( operators )

#
# ... Testing
#
if( BUILD_OPERATORS_TESTING )
  enable_testing()
  add_subdirectory( operators_testing )
endif( BUILD_OPERATORS_TESTING )

#
# ... Documentation
#
if( BUILD_OPERATORS_DOCUMENTATION )

  configure_file( Doxyfile.in Doxyfile )
  
  if( NOT OPERATORS_INSTALL_DOC_DIR )    
    set( OPERATORS_INSTALL_DOC_DIR share/${OPERATORS_VERSION}
      CACHE PATH "Path for installation of documentation")
  endif( NOT OPERATORS_INSTALL_DOC_DIR )

  if( NOT OPERATORS_INSTALL_MAN_DIR )
    set( OPERATORS_INSTALL_MAN_DIR share
      CACHE PATH "Path for installation of manual pages" )
  endif( NOT OPERATORS_INSTALL_MAN_DIR )

  find_package( Doxygen REQUIRED )

  add_custom_command(
    OUTPUT ${OPERATORS_BINARY_DIR}/doxygen.log
    COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile > doxygen.log
    MAIN_DEPENDENCY Doxyfile
    DEPENDS ${OPERATORS_SOURCE_DIR}/operators
    WORKING_DIRECTORY ${OPERATORS_BINARY_DIR} )

  add_custom_target(
    operators_documentation ALL
    DEPENDS ${OPERATORS_BINARY_DIR}/doxygen.log )

  install( DIRECTORY ${OPERATORS_BINARY_DIR}/doc/html DESTINATION ${OPERATORS_INSTALL_DOC_DIR})
  install( DIRECTORY ${OPERATORS_BINARY_DIR}/doc/man DESTINATION ${OPERATORS_INSTALL_MAN_DIR})
  
endif( BUILD_OPERATORS_DOCUMENTATION )


# end of build definition for operators
