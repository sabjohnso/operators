
configure_file( config.hpp.in config.hpp )

install( FILES
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  arithmetic.hpp
  binary_operator_list.def
  binary_specfun_list.def
  clear_macros.hpp
  comparable.hpp
  compound_assignment_operator_list.def
  compound_assignable.hpp
  import.hpp
  inequality.hpp
  macros.hpp
  operators.hpp
  ops.hpp
  specfun.hpp
  specfunable.hpp
  unary_operator_list.def
  unary_specfun_list.def
  DESTINATION ${OPERATORS_INSTALL_INCLUDE_DIR})


