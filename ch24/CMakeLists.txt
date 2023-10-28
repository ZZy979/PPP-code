add_executable(overflow_and_truncation overflow_and_truncation.cpp)
add_executable(numeric_limits numeric_limits.cpp)
add_executable(matrix_example matrix_example.cpp)
target_link_libraries(matrix_example Matrix)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
add_output_test(
  NAME matrix_example_test
  COMMAND matrix_example
  OUTPUT_FILE ${TESTDATA_DIR}/matrix_example_output.txt
)
