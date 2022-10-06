add_executable(read_and_write_first_name read_and_write_first_name.cpp)
add_executable(read_name_and_age read_name_and_age.cpp)
add_executable(read_name_and_age_v2 read_name_and_age_v2.cpp)
add_executable(read_full_name read_full_name.cpp)
add_executable(read_name_and_age_v3 read_name_and_age_v3.cpp)
add_executable(double_operators double_operators.cpp)
add_executable(integer_operators integer_operators.cpp)
add_executable(read_full_name_v2 read_full_name_v2.cpp)
add_executable(read_and_compare_names read_and_compare_names.cpp)
add_executable(detect_repeated_words detect_repeated_words.cpp)
add_executable(find_repeated_words find_repeated_words.cpp)
add_executable(unsafe_conversions unsafe_conversions.cpp)
add_executable(letter_generator letter_generator.cpp)
add_executable(exec3-2 exec3-2.cpp)
add_executable(exec3-4 exec3-4.cpp)
add_executable(exec3-5 exec3-5.cpp)
add_executable(exec3-6 exec3-6.cpp)
add_executable(exec3-7 exec3-7.cpp)
add_executable(exec3-8 exec3-8.cpp)
add_executable(exec3-9 exec3-9.cpp)
add_executable(exec3-10 exec3-10.cpp)
add_executable(exec3-11 exec3-11.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
add_output_test(
  NAME read_and_write_first_name_test
  COMMAND read_and_write_first_name
  OUTPUT_FILE ${TESTDATA_DIR}/read_and_write_first_name_output.txt
  INPUT_FILE ${TESTDATA_DIR}/first_name.txt
)
add_output_test(
  NAME read_name_and_age_test
  COMMAND read_name_and_age
  OUTPUT_FILE ${TESTDATA_DIR}/read_name_and_age_output.txt
  INPUT_FILE ${TESTDATA_DIR}/name_and_age.txt
)
add_output_test(
  NAME read_name_and_age_v2_test_success
  COMMAND read_name_and_age_v2
  OUTPUT_FILE ${TESTDATA_DIR}/read_name_and_age_output.txt
  INPUT_FILE ${TESTDATA_DIR}/name_and_age.txt
)
add_output_test(
  NAME read_name_and_age_v2_test_wrong_age
  COMMAND read_name_and_age_v2
  OUTPUT_FILE ${TESTDATA_DIR}/read_name_and_age_v2_output_wrong_age.txt
  INPUT_FILE ${TESTDATA_DIR}/age_and_name.txt
)
add_output_test(
  NAME read_name_and_age_v2_test_no_age
  COMMAND read_name_and_age_v2
  OUTPUT_FILE ${TESTDATA_DIR}/read_name_and_age_v2_output_no_age.txt
  INPUT_FILE ${TESTDATA_DIR}/first_name.txt
)
add_output_test(
  NAME read_name_and_age_v2_test_no_input
  COMMAND read_name_and_age_v2
  OUTPUT_FILE ${TESTDATA_DIR}/read_name_and_age_v2_output_no_input.txt
)
add_output_test(
  NAME read_full_name_test
  COMMAND read_full_name
  OUTPUT_FILE ${TESTDATA_DIR}/read_full_name_output.txt
  INPUT_FILE ${TESTDATA_DIR}/full_name.txt
)
add_output_test(
  NAME read_name_and_age_v3_test
  COMMAND read_name_and_age_v3
  OUTPUT_FILE ${TESTDATA_DIR}/read_name_and_age_v3_output.txt
  INPUT_FILE ${TESTDATA_DIR}/name_and_age_double.txt
)
add_output_test(
  NAME double_operators_test
  COMMAND double_operators
  OUTPUT_FILE ${TESTDATA_DIR}/double_operators_output.txt
  INPUT_FILE ${TESTDATA_DIR}/pi.txt
)
add_output_test(
  NAME integer_operators_test
  COMMAND integer_operators
  OUTPUT_FILE ${TESTDATA_DIR}/integer_operators_output.txt
  INPUT_FILE ${TESTDATA_DIR}/five.txt
)
add_output_test(
  NAME read_full_name_v2_test
  COMMAND read_full_name_v2
  OUTPUT_FILE ${TESTDATA_DIR}/read_full_name_output.txt
  INPUT_FILE ${TESTDATA_DIR}/full_name.txt
)
add_output_test(
  NAME read_and_compare_names_test_equal
  COMMAND read_and_compare_names
  OUTPUT_FILE ${TESTDATA_DIR}/read_and_compare_names_output_equal.txt
  INPUT_FILE ${TESTDATA_DIR}/twice_name.txt
)
add_output_test(
  NAME read_and_compare_names_test_less
  COMMAND read_and_compare_names
  OUTPUT_FILE ${TESTDATA_DIR}/read_and_compare_names_output_less.txt
  INPUT_FILE ${TESTDATA_DIR}/full_name.txt
)
add_output_test(
  NAME read_and_compare_names_test_greater
  COMMAND read_and_compare_names
  OUTPUT_FILE ${TESTDATA_DIR}/read_and_compare_names_output_greater.txt
  INPUT_FILE ${TESTDATA_DIR}/full_name2.txt
)
add_output_test(
  NAME detect_repeated_words_test_repeated1
  COMMAND detect_repeated_words
  OUTPUT_FILE ${TESTDATA_DIR}/detect_repeated_words_output1.txt
  INPUT_FILE ${TESTDATA_DIR}/detect_repeated_words_input1.txt
)
add_output_test(
  NAME detect_repeated_words_test_repeated2
  COMMAND detect_repeated_words
  OUTPUT_FILE ${TESTDATA_DIR}/detect_repeated_words_output2.txt
  INPUT_FILE ${TESTDATA_DIR}/detect_repeated_words_input2.txt
)
add_output_test(
  NAME detect_repeated_words_test_no_repeated
  COMMAND detect_repeated_words
  INPUT_FILE ${TESTDATA_DIR}/detect_repeated_words_input3.txt
)
add_output_test(
  NAME detect_repeated_words_test_no_input
  COMMAND detect_repeated_words
)
add_output_test(
  NAME find_repeated_words_test_repeated1
  COMMAND find_repeated_words
  OUTPUT_FILE ${TESTDATA_DIR}/find_repeated_words_output1.txt
  INPUT_FILE ${TESTDATA_DIR}/detect_repeated_words_input1.txt
)
add_output_test(
  NAME find_repeated_words_test_repeated2
  COMMAND find_repeated_words
  OUTPUT_FILE ${TESTDATA_DIR}/find_repeated_words_output2.txt
  INPUT_FILE ${TESTDATA_DIR}/detect_repeated_words_input2.txt
)
add_output_test(
  NAME find_repeated_words_test_no_repeated
  COMMAND find_repeated_words
  INPUT_FILE ${TESTDATA_DIR}/detect_repeated_words_input3.txt
)
add_output_test(
  NAME find_repeated_words_test_no_input
  COMMAND find_repeated_words
)
add_output_test(
  NAME unsafe_conversions_test
  COMMAND unsafe_conversions
  OUTPUT_FILE ${TESTDATA_DIR}/unsafe_conversions_output.txt
  INPUT_FILE ${TESTDATA_DIR}/unsafe_conversions_input.txt
)
foreach(i RANGE 1 4)
  add_output_test(
    NAME letter_generator_test_ok${i}
    COMMAND letter_generator
    OUTPUT_FILE ${TESTDATA_DIR}/letter_generator_output_ok${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/letter_generator_input_ok${i}.txt
  )
endforeach()
foreach(i RANGE 1 2)
  add_output_test(
    NAME letter_generator_test_invalid${i}
    COMMAND letter_generator
    OUTPUT_FILE ${TESTDATA_DIR}/letter_generator_output_invalid${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/letter_generator_input_invalid${i}.txt
  )
endforeach()
add_output_test(
  NAME letter_generator_test_no_input
  COMMAND letter_generator
  OUTPUT_FILE ${TESTDATA_DIR}/letter_generator_output_no_input.txt
)
add_output_test(
  NAME exec3-2_test
  COMMAND exec3-2
  OUTPUT_FILE ${TESTDATA_DIR}/exec3-2_output.txt
  INPUT_FILE ${TESTDATA_DIR}/exec3-2_input.txt
)
foreach(i RANGE 1 2)
  add_output_test(
    NAME exec3-4_test${i}
    COMMAND exec3-4
    OUTPUT_FILE ${TESTDATA_DIR}/exec3-4_output${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/exec3-4_input${i}.txt
  )
endforeach()
foreach(i RANGE 1 2)
  add_output_test(
    NAME exec3-5_test${i}
    COMMAND exec3-5
    OUTPUT_FILE ${TESTDATA_DIR}/exec3-5_output${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/exec3-5_input${i}.txt
  )
endforeach()
foreach(i RANGE 1 2)
  add_output_test(
    NAME exec3-6_test${i}
    COMMAND exec3-6
    OUTPUT_FILE ${TESTDATA_DIR}/exec3-6_output${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/exec3-6_input${i}.txt
  )
endforeach()
add_output_test(
  NAME exec3-7_test
  COMMAND exec3-7
  OUTPUT_FILE ${TESTDATA_DIR}/exec3-7_output.txt
  INPUT_FILE ${TESTDATA_DIR}/exec3-7_input.txt
)
add_output_test(
  NAME exec3-8_test_odd
  COMMAND exec3-8
  OUTPUT_FILE ${TESTDATA_DIR}/exec3-8_output_odd.txt
  INPUT_FILE ${TESTDATA_DIR}/five.txt
)
add_output_test(
  NAME exec3-8_test_even
  COMMAND exec3-8
  OUTPUT_FILE ${TESTDATA_DIR}/exec3-8_output_even.txt
  INPUT_FILE ${TESTDATA_DIR}/ten.txt
)
foreach(i RANGE 1 3)
  add_output_test(
    NAME exec3-9_test${i}
    COMMAND exec3-9
    OUTPUT_FILE ${TESTDATA_DIR}/exec3-9_output${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/exec3-9_input${i}.txt
  )
endforeach()
foreach(i RANGE 1 5)
  add_output_test(
    NAME exec3-10_test${i}
    COMMAND exec3-10
    OUTPUT_FILE ${TESTDATA_DIR}/exec3-10_output${i}.txt
    INPUT_FILE ${TESTDATA_DIR}/exec3-10_input${i}.txt
  )
endforeach()
add_output_test(
  NAME exec3-11_test
  COMMAND exec3-11
  OUTPUT_FILE ${TESTDATA_DIR}/exec3-11_output.txt
  INPUT_FILE ${TESTDATA_DIR}/exec3-11_input.txt
)
