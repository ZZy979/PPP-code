add_library(lexer lexer.cpp)
add_library(parser parser.cpp)
target_link_libraries(parser PUBLIC lexer)
add_executable(calculator_v1 main.cpp)
target_link_libraries(calculator_v1 lexer parser)

add_gtest(NAME lexer_test SOURCE lexer_test.cpp LIBRARY lexer)
add_gtest(NAME parser_test SOURCE parser_test.cpp LIBRARY parser)
