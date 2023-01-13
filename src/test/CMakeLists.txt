function (gaia_add_test test_src)
  string( REPLACE ".cpp" "" test ${test_src} )

  add_executable( ${test} ${test_src} )
  add_test(NAME ${test} COMMAND ${test})

  target_link_libraries(${test} PRIVATE gaia)
  target_link_libraries(${test} PRIVATE Qt::Core Qt::Concurrent Qt::Test)
  target_link_libraries(${test} PRIVATE ${YAML_LIBRARIES})
endfunction()

set(GAIA_TESTS
  nnsearch.cpp
  unittest.cpp
  testmemleak.cpp
  testoptimization.cpp)

foreach (test_src ${GAIA_TESTS})
  gaia_add_test(${test_src})
endforeach()
