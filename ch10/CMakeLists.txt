add_executable(read_temperatures read_temperatures.cpp)
add_library(fill_vector fill_vector.cpp)
add_library(get_int get_int.cpp)
add_executable(read_integer_in_range read_integer_in_range.cpp)
target_link_libraries(read_integer_in_range get_int)
add_library(temperature_reading temperature_reading.cpp)
add_executable(read_structured_temperatures read_structured_temperatures.cpp)
target_link_libraries(read_structured_temperatures temperature_reading)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
add_file_test(
  NAME read_temperatures_test
  COMMAND read_temperatures ${TESTDATA_DIR}/temperatures.txt
    ${CMAKE_CURRENT_BINARY_DIR}/read_temperatures_output.txt
  OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/read_temperatures_output.txt
  COMPARE_FILE ${TESTDATA_DIR}/read_temperatures_output.txt
)
add_gtest(NAME fill_vector_test SOURCE fill_vector_test.cpp LIBRARY fill_vector)
add_gtest(NAME get_int_test SOURCE get_int_test.cpp LIBRARY get_int)
add_gtest(NAME temperature_reading_test SOURCE temperature_reading_test.cpp LIBRARY temperature_reading)
add_file_test(
  NAME read_structured_temperatures_test
  COMMAND read_structured_temperatures ${TESTDATA_DIR}/structured_temperatures.txt
    ${CMAKE_CURRENT_BINARY_DIR}/read_structured_temperatures_output.txt
  OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/read_structured_temperatures_output.txt
  COMPARE_FILE ${TESTDATA_DIR}/read_structured_temperatures_output.txt
)
