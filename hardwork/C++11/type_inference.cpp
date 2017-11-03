/*

using auto / decltype

*/

#include <iostream>
#include <vector>

int main() {
  int n;
  std::vector<decltype(n)> v {1, 2, 3};

  for (auto i = v.begin(); i != v.end(); i++) {
    std::cout << *i << " ";
  }

  return 0;
}