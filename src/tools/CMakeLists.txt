set(GAIA_TOOLS
  gaiabench.cpp
  gaiafreeze.cpp
  gaiainfo.cpp
  gaiamerge.cpp)

set(QT_LIBS
    ${Qt${QT_VERSION_MAJOR}Core_LIBRARIES}
    ${Qt${QT_VERSION_MAJOR}Concurrent_LIBRARIES}
)

# Setup target executable for each tool.
foreach(tool_src ${GAIA_TOOLS})
  string( REPLACE ".cpp" "" tool ${tool_src} )

  add_executable( ${tool} ${tool_src} )

  target_include_directories(${tool} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../metrics)

  target_link_libraries(${tool} PRIVATE gaia)
  target_link_libraries(${tool} PRIVATE ${QT_LIBS})
  target_link_libraries(${tool} PRIVATE ${YAML_LIBRARIES})
endforeach(tool_src ${GAIA_TOOLS})

# Take care of additional dependencies.
target_sources(gaiabench
  PRIVATE
    frozensearch.cpp
    frozensearch.h)
