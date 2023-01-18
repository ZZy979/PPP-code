add_executable(read_temperatures read_temperatures.cpp)
add_library(fill_vector fill_vector.cpp)
add_library(get_int get_int.cpp)
add_executable(read_integer_in_range read_integer_in_range.cpp)
target_link_libraries(read_integer_in_range get_int)
add_library(temperature_reading temperature_reading.cpp)
add_executable(read_structured_temperatures read_structured_temperatures.cpp)
target_link_libraries(read_structured_temperatures temperature_reading)
add_executable(read_write_points read_write_points.cpp)
add_executable(exec10-1 exec10-1.cpp)
add_executable(store_temps store_temps.cpp)
target_link_libraries(store_temps temperature_converters)
add_executable(temp_stats temp_stats.cpp)
target_link_libraries(temp_stats temperature_converters)
add_library(roman_int roman_int.cpp)
add_executable(exec10-8 exec10-8.cpp)
add_executable(exec10-9 exec10-9.cpp)
add_executable(exec10-11 exec10-11.cpp)
add_executable(exec10-12 exec10-12.cpp)

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
add_file_test(
  NAME read_write_points_test
  COMMAND read_write_points ${CMAKE_CURRENT_BINARY_DIR}/points_output.txt
  OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/points_output.txt
  COMPARE_FILE ${TESTDATA_DIR}/points_output.txt
  INPUT_FILE ${TESTDATA_DIR}/points_input.txt
)
add_output_test(
  NAME exec10-1_test
  COMMAND exec10-1 ${TESTDATA_DIR}/exec10-1_input.txt
  OUTPUT_FILE ${TESTDATA_DIR}/exec10-1_output.txt
)
add_file_test(
  NAME store_temps_test
  COMMAND store_temps ${CMAKE_CURRENT_BINARY_DIR}/raw_temps.txt 50
  OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/raw_temps.txt
  COMPARE_FILE ${TESTDATA_DIR}/raw_temps.txt
)
add_output_test(
  NAME temp_stats_test
  COMMAND temp_stats ${TESTDATA_DIR}/raw_temps.txt
  OUTPUT_FILE ${TESTDATA_DIR}/temp_stats_output.txt
)
add_gtest(NAME roman_int_test SOURCE roman_int_test.cpp LIBRARY roman_int)
add_file_test(
  NAME exec10-8_test
  COMMAND exec10-8 ${TESTDATA_DIR}/exec10-8_input1.txt ${TESTDATA_DIR}/exec10-8_input2.txt
    ${CMAKE_CURRENT_BINARY_DIR}/exec10-8_output.txt
  OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/exec10-8_output.txt
  COMPARE_FILE ${TESTDATA_DIR}/to_be_or_not_to_be.txt
)
add_file_test(
  NAME exec10-8_test_first_empty
  COMMAND exec10-8 ${TESTDATA_DIR}/empty.txt ${TESTDATA_DIR}/exec10-8_input2.txt
  ${CMAKE_CURRENT_BINARY_DIR}/exec10-8_output_first_empty.txt
  OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/exec10-8_output_first_empty.txt
  COMPARE_FILE ${TESTDATA_DIR}/exec10-8_input2.txt
)
add_file_test(
  NAME exec10-8_test_second_empty
  COMMAND exec10-8 ${TESTDATA_DIR}/exec10-8_input1.txt ${TESTDATA_DIR}/empty.txt
  ${CMAKE_CURRENT_BINARY_DIR}/exec10-8_output_second_empty.txt
  OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/exec10-8_output_second_empty.txt
  COMPARE_FILE ${TESTDATA_DIR}/exec10-8_input1.txt
)
add_file_test(
  NAME exec10-8_test_both_empty
  COMMAND exec10-8 ${TESTDATA_DIR}/empty.txt ${TESTDATA_DIR}/empty.txt
  ${CMAKE_CURRENT_BINARY_DIR}/exec10-8_output_both_empty.txt
  OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/exec10-8_output_both_empty.txt
  COMPARE_FILE ${TESTDATA_DIR}/empty.txt
)
add_file_test(
  NAME exec10-9_test
  COMMAND exec10-9 ${TESTDATA_DIR}/exec10-9_input1.txt ${TESTDATA_DIR}/exec10-9_input2.txt
    ${CMAKE_CURRENT_BINARY_DIR}/exec10-9_output.txt
  OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/exec10-9_output.txt
  COMPARE_FILE ${TESTDATA_DIR}/exec10-9_output.txt
)
add_file_test(
  NAME exec10-9_test_first_empty
  COMMAND exec10-9 ${TESTDATA_DIR}/empty.txt ${TESTDATA_DIR}/exec10-9_input2.txt
  ${CMAKE_CURRENT_BINARY_DIR}/exec10-9_output_first_empty.txt
  OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/exec10-9_output_first_empty.txt
  COMPARE_FILE ${TESTDATA_DIR}/exec10-9_input2.txt
)
add_file_test(
  NAME exec10-9_test_second_empty
  COMMAND exec10-9 ${TESTDATA_DIR}/exec10-9_input1.txt ${TESTDATA_DIR}/empty.txt
  ${CMAKE_CURRENT_BINARY_DIR}/exec10-9_output_second_empty.txt
  OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/exec10-9_output_second_empty.txt
  COMPARE_FILE ${TESTDATA_DIR}/exec10-9_input1.txt
)
add_file_test(
  NAME exec10-9_test_both_empty
  COMMAND exec10-9 ${TESTDATA_DIR}/empty.txt ${TESTDATA_DIR}/empty.txt
  ${CMAKE_CURRENT_BINARY_DIR}/exec10-9_output_both_empty.txt
  OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/exec10-9_output_both_empty.txt
  COMPARE_FILE ${TESTDATA_DIR}/empty.txt
)
add_output_test(
  NAME exec10-11_test1
  COMMAND exec10-11 ${TESTDATA_DIR}/exec10-1_input.txt
  OUTPUT_FILE ${TESTDATA_DIR}/exec10-11_output1.txt
)
add_output_test(
  NAME exec10-11_test2
  COMMAND exec10-11 ${TESTDATA_DIR}/exec10-11_input.txt
  OUTPUT_FILE ${TESTDATA_DIR}/exec10-11_output2.txt
)
foreach(w IN ITEMS to;himself;nosuchword)
  add_output_test(
    NAME exec10-12_test_${w}
    COMMAND exec10-12 ${TESTDATA_DIR}/to_be_or_not_to_be.txt ${w}
    OUTPUT_FILE ${TESTDATA_DIR}/exec10-12_output_${w}.txt
  )
endforeach()
