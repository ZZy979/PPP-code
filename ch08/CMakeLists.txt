add_executable(drill8-1 use.cpp my.cpp)
add_library(drill8-2 swaps.cpp)
add_executable(drill8-3 drill8-3.cpp)
add_library(print_vector print_vector.cpp)
add_library(fibonacci fibonacci.cpp)
add_library(reverse_vector reverse_vector.cpp)
add_executable(exec8-7 exec8-7.cpp)
add_library(inner_product inner_product.cpp)
add_library(describe_vector describe_vector.cpp)
add_library(print_until print_until.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
add_output_test(
  NAME drill8-1_test
  COMMAND drill8-1
  OUTPUT_FILE ${TESTDATA_DIR}/drill8-1_output.txt
)
add_gtest(NAME drill8-2_test SOURCE swaps_test.cpp LIBRARY drill8-2)
add_output_test(
  NAME drill8-3_test
  COMMAND drill8-3
  OUTPUT_FILE ${TESTDATA_DIR}/drill8-3_output.txt
)
add_gtest(NAME print_vector_test SOURCE print_vector_test.cpp LIBRARY print_vector)
add_gtest(NAME fibonacci_test SOURCE fibonacci_test.cpp LIBRARY fibonacci)
add_gtest(NAME reverse_vector_test SOURCE reverse_vector_test.cpp LIBRARY reverse_vector)
add_output_test(
  NAME exec8-7_test
  COMMAND exec8-7
  OUTPUT_FILE ${TESTDATA_DIR}/exec8-7_output.txt
  INPUT_FILE ${TESTDATA_DIR}/exec8-7_input.txt
)
add_gtest(NAME inner_product_test SOURCE inner_product_test.cpp LIBRARY inner_product)
add_gtest(NAME describe_vector_test SOURCE describe_vector_test.cpp LIBRARY describe_vector)
add_gtest(NAME print_until_test SOURCE print_until_test.cpp LIBRARY print_until)
