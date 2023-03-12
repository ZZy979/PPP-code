add_executable(overriding_example overriding_example.cpp)
add_executable(drill14 drill14.cpp)
add_library(exec14_graph exec14_graph.cpp)
target_link_libraries(exec14_graph GUI exec12_graph exec13_graph)
foreach(i IN ITEMS 1;11)
  add_gui_executable(exec14-${i} exec14-${i}.cpp)
  target_link_libraries(exec14-${i} exec14_graph)
endforeach()
add_library(iterator iterator.cpp)
add_library(controller controller.cpp)
target_link_libraries(controller GUI)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
add_output_test(
  NAME overriding_example_test
  COMMAND overriding_example
  OUTPUT_FILE ${TESTDATA_DIR}/overriding_example_output.txt
)
add_output_test(
  NAME drill14_test
  COMMAND drill14
  OUTPUT_FILE ${TESTDATA_DIR}/drill14_output.txt
)
add_gtest(NAME iterator_test SOURCE iterator_test.cpp LIBRARY iterator)
add_gtest(NAME controller_test SOURCE controller_test.cpp LIBRARY controller)
