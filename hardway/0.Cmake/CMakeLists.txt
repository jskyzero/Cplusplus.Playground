cmake_minimum_required (VERSION 2.6)
project (HelloWorld)

# the version number.
set (HelloWorld_VERSION_MAJOR 1)
set (HelloWorld_VERSION_MINOR 0)
set (MESSAGE "HelloWordl!")

# configure
configure_file (
  "${PROJECT_SOURCE_DIR}/helloworld.cpp.in"
  "${PROJECT_SOURCE_DIR}/helloworld.cpp"
  )

# search path
include_directories ("${PROJECT_BINARY_DIR}")

# executable
add_executable (out helloworld.cpp)