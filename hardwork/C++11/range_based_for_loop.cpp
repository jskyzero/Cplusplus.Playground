/*

for语句将允许简单的范围迭代

*/

#include <iostream>
#include <vector>

int main() {
  std::vector<int> v {1, 2, 3};

  for (auto i : v) {
    std::cout << i << " ";
  }
  return 0;
}