#include <iostream> // for std::cin std::cout 
#include <cstring> // for memset

int binary_searchable(int size) {
  int *data = new int[size];
  memset(data, 0, sizeof(int) * size);

  for (int i = 0; i < size; i++) {
    std::cin >> data[i];
  }

  int ans = 0;
  for (int i = 0; i < size; i++) {
    bool left = true, right = true;
    for (int j = 0; j < i; j++) {
      if (data[j] > data[i]) left = false; 
    }
    for (int j = i + 1; j < size; j++) {
      if (data[j] < data[i]) right = false;
    }
    if(left && right) ans++;
  }  
  return ans;
}

int main() {
  int size;
  while (std::cin >> size) {
    std::cout << binary_searchable(size) << std::endl;
  }
}