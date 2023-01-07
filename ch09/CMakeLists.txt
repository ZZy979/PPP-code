add_library(Chrono Chrono.cpp)
add_gtest(NAME Chrono_test SOURCE Chrono_test.cpp LIBRARY Chrono)
