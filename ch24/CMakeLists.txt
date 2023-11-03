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
add_executable(drill24-1 drill24-1.cpp)
add_executable(drill24-4 drill24-4.cpp)
add_executable(drill24-5 drill24-5.cpp)
add_executable(drill24-6 drill24-6.cpp)
add_executable(drill24-7 drill24-7.cpp)
add_executable(exec24-1 exec24-1.cpp)
add_executable(exec24-8 exec24-8.cpp)
add_executable(exec24-10 exec24-10.cpp)
add_executable(exec24-11 exec24-11.cpp)

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
foreach(i RANGE 1 6)
  add_output_test(
    NAME solve_linear_equations_test${i}
    COMMAND solve_linear_equations
    OUTPUT_FILE ${TESTDATA_DIR}/solve_linear_equations_output${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/solve_linear_equations_input${i}.txt
  )
endforeach()
add_output_test(
  NAME drill24-4_test
  COMMAND drill24-4
  OUTPUT_FILE ${TESTDATA_DIR}/drill24-4_output.txt
  INPUT_FILE ${TESTDATA_DIR}/drill24-4_input.txt
)
foreach(i RANGE 1 2)
  add_output_test(
    NAME drill24-5_test${i}
    COMMAND drill24-5
    OUTPUT_FILE ${TESTDATA_DIR}/drill24-5_output${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/drill24-5_input${i}.txt
  )
endforeach()
add_output_test(
  NAME drill24-6_test
  COMMAND drill24-6
  OUTPUT_FILE ${TESTDATA_DIR}/drill24-6_output.txt
  INPUT_FILE ${TESTDATA_DIR}/drill24-6_input.txt
)
add_output_test(
  NAME exec24-1_test
  COMMAND exec24-1
  OUTPUT_FILE ${TESTDATA_DIR}/exec24-1_output.txt
)
foreach(i RANGE 1 6)
  add_output_test(
    NAME exec24-8_test${i}
    COMMAND exec24-8
    OUTPUT_FILE ${TESTDATA_DIR}/exec24-8_output${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/solve_linear_equations_input${i}.txt
  )
endforeach()
add_output_test(
  NAME exec24-11_test
  COMMAND exec24-11
  OUTPUT_FILE ${TESTDATA_DIR}/exec24-11_output.txt
)
add_gtest(NAME matrix_operation_test SOURCE matrix_operation_test.cpp)
