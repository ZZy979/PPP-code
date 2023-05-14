add_executable(sizeof_example sizeof_example.cpp)
add_library(simple_vector_v1 simple_vector.cpp)
add_executable(destructor_example destructor_example.cpp)
add_library(doubly_linked_list doubly_linked_list.cpp)
add_executable(linked_list_use linked_list_use.cpp)
target_link_libraries(linked_list_use doubly_linked_list)
add_library(doubly_linked_list_v2 doubly_linked_list_v2.cpp)
add_executable(linked_list_use_v2 linked_list_use_v2.cpp)
target_link_libraries(linked_list_use_v2 doubly_linked_list_v2)
add_executable(drill17 drill17.cpp)
add_executable(exec17-2 exec17-2.cpp)
add_library(string_algorithm_exec17 string_algorithm_exec17.cpp)
add_executable(exec17-7 exec17-7.cpp)
add_executable(exec17-9 exec17-9.cpp)
add_executable(exec17-13 exec17-13.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
add_gtest(NAME simple_vector_v1_test SOURCE simple_vector_test.cpp LIBRARY simple_vector_v1)
add_output_test(
  NAME destructor_example_test
  COMMAND destructor_example
  OUTPUT_FILE ${TESTDATA_DIR}/destructor_example_output.txt
)
add_gtest(NAME doubly_linked_list_test SOURCE doubly_linked_list_test.cpp LIBRARY doubly_linked_list)
add_output_test(
  NAME linked_list_use_test
  COMMAND linked_list_use
  OUTPUT_FILE ${TESTDATA_DIR}/linked_list_use_output.txt
)
add_gtest(NAME doubly_linked_list_v2_test SOURCE doubly_linked_list_v2_test.cpp LIBRARY doubly_linked_list_v2)
add_output_test(
  NAME linked_list_use_v2_test
  COMMAND linked_list_use_v2
  OUTPUT_FILE ${TESTDATA_DIR}/linked_list_use_output.txt
)
add_gtest(NAME string_algorithm_exec17_test SOURCE string_algorithm_exec17_test.cpp LIBRARY string_algorithm_exec17)
add_output_test(
  NAME exec17-7_test
  COMMAND exec17-7
  OUTPUT_FILE ${TESTDATA_DIR}/exec17-7_output.txt
  INPUT_FILE ${TESTDATA_DIR}/exec17-7_input.txt
)
add_output_test(
  NAME exec17-13_test
  COMMAND exec17-13
  OUTPUT_FILE ${TESTDATA_DIR}/exec17-13_output.txt
  INPUT_FILE ${TESTDATA_DIR}/gods.txt
)
