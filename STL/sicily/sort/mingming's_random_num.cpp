#include <iostream> // for std::cin std::cout 
#include <algorithm> // for std::sort
#include <set> // for std::set

typedef std::set<int> Set;

void random_sort(int size) {
  int temp_size;
  Set myset;
  for (int i = 0; i < size; i++) {
    std::cin >> temp_size;
    myset.insert(temp_size);
  }

  // std::sort(myset.begin(), myset.end());

  std::cout << myset.size() << std::endl;
  bool first = true;
  for( auto & num: myset) {
    if (first) {
      first = false;
    } else {
      std::cout << " ";
    }
    std::cout << num;
  }
  std::cout << std::endl;
}

int main() {
  int size;
  while (std::cin >> size) {
    random_sort(size);
  }
}
