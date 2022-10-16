add_library(lexer lexer.cpp)

add_gtest(NAME lexer_test SOURCE lexer_test.cpp LIBRARY lexer)
