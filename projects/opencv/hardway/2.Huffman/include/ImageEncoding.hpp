#include <ciso646>     // for and not or
#include <cstdint>     // for uint8_t
#include <cstdio>      // for printf
#include <functional>  // for function
#include <iostream>    // for cout
#include <opencv2/opencv.hpp>
#include <queue>   // for priority_queue
#include <string>  // for string
#include <vector>  // for vector

#include <BitBuffer.hpp>
#include <Huffman.hpp>

using namespace cv;
using namespace std;

#define TYPE_SIZE 256
#define TEST 1

class ImageEncoding {
 public:
  void compress(char const* const file_path) {
    auto img = imread(file_path);
    if (img.data == NULL) {
      perror("fail to open file");
      exit(-1);
    }
    // cout << img.size() << endl;
  }

  void decompress(char const* const file_path) {
    auto img = imread(file_path);
    cout << img.size() << endl;
  }
};