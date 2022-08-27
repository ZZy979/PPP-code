add_executable(convert_length_unit convert_length_unit.cpp)
add_executable(convert_currency convert_currency.cpp)
add_executable(convert_length_unit_v2 convert_length_unit_v2.cpp)
add_executable(convert_currency_v2 convert_currency_v2.cpp)
add_executable(print_squares_table print_squares_table.cpp)
add_executable(print_character_table print_character_table.cpp)
add_executable(print_squares_table_v2 print_squares_table_v2.cpp)
add_executable(print_character_table_v2 print_character_table_v2.cpp)

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
