cmake_minimum_required(VERSION 3.20)
project(PPP_code)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

# 添加一个测试，将命令的标准输出与指定文件比较
# 用法：add_output_test(NAME <name> COMMAND <command> [<arg>...] [OUTPUT_FILE <output_file>] [INPUT_FILE <input_file>])
function(add_output_test)
  cmake_parse_arguments("TEST" "" "NAME;OUTPUT_FILE;INPUT_FILE" "COMMAND" ${ARGN})
  list(POP_FRONT TEST_COMMAND TARGET_NAME)
  set(ACTUAL_OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/${TEST_NAME}_output.txt)
  if(NOT TEST_OUTPUT_FILE)
    set(TEST_OUTPUT_FILE "$<IF:$<BOOL:${WIN32}>,NUL,/dev/null>")
  endif()
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

# 添加一个GoogleTest
# 用法：add_gtest(NAME <name> SOURCE <source_file> [LIBRARY <library>] [GMOCK])
function(add_gtest)
  cmake_parse_arguments("TEST" "GMOCK" "NAME;SOURCE;LIBRARY" "" ${ARGN})
  add_executable(${TEST_NAME} ${TEST_SOURCE})
  set(GTEST_LIBRARY $<IF:$<BOOL:${TEST_GMOCK}>,GTest::gmock_main,GTest::gtest_main>)
  target_link_libraries(${TEST_NAME} ${GTEST_LIBRARY} ${TEST_LIBRARY})
  gtest_add_tests(TARGET ${TEST_NAME})
endfunction()

file(GLOB CHAPTERS RELATIVE ${CMAKE_SOURCE_DIR} ch*)
foreach(c IN ITEMS ${CHAPTERS})
  add_subdirectory(${c})
endforeach()
