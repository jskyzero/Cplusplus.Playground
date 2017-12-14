#include <iostream> // for std::cin std::cout
#include <algorithm> // for std::sort
#include <cstring> // for memset


void sort_algorithm(int size, int blank) {
  int *data = new int[size];
  memset(data, 0, sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    std::cin >> data[i];  
  }

  std::sort(data, data + size);

  bool first = true;
  for (int i = 0; i < size; i++) {
    if(0 == i % blank) {
      
      if (first) first = false;
      else std::cout << ' ';

      std::cout << data[i];
    }
  }
  std::cout << std::endl;
}

int main() {
  int size, blank;
  while(std::cin >> size >> blank && size && blank) {
    sort_algorithm(size, blank);
  }
}