add_library(lines_window lines_window.cpp)
target_link_libraries(lines_window GUI)
add_gui_executable(draw_lines draw_lines.cpp)
target_link_libraries(draw_lines lines_window)
