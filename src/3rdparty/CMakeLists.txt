target_include_directories(gaia PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(gaia PUBLIC MersenneTwister.h)

add_subdirectory(alglib)
add_subdirectory(libsvm)
