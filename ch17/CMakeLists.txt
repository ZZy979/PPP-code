add_executable(sizeof_example sizeof_example.cpp)
add_library(simple_vector_v1 simple_vector.cpp)
add_executable(destructor_example destructor_example.cpp)
add_library(doubly_linked_list doubly_linked_list.cpp)
add_executable(linked_list_use linked_list_use.cpp)
target_link_libraries(linked_list_use doubly_linked_list)

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