#include <iostream> // for std::cin std::cout 
#include <algorithm> // for sort
#include <cstring> // for memset

void easy_sort() {
  int size;
  std::cin >> size;
  int *data = new int[size];
  memset(data, 0, sizeof(int) * size);

  for (int i = 0; i < size; i++) {
    std::cin >> data[i];
  }

  std::sort(data, data+size);

  for (int i = 0; i < size; i++) {
    std::cout << data[i] << std::endl;
  }
}

int main() {
  int times;
  std::cin >> times;
  while (times--) {
    easy_sort();
  }
}