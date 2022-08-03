add_executable(hello_world hello_world.cpp)
add_executable(exec1 exec1.cpp)

add_test_output_file(
  NAME hello_world_test
  COMMAND hello_world
  OUTPUT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/testdata/hello_world_output.txt
)
add_test_output_file(
  NAME exec1_test
  COMMAND exec1
  OUTPUT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/testdata/exec1_output.txt
)
