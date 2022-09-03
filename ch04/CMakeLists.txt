add_executable(convert_length_unit convert_length_unit.cpp)
add_executable(convert_currency convert_currency.cpp)
add_executable(convert_length_unit_v2 convert_length_unit_v2.cpp)
add_executable(convert_currency_v2 convert_currency_v2.cpp)
add_executable(print_squares_table print_squares_table.cpp)
add_executable(print_character_table print_character_table.cpp)
add_executable(print_squares_table_v2 print_squares_table_v2.cpp)
add_executable(print_character_table_v2 print_character_table_v2.cpp)
add_executable(mean_median_temperature mean_median_temperature.cpp)
add_executable(simple_dictionary simple_dictionary.cpp)
add_executable(bleep_disliked_words bleep_disliked_words.cpp)
add_executable(length_statistics length_statistics.cpp)
add_executable(exec4-3 exec4-3.cpp)
add_executable(exec4-4 exec4-4.cpp)
add_executable(exec4-5 exec4-5.cpp)
add_executable(exec4-6 exec4-6.cpp)
add_executable(exec4-9 exec4-9.cpp)
add_executable(exec4-10 exec4-10.cpp)
add_executable(exec4-12 exec4-12.cpp)
add_executable(exec4-14 exec4-14.cpp)
add_executable(exec4-16 exec4-16.cpp)
add_executable(exec4-17 exec4-17.cpp)
add_executable(exec4-18 exec4-18.cpp)
add_executable(exec4-21 exec4-21.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
foreach(target IN ITEMS convert_length_unit;convert_length_unit_v2)
  foreach(i IN ITEMS cm;inch;feet)
    add_test_output(
      NAME ${target}_test_${i}
      COMMAND ${target}
      OUTPUT_FILE ${TESTDATA_DIR}/convert_length_unit_output_${i}.txt
      INPUT_FILE ${TESTDATA_DIR}/length_in_${i}.txt
    )
  endforeach()
endforeach()
foreach(i IN ITEMS yen;euro;pound;yuan)
  add_test_output(
    NAME convert_currency_test_${i}
    COMMAND convert_currency
    OUTPUT_FILE ${TESTDATA_DIR}/convert_currency_output_${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/currency_${i}.txt
  )
endforeach()
foreach(i IN ITEMS yen;euro;pound;yuan;kroner;baht)
  add_test_output(
    NAME convert_currency_v2_test_${i}
    COMMAND convert_currency_v2
    OUTPUT_FILE ${TESTDATA_DIR}/convert_currency_v2_output_${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/currency_${i}.txt
  )
endforeach()
  foreach(target IN ITEMS print_squares_table;print_squares_table_v2)
  add_test_output(
    NAME ${target}_test
    COMMAND ${target}
    OUTPUT_FILE ${TESTDATA_DIR}/squares_table.txt
  )
endforeach()
add_test_output(
  NAME print_character_table_test
  COMMAND print_character_table
  OUTPUT_FILE ${TESTDATA_DIR}/character_table.txt
)
add_test_output(
  NAME print_character_table_v2_test
  COMMAND print_character_table_v2
  OUTPUT_FILE ${TESTDATA_DIR}/character_table_v2.txt
)
foreach(i RANGE 1 3)
  add_test_output(
    NAME mean_median_temperature_test${i}
    COMMAND mean_median_temperature
    OUTPUT_FILE ${TESTDATA_DIR}/mean_median_temperature_output${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/temperatures${i}.txt
  )
endforeach()
add_test_output(
  NAME simple_dictionary_test
  COMMAND simple_dictionary
  OUTPUT_FILE ${TESTDATA_DIR}/simple_dictionary_output.txt
  INPUT_FILE ${TESTDATA_DIR}/simple_dictionary_input.txt
)
add_test_output(
  NAME bleep_disliked_words_test
  COMMAND bleep_disliked_words
  OUTPUT_FILE ${TESTDATA_DIR}/bleep_disliked_words_output.txt
  INPUT_FILE ${TESTDATA_DIR}/bleep_disliked_words_input.txt
)
add_test_output(
  NAME length_statistics_test
  COMMAND length_statistics
  OUTPUT_FILE ${TESTDATA_DIR}/length_statistics_output.txt
  INPUT_FILE ${TESTDATA_DIR}/length_statistics_input.txt
)
foreach(i RANGE 1 3)
  add_test_output(
    NAME exec4-3_test${i}
    COMMAND exec4-3
    OUTPUT_FILE ${TESTDATA_DIR}/exec4-3_output${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/temperatures${i}.txt
  )
endforeach()
foreach(i RANGE 1 5)
  add_test_output(
    NAME exec4-4_test${i}
    COMMAND exec4-4
    OUTPUT_FILE ${TESTDATA_DIR}/exec4-4_output${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/exec4-4_input${i}.txt
  )
endforeach()
foreach(i RANGE 1 6)
  add_test_output(
    NAME exec4-5_test${i}
    COMMAND exec4-5
    OUTPUT_FILE ${TESTDATA_DIR}/exec4-5_output${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/exec4-5_input${i}.txt
  )
endforeach()
add_test_output(
  NAME exec4-6_test1
  COMMAND exec4-6
  OUTPUT_FILE ${TESTDATA_DIR}/seven.txt
  INPUT_FILE ${TESTDATA_DIR}/7.txt
)
add_test_output(
  NAME exec4-6_test2
  COMMAND exec4-6
  OUTPUT_FILE ${TESTDATA_DIR}/7.txt
  INPUT_FILE ${TESTDATA_DIR}/seven.txt
)
add_test_output(
  NAME exec4-6_test3
  COMMAND exec4-6
  OUTPUT_FILE ${TESTDATA_DIR}/exec4-6_unknown.txt
  INPUT_FILE ${TESTDATA_DIR}/10.txt
)
add_test_output(
  NAME exec4-6_test4
  COMMAND exec4-6
  OUTPUT_FILE ${TESTDATA_DIR}/exec4-6_unknown.txt
  INPUT_FILE ${TESTDATA_DIR}/ten.txt
)
add_test_output(
  NAME exec4-9_test
  COMMAND exec4-9
  OUTPUT_FILE ${TESTDATA_DIR}/exec4-9_output.txt
)
add_test_output(
  NAME exec4-10_test
  COMMAND exec4-10
  OUTPUT_FILE ${TESTDATA_DIR}/exec4-10_output.txt
  INPUT_FILE ${TESTDATA_DIR}/exec4-10_input.txt
)
add_test_output(
  NAME exec4-12_test
  COMMAND exec4-12
  OUTPUT_FILE ${TESTDATA_DIR}/primes.txt
  INPUT_FILE ${TESTDATA_DIR}/100.txt
)
add_test_output(
  NAME exec4-14_test
  COMMAND exec4-14
  OUTPUT_FILE ${TESTDATA_DIR}/primes.txt
  INPUT_FILE ${TESTDATA_DIR}/100.txt
)
add_test_output(
  NAME exec4-16_test
  COMMAND exec4-16
  OUTPUT_FILE ${TESTDATA_DIR}/exec4-16_output.txt
  INPUT_FILE ${TESTDATA_DIR}/exec4-16_input.txt
)
add_test_output(
  NAME exec4-16_test_empty
  COMMAND exec4-16
  OUTPUT_FILE ${TESTDATA_DIR}/empty_sequence.txt
)
add_test_output(
  NAME exec4-17_test
  COMMAND exec4-17
  OUTPUT_FILE ${TESTDATA_DIR}/exec4-17_output.txt
  INPUT_FILE ${TESTDATA_DIR}/exec4-17_input.txt
)
add_test_output(
  NAME exec4-17_test_empty
  COMMAND exec4-17
  OUTPUT_FILE ${TESTDATA_DIR}/empty_sequence.txt
)
foreach(i RANGE 1 3)
  add_test_output(
    NAME exec4-18_test${i}
    COMMAND exec4-18
    OUTPUT_FILE ${TESTDATA_DIR}/exec4-18_output${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/exec4-18_input${i}.txt
  )
endforeach()
add_test_output(
  NAME exec4-21_test
  COMMAND exec4-21
  OUTPUT_FILE ${TESTDATA_DIR}/exec4-21_output.txt
  INPUT_FILE ${TESTDATA_DIR}/exec4-21_input.txt
)
