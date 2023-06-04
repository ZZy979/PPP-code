add_library(simple_vector_v3 simple_vector.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
add_gtest(NAME simple_vector_v3_test SOURCE simple_vector_test.cpp LIBRARY simple_vector_v3)
