cmake_minimum_required (VERSION 3.1)

project (Huffman)

# -std=c++11
set (CMAKE_CXX_STANDARD 14)
# flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(EXECUTABLE_OUTPUT_PATH ${Huffman_SOURCE_DIR})

subdirs(src)