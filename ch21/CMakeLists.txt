add_executable(calculate_total_cost calculate_total_cost.cpp)
add_executable(calculate_stock_market_index calculate_stock_market_index.cpp)

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
