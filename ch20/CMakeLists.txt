add_library(get_jack_and_jill_data get_jack_and_jill_data.cpp)
foreach(i RANGE 1 4)
  add_executable(jack_and_jill_v${i} jack_and_jill_v${i}.cpp)
  target_link_libraries(jack_and_jill_v${i} get_jack_and_jill_data)
endforeach()
add_library(copy copy.cpp)
add_library(doubly_linked_list_v4 doubly_linked_list_v4.cpp)
add_library(simple_text_editor simple_text_editor.cpp)
add_executable(drill20 drill20.cpp)
target_link_libraries(drill20 copy)
add_executable(exec20-12 exec20-12.cpp)
add_library(singly_linked_list singly_linked_list.cpp)
add_library(pvector pvector.cpp)
add_library(ovector ovector.cpp)
add_library(ownership_vector ownership_vector.cpp)
add_library(range_checked_iterator range_checked_iterator.cpp)
add_executable(exec20-20 exec20-20.cpp)

set(TESTDATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
foreach(i RANGE 1 4)
  add_output_test(
    NAME jack_and_jill_v${i}_test
    COMMAND jack_and_jill_v${i}
    OUTPUT_FILE ${TESTDATA_DIR}/jack_and_jill_output.txt
    INPUT_FILE ${TESTDATA_DIR}/jack_and_jill.txt
  )
endforeach()
add_output_test(
  NAME jack_and_jill_v4_test_empty
  COMMAND jack_and_jill_v4
  OUTPUT_FILE ${TESTDATA_DIR}/jack_and_jill_output_empty.txt
)
add_gtest(NAME copy_test SOURCE copy_test.cpp LIBRARY copy)
add_gtest(NAME doubly_linked_list_v4_test SOURCE doubly_linked_list_v4_test.cpp LIBRARY doubly_linked_list_v4 counted_element)
add_gtest(NAME simple_text_editor_test SOURCE simple_text_editor_test.cpp LIBRARY simple_text_editor)
add_output_test(
  NAME drill20_test
  COMMAND drill20
  OUTPUT_FILE ${TESTDATA_DIR}/drill20_output.txt
)
add_output_test(
  NAME exec20-12_test
  COMMAND exec20-12
  OUTPUT_FILE ${TESTDATA_DIR}/exec20-12_output.txt
  INPUT_FILE ${TESTDATA_DIR}/exec20-12_input.txt
)
add_output_test(
  NAME exec20-12_test_empty
  COMMAND exec20-12
  OUTPUT_FILE ${TESTDATA_DIR}/exec20-12_output_empty.txt
)
add_gtest(NAME singly_linked_list_test SOURCE singly_linked_list_test.cpp LIBRARY singly_linked_list)
add_gtest(NAME pvector_test SOURCE pvector_test.cpp LIBRARY pvector counted_element)
add_gtest(NAME ovector_test SOURCE ovector_test.cpp LIBRARY ovector counted_element)
add_gtest(NAME ownership_vector_test SOURCE ownership_vector_test.cpp LIBRARY ownership_vector counted_element)
add_gtest(NAME range_checked_iterator_test SOURCE range_checked_iterator_test.cpp LIBRARY range_checked_iterator)
