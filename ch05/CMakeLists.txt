add_library(area area.cpp)
add_executable(temperature_stats_buggy temperature_stats_buggy.cpp)
add_executable(temperature_stats_fixed temperature_stats_fixed.cpp)
add_library(temperature_converters temperature_converters.cpp)
add_library(solve_equation solve_equation.cpp)
add_executable(sum_n_integers sum_n_integers.cpp)
add_executable(fibonacci_series fibonacci_series.cpp)
add_executable(bulls_and_cows bulls_and_cows.cpp)

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
add_gtest(NAME temperature_converters_test SOURCE temperature_converters_test.cpp LIBRARY temperature_converters)
add_gtest(NAME solve_equation_test SOURCE solve_equation_test.cpp LIBRARY solve_equation)
foreach(i RANGE 1 2)
  add_output_test(
    NAME sum_n_integers_test${i}
    COMMAND sum_n_integers
    OUTPUT_FILE ${TESTDATA_DIR}/sum_n_integers_output${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/sum_n_integers_input${i}.txt
  )
endforeach()
add_output_test(
  NAME fibonacci_series_test
  COMMAND fibonacci_series
  OUTPUT_FILE ${TESTDATA_DIR}/fibonacci_series_output.txt
)
