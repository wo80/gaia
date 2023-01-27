add_library(gaia2 STATIC)
add_library(Gaia2::gaia2 ALIAS gaia2)

set_target_properties(gaia2 PROPERTIES DEBUG_POSTFIX _d)

if(MSVC)
  add_compile_definitions(NOMINMAX)
  add_compile_definitions(_USE_MATH_DEFINES)
  add_compile_options(/W4)

  target_compile_options(gaia2 PRIVATE /MP)
else()
  add_compile_options(-Wall)
endif()

if(Qt6_FOUND AND MSVC)
  add_compile_options(/Zc:__cplusplus /permissive-)
endif()

target_compile_definitions(gaia2
  PRIVATE
    GAIA_VERSION="${gaia_VERSION_STRING}"
    GAIA_GIT_SHA="")

include_directories(${EIGEN3_INCLUDE_DIRS})
target_link_libraries(gaia2 Eigen3::Eigen)

if(TBB_FOUND)
  add_compile_definitions(HAVE_TBB)
  include_directories(${TBB_INCLUDE_DIRS})
  target_link_libraries(gaia2 TBB::tbb)
else()
  message("Building without TBB.")
endif()

add_definitions(${Qt${QT_VERSION_MAJOR}Concurrent_DEFINITIONS})

include_directories(
  ${Qt${QT_VERSION_MAJOR}Core_INCLUDE_DIRS}
  ${Qt${QT_VERSION_MAJOR}Concurrent_INCLUDE_DIRS})

target_link_libraries(gaia2 Qt::Core Qt::Concurrent)

target_include_directories(gaia2
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_sources(gaia2
  PRIVATE
    convert.cpp
    dataset.cpp
    debugging.cpp
    descriptortree.cpp
    frozendataset.cpp
    gaia.cpp
    gaiamath.cpp
    linalg.cpp
    parameter.cpp
    pointlayout.cpp
    point.cpp
    region.cpp
    searchspace.cpp
    searchspacepool.cpp
    timer.cpp
    transformation.cpp
    utils.cpp
    baseexception.h
    convert.h
    dataset.h
    debugging.h
    descriptor.h
    descriptortree.h
    factory.h
    frozendataset.h
    gaia.h
    gaiaexception.h
    gaiamath.h
    linalg.h
    osdetect.h
    parameter.h
    point.h
    pointlayout.h
    queryoptimizer.h
    queryoptimizer_impl.h
    region.h
    searchspace.h
    searchspace_impl.h
    searchspacepool.h
    searchspacepool_impl.h
    textprogress.h
    timer.h
    transformation.h
    types.h
    utils.h
    view.h
    view_impl.h
)

if(GAIA_USE_YAML)
  include_directories(${YAML_INCLUDE_DIR})
  target_link_libraries(gaia2 ${YAML_LIBRARIES})
  target_sources(gaia2
    PRIVATE
      yamlcpp.cpp
      yamlcpp.h
  )
endif()

add_subdirectory(3rdparty)
add_subdirectory(algorithms)
add_subdirectory(metrics)
add_subdirectory(parser)

if(BUILD_TOOLS)
  add_subdirectory(tools)
endif()

if(BUILD_TESTS AND CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  enable_testing()
  add_subdirectory(test)
endif()
