add_gui_executable(graphing_functions graphing_functions.cpp)
add_gui_executable(exp_approximation exp_approximation.cpp)
add_gui_executable(graphing_japanese_age graphing_japanese_age.cpp)
add_gui_executable(function_graphing_drill function_graphing_drill.cpp)
add_library(person person.cpp)
add_library(factorial factorial.cpp)
add_library(exec15_graph exec15_graph.cpp)
target_link_libraries(exec15_graph GUI)
add_gui_executable(exec15-2 exec15-2.cpp)
target_link_libraries(exec15-2 exec15_graph)
add_gui_executable(exec15-4 exec15-4.cpp)
add_gui_executable(exec15-5 exec15-5.cpp)
add_gui_executable(exec15-8 exec15-8.cpp)
target_link_libraries(exec15-8 exec15_graph)
add_gui_executable(exec15-11 exec15-11.cpp)

add_gtest(NAME person_test SOURCE person_test.cpp LIBRARY person)
add_gtest(NAME factorial_test SOURCE factorial_test.cpp LIBRARY factorial)
