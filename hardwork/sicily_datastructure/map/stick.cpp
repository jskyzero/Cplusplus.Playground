#include <iostream>
#include <map>

typedef std::map<int, int> Map;

int stick(int size) {
  int temp_data;
  Map data;
  for (int i = 0; i < size; i++) {
    std::cin >> temp_data;
    data[temp_data]++;
  }

  int ans;
  for (auto & temp_data : data) {
    if (1 == temp_data.second % 2) {
      ans = temp_data.first;
      break;
    }
  }
  return ans;
}

int main() {
  int size;
  while (std::cin >> size && size) {
    std::cout << stick(size) << std::endl;
  }
} 