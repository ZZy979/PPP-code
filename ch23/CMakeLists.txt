add_library(email_message email_message.cpp)
add_executable(find_email find_email.cpp)
target_link_libraries(find_email email_message)
add_executable(find_postal_codes find_postal_codes.cpp)
add_executable(test_regex test_regex.cpp)
add_executable(verify_table verify_table.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
add_gtest(NAME string_convert_test SOURCE string_convert_test.cpp)
add_output_test(
  NAME find_email_test
  COMMAND find_email ${TESTDATA_DIR}/example.eml "John Doe <jdoe@machine.example>"
  OUTPUT_FILE ${TESTDATA_DIR}/find_email_output.txt
)
add_output_test(
  NAME find_postal_codes_test
  COMMAND find_postal_codes ${TESTDATA_DIR}/find_postal_codes_input.txt
  OUTPUT_FILE ${TESTDATA_DIR}/find_postal_codes_output.txt
)
foreach(i RANGE 1 5)
  add_output_test(
    NAME test_regex_test${i}
    COMMAND test_regex
    OUTPUT_FILE ${TESTDATA_DIR}/test_regex_output${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/test_regex_input${i}.txt
  )
endforeach()
add_output_test(
  NAME verify_table_test
  COMMAND verify_table ${TESTDATA_DIR}/table.txt
  OUTPUT_FILE ${TESTDATA_DIR}/verify_table_output_ok.txt
)
