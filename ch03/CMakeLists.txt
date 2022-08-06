add_executable(read_and_write_first_name read_and_write_first_name.cpp)
add_executable(read_name_and_age read_name_and_age.cpp)
add_executable(read_name_and_age_v2 read_name_and_age_v2.cpp)
add_executable(read_full_name read_full_name.cpp)
add_executable(read_name_and_age_v3 read_name_and_age_v3.cpp)

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
