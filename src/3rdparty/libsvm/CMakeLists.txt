target_include_directories(gaia PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(gaia
  PRIVATE
    gaiasvmutils.cpp
    svm.cpp
  PUBLIC
    gaiasvmutils.h
    svm.h)
