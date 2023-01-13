cmake_minimum_required(VERSION 3.16.0)

project(gaia VERSION 2.4.6
             DESCRIPTION "C++ library for similarity measures and classifications on the results of audio analysis"
             LANGUAGES C CXX)

file(STRINGS "VERSION" gaia_VERSION_STRING)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)

option(BUILD_TESTS "Build tests" OFF)
option(BUILD_TOOLS "Build tools" OFF)
option(ENABLE_TBB "Enable Intel TBB" OFF)

set(GAIA_USE_YAML OFF)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Concurrent Test REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Concurrent Test REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
find_package(YAML)

if(YAML_FOUND)
  set(GAIA_USE_YAML ON)
endif()

if(ENABLE_TBB)
  find_package(TBB)
endif()

add_subdirectory(src)
