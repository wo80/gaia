target_include_directories(gaia2
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_sources(gaia2
  PRIVATE
    filter.cpp
    filterwrapper.cpp
    lex.yy.cpp
    filter.h
    filterwrapper.h
    grammar.h
    parsertypes.h
    token.h
)