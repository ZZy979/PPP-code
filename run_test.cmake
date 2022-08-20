# 运行测试，输出到指定的文件
# cmake -P run_test.cmake <command> <output_file> <input_file> [<arg>...]
foreach(i RANGE 6 ${CMAKE_ARGC})
  list(APPEND ARGS ${CMAKE_ARGV${i}})
endforeach()
execute_process(
  COMMAND ${CMAKE_ARGV3} ${ARGS}
  INPUT_FILE ${CMAKE_ARGV5}
  OUTPUT_FILE ${CMAKE_ARGV4}
  ERROR_FILE ${CMAKE_ARGV4}
  COMMAND_ERROR_IS_FATAL ANY
)
