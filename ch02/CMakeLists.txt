add_executable(hello_world hello_world.cpp)
add_executable(exec2-1 exec2-1.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
add_output_test(
  NAME hello_world_test
  COMMAND hello_world
  OUTPUT_FILE ${TESTDATA_DIR}/hello_world_output.txt
)
add_output_test(
  NAME exec2-1_test
  COMMAND exec2-1
  OUTPUT_FILE ${TESTDATA_DIR}/exec2-1_output.txt
)
