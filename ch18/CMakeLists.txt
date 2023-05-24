add_library(simple_vector_v2 simple_vector.cpp)
add_executable(debug_ctor_dtor debug_ctor_dtor.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
add_gtest(NAME simple_vector_v2_test SOURCE simple_vector_test.cpp LIBRARY simple_vector_v2)
