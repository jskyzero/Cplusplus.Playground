#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

#define CAT_FILE_PARH "img/cat.png"

int main() {
  auto cat_img = imread(CAT_FILE_PARH, IMREAD_COLOR);
  cout << cat_img.size() << endl;

  return 0;
}
