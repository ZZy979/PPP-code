cmake_minimum_required(VERSION 3.20)
project(PPP_code)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

# 添加一个测试，将命令的标准输出与指定文件比较
# 用法：add_test_output_file(NAME <name> COMMAND <command> [<arg>...] OUTPUT_FILE <file>)
function(add_test_output_file)
  cmake_parse_arguments("TEST" "" "NAME;OUTPUT_FILE" "COMMAND" ${ARGN})
  set(ACTUAL_OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/${TEST_NAME}_output.txt)
  list(GET TEST_COMMAND 0 TARGET_NAME)
  add_custom_command(
    TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${TEST_COMMAND} > ${ACTUAL_OUTPUT_FILE}
  )
  # TODO 尝试fixture方法
  add_test(
    NAME ${TEST_NAME}
    COMMAND ${CMAKE_COMMAND} -E compare_files --ignore-eol ${TEST_OUTPUT_FILE} ${ACTUAL_OUTPUT_FILE}
  )
endfunction()

add_subdirectory(ch02)
