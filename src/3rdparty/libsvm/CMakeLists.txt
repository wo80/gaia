target_include_directories(gaia2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(gaia2
  PRIVATE
    gaiasvmutils.cpp
    svm.cpp
    gaiasvmutils.h
    svm.h)
