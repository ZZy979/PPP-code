add_executable(convert_length_unit convert_length_unit.cpp)
add_executable(convert_currency convert_currency.cpp)
add_executable(convert_length_unit_switch convert_length_unit_switch.cpp)
add_executable(convert_currency_switch convert_currency_switch.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
foreach(target IN ITEMS convert_length_unit;convert_length_unit_switch)
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
    NAME convert_currency_switch_test_${i}
    COMMAND convert_currency_switch
    OUTPUT_FILE ${TESTDATA_DIR}/convert_currency_switch_output_${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/currency_${i}.txt
  )
endforeach()
