#include <ImageEncoding.hpp>

void test() {
  cout << BitBuffer(0x1111, 32).addBit(1)<< endl;
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
    cout << "Usage: ./out [-d|-u] file" << endl
         << "       ./out test" << endl;
    return 1;
  }

}
