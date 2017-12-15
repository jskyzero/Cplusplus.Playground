cmake_minimum_required (VERSION 3.1)

# -std=c++11
set (CMAKE_CXX_STANDARD 14)

project (Huffman)
find_package (OpenCV REQUIRED)
add_executable (out Huffman.cpp)
target_link_libraries (out ${OpenCV_LIBS})