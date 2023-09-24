add_executable(calculate_total_cost calculate_total_cost.cpp)
add_executable(calculate_stock_market_index calculate_stock_market_index.cpp)
add_executable(word_frequency word_frequency.cpp)
add_executable(calculate_stock_market_index_v2 calculate_stock_market_index_v2.cpp)
add_executable(simple_dictionary_v2 simple_dictionary_v2.cpp)
add_library(sort_strings_ignore_case sort_strings_ignore_case.cpp)
foreach(i RANGE 1 3)
  add_executable(drill21-${i} drill21-${i}.cpp)
endforeach()
add_library(count count.cpp)
add_executable(exec21-6 exec21-6.cpp)
add_library(binary_search binary_search.cpp)
add_executable(exec21-8 exec21-8.cpp)
add_library(order order.cpp)
add_executable(exec21-9 exec21-9.cpp)
target_link_libraries(exec21-9 order)
add_fltk_executable(exec21-11 exec21-11.cpp order_list_window.cpp order_list_table.cpp
  order_edit_window.cpp purchase_list_table.cpp)
target_link_libraries(exec21-11 order)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
add_gtest(NAME larger_than_test SOURCE larger_than_test.cpp)
add_output_test(
  NAME calculate_total_cost_test
  COMMAND calculate_total_cost
  OUTPUT_FILE ${TESTDATA_DIR}/calculate_total_cost_output.txt
  INPUT_FILE ${TESTDATA_DIR}/calculate_total_cost_input.txt
)
add_output_test(
  NAME calculate_stock_market_index_test
  COMMAND calculate_stock_market_index
  OUTPUT_FILE ${TESTDATA_DIR}/calculate_stock_market_index_output.txt
  INPUT_FILE ${TESTDATA_DIR}/calculate_stock_market_index_input.txt
)
add_output_test(
  NAME word_frequency_test
  COMMAND word_frequency
  OUTPUT_FILE ${TESTDATA_DIR}/word_frequency_output.txt
  INPUT_FILE ${TESTDATA_DIR}/word_frequency_input.txt
)
add_output_test(
  NAME calculate_stock_market_index_v2_test
  COMMAND calculate_stock_market_index_v2
  OUTPUT_FILE ${TESTDATA_DIR}/calculate_stock_market_index_v2_output.txt
)
add_file_test(
  NAME simple_dictionary_v2_test
  COMMAND simple_dictionary_v2 ${TESTDATA_DIR}/simple_dictionary_v2_input.txt
    ${CMAKE_CURRENT_BINARY_DIR}/simple_dictionary_v2_output.txt
  OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/simple_dictionary_v2_output.txt
  COMPARE_FILE ${TESTDATA_DIR}/simple_dictionary_v2_output.txt
)
add_gtest(NAME sort_strings_ignore_case_test SOURCE sort_strings_ignore_case_test.cpp LIBRARY sort_strings_ignore_case)
add_output_test(
  NAME drill21-1_test
  COMMAND drill21-1 ${TESTDATA_DIR}/drill21-1_input.txt
  OUTPUT_FILE ${TESTDATA_DIR}/drill21-1_output.txt
)
add_output_test(
  NAME drill21-2_test
  COMMAND drill21-2
  OUTPUT_FILE ${TESTDATA_DIR}/drill21-2_output.txt
  INPUT_FILE ${TESTDATA_DIR}/drill21-2_input.txt
)
add_output_test(
  NAME drill21-3_test
  COMMAND drill21-3
  OUTPUT_FILE ${TESTDATA_DIR}/drill21-3_output.txt
  INPUT_FILE ${TESTDATA_DIR}/drill21-3_input.txt
)
add_gtest(NAME count_test SOURCE count_test.cpp LIBRARY count)
add_output_test(
  NAME exec21-6_test
  COMMAND exec21-6
  OUTPUT_FILE ${TESTDATA_DIR}/exec21-6_output.txt
  INPUT_FILE ${TESTDATA_DIR}/exec21-6_input.txt
)
add_gtest(NAME binary_search_test SOURCE binary_search_test.cpp LIBRARY binary_search)
add_output_test(
  NAME exec21-8_test
  COMMAND exec21-8
  OUTPUT_FILE ${TESTDATA_DIR}/exec21-8_output.txt
  INPUT_FILE ${TESTDATA_DIR}/word_frequency_input.txt
)
add_gtest(NAME order_test SOURCE order_test.cpp LIBRARY order)
add_file_test(
  NAME exec21-9_test
  COMMAND exec21-9 ${TESTDATA_DIR}/order_data1.txt ${TESTDATA_DIR}/order_data2.txt
    ${CMAKE_CURRENT_BINARY_DIR}/exec21-9_output.txt
  OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/exec21-9_output.txt
  COMPARE_FILE ${TESTDATA_DIR}/exec21-9_output.txt
)
