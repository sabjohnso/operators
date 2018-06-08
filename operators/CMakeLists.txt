
configure_file( config.hpp.in config.hpp )

install( FILES
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  comparable.hpp
  inequality.hpp
  import.hpp
  ops.hpp
  arithmetic.hpp
  specfun.hpp
  operators.hpp
  binary_operator_list.def
  unary_specfun_list.def
  binary_specfun_list.def
  macros.hpp
  clear_macros.hpp
  DESTINATION ${OPERATORS_INSTALL_INCLUDE_DIR})
  
