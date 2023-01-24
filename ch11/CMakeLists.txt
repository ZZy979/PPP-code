add_executable(output_integer_in_different_bases output_integer_in_different_bases.cpp)
add_executable(input_integer_in_different_bases input_integer_in_different_bases.cpp)
add_executable(output_float_in_different_formats output_float_in_different_formats.cpp)
add_executable(set_precision set_precision.cpp)
add_executable(set_field_width set_field_width.cpp)
add_executable(read_write_binary_file read_write_binary_file.cpp)
add_library(str_to_double str_to_double.cpp)

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
add_file_test(
  NAME read_write_binary_file_test
  COMMAND read_write_binary_file ${TESTDATA_DIR}/integers.bin
    ${CMAKE_CURRENT_BINARY_DIR}/read_write_binary_file.bin
  OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/read_write_binary_file.bin
  COMPARE_FILE ${TESTDATA_DIR}/integers.bin
)
add_gtest(NAME str_to_double_test SOURCE str_to_double_test.cpp LIBRARY str_to_double)
