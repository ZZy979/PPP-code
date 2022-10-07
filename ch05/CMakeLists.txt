add_library(area area.cpp)
add_executable(temperature_stats_buggy temperature_stats_buggy.cpp)
add_executable(temperature_stats_fixed temperature_stats_fixed.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
add_gtest(NAME area_test SOURCE area_test.cpp LIBRARY area)
foreach(s IN ITEMS buggy;fixed)
  foreach(i IN ITEMS 20040216;20040723;negative)
    add_output_test(
      NAME temperature_stats_${s}_test_${i}
      COMMAND temperature_stats_${s}
      OUTPUT_FILE ${TESTDATA_DIR}/temperature_stats_${s}_output_${i}.txt
      INPUT_FILE ${TESTDATA_DIR}/Lubbock_temperatures_${i}.txt
    )
  endforeach()
endforeach()
