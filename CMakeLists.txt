cmake_minimum_required(VERSION 3.20)
project(PPP_code)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

# 添加一个测试，将命令的标准输出与指定文件比较
# 用法：add_test_output(NAME <name> COMMAND <command> [<arg>...] OUTPUT_FILE <output_file> [INPUT_FILE <input_file>])
function(add_test_output)
  cmake_parse_arguments("TEST" "" "NAME;OUTPUT_FILE;INPUT_FILE" "COMMAND" ${ARGN})
  list(POP_FRONT TEST_COMMAND TARGET_NAME)
  set(ACTUAL_OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/${TEST_NAME}_output.txt)
  if(NOT TEST_INPUT_FILE)
    set(TEST_INPUT_FILE "$<IF:$<BOOL:${WIN32}>,NUL,/dev/null>")
  endif()

  add_test(
    NAME ${TEST_NAME}_run
    COMMAND ${CMAKE_COMMAND} -P ${PPP_code_SOURCE_DIR}/run_test.cmake
    $<TARGET_FILE:${TARGET_NAME}> ${ACTUAL_OUTPUT_FILE} ${TEST_INPUT_FILE} ${TEST_COMMAND}
  )
  add_test(
    NAME ${TEST_NAME}_compare
    COMMAND ${CMAKE_COMMAND} -E compare_files --ignore-eol ${TEST_OUTPUT_FILE} ${ACTUAL_OUTPUT_FILE}
  )
  add_test(
    NAME ${TEST_NAME}_cleanup
    COMMAND ${CMAKE_COMMAND} -E rm ${ACTUAL_OUTPUT_FILE}
  )
  set_tests_properties(${TEST_NAME}_run PROPERTIES FIXTURES_SETUP ${TEST_NAME}_output)
  set_tests_properties(${TEST_NAME}_compare PROPERTIES FIXTURES_REQUIRED ${TEST_NAME}_output)
  set_tests_properties(${TEST_NAME}_cleanup PROPERTIES FIXTURES_CLEANUP ${TEST_NAME}_output)
endfunction()

add_subdirectory(ch02)
