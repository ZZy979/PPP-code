add_library(simple_vector_v2 simple_vector.cpp)
add_executable(debug_ctor_dtor debug_ctor_dtor.cpp)
add_library(palindrome palindrome.cpp)
add_executable(drill18 drill18.cpp)
add_library(string_algorithm_exec18 string_algorithm_exec18.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
add_gtest(NAME simple_vector_v2_test SOURCE simple_vector_test.cpp LIBRARY simple_vector_v2)
add_gtest(NAME palindrome_test SOURCE palindrome_test.cpp LIBRARY palindrome)
add_output_test(
  NAME drill18_test
  COMMAND drill18
  OUTPUT_FILE ${TESTDATA_DIR}/drill18_output.txt
)
add_gtest(NAME string_algorithm_exec18_test SOURCE string_algorithm_exec18_test.cpp LIBRARY string_algorithm_exec18)
