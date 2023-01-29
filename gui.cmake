# 获取FLTK库，用于第12~16章的GUI程序
set(FLTK_BUILD_TEST OFF CACHE BOOL " " FORCE)
FetchContent_Declare(
  fltk
  GIT_REPOSITORY https://github.com/fltk/fltk.git
  GIT_TAG release-1.3.8
)
FetchContent_MakeAvailable(fltk)

if(WIN32)
  set(GUI_TYPE WIN32)
elseif(APPLE)
  set(GUI_TYPE MACOSX_BUNDLE)
else()
  set(GUI_TYPE)
endif()

# 添加一个GUI可执行程序并链接到FLTK库，用法：
# add_fltk_executable(<name> <source>...)
function(add_fltk_executable name)
  add_executable(${name} ${GUI_TYPE} ${ARGN})
  target_include_directories(${name} PRIVATE ${fltk_SOURCE_DIR} ${fltk_BINARY_DIR})
  target_link_libraries(${name} fltk)
endfunction()

# 添加一个GUI可执行程序并链接到GUI库，用法：
# add_gui_executable(<name> <source>...)
function(add_gui_executable name)
  add_executable(${name} ${GUI_TYPE} ${ARGN})
  target_link_libraries(${name} GUI)
endfunction()
