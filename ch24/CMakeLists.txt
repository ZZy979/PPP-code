link_libraries(Matrix)  # link all targets in current directory to library Matrix
add_executable(overflow_and_truncation overflow_and_truncation.cpp)
add_executable(numeric_limits numeric_limits.cpp)
add_executable(matrix_example matrix_example.cpp)
add_executable(two_dim_matrix two_dim_matrix.cpp)
add_library(gaussian_elimination gaussian_elimination.cpp)
add_executable(solve_linear_equations solve_linear_equations.cpp)
target_link_libraries(solve_linear_equations gaussian_elimination)
add_executable(solve_random_system solve_random_system.cpp)
target_link_libraries(solve_random_system gaussian_elimination)
add_executable(generate_normal_dist_histogram generate_normal_dist_histogram.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
add_output_test(
  NAME matrix_example_test
  COMMAND matrix_example
  OUTPUT_FILE ${TESTDATA_DIR}/matrix_example_output.txt
)
add_output_test(
  NAME two_dim_matrix_test
  COMMAND two_dim_matrix
  OUTPUT_FILE ${TESTDATA_DIR}/two_dim_matrix_output.txt
)
foreach(i RANGE 1 5)
  add_output_test(
    NAME solve_linear_equations_test${i}
    COMMAND solve_linear_equations
    OUTPUT_FILE ${TESTDATA_DIR}/solve_linear_equations_output${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/solve_linear_equations_input${i}.txt
  )
endforeach()
