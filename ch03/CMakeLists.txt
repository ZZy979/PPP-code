add_executable(read_and_write_first_name read_and_write_first_name.cpp)
add_executable(read_name_and_age read_name_and_age.cpp)
add_executable(read_name_and_age_v2 read_name_and_age_v2.cpp)
add_executable(read_full_name read_full_name.cpp)
add_executable(read_name_and_age_v3 read_name_and_age_v3.cpp)
add_executable(double_operators double_operators.cpp)
add_executable(integer_operators integer_operators.cpp)
add_executable(read_full_name_v2 read_full_name_v2.cpp)
add_executable(read_and_compare_names read_and_compare_names.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
add_test_output(
  NAME read_and_write_first_name_test
  COMMAND read_and_write_first_name
  OUTPUT_FILE ${TESTDATA_DIR}/read_and_write_first_name_output.txt
  INPUT_FILE ${TESTDATA_DIR}/first_name.txt
)
add_test_output(
  NAME read_name_and_age_test
  COMMAND read_name_and_age
  OUTPUT_FILE ${TESTDATA_DIR}/read_name_and_age_output.txt
  INPUT_FILE ${TESTDATA_DIR}/name_and_age.txt
)
add_test_output(
  NAME read_name_and_age_v2_test_success
  COMMAND read_name_and_age_v2
  OUTPUT_FILE ${TESTDATA_DIR}/read_name_and_age_output.txt
  INPUT_FILE ${TESTDATA_DIR}/name_and_age.txt
)
add_test_output(
  NAME read_name_and_age_v2_test_wrong_age
  COMMAND read_name_and_age_v2
  OUTPUT_FILE ${TESTDATA_DIR}/read_name_and_age_v2_output_wrong_age.txt
  INPUT_FILE ${TESTDATA_DIR}/age_and_name.txt
)
add_test_output(
  NAME read_name_and_age_v2_test_no_age
  COMMAND read_name_and_age_v2
  OUTPUT_FILE ${TESTDATA_DIR}/read_name_and_age_v2_output_no_age.txt
  INPUT_FILE ${TESTDATA_DIR}/first_name.txt
)
add_test_output(
  NAME read_name_and_age_v2_test_no_input
  COMMAND read_name_and_age_v2
  OUTPUT_FILE ${TESTDATA_DIR}/read_name_and_age_v2_output_no_input.txt
)
add_test_output(
  NAME read_full_name_test
  COMMAND read_full_name
  OUTPUT_FILE ${TESTDATA_DIR}/read_full_name_output.txt
  INPUT_FILE ${TESTDATA_DIR}/full_name.txt
)
add_test_output(
  NAME read_name_and_age_v3_test
  COMMAND read_name_and_age_v3
  OUTPUT_FILE ${TESTDATA_DIR}/read_name_and_age_v3_output.txt
  INPUT_FILE ${TESTDATA_DIR}/name_and_age_double.txt
)
add_test_output(
  NAME double_operators_test
  COMMAND double_operators
  OUTPUT_FILE ${TESTDATA_DIR}/double_operators_output.txt
  INPUT_FILE ${TESTDATA_DIR}/pi.txt
)
add_test_output(
  NAME integer_operators_test
  COMMAND integer_operators
  OUTPUT_FILE ${TESTDATA_DIR}/integer_operators_output.txt
  INPUT_FILE ${TESTDATA_DIR}/five.txt
)
add_test_output(
  NAME read_full_name_v2_test
  COMMAND read_full_name_v2
  OUTPUT_FILE ${TESTDATA_DIR}/read_full_name_output.txt
  INPUT_FILE ${TESTDATA_DIR}/full_name.txt
)
add_test_output(
  NAME read_and_compare_names_test_equal
  COMMAND read_and_compare_names
  OUTPUT_FILE ${TESTDATA_DIR}/read_and_compare_names_output_equal.txt
  INPUT_FILE ${TESTDATA_DIR}/twice_name.txt
)
add_test_output(
  NAME read_and_compare_names_test_less
  COMMAND read_and_compare_names
  OUTPUT_FILE ${TESTDATA_DIR}/read_and_compare_names_output_less.txt
  INPUT_FILE ${TESTDATA_DIR}/full_name.txt
)
add_test_output(
  NAME read_and_compare_names_test_greater
  COMMAND read_and_compare_names
  OUTPUT_FILE ${TESTDATA_DIR}/read_and_compare_names_output_greater.txt
  INPUT_FILE ${TESTDATA_DIR}/full_name2.txt
)
