add_executable(sizeof_example sizeof_example.cpp)
add_library(simple_vector_v1 simple_vector.cpp)
add_executable(destructor_example destructor_example.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
add_gtest(NAME simple_vector_v1_test SOURCE simple_vector_test.cpp LIBRARY simple_vector_v1)
add_output_test(
  NAME destructor_example_test
  COMMAND destructor_example
  OUTPUT_FILE ${TESTDATA_DIR}/destructor_example_output.txt
)
