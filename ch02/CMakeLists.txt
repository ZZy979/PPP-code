add_executable(hello_world hello_world.cpp)
add_executable(exec1 exec1.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
add_test_output(
  NAME hello_world_test
  COMMAND hello_world
  OUTPUT_FILE ${TESTDATA_DIR}/hello_world_output.txt
)
add_test_output(
  NAME exec1_test
  COMMAND exec1
  OUTPUT_FILE ${TESTDATA_DIR}/exec1_output.txt
)
