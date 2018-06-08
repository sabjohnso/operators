
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
  unary_specfun_list.def
  DESTINATION ${OPERATORS_INSTALL_INCLUDE_DIR})
  
