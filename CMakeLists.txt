cmake_minimum_required(VERSION 3.10)

if(NOT WIN32)
  string(ASCII 27 Esc)
  set(ColorReset   "${Esc}[m")
  set(ColorBold    "${Esc}[1m")
  set(ColorRed     "${Esc}[31m")
  set(ColorGreen   "${Esc}[32m")
  set(ColorYellow  "${Esc}[33m")
  set(ColorBlue    "${Esc}[34m")
  set(ColorMagenta "${Esc}[35m")
  set(ColorCyan    "${Esc}[36m")
  set(ColorWhite   "${Esc}[37m")
endif()

site_name(SITE_NAME)

if(SITE_NAME MATCHES "ews.illinois.edu$")
    set(EWS TRUE)
endif()


if(NOT DEFINED EWS)
    set(CMAKE_C_COMPILER "/usr/bin/clang")
    set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
    set(CMAKE_LINKER "/usr/bin/clang++")
else()
    set(CMAKE_C_COMPILER "/software/llvm-6.0.1/bin/clang")
    set(CMAKE_CXX_COMPILER "/software/llvm-6.0.1/bin/clang++")
    set(CMAKE_LINKER "/software/llvm-6.0.1/bin/clang++")

    # Add other required flags for EWS.
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi")
endif()

# Specify C++ Standard.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define project.   
project(${assignment_name} VERSION ${assignment_version})

# Specify Debug build.
set(CMAKE_BUILD_TYPE Debug)

# Specify warnings for all builds.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function")

# Specify debug symbols and no optimizations for Debug builds.
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DCS225_SOLUTION -D_GLIBCXX_DEBUG -O0 -gdwarf-4")

# Specify additional clean files.
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_CLEAN_FILES "${assignment_clean_rm}")

# Add Catch2.
# Note: Ubuntu 20.04 LTS does not have Catch2 on apt
# See: https://github.com/catchorg/Catch2/issues/1383

# Path definitions.
set(lib_dir ${CMAKE_SOURCE_DIR}/lib)
set(src_dir ${CMAKE_SOURCE_DIR}/src)

# Run CMakeLists in lib_dir to build our required libraries.
add_subdirectory(${lib_dir})

# Run CMakeLists in src_dir to build the student's code.
add_subdirectory(${src_dir})

# Add the Catch2 entrypoint using Catch2, our libs and src code.

# Add the assignment entrypoints using our libs and src code.
foreach(entrypoint IN LISTS assignment_entrypoints)
    add_executable(${entrypoint} ${entry_dir}/${entrypoint}.cpp)
    target_link_libraries(${entrypoint} PRIVATE libs src)
endforeach()

add_custom_target(
    install_graphviz
    COMMAND apt update
    COMMAND apt install -y graphviz
)