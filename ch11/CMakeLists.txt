add_executable(output_integer_in_different_bases output_integer_in_different_bases.cpp)
add_executable(input_integer_in_different_bases input_integer_in_different_bases.cpp)
add_executable(output_float_in_different_formats output_float_in_different_formats.cpp)
add_executable(set_precision set_precision.cpp)
add_executable(set_field_width set_field_width.cpp)
add_executable(print_contact_table print_contact_table.cpp)
add_executable(read_write_binary_file read_write_binary_file.cpp)
add_library(str_to_double str_to_double.cpp)
add_library(punct_stream punct_stream.cpp)
add_executable(custom_separator_dictionary custom_separator_dictionary.cpp)
target_link_libraries(custom_separator_dictionary punct_stream)
add_executable(exec11-1 exec11-1.cpp)
add_executable(exec11-2 exec11-2.cpp)
add_executable(exec11-3 exec11-3.cpp)
add_executable(exec11-4 exec11-4.cpp)
add_executable(exec11-5 exec11-5.cpp)
add_library(punct_stream_v2 punct_stream_v2.cpp)
target_link_libraries(punct_stream_v2 punct_stream)
add_executable(custom_separator_dictionary_v2 custom_separator_dictionary_v2.cpp)
target_link_libraries(custom_separator_dictionary_v2 punct_stream_v2)
add_library(split split.cpp)
target_link_libraries(split punct_stream)
add_executable(exec11-12 exec11-12.cpp)
add_executable(exec11-13 exec11-13.cpp)
add_executable(exec11-14 exec11-14.cpp)
add_executable(exec11-15 exec11-15.cpp)
add_executable(exec11-16 exec11-16.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
add_output_test(
  NAME output_integer_in_different_bases_test
  COMMAND output_integer_in_different_bases
  OUTPUT_FILE ${TESTDATA_DIR}/output_integer_in_different_bases_output.txt
)
foreach(i RANGE 1 2)
  add_output_test(
    NAME input_integer_in_different_bases_test${i}
    COMMAND input_integer_in_different_bases
    OUTPUT_FILE ${TESTDATA_DIR}/input_integer_in_different_bases_output${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/input_integer_in_different_bases_input${i}.txt
  )
endforeach()
add_output_test(
  NAME output_float_in_different_formats_test
  COMMAND output_float_in_different_formats
  OUTPUT_FILE ${TESTDATA_DIR}/output_float_in_different_formats_output.txt
)
add_output_test(
  NAME set_precision_test
  COMMAND set_precision
  OUTPUT_FILE ${TESTDATA_DIR}/set_precision_output.txt
)
add_output_test(
  NAME set_field_width_test
  COMMAND set_field_width
  OUTPUT_FILE ${TESTDATA_DIR}/set_field_width_output.txt
)
add_output_test(
  NAME print_contact_table_test
  COMMAND print_contact_table
  OUTPUT_FILE ${TESTDATA_DIR}/print_contact_table_output.txt
)
add_file_test(
  NAME read_write_binary_file_test
  COMMAND read_write_binary_file ${TESTDATA_DIR}/integers.bin
    ${CMAKE_CURRENT_BINARY_DIR}/read_write_binary_file.bin
  OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/read_write_binary_file.bin
  COMPARE_FILE ${TESTDATA_DIR}/integers.bin
)
add_gtest(NAME str_to_double_test SOURCE str_to_double_test.cpp LIBRARY str_to_double)
add_gtest(NAME punct_stream_test SOURCE punct_stream_test.cpp LIBRARY punct_stream)
add_output_test(
  NAME custom_separator_dictionary_test
  COMMAND custom_separator_dictionary
  OUTPUT_FILE ${TESTDATA_DIR}/custom_separator_dictionary_output.txt
  INPUT_FILE ${TESTDATA_DIR}/custom_separator_dictionary_input.txt
)
add_file_test(
  NAME exec11-1_test
  COMMAND exec11-1 ${TESTDATA_DIR}/exec11-1_input.txt ${CMAKE_CURRENT_BINARY_DIR}/exec11-1_output.txt
  OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/exec11-1_output.txt
  COMPARE_FILE ${TESTDATA_DIR}/exec11-1_output.txt
)
foreach(w IN ITEMS to;himself;nosuchword)
  add_output_test(
    NAME exec11-2_test_${w}
    COMMAND exec11-2 ${CMAKE_SOURCE_DIR}/ch10/testdata/to_be_or_not_to_be.txt ${w}
    OUTPUT_FILE ${TESTDATA_DIR}/exec11-2_output_${w}.txt
  )
endforeach()
add_output_test(
  NAME exec11-3_test
  COMMAND exec11-3
  OUTPUT_FILE ${TESTDATA_DIR}/exec11-3_output.txt
  INPUT_FILE ${TESTDATA_DIR}/exec11-3_input.txt
)
add_output_test(
  NAME exec11-4_test
  COMMAND exec11-4
  OUTPUT_FILE ${TESTDATA_DIR}/exec11-4_output.txt
  INPUT_FILE ${TESTDATA_DIR}/exec11-4_input.txt
)
add_output_test(
  NAME exec11-5_test
  COMMAND exec11-5
  OUTPUT_FILE ${TESTDATA_DIR}/exec11-5_output.txt
  INPUT_FILE ${TESTDATA_DIR}/exec11-5_input.txt
)
add_gtest(NAME punct_stream_v2_test SOURCE punct_stream_v2_test.cpp LIBRARY punct_stream_v2)
add_output_test(
  NAME custom_separator_dictionary_v2_test
  COMMAND custom_separator_dictionary_v2
  OUTPUT_FILE ${TESTDATA_DIR}/custom_separator_dictionary_v2_output.txt
  INPUT_FILE ${TESTDATA_DIR}/custom_separator_dictionary_v2_input.txt
)
add_gtest(NAME split_test SOURCE split_test.cpp LIBRARY split)
add_output_test(
  NAME exec11-12_test
  COMMAND exec11-12
  OUTPUT_FILE ${TESTDATA_DIR}/exec11-12_output.txt
  INPUT_FILE ${TESTDATA_DIR}/exec11-12_input.txt
)
add_output_test(
  NAME exec11-13_test
  COMMAND exec11-13
  OUTPUT_FILE ${TESTDATA_DIR}/exec11-13_output.txt
  INPUT_FILE ${TESTDATA_DIR}/exec11-13_input.txt
)
add_output_test(
  NAME exec11-14_test
  COMMAND exec11-14
  OUTPUT_FILE ${TESTDATA_DIR}/exec11-14_output.txt
  INPUT_FILE ${TESTDATA_DIR}/exec11-14_input.txt
)
add_output_test(
  NAME exec11-15_test
  COMMAND exec11-15
  OUTPUT_FILE ${TESTDATA_DIR}/exec11-15_output.txt
  INPUT_FILE ${TESTDATA_DIR}/exec11-15_input.txt
)
add_output_test(
  NAME exec11-16_test
  COMMAND exec11-16
  OUTPUT_FILE ${TESTDATA_DIR}/exec11-16_output.txt
  INPUT_FILE ${TESTDATA_DIR}/exec11-16_input.txt
)
