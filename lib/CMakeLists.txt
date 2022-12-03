# Path definitions.
set(lib_dir ${CMAKE_CURRENT_SOURCE_DIR})

# Add overall libs library.
file(GLOB_RECURSE lib_sources CONFIGURE_DEPENDS ${lib_dir}/*.cpp)
add_library(libs ${lib_sources})
target_include_directories(libs PUBLIC ${lib_dir})