#
# ... Build script for operators
#

cmake_minimum_required( VERSION 3.1 )

project( OPERATORS )

set( OPERATORS_MAJOR  0 )
set( OPERATORS_MINOR  1 )
set( OPERATORS_UPDATE 0 )
set( OPERATORS_VERSION operators-${OPERATORS_MAJOR}.${OPERATORS_MINOR} )
set( OPERATORS_VERSION_UPDATE ${OPERATORS_VERSION}.{OPERATORS_UPDATE} )

option( BUILD_OPERATORS_TESTING  "Build the operators tests" ON )
option( BUILD_OPERATORS_DOCUMENTATION "Build the operators documenation" ON )

include_directories( 
  ${OPERATORS_SOURCE_DIR}
  ${OPERATORS_BINARY_DIR} )

if( NOT OPERATORS_INSTALL_INCLUDE_DIR )
  set( OPERATORS_INSTALL_INCLUDE_DIR include/operators
    CACHE PATH "Path for installation of header files" )
endif( NOT OPERATORS_INSTALL_INCLUDE_DIR )

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
