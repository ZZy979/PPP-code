add_executable(calculate_total_cost calculate_total_cost.cpp)
add_executable(calculate_stock_market_index calculate_stock_market_index.cpp)
add_executable(word_frequency word_frequency.cpp)
add_executable(calculate_stock_market_index_v2 calculate_stock_market_index_v2.cpp)
add_executable(simple_dictionary_v2 simple_dictionary_v2.cpp)
add_library(sort_strings_ignore_case sort_strings_ignore_case.cpp)

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
