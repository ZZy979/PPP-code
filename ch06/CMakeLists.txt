add_executable(calculator_v0 calculator_v0.cpp)
add_subdirectory(calculator_v1)
add_executable(exec6-4 exec6-4.cpp)
add_executable(exec6-9 exec6-9.cpp)
add_executable(exec6-10 exec6-10.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
foreach(i RANGE 1 5)
  add_output_test(
    NAME calculator_v0_test${i}
    COMMAND calculator_v0
    OUTPUT_FILE ${TESTDATA_DIR}/calculator_v0_output${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/calculator_v0_input${i}.txt
  )
endforeach()
add_output_test(
  NAME exec6-4_test
  COMMAND exec6-4
  OUTPUT_FILE ${CMAKE_SOURCE_DIR}/ch04/testdata/exec4-21_output.txt
  INPUT_FILE ${CMAKE_SOURCE_DIR}/ch04/testdata/exec4-21_input.txt
)
add_output_test(
  NAME exec6-9_test
  COMMAND exec6-9
  OUTPUT_FILE ${TESTDATA_DIR}/exec6-9_output.txt
  INPUT_FILE ${TESTDATA_DIR}/exec6-9_input.txt
)
add_output_test(
  NAME exec6-10_test
  COMMAND exec6-10
  OUTPUT_FILE ${TESTDATA_DIR}/exec6-10_output.txt
  INPUT_FILE ${TESTDATA_DIR}/exec6-10_input.txt
)
