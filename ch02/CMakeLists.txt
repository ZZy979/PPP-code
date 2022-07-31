add_executable(hello_world hello_world.cpp)

add_test(NAME run_hello_world COMMAND hello_world)
set_tests_properties(run_hello_world PROPERTIES PASS_REGULAR_EXPRESSION "Hello, World!\n")
