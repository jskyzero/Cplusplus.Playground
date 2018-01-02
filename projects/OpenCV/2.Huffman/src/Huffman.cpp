#include <ciso646>     // for and not or
#include <iostream>    // for cout


#include <BitBuffer.hpp>
#include <Huffman.hpp>
#include <ImageEncoding.hpp>

void test() {
  auto back_transform_table = std::map<BitBuffer, uchar, BitBufferCompare>();
  back_transform_table.insert(std::pair<BitBuffer, uchar>(BitBuffer(1, 1), 1));
  back_transform_table.insert(std::pair<BitBuffer, uchar>(BitBuffer(1, 1), 1));

  back_transform_table[BitBuffer(2, 2)] = 2;
  back_transform_table[BitBuffer(3, 2)] = 2;
}

int main(int argc, char* argv[]) {

  auto image_encoding = ImageEncoding();
  // ./out -d img/cat.png
  if (argc == 3 and strcmp(argv[1], "-d") == 0) {
    image_encoding.compress(argv[2]);
    return 0;
  // ./out -u img/cat.png.huffman
  } else if (argc == 3 and strcmp(argv[1], "-u") == 0) {
    image_encoding.decompress(argv[2]);
    return 0;
  // ./c test
  } else if (argc == 2 and strcmp(argv[1], "test") == 0) {
    test();
    return 0;
  } else {
  // print help message
    std::cout << "Usage: ./out [-d|-u] file" << std::endl
         << "       ./out test" << std::endl;
    return 1;
  }

}
