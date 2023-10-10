add_library(email_message email_message.cpp)
add_executable(find_email find_email.cpp)
target_link_libraries(find_email email_message)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
add_gtest(NAME string_convert_test SOURCE string_convert_test.cpp)
add_output_test(
  NAME find_email_test
  COMMAND find_email ${TESTDATA_DIR}/example.eml "John Doe <jdoe@machine.example>"
  OUTPUT_FILE ${TESTDATA_DIR}/find_email_output.txt
)
