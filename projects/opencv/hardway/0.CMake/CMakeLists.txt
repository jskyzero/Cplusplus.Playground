cmake_minimum_required (VERSION 2.6)
project (HelloWorld)

# the version number.
set (HelloWorld_VERSION_MAJOR 1)
set (HelloWorld_VERSION_MINOR 0)
set (MESSAGE "HelloWordl!")

option (USE_SOME_LIB
        "Use Self Designed Library" ON)


if (USE_SOME_LIB)
add_library(SomeLib SomeLib/somefunction.cpp)
include_directories (${PROJECT_SOURCE_DIR}/SomeLib)
#   include_directories (${PROJECT_SOURCE_DIR}/SomeLib)
#   add_subdirectory (SomeLib)
  set (EXTRA_LIBS ${EXTRA_LIBS} SomeLib)
endif (USE_SOME_LIB)

# configure
configure_file (
  "${PROJECT_SOURCE_DIR}/helloworld.in.cpp"
  "${PROJECT_SOURCE_DIR}/helloworld.cpp"
  )

# search path
include_directories ("${PROJECT_BINARY_DIR}")

# executable
add_executable (out helloworld.cpp)
target_link_libraries (out ${EXTRA_LIBS})
