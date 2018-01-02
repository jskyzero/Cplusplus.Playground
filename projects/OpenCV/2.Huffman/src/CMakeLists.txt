include_directories(${Huffman_SOURCE_DIR}/include)
find_package (OpenCV REQUIRED)
add_executable (out Huffman.cpp)
target_link_libraries (out ${OpenCV_LIBS})