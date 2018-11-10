
macro( operators_add_simple_test  name )
  add_executable( ${name}_test ${name}_test.cpp ) 
  target_link_libraries( ${name}_test PRIVATE operators )
  add_test( ${name} ${name}_test ) 
endmacro()
 
operators_add_simple_test( inequality )
operators_add_simple_test( comparable )
operators_add_simple_test( ops )
operators_add_simple_test( arithmetic )
operators_add_simple_test( specfun )
