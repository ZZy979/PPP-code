add_library(email_message email_message.cpp)
add_executable(find_email find_email.cpp)
target_link_libraries(find_email email_message)
add_executable(find_postal_codes find_postal_codes.cpp)
add_executable(test_regex test_regex.cpp)
add_executable(verify_table verify_table.cpp)
add_executable(find_email_v2 find_email_v2.cpp)
target_link_libraries(find_email_v2 email_message)
add_executable(exec23-6 exec23-6.cpp)
add_executable(exec23-8 exec23-8.cpp)
add_executable(exec23-10 exec23-10.cpp)
add_executable(exec23-12 exec23-12.cpp)
add_executable(exec23-13 exec23-13.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
add_gtest(NAME string_convert_test SOURCE string_convert_test.cpp)
add_output_test(
  NAME find_email_test1
  COMMAND find_email ${TESTDATA_DIR}/example.eml "John Doe <jdoe@machine.example>"
  OUTPUT_FILE ${TESTDATA_DIR}/find_email_output1.txt
)
add_output_test(
  NAME find_email_test2
  COMMAND find_email ${TESTDATA_DIR}/test.eml "Alice <alice@example.com>"
  OUTPUT_FILE ${TESTDATA_DIR}/find_email_output2.txt
)
add_output_test(
  NAME find_email_test3
  COMMAND find_email "${CMAKE_SOURCE_DIR}/ch21/testdata/Alice's Adventures in Wonderland.txt" "Alice <alice@example.com>"
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
add_output_test(
  NAME find_email_v2_test1
  COMMAND find_email_v2 ${TESTDATA_DIR}/test.eml
  OUTPUT_FILE ${TESTDATA_DIR}/find_email_v2_output1.txt
)
add_output_test(
  NAME find_email_v2_test2
  COMMAND find_email_v2 -sa bob@example.com ${TESTDATA_DIR}/test.eml
  OUTPUT_FILE ${TESTDATA_DIR}/find_email_v2_output2.txt
)
add_output_test(
  NAME find_email_v2_test3
  COMMAND find_email_v2 -s Meeting ${TESTDATA_DIR}/test.eml
  OUTPUT_FILE ${TESTDATA_DIR}/find_email_v2_output3.txt
)
add_output_test(
  NAME find_email_v2_test4
  COMMAND find_email_v2 -rn Alice -s Re: ${TESTDATA_DIR}/test.eml
  OUTPUT_FILE ${TESTDATA_DIR}/find_email_v2_output4.txt
)
add_output_test(
  NAME find_email_v2_test5
  COMMAND find_email_v2 -sn Eric -ra dale@example.com -s Camping ${TESTDATA_DIR}/test.eml
  OUTPUT_FILE ${TESTDATA_DIR}/find_email_v2_output5.txt
)
add_output_test(
  NAME exec23-6_test
  COMMAND exec23-6 ${TESTDATA_DIR}/exec23-6_input.txt
  OUTPUT_FILE ${TESTDATA_DIR}/exec23-6_output.txt
)
add_output_test(
  NAME exec23-8_test1
  COMMAND exec23-8 "\\w{2}\\s*\\d{5}(-\\d{4})?" ${TESTDATA_DIR}/test_regex_input1.txt
  OUTPUT_FILE ${TESTDATA_DIR}/exec23-8_output1.txt
)
add_output_test(
  NAME exec23-8_test2
  COMMAND exec23-8 "abc" ${TESTDATA_DIR}/test_regex_input2.txt
  OUTPUT_FILE ${TESTDATA_DIR}/exec23-8_output2.txt
)
add_output_test(
  NAME exec23-8_test3
  COMMAND exec23-8 "x+" ${TESTDATA_DIR}/test_regex_input2.txt
)
add_file_test(
  NAME exec23-10_test
  COMMAND exec23-10 ${TESTDATA_DIR}/table.txt ${CMAKE_CURRENT_BINARY_DIR}/exec23-10_output.txt
  OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/exec23-10_output.txt
  COMPARE_FILE ${TESTDATA_DIR}/exec23-10_output.txt
)
# gcc 12.1以下的std::get_time()有bug：https://gcc.gnu.org/bugzilla/show_bug.cgi?id=45896
if(MSVC OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 12.1)
  add_output_test(
    NAME exec23-12_test
    COMMAND exec23-12 ${TESTDATA_DIR}/exec23-6_input.txt
    OUTPUT_FILE ${TESTDATA_DIR}/exec23-12_output.txt
  )
endif()
add_output_test(
  NAME exec23-13_test
  COMMAND exec23-13
  OUTPUT_FILE ${TESTDATA_DIR}/exec23-13_output.txt
)
