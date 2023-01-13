add_executable(temperature_readings temperature_readings.cpp)
add_library(fill_vector fill_vector.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
# 为了使用文件绝对路径，temperature_readings的标准输入文件必须由CMake动态生成，太麻烦了……
add_gtest(NAME fill_vector_test SOURCE fill_vector_test.cpp LIBRARY fill_vector)
