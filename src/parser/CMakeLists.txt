target_include_directories(gaia2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(gaia2
  PRIVATE
    filter.cpp
    filterwrapper.cpp
    lex.yy.cpp
  PUBLIC
    filter.h
    filterwrapper.h
    grammar.h
    parsertypes.h
    token.h)
