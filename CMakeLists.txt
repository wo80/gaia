cmake_minimum_required(VERSION 3.19.0)

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

add_compile_definitions(CPP_11)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_subdirectory(src)

install(TARGETS gaia2
  EXPORT Gaia2Targets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include)

configure_package_config_file(
  cmake/Gaia2Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/Gaia2Config.cmake
  PATH_VARS CMAKE_INSTALL_INCLUDEDIR
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Gaia2
)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/Gaia2ConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

# Maybe not the best idea to install headers this way.
install(DIRECTORY src/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/gaia2
  FILES_MATCHING
    PATTERN "*.h"
    PATTERN "3rdparty" EXCLUDE
    PATTERN "bindings" EXCLUDE
    PATTERN "doc" EXCLUDE
    PATTERN "stlfacade" EXCLUDE
    PATTERN "test" EXCLUDE
    PATTERN "tools" EXCLUDE
)

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/Gaia2Config.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/Gaia2ConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Gaia2
)

install(EXPORT Gaia2Targets
  FILE Gaia2Targets.cmake
  NAMESPACE Gaia2::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Gaia2)