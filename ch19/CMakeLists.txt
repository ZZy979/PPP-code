add_library(simple_vector_v3 simple_vector.cpp)
add_library(simple_array simple_array.cpp)
add_library(counted_element counted_element.cpp)
add_executable(drill19 drill19.cpp)
add_library(vector_add vector_add.cpp)
add_library(inner_product_v2 inner_product.cpp)
add_library(pair pair.cpp)
add_library(symbol_table symbol_table.cpp)
target_link_libraries(symbol_table pair)
add_library(doubly_linked_list_v3 doubly_linked_list_v3.cpp)
add_executable(exec19-4 exec19-4.cpp)
target_link_libraries(exec19-4 doubly_linked_list_v3 god)
add_library(number number.cpp)
add_library(simple_allocator simple_allocator.cpp)
add_library(unique_ptr unique_ptr.cpp)
add_library(counted_ptr counted_ptr.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
add_gtest(NAME simple_vector_v3_test SOURCE simple_vector_test.cpp LIBRARY simple_vector_v3 counted_element)
add_gtest(NAME simple_array_test SOURCE simple_array_test.cpp LIBRARY simple_array)
add_output_test(
  NAME drill19_test
  COMMAND drill19
  OUTPUT_FILE ${TESTDATA_DIR}/drill19_output.txt
  INPUT_FILE ${TESTDATA_DIR}/drill19_input.txt
)
add_gtest(NAME vector_add_test SOURCE vector_add_test.cpp LIBRARY vector_add)
add_gtest(NAME inner_product_v2_test SOURCE inner_product_test.cpp LIBRARY inner_product_v2)
add_gtest(NAME symbol_table_test SOURCE symbol_table_test.cpp LIBRARY symbol_table)
add_gtest(NAME doubly_linked_list_v3_test SOURCE doubly_linked_list_v3_test.cpp LIBRARY doubly_linked_list_v3)
add_output_test(
  NAME exec19-4_test
  COMMAND exec19-4
  OUTPUT_FILE ${CMAKE_SOURCE_DIR}/ch17/testdata/exec17-13_output.txt
  INPUT_FILE ${CMAKE_SOURCE_DIR}/ch17/testdata/gods.txt
)
add_gtest(NAME number_test SOURCE number_test.cpp LIBRARY number)
add_gtest(
  NAME simple_allocator_test
  SOURCE simple_allocator_test.cpp
  LIBRARY simple_allocator simple_vector_v3 counted_element
)
add_gtest(NAME unique_ptr_test SOURCE unique_ptr_test.cpp LIBRARY unique_ptr counted_element)
add_gtest(NAME counted_ptr_test SOURCE counted_ptr_test.cpp LIBRARY counted_ptr counted_element)
