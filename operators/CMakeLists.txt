
configure_file( config.hpp.in config.hpp )

install( FILES
  config.hpp
  inequality.hpp
  import.hpp
  ops.hpp
  arithmetic.hpp
  specfun.hpp
  operators.hpp
  unary_specfun_list.def
  DESTINATION ${OPERATORS_INSTALL_INCLUDE_DIR})
  
