add_library(Matrix INTERFACE)
target_sources(Matrix PUBLIC FILE_SET HEADERS FILES Matrix.h MatrixIO.h)
target_include_directories(Matrix INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
