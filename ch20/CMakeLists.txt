add_library(get_jack_and_jill_data get_jack_and_jill_data.cpp)
foreach(i RANGE 1 3)
  add_executable(jack_and_jill_v${i} jack_and_jill_v${i}.cpp)
  target_link_libraries(jack_and_jill_v${i} get_jack_and_jill_data)
endforeach()
add_library(copy copy.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
foreach(i RANGE 1 3)
  add_output_test(
    NAME jack_and_jill_v${i}_test
    COMMAND jack_and_jill_v${i}
    OUTPUT_FILE ${TESTDATA_DIR}/jack_and_jill_output.txt
    INPUT_FILE ${TESTDATA_DIR}/jack_and_jill.txt
  )
endforeach()
add_gtest(NAME copy_test SOURCE copy_test.cpp LIBRARY copy)
