add_library(area area.cpp)

add_gtest(NAME area_test SOURCE area_test.cpp LIBRARY area)
