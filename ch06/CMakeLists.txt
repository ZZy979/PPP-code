add_executable(calculator_v0 calculator_v0.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
foreach(i RANGE 1 5)
  add_output_test(
    NAME calculator_v0_test${i}
    COMMAND calculator_v0
    OUTPUT_FILE ${TESTDATA_DIR}/calculator_v0_output${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/calculator_v0_input${i}.txt
  )
endforeach()
